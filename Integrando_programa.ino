






/* 

Codigo de control del Sensor de Impacto

*/

void sensorImpacto(){
  
  AlarmaChoque= digitalRead (shockSensor) ; // Leemos el estado del pin de detección f 3 val
  if (AlarmaChoque == HIGH)                 // Cuando el sensor detecta una vibración entonces....
  {
    digitalWrite(dirA, 0);                  // desconectamos direccion A L
    digitalWrite(dirB, 0);                  // desconectamos direccion A L
  }
}