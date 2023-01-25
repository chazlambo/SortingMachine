void testStatusLED() {
  testBool = 1;
  char input;
  while (testBool) {
    Serial.println("Servo Test Function:");
    Serial.println("p - Pause light");
    Serial.println("r - Ready light");
    Serial.println("s - Sorting light");
    Serial.println("e - Estop check");
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
        case 'p':
          pauseLED();
          break;

        case 'r':
          readyLED();
          break;

        case 's':
          sortingLED();
          break;

        case 'e':
          if (digitalRead(ESTOP) == HIGH) {
            digitalWrite(STATUS_RED, LOW);
            digitalWrite(STATUS_GREEN, HIGH);
            digitalWrite(STATUS_BLUE, LOW);
          }
          else {
            digitalWrite(STATUS_RED, HIGH);
            digitalWrite(STATUS_GREEN, LOW);
            digitalWrite(STATUS_BLUE, LOW);
          }
          break;

        case 'z':
          Serial.println("Ending Status LED test...");
          testBool = 0;
          break;
          
        default:
          Serial.println("Invalid Input.");
          break;
      }
    }
  }

  digitalWrite(STATUS_RED, LOW);
  digitalWrite(STATUS_GREEN, LOW);
  digitalWrite(STATUS_BLUE, LOW);
}
