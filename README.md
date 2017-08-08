# TouchMeNot

 * TouchMeNot is a robotic arm coupled to a piezo vibration sensor 
 * which signals every tap event with an LED blink.
 
 * v2.0 uses a solenoid to tie the tap whereas v3.0 is actually a downgraded version which you can
 * without a vibration sensor by manually entering a delay (dafualt is 1ms). v3.0 is recommended for
 * consistent stimulus timing beween trials if you if you don't have a good reliable vibration sensor.
 * 
 * This solenoid taps for 'rep' times with an inter stimulus interval of 'isi' milliseconds. 
 * The piezo sensor reports every tap with an LED blink. 
 * These three parameters can be changed from the highlighted 'SET PARAMETERS HERE' box.
 * 
 * WIRING THE CIRCUIT:
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
 * Piezo (positive) to analog A1 pin and negative to common ground.
 * A 220ohm (depends on your sensor) resistor connected from A1 to ground in parallel with the PEIZO.
 * Sensor LED on pin 2 and grounded to the common ground.
 * (troubleshooting tip: use serial print to monitor sensor vals)
 * 
 * Thanks to the open-source arduino community. This project builds on open source arduino tutorials.
 * 
 * More info: Gokul Rajan (gklrajan@gmaildotcom), DEL-BENE Lab, Paris; 22-07-2017
 * updated on 31_07_2017
 * Last updated on 05_07_2017
