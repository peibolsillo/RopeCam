/*
  Rope Cam - Disposivo de tirolina asistido para camaras y dipositivos

  El programa realizara diferentes acciones con motor, un potenciometro (Rottary), 4 pulsadores, 1 LED, 1 Sensor de vibracion LED, etc

  En el modo normal, el indicador de modo parpadeará lentamente. En este modo se puede controlar la velocidad de
  ROPECAM de 0 a 1,2 m/s (0 - 3,9 fps) girando la rueda de velocidad.

    1. Al mover la Joystick de velocidad en el sentido de las agujas del reloj (hacia la flecha amarilla) hará que 
       el dispositivo principal se mueva hacia el lado del dispositivo RopeCam con las marcas de dirección amarillas.

    2. Cuando se suelte la rueda de velocidad, la unidad se detendrá.

  En el modo normal, Ropecam se puede configurar para que se mueva automáticamente entre los finales de carrera digitales.
  Compruebe los siguientes pasos para ver cómo:

    1. Hay que asegurarse que las paradas digitales (finales de carrera) están configuradas en ambos lados.

    2. Controla la velocidad con Joystick como siempre. Cuando alcance la velocidad deseada, pulse
       el botón Play/Pause para iniciar el ping-pong Motion entre los finales de carrera digitales.

    3. Pulse el botón Play/Pause una vez más para detener el movimiento del Ping-Pong.

  Entra en el modo Sport haciendo clic en el botón de modo una vez después de encender el mando a distancia. Cuando 
  la luz de modo indicador comienza a parpadear más rápido, sabes que está en el modo Sport. En este modo se puede 
  controlar la velocidad de ROPECAM de 0 a 9,5 m / s (0 - 31 fps) girando la rueda de velocidad.

    1. Al mover el Joystick en el sentido que se desee (hacia una de las flechas amarilla) hará que el 
       dispositivo se mueva hacia el lado donde tiene marcas de dirección amarillas.

    2. Cuando se suelte el Joystick, la unidad se detendrá.

 En el modo de lapso de tiempo (Timelapse), el indicador de modo (LED) se enciende continuamente. En este modo se puede 
 controlar la aceleración de ROPECAM moviento el Joystick hacia direccion de la flecha.

    1. En el modo de timelapse, el indicador de modo se enciende continuamente. En este modo se puede controlar 
       la aceleración de ROPECAM moviendo el Joystick hacia la derecha (flecha amarilla). 

    2. Al soltar el Joystick, el dispositivo continuará a la misma velocidad.

    3. Detenga el dispositivo pulsando el botón de Play/Pause del mando a distancia. La velocidad se puede ajustar
       tanto en estado de pausa y en movimiento y las luces de indicación de velocidad mostrarán la velocidad 
       establecida actualmente.

    4. Al pulsar el botón de Play/Pause de nuevo nuevo en el dispositivo comenzará a moverse en la velocidad establecida. 
       Vea los diferentes niveles de velocidad a continuación.

                                                            LED       LED       LED
        TIMELAPSE SPEED LEVEL 1 =  6.6 metros por hora  -  Blink      Off       Off
        TIMELAPSE SPEED LEVEL 2 = 12.4 metros por hora  -   Lit       Off       Off
        TIMELAPSE SPEED LEVEL 3 = 20.0 metros por hora  -   Lit      Blink      Off
        TIMELAPSE SPEED LEVEL 4 = 25.8 metros por hora  -   Lit       Lit       Off
        TIMELAPSE SPEED LEVEL 5 = 32.8 metros por hora  -   Lit       Lit      Blink
        TIMELAPSE SPEED LEVEL 6 = 40.0 metros por hora  -   Lit       Lit       Lit
       

    5. Para restablecer la velocidad por completo, haga clic dos veces en el botón de Play/Pause.       

* El mando a distancia establece automáticamente en modo normal cuando se enciende. Cambiar modos pulsando el 
  botón de modo.

* Normal Mode: El LED indicador del modo parpadea lentamente.
* Sport Mode: El LED indicador del modo parpadea rapidamente.
* Time Lapse Mode: El LED indicador del modo se mantiene encendido continuamente.


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
