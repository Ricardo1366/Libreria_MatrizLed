Libreria MatrizLed
=======================
Arduino
-------
Para instalar esta librería en Arduino solo hay que descargar el fichero "ZIP" pulsando [AQUÍ](https://github.com/Ricardo1366/Libreria_MatrizLed/archive/refs/heads/master.zip). Una vez descargado se instala desde la opción de menú "Programa | Incluir librería | Añadir biblioteca ZIP"
![Instalar librería ZIP](https://github.com/Ricardo1366/MakAlc_Alarma/raw/master/test/Instalar_Libreria_Zip.JPG)

PlaformIO
---------
Para trabajar con esta librería en PlatormIO solo tienes que incluir en el fichero platformio.ini el siguiente texto:
```text
lib_deps =
           https://github.com/Ricardo1366/Libreria_MatrizLed@^1.1.0
```
Documentación
=============
MatrizLed implementa la clase "MatrizLed" cuya funcionalidad es devolver la posición física de un led en una tira de leds secuenciales que se han dispuesto en forma de matriz.

Por ejemplo , tenemos una matriz de 4 x 4 donde el primer led está ubicado en la esquina superior izquierda y las tiras de leds están ubicadas horizontalmente. La matriz se numera partiendo de la esquina inferior izquierda.
Si miramos la coordenada 0,0 le corresponde la dirección 15. A la 1,1 la 9 o a la 0,3 la 0.

Utilizando esta clase, solo tienes que declarar la matriz y cuando le pasas las coordenadas te devuelve la dirección física del led.

![Matriz led 4x4](https://github.com/Ricardo1366/Libreria_MatrizLed/blob/master/examples/Matriz_8x8.jpg)

La declaración es la siguiente:
```cpp
MatrizLed Nombre_Variable;
```

FUNCIONES
---------
__begin__: Inicializa la matriz con los parámetros que se le pasan.

Cols = Número de columnas de la matriz.

Rows = Número de filas de la matriz.

inicio = Ubicación física del primer led. (En cual de las cuatro esquinas se encuentra)

direccion = Dirección en la que se encuentra el siguiente led en la matriz partiendo del primero (Horizontal/Vertical).

offset = Dirección del primer led de la matriz dentro de la tira de leds si es distinta de 0 (opcional) ;

primeraFila = Que fila se considera la primera en la matriz de leds, la superior o la inferior.

En la siguiente imagen se ve en que posición de la matriz se guarda cada dirección física del led en función de si la primera fila es la superior o la inferior.

![Ubicación primera fila](https://github.com/Ricardo1366/Libreria_MatrizLed/blob/master/examples/Ubicacion_primera_fila.jpg)

__posicion__: Devuelve la posición física del led en la tira.

columna = Número de columna.

fila = Número de fila.


Si encuentras algún fallo en la ejecución de la librería, por favor informa [AQUÍ](mailto:ricardomakeralicante@gmail.com)
