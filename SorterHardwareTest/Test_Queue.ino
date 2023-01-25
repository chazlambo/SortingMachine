void testQueue() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Queue Test Function:");
    Serial.println("Select Mode:");
    Serial.println("r - Raw values");
    Serial.println("n - Number of M&Ms");
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
        case 'r':
          while (Serial.available() == 0) {
            readQueue();
            for (uint8_t i = 0; i < sensorCount; i++)
            {
              Serial.print(sensorValues[i]);
              Serial.print('\t');
            }
            Serial.println();
            delay(100);
          }
          break;


        case 'n':
          while (Serial.available() == 0) {
            readQueue();
            Serial.print("Number of M&M's: ");
            Serial.println(numMM);
            delay(100);
          }
          break;

        case 'z':
          Serial.println("Ending Queue test...");
          testBool = 0;
          break;
        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }
}
