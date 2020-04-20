
const int pinModo = 2;
const int ledPin = 13;

int contadorPulsacion = 0;
int estadoActual = 0;
int estadoAnterior = 0;


void setup(){
    
    pinMode(pinModo, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Arrancando programa");
}

void loop(){
    
    estadoActual = digitalRead(pinModo);
    
    if (estadoActual != estadoAnterior){
        if(estadoActual == HIGH){
            contadorPulsacion++;
        }
        else{
            Serial.println("A la espera de nueva pulsación para cambio de Modo");
        }
    }
    if (contadorPulsacion == 1){
        normalMode();    
    }
    
    else if (contadorPulsacion==2){
        sportMode();
    }
    else if (contadorPulsacion==3){
        timelapseMode();
    }
    else if (contadorPulsacion==4){
        contadorPulsacion = 1;
    }
    else{
        Serial.println("Modo: ");
    }
    delay(50);
    
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

void timelapseMode(){
    
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
        Serial.println("Se reinicia contador a 0");
    }
    else{
        Serial.println("Esperando pulsacion");
    }
}
