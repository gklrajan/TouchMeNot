/*
 * TouchMeNot_v2.0 is a solenoid actuator coupled to a piezo vibration sensor 
 * which signals a tap event with an LED blink.
 * 
 * This solenoid taps for 'rep' times with an inter stimulus interval of 'isi' milliseconds. 
 * The piezo sensor reports every tap which exceeds the pre-set 'threshhold' value by an LED blink. 
 * These three parameters can be changed from the highlighted 'SET PARAMETERS HERE' box.
 * 
 * WWIRING THE CIRCUIT:
 * POWER externally as your solenoid most likely requires more power than 
 * what the arduino can supply (I use 9V+9V batterires in series for a 12V solenoid).
 * 
 * SOLENOID positive to battery positive and negative to Collector leg of transistor. 
 * A DIODE across the solenoid to prevent damage from reverse current.
 * 
 * TRANSISTOR is an extra muscles to our nerdy arduino. I use TIP120 here.
 * (ID tip: when front-side (labelled block) is facing you - L to R : B;C,E legs)
 * 
 * Base leg to a 1K ohm resistor and the other end of the resistor to pin7-- our control pin.
 * The Collector leg to the ground leg of the solenoid.
 * The Emitter leg to the common ground of our circuit.
 * 
 * Piezo(positive) to analog A1 pin and negative to common ground.
 * A 220 ohm resistor (depends on your piezo sensor) connected from A1 to ground in parallel with the PEIZO.
 * Sensor LED on pin 2 and grounded to the common ground.
 * (troubleshooting tip: use serial print to monitor sensor vals and troubleshoot)
 * 
 * Thanks to the open-source arduino community. This project builds on open source arduino tutorials.
 * 
 * More info: Gokul Rajan (gklrajan@gmaildotcom), DEL-BENE Lab, Paris; 22-07-2017
 * updated on 31_07_2017
 * Last updated on 08_07_2017
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

void setup() {

  pinMode(solenoidPin, OUTPUT); //sets solenoid pin as an output pin
  pinMode(sensorLED, OUTPUT); // sets the sensorLED pin as as output pin
//  pinMode(knockSensor, INPUT); //sets the piezo sensor pin as an input pin
//  Serial.begin(9600); // use the serial port
}

void loop() 
{
  
  delay(30000);
  
  for (int i=1; i<=rep ; i++) 
  {
    
  //sensorValBefore = analogRead(knockSensor);  //keep reading the sensor value until 
                        //it is above the set threshold (every tap event)
  
  //Serial.print("Before: "); // print sensor value in serial monitor                   
  //Serial.println(sensorValBefore); // print sensor value in serial monitor
  //delay(500);  
  
  digitalWrite(solenoidPin, HIGH); //Solenoid ON
  delay(1000);
  
  //sensorValDuring = analogRead(knockSensor);  //keep reading the sensor value until 
                        //it is above the set threshold (every tap event)
  //Serial.print("During: "); // print sensor value in serial monitor                   
  //Serial.println(sensorValDuring); // print sensor value in serial monitor
  
  digitalWrite(solenoidPin, LOW); //Solenoid OFF
  delayMicroseconds(1000);

  digitalWrite(sensorLED, HIGH);

  //Serial.print("After: "); // print sensor value in serial monitor                                        
  //Serial.println(sensorValAfter); // print sensor value in serial monitor

  delay(LEDdelay); // a 5sec delay before switching off the LED again
  digitalWrite(sensorLED, LOW);

  delay(isi1);
  //delay(isi2);
  
  }

  delay(30000);
  delay(30000);
  delay(30000);
  delay(30000);

}
