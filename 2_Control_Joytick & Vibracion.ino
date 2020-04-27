

#define joystick  A0            //Eje X del Joystick
const int mode_SW = 2;          //Pulsador del Joystick

#define finCa_1   4             //Pulsadore de Pin de Carrera digital 1
#define finCa_2   5             //Pulsadore de Pin de Carrera digital 2

int shockSensor = 7;            //SafeStop en caso de choque, parar motor

#define dirA  9                 //Pin del Controlador L293D direccion A 
#define dirB  10                //Pin del Controlador L293D direccion A  

bool val1 = true ;              //Para configurar los pulsadores actuen como interruptores "finCa_1"
bool val2 = true ;              //Para configurar los pulsadores actuen como interruptores "finCa_2"
bool estado_anterior = true ;   //Variable control cambio de estado de los pulsadores

int  value = 0;                 //variable para control del estado del Joystick



void setup() {
  // put your setup code here, to run once:
  
 
  pinMode(finCa_1, INPUT_PULLUP);
  pinMode(finCa_2, INPUT_PULLUP);
  
  pinMode (shockSensor, INPUT) ;
  
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("RopeCam arrancando");
  Serial.println("---------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Esperando una respuesta");
  Serial.print(".");
  Serial.print(".");
  Serial.print(".");
  Serial.print(".");
  
}

/* 

Codigo de control del Joystick

*/
         
void joy_sportMode(){
  
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
    
}


/* 

Codigo de control del Sensor de Vibración

*/

boolean alarmaChoque = digitalRead(shockSensor);           // Definimos el nombre de la variable donde vamos a grabar las lecturas


while (alarmaChoque){
                						    // Cuando el sensor detecta una vibración entonces.	
    digitalWrite(dirA, 0);                  // desconectamos direccion A L
    digitalWrite(dirB, 0);                  // desconectamos direccion A L
    
    alarmaChoque = digitalRead (shockSensor);
    
  }

void loop() {
  // put your main code here, to run repeatedly:
    
    sensorVibracion();                                 //Si el dispositivo detecta una vibración, para el motor
    joy_sportMode();                                   //declaro la funcion para el control del Jostick en SportMode

/* 

Control pulsador para movimiento hacia finCa_2 con botones

*/
    
    bool  val1 =  digitalRead(finCa_2) ;     //leemos el botón: false  =  LOW
    bool  val2 =  digitalRead(finCa_1) ;       //leemos el botón: false  =  LOW

        if ( val1 != estado_anterior )      //hay cambio : Han pulsado o soltado
        {      
        val1 != estado_anterior ;                 // cambiamos el estado
            if(val1 == LOW)
            analogWrite(dirA, 60);
            digitalWrite(dirB, LOW);
            Serial.println("Going Forward");
            delay(250);
        }
        else if ( val2 != estado_anterior)
        {
        val2 != estado_anterior;
        {
            if(val2 == LOW)
            digitalWrite(dirA, LOW);
            analogWrite(dirB, 60);
            Serial.println("Going Reverse");
            delay(250);
            
        } 
        } 
            else{
            digitalWrite(dirA, LOW);
            digitalWrite(dirB, LOW); 
            Serial.println("Stopped");     
        }


}
