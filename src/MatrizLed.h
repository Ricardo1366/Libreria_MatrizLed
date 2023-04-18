#pragma once
#include <Arduino.h>
// Posición física del primer led en la matriz.
enum class ml_Inicio
{
	Inicio_Superior_Izquierda,
	Inicio_Superior_Derecha,
	Inicio_Inferior_Izquierda,
	Inicio_Inferior_Derecha
};

// Dirección de las tiras de leds en la matriz.
enum class ml_Direccion
{
	Direccion_Horizontal,
	Direccion_Vertical
};

enum class ml_UbicacionPrimeraFila
{
	Superior,
	Inferior
};

// Controla una matriz de leds compuesta por tiras de leds secuenciales.
class MatrizLed
{
public:

	// Controla una matriz de leds compuesta por tiras de leds secuenciales.
	MatrizLed();

	// Guarda las características de la matriz de leds para el cálculo.
	// Cols = Número de columnas de la matriz.
	// Rows = Número de filas de la matriz
	// inicio = Ubicación física del primer led
	// direccion = dirección en la que se encuentra el siguiente led en la matriz partiendo del primero.
	// offset = Direccón del primer led de la matriz si es distinta de 0 (opcional) ;
	// primeraFila = Indica si consideramos como primera fila la fila superior de la matriz de leds o si es la inferior.
	void begin(int Cols, int Rows, ml_Inicio inicio, ml_Direccion direccion, int offset = 0, ml_UbicacionPrimeraFila primeraFila = ml_UbicacionPrimeraFila::Inferior);

	// Devuelve la posición del led en función de la columna y fila suministradas.
	int posicion(int columna, int fila);

private:
	ml_Direccion _direccion;
	ml_UbicacionPrimeraFila _primeraFila;
	bool FilaInvertida = false, ColumnaInvertida = false, _CambioFila = false, _CambioColumna = false;
	int _Columna = 0, _Fila = 0, _nCols = 0, _nRows = 0, resultado = 0, _offset = 0;
};
