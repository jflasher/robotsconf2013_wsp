////
// Simple example to illustrate some Arduino concepts
// Will blink between two LEDs tied to different relay states
//
// Written by Joe Flasher (flasher@istrategylabs.com) based on countless examples
////

// Action strings
#define INCREASE_ACTION "inc"
#define DECREASE_ACTION "dec"

// What pin is the relay connected to
const int relayPin = 2;

// The starting delay in between blinking
int delayTime = 2000;
// The time to increase or decrease the delay time based on an input
const int delayIncrement = 200;

// The setup loop, will run just once when the program starts
void setup() {
  // For serial input/output
  Serial.begin(9600);
  
  // Set the relay pin to be an output rather than expecting input
  pinMode(relayPin, OUTPUT);
}

// The program loop, will run over and over again, FOREVER!
void loop() {
  // If there is anything in the serial buffer, read it in and handle the action
  if (Serial.available() > 0) {
    String s = Serial.readString();
    changeTiming(s);
  }  
  
  // Set pin state one way
  setPinState(HIGH);
  
  // Pause for the delay time period
  delay(delayTime);
  
  // And flip the state
  setPinState(LOW);
  
  // And pause again
  delay(delayTime);
} 

// Set the pin state
void setPinState(int state) {
  digitalWrite(relayPin, state);
  Serial.print("Setting relay state to: ");
  Serial.println(state);
}

// Increase or decrease the delay timing
void changeTiming(String action) {
  if (action == INCREASE_ACTION) {
    delayTime += delayIncrement;
    Serial.print("Increasing delay time to ");
    Serial.println(delayTime);
  } else if (action == DECREASE_ACTION) {
    delayTime -= delayIncrement;
    Serial.print("Decreasing delay time to ");
    Serial.println(delayTime);    
  } else {
    Serial.println("Uh oh, unknown action!");
  }
}
