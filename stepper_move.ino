/*  Modo Normal
 *      
 *  velocidad max de 0 - 1,2 m/s
 *  1 vuelta 200 pasos / step
 */
 
// Defines pins numbers
const byte stepPin = 3;
const byte dirPin = 4;

const byte joystick = A0;
const byte buttonSet = 5;

const byte buttonPlay = 2;
const byte FCder = 7;
const byte FCizq = 8;
const byte ledPinMode = 13;


const byte ledVel1 = 9;
const byte ledVel2 = 10;
const byte ledVel3 = 11;
const byte ledVel4 = 12;

boolean buttonSetState = HIGH;
boolean ledState = LOW;
boolean ledVelState = LOW;
const long normalInterval = 1000;
const long ledVelInterval = 500;
unsigned long previousMillis = 0;

 
void setup() {
  // Establecer los 2 dos pines de salida
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  
  pinMode(buttonSet,INPUT);
  pinMode(buttonPlay,INPUT);
  pinMode(FCder,INPUT);
  pinMode(FCizq,INPUT);
 
}
void loop() {
    
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= normalInterval){
    previuosMillis = currentMillis;

    if (ledState == LOW){
    ledState = HIGH;
    }else{
    ledState = LOW;
    }
    digitalWrite(ledPinMode, ledState);
    }
    
  int valJoy = analogRead(joystick);
  byte mapJoyD = (valJoy, 0, 1023, 0, 255);
  byte mapJoy = (valJoy, 0, 1023, 100, 1800);
  byte mapJoystick = (valJoy, 0, 1023, 1, 12);
  
  mapJoyD >>= 1;
  if(mapJoyD > 255){
      switch(mapJoystick){
          case 1:
          digitalWrite(ledVel1, LOW);
          delay(250);
          digitalWrite(ledVel1,HIGH);
          delay(250);
          digitalWrite(ledVel2, LOW);
          digitalWrite(ledVel3, LOW);
          break;
          case 2:
          digitalWrite(ledVel1, HIGH);
          digitalWrite(ledVel2, LOW);
          digitalWrite(ledVel3, LOW);
          break;
          case 3:
          digitalWrite(ledVel1, HIGH);
          digitalWrite(ledVel2, LOW);
          delay(250);
          digitalWrite(ledVel2,HIGH);
          delay(250);h
          digitalWrite(ledVel3, LOW);
          break;
          case 4:
          digitalWrite(ledVel1, HIGH);
          digitalWrite(ledVel2, HIGH);
          digitalWrite(ledVel3, LOW);
          break;
          
          }
      }
      
    digitalWrite(dirPin, HIGH);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(mapJoy - 4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(mapJoy - 4000);
    
    }
  else if(mapJoyD < 256){
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000 - mapJoy);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000 - mapJoy);
    }
  else{
    digitalWrite(stepPin, 0);
    digitalWrite(stepPin, 0);
    Serial.print("- Stop -");
    }
}

