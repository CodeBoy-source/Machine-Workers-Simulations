#include "../include/multiplesmaquinas1trabajador.h"
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
    operario_libre = true;
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
    if (operario_libre && maquinas_libres>0) {
        nodo.suceso = SUCESO_FIN_CARGA;
        nodo.tiempo = reloj+genera_carga(tcarga);
        nodo.tllego = reloj;
        insertar_lsuc(nodo);
        operario_libre = false;
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
        operario_libre = true;
        comienzo_ocio = reloj;
    }
}


/* Procedimiento fin de procesamiento */
void fin_procesamiento()
{
    if (operario_libre) {
        nodo.suceso = SUCESO_FIN_DESCARGA;
        nodo.tiempo = reloj+genera_descarga(tdescarga);
        //nodo.tllego se deja como esta, se hereda del suceso actual
        insertar_lsuc(nodo);
        operario_libre = false;
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
        operario_libre = true;
        comienzo_ocio = reloj;
    }
}


/* Procedimiento fin de simulacion */
void fin_simulacion()
{
    parar=true;
    acum_lleg += (reloj-tdus_lleg)*encola_lleg;
    acum_sal += (reloj-tdus_sal)*encola_sal;
    if (operario_libre) acum_ocio += reloj-comienzo_ocio;
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
void generador_informes(int simulaciones, ofstream& myfile)
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

    if(streambuffer==0){
        printf("\n\nINFORME ->");
        printf("\n\nNumero de trabajos esperando ser cargados: media(%f), dt(%f)",media[0],dt[0]);
        printf("\nNumero de trabajos esperando ser descargados: media(%f), dt(%f)",media[1],dt[1]);
        printf("\nNumero de trabajos procesados: media(%f), dt(%f)",media[2],dt[2]);
        printf("\nTiempo de estancia de los trabajos: media(%f), dt(%f)",media[3],dt[3]);
        printf("\nPorcentaje de tiempo de ocio del operario: media(%f), dt(%f)",media[4],dt[4]);
        printf("\n\n");
    }else{
        myfile << setprecision(5) << setw(15) << media[0] << setw(15) << dt[0] <<
            setprecision(5) << setw(15) << media[1] << setw(15) << dt[1] <<
            setprecision(5) << setw(15) << media[2] << setw(15) << dt[2] <<
            setprecision(5) << setw(15) << media[3] << setw(15) << dt[3] <<
            setprecision(5) << setw(15) << media[4] << setw(15) << dt[4] <<
            endl;
    }
}


/* Generadores de datos */
// Generador de tiempos entre llegadas de trabajos
float genera_trabajo(float tllegada)
{
    float res = -1;
    switch(FUNC){
        case 0:
            res = generador_exponencial(tllegada);
            break;
        case 1:
            res =  generador_deterministico(tllegada);
            break;
        case 2:
            res =  generador_uniforme(tllegada);
            break;
    }
    return res;
}

// Generador de tiempos de carga
float genera_carga(float tcarga)
{
    float res = -1;
    switch(FUNC){
        case 0:
            res = generador_exponencial(tcarga);
            break;
        case 1:
            res =  generador_deterministico(tcarga);
            break;
        case 2:
            res =  generador_uniforme(tcarga);
            break;
    }
    return res;
}

// Generador de tiempos de descarga
float genera_descarga(float tdescarga)
{
    float res = -1;
    switch(FUNC){
        case 0:
            res = generador_exponencial(tdescarga);
            break;
        case 1:
            res =  generador_deterministico(tdescarga);
            break;
        case 2:
            res =  generador_uniforme(tdescarga);
            break;
    }
    return res;
}

// Generador de tiempos de procesamiento
float genera_procesamiento(float tproceso)
{
    float res = -1;
    switch(FUNC){
        case 0:
            res = generador_exponencial(tproceso);
            break;
        case 1:
            res =  generador_deterministico(tproceso);
            break;
        case 2:
            res =  generador_uniforme(tproceso);
            break;
    }
    return res;
}

float generador_exponencial(float media)
{
    float u;
    u = (float) random();
    u = (float) (u/(RAND_MAX+1.0));
    return(-media*log(1-u));
}

float generador_deterministico(float media){
    return media;
}

float generador_uniforme(float media){
    float min = media - media * 0.5;
    float max = media + media * 0.5;
    float u = (float) random();
    u = (float) (u/(RAND_MAX+1.0));
    return (min + (max-min)+u);
}


/* Programa principal */
int main(int argc, char *argv[])
{
    int i, simulaciones;

    if(argc <= 2)
    {
        printf("[ERROR]:Execution format: ./main <repeat_til> <func_type>[0:exp,1:det,2:uni] [OPTIONAL]:<Save results>(Defaults: True)[0:1]\n");
        exit(1);
    }

    sscanf(argv[1],"%d",&simulaciones);
    streambuffer = 1;
    FUNC = atoi(argv[2]);
    if(!(FUNC-3<0)){
        cerr << "[ERROR]: Invalid function type, 0 - for exponential, 1 - deterministic and 2 for uniform" << endl;
        exit(-1);
    }
    string func_name;
    switch(FUNC){
        case 0:
            func_name="EXP";
            break;
        case 1:
            func_name="DET";
            break;
        case 2:
            func_name="UNI";
            break;
    }
    if(argc>3){
        if(atoi(argv[3])==0)
            streambuffer = 0;
    }

    // Try to store the results in a file
    string path;
    stringstream oss;
    ofstream data;
    if(streambuffer==1){
        path = get_selfpath();
        path = path.substr(0,path.find_last_of("/\\") + 1);
        oss << path << "../resultados/maquinas" << func_name << ".txt";
        data.open(oss.str(),ios::out|ios::trunc);
        if(!data.is_open()){
            cerr << "[ERROR]: Couldn't open file to save results" << endl;
            streambuffer = 0;
        }
    }

    informe = (float **) malloc (simulaciones*sizeof(float *));
    for(i=0; i<simulaciones; i++)
        informe[i] = (float *) malloc (5*sizeof(float));

    srandom(time(NULL));
    //srandom(123456);

    for(unsigned int i=0;i<10;i++){
        for(cont_simu=0; cont_simu<simulaciones; cont_simu++)
        {
        progress_bar(
                raNge1(cont_simu+i*simulaciones,10*simulaciones)
                );
            inicializacion();
            while(parar==false)
            {
                temporizacion();
                suceso();
            }
        }
        generador_informes(simulaciones,data);
    }
    progress_bar(
            1
            );

    for(i=0; i<simulaciones; i++)
        free(informe[i]);
    free(informe);

    cout << endl;
    return 0;
}
