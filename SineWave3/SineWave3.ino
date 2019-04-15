#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
//uint8_t servonum = 11;

void setup() {
  Serial.begin(9600);
  
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  
  float theta = millis () * 0.001 ;

// Drive servo 11 at sin wave equivalent
  int val = 90 + 70 * sin (theta);

  val = map(val, 0, 180, SERVOMIN, SERVOMAX);
  
  pwm.setPWM(11, 0, val);

// Drive servo 12 with off sin wave
  int val2 = 90 + 70 * sin (theta+1);

  val2 = map(val2, 0, 180, SERVOMIN, SERVOMAX);
  
  pwm.setPWM(12, 0, val2);

// Drive servo 13 with off sin wave
  int val3 = 90 + 70 * sin (theta+2);

  val3 = map(val3, 0, 180, SERVOMIN, SERVOMAX);
  
  pwm.setPWM(13, 0, val3);


  // Drive servo 14 with off sin wave
  int val4 = 90 + 70 * sin (theta+3);

  val4 = map(val4, 0, 180, SERVOMIN, SERVOMAX);
  
  pwm.setPWM(14, 0, val4);



  // Drive servo 15 with off sin wave
  int val5 = 90 + 70 * sin (theta+4);

  val5 = map(val5, 0, 180, SERVOMIN, SERVOMAX);
  
  pwm.setPWM(15, 0, val5);
  
  
}
