void rotate(void) {
  motorPos_des = PI / 3;
  double time_iter = 0;
  error_old = 100;

  while (Serial.available() != 0) {
    Serial.read();
  }

  

  t_ms = micros();
  t = t_ms / 1000000.0;
  t_old_mot = t;
  t_old_scan = t;

  while (Serial.available() == 0) {
    t_ms = micros();
    t = t_ms / 1000000.0;
    

    if (t > t_old_enc + T_enc) {
      updateEncoder();
    }

    if (t > t_old_mot + T_mot) {
      pidMotor();
    }





    if (abs(error) < 0.02 && t > t_old_scan + T_scan) {
      Serial.println("\n IN POSITION, STARTING SCAN");
      drive(0);
      motorPos_des += (PI / 3);
      time_iter = t;

      ierror = 0;
      derror_raw = 0;
      derror = 0;

      delay(2000);
    }

  }
  drive(0);
}
