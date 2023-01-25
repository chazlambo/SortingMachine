void testMotorOpenLoop(void) {
  testBool = 1;
  char input;
  int inpVal;
  Serial.println("Open Loop Motor Test: ");
  Serial.println("Enter any number from -255 to 255 to write to motor.");
  Serial.println("Enter 'z' to end test.");
  while (testBool) {
    t_ms = micros();
    t = t_ms / 1000000.0;
    if (t > t_old_enc + T_enc) {
      updateEncoder();

      if (oled_setup) {
        openLoopDisplay();
      }
      else {
        // Print to Serial Monitor
        Serial.print(t, 5); Serial.print(",\t"); Serial.print(counts);
        Serial.print("\t Spd: "); Serial.print(mSpdCmd);
        Serial.print("\t Pos: "); Serial.print(motorPos);
        Serial.print("\t Vel: "); Serial.println(motorVel                                                                          );
      }
    }

    if (t > t_old_mot + T_mot) {
      // Check for valid serial byte
      if (Serial.available() > 0) {
        if (isAlpha(Serial.peek())) {
          input = Serial.read();
          while (Serial.available() > 0) {
            Serial.read();
          }
          Serial.print("User input was: ");
          Serial.println(input);
          switch (input) {
            case 'z':
              Serial.println("Ending open loop motor test...");
              testBool = 0;
              mSpdCmd = 0;
              drive(mSpdCmd);
              break;
            default:
              Serial.println("Invalid Input.");
              break;
          }
        }
        else {
          inpVal = Serial.parseInt();
          if (inpVal > 255) {
            inpVal = 255;
          }
          else if (inpVal < -255) {
            inpVal = -255;
          }
          Serial.print("Setting motor to: ");
          Serial.println(inpVal);

          mSpdCmd = inpVal;
          drive(mSpdCmd);
        }
      }
      t_old_mot = t;
    }
  }
}
