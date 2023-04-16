#include <Arduino.h>
#include <MatrizLed.h>

#define NUEMROCOLUMAS 4
#define NUMEROFILAS 4

void dibujaMatriz();

MatrizLed miMatriz;
char dato[6];

void setup()
{
  Serial.begin(115200);
  
  Serial.println(F("Posición led = Superior izquierda, desplazamiento horizontal."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Superior_Izquierda, ml_Direccion::Direccion_Horizontal);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Superior izquierda, desplazamiento vertical."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Superior_Izquierda, ml_Direccion::Direccion_Vertical);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Superior derecha, desplazamiento horizontal."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Superior_Derecha, ml_Direccion::Direccion_Horizontal);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Superior derecha, desplazamiento vertical."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Superior_Derecha, ml_Direccion::Direccion_Vertical);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Inferior izquierda, desplazamiento horizontal."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Inferior_Izquierda, ml_Direccion::Direccion_Horizontal);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Inferior izquierda, desplazamiento vertical."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Inferior_Izquierda, ml_Direccion::Direccion_Vertical);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Inferior derecha, desplazamiento horizontal."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Inferior_Derecha, ml_Direccion::Direccion_Horizontal);
  dibujaMatriz();
  Serial.println();
  Serial.println();
  delay(200);

  Serial.println(F("Posición led = Inferior derecha, desplazamiento vertical."));
  // Definimos la posición de la matriz y su tamaño.
  miMatriz.begin(NUEMROCOLUMAS, NUMEROFILAS, ml_Inicio::Inicio_Inferior_Derecha, ml_Direccion::Direccion_Vertical);
  dibujaMatriz();
  Serial.println();
  Serial.println();

}

void loop()
{
 
}

void dibujaMatriz()
{

  // Para que en el monitor se vea en el mismo orden que los leds estan en la placa
  // tenemos que recorrer la matriz de arriba abajo y de izquierda a derecha;
  for (int fil = (NUMEROFILAS - 1); fil >= 0; fil--)
  {
    for (int Col = 0; Col < NUEMROCOLUMAS; Col++)
    {
      sprintf(dato, " %3u,", miMatriz.posicion(Col, fil));
      Serial.print(dato);
    }
    Serial.println();
  }
}