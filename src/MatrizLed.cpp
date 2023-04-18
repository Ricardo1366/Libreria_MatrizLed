#include <Arduino.h>
#include <MatrizLed.h>

// Declaración de la clase
MatrizLed::MatrizLed()
{
	_Columna = 0;
	_Fila = 0;
	_nCols = 0;
	_nRows = 0;
	resultado = 0;
}

// Configuración
void MatrizLed::begin(int Cols, int Rows, ml_Inicio inicio, ml_Direccion direccion, int offset, ml_UbicacionPrimeraFila primeraFila)
{

	_nCols = Cols;
	_nRows = Rows;
	_direccion = direccion;
	_offset = offset;
	_primeraFila = primeraFila;

	switch (inicio)
	{
	case ml_Inicio::Inicio_Inferior_Derecha:
		FilaInvertida = false;
		ColumnaInvertida = _direccion == ml_Direccion::Direccion_Horizontal ? false : true;
		break;
	case ml_Inicio::Inicio_Inferior_Izquierda:
		FilaInvertida = false;
		ColumnaInvertida = _direccion == ml_Direccion::Direccion_Horizontal ? true : false;
		break;
	case ml_Inicio::Inicio_Superior_Derecha:
		FilaInvertida = true;
		ColumnaInvertida = _direccion == ml_Direccion::Direccion_Horizontal ? false : true;
		break;
	case ml_Inicio::Inicio_Superior_Izquierda:
		FilaInvertida = true;
		ColumnaInvertida = _direccion == ml_Direccion::Direccion_Horizontal ? true : false;
		break;
	default:
		break;
	}
	// Si las columnas son pares hay que invertir la dirección de las filas en dos casos.
	// Superior derecha en vertical e Inferior derecha en vertical
	if (_nCols % 2 == 0)
	{
		if (_direccion == ml_Direccion::Direccion_Vertical)
		{
			if (inicio == ml_Inicio::Inicio_Inferior_Derecha || inicio == ml_Inicio::Inicio_Superior_Derecha)
			{
				FilaInvertida = !FilaInvertida;
			}
		}
	}
	// Si las filas son pares hay que invertir la dirección de las columnas en dos casos.
	// Superior izquierda en horizontal y Superior derecha en horizontal
	if (_nRows % 2 == 0)
	{
		if (_direccion == ml_Direccion::Direccion_Horizontal)
		{
			if (inicio == ml_Inicio::Inicio_Superior_Izquierda || inicio == ml_Inicio::Inicio_Superior_Derecha)
			{
				ColumnaInvertida = !ColumnaInvertida;
			}
		}
	}
}

// Cáculo de la posición
int MatrizLed::posicion(int columna, int fila)
{
	// Si el número es inferior a cero o superior al nº máximo de leds se calcula el número correspondiente.
	// Por ejemplo si el máximo son 8 y pasamos 9 devuelve 1
	// Si pasamos -1 devuelve 7
	if (columna >= 0)
	{
		columna %= _nCols;
	}
	else
	{
		columna = _nCols + (columna % _nCols);
		if (columna == _nCols)
		{
			columna = 0;
		}
	}

	if (fila >= 0)
	{
		fila %= _nRows;
	}
	else
	{
		fila = _nRows + (fila % _nRows);
		if (fila == _nRows)
		{
			fila = 0;
		}
	}

	_CambioColumna = ColumnaInvertida;
	_CambioFila = FilaInvertida;

	// En caso de definir como primer fila la superior hay que invertir la posición.
	if(_primeraFila == ml_UbicacionPrimeraFila::Superior){
		fila = _nRows - fila - 1;
	}
	
	// En función de si la dirección es horizontal/vertical hay que invertir la columna/fila
	if (_direccion == ml_Direccion::Direccion_Horizontal)
	{
		_CambioColumna = fila % 2 == 1 ? ColumnaInvertida : !ColumnaInvertida;
	}
	else
	{
		_CambioFila = columna % 2 == 1 ? !FilaInvertida : FilaInvertida;
	}

	// Calculamos el número de columna/fila en función de si está invertida o no.
	_Columna = _CambioColumna ? _nCols - columna - 1 : columna;
	_Fila = _CambioFila ? _nRows - fila - 1 : fila;

	// Cálculo de la posición lineal del led.
	if (_direccion == ml_Direccion::Direccion_Horizontal)
	{
		resultado = _Fila * _nCols + _Columna;
	}
	else
	{
		resultado = _Columna * _nRows + _Fila;
	}
	return resultado + _offset;
}
