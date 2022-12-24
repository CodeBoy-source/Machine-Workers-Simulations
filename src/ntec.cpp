#include "../include/ntec.h"
#include "../../include/utils.h"
#include <string>
#include <random>
#include <iostream>
#include <fstream>

bool compare(const suc &s1, const suc &s2)
{ return s1.tiempo < s2.tiempo; }


/* Inserta de forma ordenada un elemento en la lista de sucesos */
void insertar_lsuc(suc n)
{
    lsuc.push_back(n);

    // Mantener ordenada la lista por el tiempo de los sucesos
    lsuc.sort(compare);
}


/* Procedimiento inicializacion */
void inicializacion()
{
    // inicializacion de variables de estado
    reloj = 0.0;
    operario_ocupado = 0;
    maquinas_libres = num_maquinas;
    encola_lleg = 0;
    while(!cola_llegadas.empty()) {cola_llegadas.pop_front();}
    encola_sal = 0;
    while(!cola_salidas.empty()) {cola_salidas.pop_front();}
    tdus_lleg = 0.0;
    tdus_sal = 0.0;

    // inicializacion de contadores estadisticos
    acum_lleg = 0.0;
    acum_sal = 0.0;
    acum_estancia = 0.0;
    acum_ocio = 0.0;
    total_procesados = 0;
    comienzo_ocio = reloj;

    // inicializacion de la lista de sucesos
    while(!lsuc.empty()) {lsuc.pop_front();}
    nodo.tllego = 0;
    nodo.suceso = SUCESO_FIN_SIMULACION;
    nodo.tiempo = reloj+tparada;
    insertar_lsuc(nodo);
    nodo.suceso = SUCESO_LLEGADA_TRABAJO;
    nodo.tiempo = reloj+genera_trabajo(tllegada);
    insertar_lsuc(nodo);

    parar=false;
}


/* Procedimiento temporizacion */
void temporizacion()
{
    nodo = lsuc.front();
    lsuc.pop_front();
    reloj = nodo.tiempo;
}


/* Procedimiento suceso */
void suceso()
{
    switch(nodo.suceso)
    {
        case SUCESO_LLEGADA_TRABAJO: llegada_trabajo(); break;
        case SUCESO_FIN_CARGA: fin_carga(); break;
        case SUCESO_FIN_DESCARGA: fin_descarga(); break;
        case SUCESO_FIN_PROCESAMIENTO: fin_procesamiento(); break;
        case SUCESO_FIN_SIMULACION: fin_simulacion(); break;
    }
}


/* Peocedimiento llegada de trabajo */
void llegada_trabajo()
{
    nodo.suceso = SUCESO_LLEGADA_TRABAJO;
    nodo.tiempo = reloj+genera_trabajo(tllegada);
    nodo.tllego = 0;
    insertar_lsuc(nodo); //programa la proxima llegada
    if (operario_ocupado<num_workers && maquinas_libres>0) {
        nodo.suceso = SUCESO_FIN_CARGA;
        nodo.tiempo = reloj+genera_carga(tcarga);
        nodo.tllego = reloj;
        insertar_lsuc(nodo);
        operario_ocupado++;
        maquinas_libres --;
        acum_ocio += reloj-comienzo_ocio;
    }
    else {
        acum_lleg += (reloj-tdus_lleg)*encola_lleg;
        tdus_lleg = reloj;
        encola_lleg ++;
        cola_llegadas.push_back(reloj);
    }
}


/* Procedimiento fin de carga */
void fin_carga()
{
    float cuandollegue;

    nodo.suceso = SUCESO_FIN_PROCESAMIENTO;
    nodo.tiempo = reloj+genera_procesamiento(tproceso);
    //nodo.tllego se deja como esta, se hereda del suceso actual
    insertar_lsuc(nodo);
    if (encola_sal > 0)
    {
        acum_sal += (reloj-tdus_sal)*encola_sal;
        tdus_sal = reloj;
        encola_sal --;
        cuandollegue = cola_salidas.front();
        cola_salidas.pop_front();
        nodo.suceso = SUCESO_FIN_DESCARGA;
        nodo.tiempo = reloj+genera_descarga(tdescarga);
        nodo.tllego = cuandollegue;
        insertar_lsuc(nodo);
    }
    else if (encola_lleg > 0 && maquinas_libres > 0)
    {
        acum_lleg += (reloj-tdus_lleg)*encola_lleg;
        tdus_lleg = reloj;
        encola_lleg --;
        maquinas_libres --;
        cuandollegue = cola_llegadas.front();
        cola_llegadas.pop_front();
        nodo.suceso = SUCESO_FIN_CARGA;
        nodo.tiempo = reloj+genera_carga(tcarga);
        nodo.tllego = cuandollegue;
        insertar_lsuc(nodo);
    }
    else {
        operario_ocupado--;
        comienzo_ocio = reloj;
    }
}


/* Procedimiento fin de procesamiento */
void fin_procesamiento()
{
    if (operario_ocupado<num_workers) {
        nodo.suceso = SUCESO_FIN_DESCARGA;
        nodo.tiempo = reloj+genera_descarga(tdescarga);
        //nodo.tllego se deja como esta, se hereda del suceso actual
        insertar_lsuc(nodo);
        operario_ocupado++;
        acum_ocio += reloj-comienzo_ocio;
    }
    else
    {
        acum_sal += (reloj-tdus_sal)*encola_sal;
        tdus_sal = reloj;
        encola_sal ++;
        cola_salidas.push_back(nodo.tllego);
    }
}


/* Procedimiento fin de descarga */
void fin_descarga()
{
    float cuandollegue;

    maquinas_libres ++;
    total_procesados ++;
    acum_estancia += reloj-nodo.tllego;
    if (encola_sal > 0)
    {
        acum_sal += (reloj-tdus_sal)*encola_sal;
        tdus_sal = reloj;
        encola_sal --;
        cuandollegue = cola_salidas.front();
        cola_salidas.pop_front();
        nodo.suceso = SUCESO_FIN_DESCARGA;
        nodo.tiempo = reloj+genera_descarga(tdescarga);
        nodo.tllego = cuandollegue;
        insertar_lsuc(nodo);
    }
    else if (encola_lleg > 0)
    {
        acum_lleg += (reloj-tdus_lleg)*encola_lleg;
        tdus_lleg = reloj;
        encola_lleg --;
        maquinas_libres --;
        cuandollegue = cola_llegadas.front();
        cola_llegadas.pop_front();
        nodo.suceso = SUCESO_FIN_CARGA;
        nodo.tiempo = reloj+genera_carga(tcarga);
        nodo.tllego = cuandollegue;
        insertar_lsuc(nodo);
    }
    else {
        operario_ocupado--;
        comienzo_ocio = reloj;
    }
}


/* Procedimiento fin de simulacion */
void fin_simulacion()
{
    parar=true;
    acum_lleg += (reloj-tdus_lleg)*encola_lleg;
    acum_sal += (reloj-tdus_sal)*encola_sal;
    if (operario_ocupado<num_workers) acum_ocio += reloj-comienzo_ocio;
    //printf("\nNumero de trabajos esperando ser cargados = %f",acum_lleg/reloj);
    informe[cont_simu][0] = acum_lleg/reloj;
    //printf("\nNumero de trabajos esperando ser descargados = %f",acum_sal/reloj);
    informe[cont_simu][1] = acum_sal/reloj;
    //printf("\nTotal de trabajos procesados= %f",total_procesados);
    informe[cont_simu][2] = total_procesados;
    //printf("\nTiempo de estancia de los trabajos = %f",acum_estancia/total_procesados);
    informe[cont_simu][3] = acum_estancia/total_procesados;
    //printf("\nPorcentaje de tiempo de ocio del operario = %f",acum_ocio*100/reloj);
    informe[cont_simu][4] = acum_ocio*100/reloj;
}


/* El generador de informes se encarga de calcular la media y desviacion tipica de los valores obtenidos */
void generador_informes(int simulaciones, int turn)
{
    float media[5], dt[5];
    int i,j;

    for(j=0; j<5; j++)
    {
        media[j] = 0;
        for(i=0; i<simulaciones; i++)
            media[j] += informe[i][j];
        media[j] /= simulaciones;

        dt[j] = 0;
        for(i=0; i<simulaciones; i++)
            dt[j] += informe[i][j] * informe[i][j];
        dt[j] = sqrt((dt[j]-simulaciones*media[j]*media[j]) / (simulaciones-1.0));
    }

    if(turn==0){
        for(j=0;j<5;j++)
            media1[j] = media[j];
    }else{
        //cout << endl << media1[0] << " - " << media[0] << endl;
        switch(viewpoint){
            case 0:
                diffs[contdiff++] = media1[0]-media[0];
                if(media1[0]<media[0]){
                    better[0]++;
                }else if (media1[0]>=media1[0]){
                    better[1]++;
                }
                break;
            case 1:
                diffs[contdiff++] = media1[2]-media[2];
                if(media1[2]>media[2]){
                    better[0]++;
                }else if (media1[2]<=media1[2]){
                    better[1]++;
                }
                break;
        }
    }
}


/* Generadores de datos */
// Generador de tiempos entre llegadas de trabajos
float genera_trabajo(float tllegada)
{ return generador_exponencial(tllegada); }

// Generador de tiempos de carga
float genera_carga(float tcarga)
{
    return generador_exponencial(tcarga);
}

// Generador de tiempos de descarga
float genera_descarga(float tdescarga)
{
    return generador_exponencial(tdescarga);
}

// Generador de tiempos de procesamiento
float genera_procesamiento(float tproceso)
{
    return generador_exponencial(tproceso);
}

float generador_exponencial(float media)
{
    float u;
    u = (float) random();
    u = (float) (u/(RAND_MAX+1.0));
    return(-media*log(1-u));
}

void simular(int i, int simulaciones){
    for(cont_simu=0; cont_simu<simulaciones; cont_simu++)
    {
        progress_bar(
                raNge1(cont_simu + i,MEAN*agg_probar)
                );
        inicializacion();
        while(parar==false)
        {
            temporizacion();
            suceso();
        }
    }
}

void inicializar_casoA(){
    num_maquinas = 10;
    num_workers = 2;
    tcarga = 3;
    tdescarga = 2;
}

void inicializar_casoB(){
    num_maquinas = 10;
    num_workers = 1;
    tcarga = 1.5;
    tdescarga = 1;
}

void resetearInformes(int simulaciones){
    int i;
    for(i=0; i<simulaciones; i++)
        free(informe[i]);

    for(i=0; i<simulaciones; i++)
        informe[i] = (float *) malloc (5*sizeof(float));
}

void generaIntervalo(float* interval){
    float mean = 0;
    for(int i=0;i<MEAN;i++){
        mean += diffs[i];
    }
    mean /= MEAN;
    float var = 0;
    for (int i = 0; i < MEAN; ++i) {
        var += ( diffs[i] - mean ) * (diffs[i] - mean);
    }
    var /= (MEAN-1);

    float temp = 1.9842 * sqrt(var/MEAN);
    interval[0] = mean - temp;
    interval[1] = mean + temp;
}

/* Programa principal */
int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("[ERROR]:Execution format: ./main <metric>[0-NTEC, 1-TTP]\n");
        printf("[OPTIONAL] (Store results)(Defaults: True)\n");
        exit(1);
    }

    sscanf(argv[1],"%d",&viewpoint);
    streambuffer = 1;
    if(argc>2){
        if(atoi(argv[2])==0)
            streambuffer = 0;
    }

    // Try to store the results in a file
    string path;
    stringstream oss;
    ofstream data;
    if(streambuffer==1){
        path = get_selfpath();
        path = path.substr(0,path.find_last_of("/\\") + 1);
        oss << setprecision(2) << path << "../resultados/ntec-s:" << ((viewpoint==0)?"NTEC":"TTP")<< ".txt";
        data.open(oss.str(),ios::out|ios::trunc);
        if(!data.is_open()){
            cerr << "[ERROR]: Couldn't open file to save results" << endl;
            streambuffer = 0;
        }
    }


    srandom(time(NULL));
    //srandom(123456);

    agg_probar = 0;
    for(int i=0;i<sz_probar;i++){
        agg_probar += 2*probar_para[i];
    }

    int cont = 0;
    media1 = new float[5];
    float* interval = new float[2];
    better = new float[2];
    for(int j=0;j<sz_probar;j++){
        better[0] = 0;
        better[1] = 0;
        informe = (float **) malloc (probar_para[j]*sizeof(float *));
        for(int i=0; i<probar_para[j]; i++)
            informe[i] = (float *) malloc (5*sizeof(float));

        contdiff = 0;
        diffs = (float*) malloc(MEAN*sizeof(float));
        for(int i=0;i<MEAN;i++){
            inicializar_casoA();
            simular(cont,probar_para[j]);
            cont += probar_para[j];
            generador_informes(probar_para[j],0);
            inicializar_casoB();
            simular(cont,probar_para[j]);
            cont += probar_para[j];
            generador_informes(probar_para[j],1);
        }
        better[0] = better[0] / (float)MEAN * 100;
        better[1] = better[1] / (float)MEAN * 100;
        generaIntervalo(interval);
        if(streambuffer)
            data << setprecision(5) << setw(10) << probar_para[j]
                << setw(10) << better[0] << setw(10) << better[1] << setw(10) << interval[0] << setw(10) << interval[1] << endl;
        else{
            cout << "\nCaso Media-A-B: " << probar_para[j] << "\t" << better[0] << "\t" << better[1] << "\t" << interval[0] << "\t" << interval[1] << endl;
            cout << flush;
        }
        for(int i=0; i<probar_para[j]; i++)
            free(informe[i]);
        free(informe);
        free(diffs);
    }
    progress_bar(1);


    cout << endl;
    return 0;
}
