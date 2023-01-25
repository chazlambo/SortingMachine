void setupFun(void) {
  // Start Serial Communication
  Serial.begin(9600);
  while (!Serial) { // Wait for available Serial
  }

  // Run setup for hardware components
  systemSetup();
  if (system_setup) {
    Serial.println("System Setup Complete.");
  }
  else {
    Serial.println("System Setup Failed.");
  }
  motorSetup();
  if (motor_setup) {
    Serial.println("Motor Setup Complete.");
  }
  else {
    Serial.println("Motor Setup Failed.");
  }

  oledSetup();
  if (oled_setup) {
    Serial.println("OLED Setup Complete.");
  }
  else {
    Serial.println("OLED Setup Failed.");
  }

  servoSetup();
  if (servo_setup) {
    Serial.println("Servo Setup Complete.");
  }
  else {
    Serial.println("Servo Setup Failed.");
  }

  colorSetup();
  if (color_setup) {
    Serial.println("Color Setup Complete.");
  }
  else {
    Serial.println("Color Setup Failed.");
  }

  IRSetup();
  if (ir_setup) {
    Serial.println("IR Setup Complete.");
  }
  else {
    Serial.println("IR Setup Failed.");
  }

  queueSetup();
  if (ir_setup) {
    Serial.println("Queue Setup Complete.");
  }
  else {
    Serial.println("Queue Setup Failed.");
  }

  HESetup();
  if (he_setup) {
    Serial.println("HE Sensor Setup Complete.");
  }
  else {
    Serial.println("HE Sensor Setup Failed.");
  }

  buttonSetup();
  if (button_setup) {
    Serial.println("Button Setup Complete.");
  }
  else {
    Serial.println("Button Setup Failed.");
  }

}
