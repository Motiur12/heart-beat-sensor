#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;
int val;
int tempPin = 1;

PulseSensorPlayground pulseSensor;


void setup() {
 Serial.begin(9600);

 pulseSensor.analogInput(PulseWire);
 pulseSensor.blinkOnPulse(LED13);
 pulseSensor.setThreshold(Threshold);

 if (pulseSensor.begin()) {
  }

}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();
  val = analogRead(tempPin);
  float mv = (val/1024.0)*5000;
  float cel = mv/10;


  if(pulseSensor.sawStartOfBeat()){

    Serial.println(myBPM);
    Serial.print(cel);
    Serial.println();
  }
    delay(20);
  

}
