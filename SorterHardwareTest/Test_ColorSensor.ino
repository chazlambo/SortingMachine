void testColorSensor() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Color Sensor Test Function:");
    Serial.println("r - Rotate Plate");
    Serial.println("s - Scan Color");

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
          colorScan();
          colorDisplay(parseColor());
          break;

        case 'r':
          alignFun();
          break;

        case 'z':
        Serial.println("Ending color sensor test...");
          testBool = 0;
          break;

          
        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }
  
}
