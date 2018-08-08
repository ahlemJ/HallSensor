const byte ledPin = 3;
const byte interruptPin = 2;
volatile byte state = LOW;
long int i=0;
int ledState = 0;         // current state of the LED
int lastLedState = 0;     // previous state of the LED
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
Serial.begin(115200);
}

void loop() {


ledState= digitalRead(interruptPin );  
digitalWrite(ledPin, ledState);    //Change the state of the Led is there is a magnet 
 // compare the LedState to its previous state
if(ledState != lastLedState && ledState!=0) {    // if the current state is HIGH then increment the counter
  i=i+1; Serial.println(i);
  }
delay (50);  // Delay a little bit to avoid bouncing
lastLedState=ledState ;

}

void test() {

}
