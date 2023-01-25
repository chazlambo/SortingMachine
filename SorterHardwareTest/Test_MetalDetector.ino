void testMetalDetector() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Hall Effect Sensor Test Function:");
    Serial.println("s - Detect Metal");
    Serial.println("r - Rotate");
    Serial.println("z - End Test");

    while (Serial.available() == 0) {}
    if (Serial.available() > 0) {
      input = Serial.read();
      while (Serial.available() > 0) {
        Serial.read();
      }
      Serial.print("User input was: ");
      Serial.println(input);

      switch (input) {
        case 's':
          if (metalDetect() == 1) {
            Serial.println("\n METAL DETECTED \n");
          }
          else {
            Serial.println("\n METAL NOT DETECTED \n");
          }
          break;

        case 'r':
          alignFun();
          break;

        case 'z':
          Serial.println("Metal detection test...");
          testBool = 0;
          break;


        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }

}
