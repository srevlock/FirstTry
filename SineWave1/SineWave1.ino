
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  
  float theta = millis () * 0.001 ;

  int val = 90 + 70 * sin (theta);
  Serial.print("servo angle =") ;
  Serial.print(val) ;
  val = map(val, 0, 180, SERVOMIN, SERVOMAX);
  Serial.print("  servo step =") ;
  Serial.println(val) ;
  
  int val2 = 90 + 70 * sin (theta+2);
  Serial.print("servo2 angle =") ;
  Serial.print(val2) ;
  val2 = map(val2, 0, 180, SERVOMIN, SERVOMAX);
  Serial.print("  servo step =") ;
  Serial.println(val) ;
  
  
  //pwm.setPWM(servonum, 0, val);
   /*
  Serial.print("servo angle =") ;   
  Serial.print(90 + 70 * sin (theta)); 
  Serial.print("    servo2 angle =") ;   
  Serial.print(90 + 70 * sin (theta+2));
  Serial.print("    servo3 angle =") ;   
  Serial.print(90 + 70 * sin (theta+4));
  Serial.print("    servo4 angle =") ;   
  Serial.print(90 + 70 * sin (theta+6));  
  Serial.print("    servo5 angle =") ;
  Serial.println(90 + 70 * sin (theta+8));
  */
  
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
