void testServos() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Servo Test Function:");
    Serial.println("c - Contaminate position");
    Serial.println("s - Sorted position");
    Serial.println("p - Pass-on position");
    Serial.println("z - Back to menu\n\n");

    while (Serial.available() == 0) {}
    if (Serial.available() > 0) {
      input = Serial.read();
      while (Serial.available() > 0) {
        Serial.read();
      }
      Serial.print("User input was: ");
      Serial.println(input);

      switch (input) {
        case 'c':
          if (oled_setup) {
            servoDisplayUpdate(1);
          }
          else {
            Serial.println("Setting servos to contaminate position.");
          }
          servoContam();
          break;

        case 's':
          if (oled_setup) {
            servoDisplayUpdate(2);
          }
          else {
            Serial.println("Setting servos to sorted position.");
          }
          servoSort();
          break;
        case 'p':
          if (oled_setup) {
            servoDisplayUpdate(3);
          }
          else {
            Serial.println("Setting servos to pass-on position.");
          }

          servoPass();
          break;
        case 'z':
          Serial.println("Ending servo test...");
          testBool = 0;
          break;
        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }
}
