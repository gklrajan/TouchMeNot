/*
 * This version of the TouchMeNot can be triggered from an external software> 
 * For instance, in the following code the arduino waits for a serial command 
 * which is sent to the serial port based on the position of the animal tracked from a online 
 * tracking software.
 * 
 * In principle, you can use any trigger to control the arduino in the external word - this can a simple button
 * on your GUI or an output of a complicated analysis that you run from withuin a program to decide when to trigger the arduino.
 * 
 * Have fun!
*/

/////////////////////////////////////////////////////////////
//SET PARAMETERS HERE//
int rep = 8; // number of repetitions of the stimulus (tap)
int isi1 = 24000; // inter-stimulus interval in milliseconds "30 secs" (24sec isi1 +5sec LEDdelay + 1sec loop delay)
//int isi2 = 30000;
int LEDdelay = 5000;
//const int threshold = 10; // threshold value determines at 
            // what detected vibration should the LED light
/////////////////////////////////////////////////////////////


// solenoid
int solenoidPin = 7;

//peizo init
const int sensorLED = 2; // LED connected to digital pin
//const int knockSensor = A1; // the piezo connected to A1

//to store sensor values
//int sensorValBefore = 0; // variable to store the value read from the sensor pin
//int sensorValAfter = 0;
//int sensorValDuring = 0;

  int incomingByte = 0;

void setup() {

  pinMode(solenoidPin, OUTPUT); //sets solenoid pin as an output pin
  pinMode(sensorLED, OUTPUT); // sets the sensorLED pin as as output pin
//  pinMode(knockSensor, INPUT); //sets the piezo sensor pin as an input pin
  Serial.begin(9600); // use the serial port
}

void loop() 
{
  
  //delay(30000);
  
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte == 48)
    {

  digitalWrite(solenoidPin, HIGH); //Solenoid ON
  delay(1000);
  
  digitalWrite(solenoidPin, LOW); //Solenoid OFF
  delayMicroseconds(1000);

  digitalWrite(sensorLED, HIGH);

  delay(LEDdelay); // a 5sec delay before switching off the LED again
  digitalWrite(sensorLED, LOW);


  //delay(30000);
  //delay(30000);

      
    }
  }
}
