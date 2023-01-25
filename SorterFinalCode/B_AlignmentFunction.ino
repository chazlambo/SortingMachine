void alignFun(void){
  digitalWrite(ALIGN_LED, HIGH);
  detectVal = analogRead(IR_ALIGN);
  drive(60);
  delay(100);
  int sensorValue = analogRead(A1);
  
  while(detectVal > 100) {
    detectVal = analogRead(IR_ALIGN);
  }
  while(detectVal < detectThreshold) {
    detectVal = analogRead(IR_ALIGN);
    // Serial.println(detectVal);
    //Serial.println(analogRead(IR_ALIGN));
    delay(1);
  }
  drive(0);
  digitalWrite(ALIGN_LED, LOW);
  myEnc.write(0);
  
  ierror = 0;
  derror_raw = 0;
  derror = 0;
}
