/*
* ROPE CAM
* Dispositivo de tirolina para camaras
*/

const int joystick = A0;        //Eje X del Joystick        
const int pinModo = 2;			//Pulsador del Joystick
const int ledPin = 13;

const int shockSensor = 7;      //SafeStop en caso de choque, para motor

int contadorPulsacion = 0;
int estadoActual = 0;
int estadoAnterior = 0;

int  value = 0;                 //variable para control del estado del Joystick

boolean AlarmaChoque;           // Definimos el nombre de la variable donde vamos a grabar las lecturas


#define dirA  9                 //Pin del Controlador L293D direccion A 
#define dirB  10                //Pin del Controlador L293D direccion A  

void setup(){
    
    pinMode(pinModo, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    
    pinMode(dirA, OUTPUT);
    pinMode(dirB, OUTPUT); 
       
    
    Serial.begin(9600);
    Serial.println("Arrancando programa");
    
}

void loop(){
    
    estadoActual = digitalRead(pinModo);
    
    if (estadoActual != estadoAnterior){
        if(estadoAhora == HIGH){
            contadorPulsacion++;
        }
        else{
            Serial.println("No se ha detectado Pulsacion");
        }
        
    if (contadorPulsacion == 0){
        normalMode();    
    }
    
    else if (contadorPulsacion==1){
        sportMode();
    }
    else if (contadorPulsacion==2){
        timelapseMode();
    }
    else if (contaorPulsacion==3){
        contadorPusacion=0;
    }
    else{Serial.println("Modo: ");
    }
    
    estadoAnterior = estadoActual;
    
    
}

void normalMode(){
    
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        delay(1000);
        
        Serial.println("Normal Mode");
}

/* 

Codigo de control del Joystick en modo Sport / libre

*/

void sportMode(){
    
  value = analogRead(joystick);   
  value >>= 1;                    //Sinceramente esta declaracion no se porque la hace :( !!!!
  
  if(value > 255){
    digitalWrite(dirB, 0);
    analogWrite(dirA, (value - 256));
    Serial.print("Se mueve hacia finCa_2: ");
    Serial.print( (value - 256) );
    Serial.print("\n");
    }
  else if(value < 255){
    digitalWrite(dirA, 0);
    analogWrite(dirB,(255 - value));
    Serial.print("Se mueve hacia atrás: ");
    Serial.print( (255 - value) );
    Serial.print("\n");
    }
  else{
    digitalWrite(dirA, 0);
    digitalWrite(dirB, 0);
    Serial.print("- Stop -");
    }

        digitalWrite(ledPin, HIGH);
        delay(250);
        digitalWrite(ledPin, LOW);
        delay(250);
        Serial.println("Sport Mode");
}

void timeLapseMode(){
    
        digitalWrite(ledPin, HIGH);
        Serial.println("Timelapse Mode");
}


/* 

Codigo de control del Sensor de Vibración

*/

void sensorVibracion(){
  
  AlarmaChoque = digitalRead (shockSensor) ; // Leemos el estado del pin de detección f 3 val
  if (AlarmaChoque == HIGH)                 // Cuando el sensor detecta una vibración entonces....
  {
    digitalWrite(dirA, 0);                  // desconectamos direccion A L
    digitalWrite(dirB, 0);                  // desconectamos direccion A L
  }
}

