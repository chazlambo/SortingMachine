void testButton() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Servo Test Function:");

    while (Serial.available() == 0) {
      if (buttonRead() == 1) {
        Serial.println("BUTTON PRESSED");
      }
      else {
        Serial.println("BUTTON NOT PRESSED");
      }
    }
    if (Serial.available() > 0) {
      input = Serial.read();
      while (Serial.available() > 0) {
        Serial.read();
      }
      Serial.print("User input was: ");
      Serial.println(input);

      switch (input) {
        case 'z':
          Serial.println("Ending button test...");
          testBool = 0;
          break;


        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }

}
