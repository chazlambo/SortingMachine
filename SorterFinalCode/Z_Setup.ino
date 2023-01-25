void setupFun(void) {
  // Setup function to initialize all tab specific variables and user-defined functions
  Serial.begin(9600);
  while (!Serial){}
  systemSetup();
  motorSetup();
  oledSetup();
  servoSetup();
  colorSetup();
  IRSetup();
  queueSetup();
  HESetup();
  buttonSetup();
}
