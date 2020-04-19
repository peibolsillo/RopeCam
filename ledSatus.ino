
const int pinModo = 2;
cont int ledPin = 13;

int contadorPulsacion = 0;
int estadoActual = 0;
int estadoAnterior = 0;
 
unsigned long duration;


void setup();{
    
    
const int pinModo = 2;
cont int ledPin = 13;

int contadorPulsacion = 0;
int estadoAhora = 0;
int estadoAnterior = 0;
 
unsigned long duration;


void setup(){
    
    pinMode(pinModo, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
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
    else{
        Serial.println("Modo: ");
    }
            
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

void sportMode(){
    
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

void resetCount(){
    if (contadorPulsacion == 4){
        contadorPulsacion = 0;
        digitalWrite(ledPin, LOW);
        delay(100);
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
        Serial.println("Loop Menu");
        Serial.Println("Se reinicia contador a 0");
    }
    else{
        Serial.println("Esperando pulsacion");
    }
}
pinMode(pinModo, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Arrancando programa");
    
}

void loop();{
    
    estadoActual = digitalRead(pinModo);
    
    if (estadoActual != estadoAnterior){
        if(estadoAhora == HIGH){
            contadorPulsacion++;
        }
        else{
            Serial.println("No se ha detectado Pulsacion");
        }
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
    else{
        Serial.println("Modo: ");
    }
            
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

void sportMode(){
    
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

void resetCount(){
    if (contadorPulsacion == 4){
        contadorPulsacion = 0;
        digitalWrite(ledPin, LOW);
        delay(100);
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
        Serial.println("Loop Menu");
        Serial.Println("Se reinicia contador a 0");
    }
    else{
        Serial.println("Esperando pulsacion");
    }
}

