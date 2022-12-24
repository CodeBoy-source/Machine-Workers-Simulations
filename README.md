## Operario - Fotocopiadora.
Un centro de trabajo dispone de k máquinas idénticas (p.e. fotocopiadoras) y un único
operario encargado de manejarlas. Los trabajos que van llegando deben cargarse en una máquina
(si hay alguna disponible) por parte del operario. Si todas las máquinas están ocupadas, los
trabajos deben esperar turno (en una única cola). Incluso si hay máquinas disponibles, los
trabajos deben esperar hasta que el operario esté libre para cargarlos en una máquina. Una
vez cargado un trabajo, la máquina lo procesa automáticamente sin requerir la intervenci ́on
del operario hasta que termina. No obstante, cuando una máquina termina un trabajo, este
debe de ser descargado de la misma por el operario.

## ¿Cómo funciona?
Se necesitan acumuladores para calcular las medidas de rendimiento deseadas, `acum_lleg`y
`acum_sal`para el número medio de trabajos en las colas, `acum_ocio`para el tiempo de ocio del
operario, `total_procesados`para el número de trabajos procesador y `acum_estancia`para el
tiempo medio de estancia de los trabajos.

_Parámetros de entrada_: `num_maquinas, tllegada, tcarga, tdescarga, tproceso` que son
tiempos medios entre llegadas de carga, descarga, y proceso). y `tparada` que es el
tiempo que durará la simulación. (Apenas `maquinasmodificables` permite modificar
esos parámetros al ejecutar).

## ¿Cómo ejecutar?
Tenemos dos archivos en `./bin`:
- `./bin/maquinas1trabajador 10000 0 1`
    - El primer parámetro hace referencia al número de simulaciones a ejecutar.
    - El segundo parámetro es el tipo de función generadora a utilizar:
        - 0 -> Es el generador exponencial por defecto.
        - 1 -> Es el generador deterministico.
        - 2 -> Es el generador uniforme.
    - El tercer parámetro es si queremos guardar o no los resultados en `./resultados`.
- `./bin/maquinasmodificables 10000 10 8 1 0.6 0.4 1`
    - El primer parámetro hace referencia al número de simulaciones a ejecutar
    - El segundo es `num_maquinas` o número de máquinas.
    - El tercero es `tproceso` o tiempo que tarda las máquinas en hacer un trabajo.
    - El cuarto es `num_workers` o número de operarios.
    - El quinto es `tcarga` o tiempo que tarda un operario en cargar un trabajo.
    - El sexto es `tdescarga` o tiempo que tarda un operario en descargar un trabajo.
    - El séptimo es si queremos guardar o no los resultados en `./resultados`.
- `./bin/ntec 0`
    - El primer parámetro el tipo de métrica. 0 para NTEC, 1 para TTP.
- `./bin/best_model`
    - hace uso del ejecutable anterior para que genere los resultados
    para los K modelos (infelizmente los modelos no son fácil de cambiar sin tocar
    el código) y realiza las comparaciones con los resultados obtenidos e imprime por
    pantalla los intervalos y porcentajes obtenidos.

## ¿Y los resultados?
En caso de que se haya activado el bit para guardar los resultados (por defecto está
activado) se guardarán los resultados en la carpeta `./resultados/`.
Los resultados guardados tienen como nombre los parámetros utilizado para su ejecución
para poder diferenciar-los y asegurar un nombre único. Además, disponemos de una
carpeta `./resultados/graphs/` con métodos más visuales para los datos.

## Carpeta - scripts:
En esa carpeta poseemos scripts utilizados para generar todos los datos necesarios
para la documentación de esta práctica de forma automática.
