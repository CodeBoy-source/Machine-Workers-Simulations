#include "../../include/utils.h"
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <cstdlib>

float better[] = {0,0,0,0};
string path;
unsigned int n_0 = 20;
unsigned int szm = 4;
float** models = new float*[szm];
unsigned int cont = 0;
float** means = new float*[szm];
float** vars = new float*[szm];
float** weights = new float*[szm];

string generateName(int num_maquinas, float tproceso,
        int num_workers, float tcarga, float tdescarga){
    stringstream oss;
    oss << setprecision(2) << "N_m:" << num_maquinas << "tp:" <<
        tproceso << "N_w:" << num_workers << "tc:" <<
        tcarga << "td:" << tdescarga << ".txt";
    return oss.str();
}

void openFiles(fstream* files){
    files[0].open(path+"../resultados/"+generateName(10,8,1,0.6,0.4));
    files[1].open(path+"../resultados/"+generateName(10,8,2,1.2,0.8));
    files[2].open(path+"../resultados/"+generateName(10,8,5,3,2));
    files[3].open(path+"../resultados/"+generateName(10,8,10,6,4));
}

void closeFiles(fstream* files){
    files[0].close();
    files[1].close();
    files[2].close();
    files[3].close();
}

float get_tiempo_medio_estancia(fstream& file){
    if(!file.is_open()){
        cerr << "[ERROR]: File is not open, can't read data" << endl;
        exit(-1);
    }
    float res;
    for(unsigned int i=0;i<7;i++){
        file >> res;
    }
    return res;
}

void compute_best(fstream* files){
    float value1 = get_tiempo_medio_estancia(files[0]);
    float value2 = get_tiempo_medio_estancia(files[1]);
    float value3 = get_tiempo_medio_estancia(files[2]);
    float value4 = get_tiempo_medio_estancia(files[3]);

    models[0][cont] = value1;
    models[1][cont] = value2;
    models[2][cont] = value3;
    models[3][cont] = value4;
    cont++;
}

void count_best(fstream* files){
    float value1 = get_tiempo_medio_estancia(files[0]);
    float value2 = get_tiempo_medio_estancia(files[1]);
    float value3 = get_tiempo_medio_estancia(files[2]);
    float value4 = get_tiempo_medio_estancia(files[3]);

    bool index1=false, index3=false;
    float pair1_max = value2, pair2_max = value4;
    if(value1<=value2){
        pair1_max = value1;
        index1=true;
    }
    if(value3<=value4){
        pair2_max = value3;
        index3=true;
    }
    if(pair1_max<=pair2_max){
        if(index1){
            better[0]++;
        }else{
            better[1]++;
        }
    }else{
        if(index3){
            better[2]++;
        }else{
            better[3]++;
        }
    }


}

void get_stats(unsigned int n){
    float mean = 0;
    for(unsigned int i=0;i<szm; i++){
        mean = 0;
        for(unsigned int j=0;j<n;j++){
            mean += models[i][j];
        }
        means[i][0] = mean;
    }
    for(unsigned int i=0;i<szm;i++){
        means[i][0] /= n;
    }

    float var = 0;
    for(unsigned int i=0;i<szm;i++){
        var = 0;
        for (unsigned int j = 0; j<n; ++j) {
           var += (models[i][j] - means[i][0]) * (models[i][j] - means[i][0]);
        }
        vars[i][0] = var/((float)n-1);
    }
}

void get_stats_for(unsigned int N, unsigned int m){
    float mean = 0;
    unsigned int i;
    for(i=0;i<N;i++){
        mean += models[m][i];
    }
    means[m][0] = mean / N;

    float var = 0;
    for (i = 0; i < N; i++) {
        var += (models[m][i] - means[m][0]) * (models[m][i] - means[m][0]);
    }
    vars[m][0] = var/((float)N-1);
}

int main(){

    fstream* files = new fstream[szm];
    path = get_selfpath();
    path = path.substr(0,path.find_last_of("/\\") + 1);

    int simulaciones = 100;

    int exitStatus = 0;

    string* commands = new string[4];
    commands[0] = path+"maquinasmodificable "+to_string(simulaciones)+" 10 8 1 0.6 0.4 1 > /dev/null";
    commands[1] = path+"maquinasmodificable "+to_string(simulaciones)+" 10 8 2 1.2 0.8 1 > /dev/null";
    commands[2] = path+"maquinasmodificable "+to_string(simulaciones)+" 10 8 5 3 2 1 > /dev/null";
    commands[3] = path+"maquinasmodificable "+to_string(simulaciones)+" 10 8 10 6 4 1 > /dev/null";

    unsigned int n_0 = 20;
    for(unsigned int i=0;i<szm;i++){
        means[i] = new float[2];
        vars[i] = new float[2];
        weights[i] = new float[1];
        models[i] = new float[n_0];
    }

    for(unsigned int i=0;i<n_0;i++){
        exitStatus = system(commands[0].c_str());
        exitStatus = system(commands[1].c_str());
        exitStatus = system(commands[2].c_str());
        exitStatus = system(commands[3].c_str());
        if(exitStatus<0){
            cerr << " [ERROR]: Couldn't execute the auxiliar program" << endl;
            exit(-1);
        }
        openFiles(files);
        compute_best(files);
        closeFiles(files);
    }

    get_stats(n_0);

    float d = 0.5*0.5;
    float h1 = 2.583*2.583;
    unsigned int* N_m = new unsigned int[szm];
    for(unsigned int i=0;i<szm;i++){
        N_m[i] = max((int)n_0+1,
                (int)ceil(
                        (h1 * vars[i][0])/( d )
                    )
                );
    }

    for(unsigned int i=0;i<szm;i++){
        means[i][1] = means[i][0];
        vars[i][1] = vars[i][0];
        models[i] =  new float[N_m[i]-n_0];
    }

    for(unsigned int i=0;i<szm;i++){
        for(unsigned int j=0;j<N_m[i]-n_0;j++){
            exitStatus = system(commands[i].c_str());
            openFiles(files);
            models[i][j] = get_tiempo_medio_estancia(files[i]);
            closeFiles(files);
        }
        get_stats_for(N_m[i]-n_0,i);
    }

    float ratio, invratio, denominator, nominator;
    for(unsigned int i=0;i<szm;i++){
        ratio = (float) n_0 / (float) N_m[i];
        invratio = (float) N_m[i] / (float) n_0;
        nominator = (N_m[i] - n_0)*d;
        denominator = (h1*vars[i][1]);
        weights[i][0] = ratio * ( 1 + sqrt( 1 - invratio * ( 1 - nominator/denominator ) ) );
        weights[i][1] = 1 - weights[i][0];
    }

    float* Wmeans = new float[szm];
    cout << "Medias Ponderadas obtenidas: " << endl;
    for(unsigned int i=0;i<szm;i++){
        Wmeans[i] = weights[i][0]*means[i][1] + weights[i][1]*means[i][0];
        cout << Wmeans[i] << "\t";
    }
    cout << endl;

    for(int i=0;i<simulaciones;i++){
        exitStatus = system(commands[0].c_str());
        exitStatus = system(commands[1].c_str());
        exitStatus = system(commands[2].c_str());
        exitStatus = system(commands[3].c_str());
        if(exitStatus<0){
            cerr << " [ERROR]: Couldn't execute the auxiliar program" << endl;
            exit(-1);
        }
        openFiles(files);
        count_best(files);
        closeFiles(files);
    }
    cout << "Conteo de mejor modelo" << endl;
    for(unsigned int i=0;i<4;i++){
        better[i] /= (float)simulaciones;
        cout << better[i]*100 << "%\t";
    }
    cout << endl;
}
