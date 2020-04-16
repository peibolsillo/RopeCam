/*
  KY-002 Sensor de choque
  Definiremos la variable que vamos a usar, para registrar si detectamos vibración o no (en nuestro caso AlarmaChoque),
  y  monitorizaremos la variable de detección de choque para que encienda el LED en caso de choque mecánico

  La descripción completa del proyecto se encuentra disponible en
  http://soloarduino.blogspot.com.es/2013/12/sensor-de-choque-keyes-ky002-ky-002.html

  Este código es de uso público.
  Preparado el 3 de septiembre del 2016
  por Manuel Dominguez
*/

int Led = 13 ;// Definimos el pin de alarma visual
int Shock = 2; // Definimos el pin de deteccion de vibracion
boolean AlarmaChoque; // Definimos el nombre de la variable donde vamos a grabar las lecturas

void setup ()
{
  pinMode (Led, OUTPUT) ; // Definimos el pin de alarma visual como salida
  pinMode (Shock, INPUT) ; // Definimos el pin de detección de vibración como entrada
}
void loop ()
{
  AlarmaChoque= digitalRead (Shock) ; // Leemos el estado del pin de detección f 3 val
  if (AlarmaChoque == HIGH) // Cuando el sensor detecta una vibración entonces....
  {
    digitalWrite (Led, HIGH); // el led se enciende si no....
  }
  else
  {
    digitalWrite (Led, LOW); // el led se mantiene apagado.
  }
}
