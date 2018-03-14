/*
 * ENGR 385 Microprocessor Systems.
 * Lab 9 Interrupts.
 * 
 * The following code implements interrupts to toggle a pin.
 * In this case, when the button is pressed, the interrupt is 
 * executed and makes the led turn on and off. The buton is not
 * directly controlling the led, but instead it's the interrupt
 * service routine that is doing the work.
 * 
 * Code written by Nash Reilly (https://www.allaboutcircuits.com/technical-articles/using-interrupts-on-arduino/)
 */

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, pin_ISR, CHANGE);
}

void loop() {
  // Nothing here is needed.
}

void pin_ISR() {

  // buttonState takes the current state of the button being pressed.
  buttonState = digitalRead(buttonPin);

  // Set the led to the buttons current state.
  digitalWrite(ledPin, buttonState);
}
