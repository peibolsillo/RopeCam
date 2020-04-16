/*
* ROPE CAM
* Dispositivo de tirolina para camaras
*/

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

const int buttonPin = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);    // Usar una resistencia de 330 OHMS

  Serial.begin(9600);
  Serial.println("Starting...");
  
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a 1/4 of a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a 1/4 of a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a 1/4 of a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a 1/4 of a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a of a second and STOP
  
}

// the loop function runs over and over again forever
void loop() {
/*
 * Si pulsa una vez pone Modo Normal, si Pulsa otra vez, pone el Modo Sport, y si pulsa otra vez
 * pone el Modo TimeLapse y por ultimo y vuelve a pulsar vuelve al modo Normal
 * 
 *  Normal Mode     = 0
 *  Sport Mode      = 1
 *  Timelapse Mode  = 2
 *  
 */

// lee el estado del pulsador buttonPin:
  buttonState = digitalRead(buttonPin);

 // compara el buttonState con el estado previo en el que estaba
  if (buttonState != lastButtonState) {
    // Si el estado a cambiado, incrementa el contador
    if (buttonState == HIGH) {
      // Si el estado actual es HIGH entonces el boton pará de apagado a encendido:
      buttonPushCounter++;
      Serial.println("Encendido");
      Serial.print("Numero de pulsaciones: ");
      Serial.println(buttonPushCounter);
    } else {
      // Si el estado se encuentra en LOW en boton parará de encendido a apagado:
      Serial.println("off");
    }
    // Delay para prevenir el bouncing del pushbutton
    delay(50);
  }
  // guarda el estado actual como el ultimo estado, para la proxima vez en bucle
  lastButtonState = buttonState;


  /* 
   *  En estado:
   *  0 = esta en Normal Mode,  si pulsamos otra vez, se pone el contador en
   *  1 = cambia a Sportmode Mode y si pulsamos otra vez el contador para a
   *  2 = cambia a timelapse Mode y por ultimo si volvemos a pulsar, el contador pasaria a
   *  3 = que devolveria el contador a 0 y volveria a empezar.
   */
   
  // En estado: 
  
  if (buttonPushCounter == 0) {
    normalMode();
    Serial.println("Normal Mode");
  }

  else if ((buttonPushCounter == 1)) {
    sportMode();
    Serial.println("Sport Mode");
    
  }

  else if ((buttonPushCounter == 2)) {
    timelapseMode();
    Serial.println("Timelapse Mode");
  }

  else {buttonPushCounter = 0;} 
  
  
}

/*
 * AQUI DECLARO LAS DIFERENTES FUNCIONES DEL PROGRAMA PARA LUEGO IR EJECUTANDO SEGÚN CONVENGA
 */

void normalMode() {
/*
 * LED blinking Slowly for a Normal Mode
 */

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  
}

void sportMode() {
/*
 * LED blinking Rapidly for a Sport Mode
 */

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(150);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(150);                       // wait for a second
  
}

void timelapseMode() {
/*
 * LED Stay HOLD for a Time Lapse Mode
 */

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
}
