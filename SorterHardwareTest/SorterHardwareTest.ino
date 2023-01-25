// TIME VARIABLES
unsigned long t_ms = 0;
double t = 0;

// INTERVAL VARIABLES
double T_mot = 0.02;
double T_enc = 0.01;
double T_color = 0.5;
double T_scan = 5;

// TIME UPDATE VARS
double t_old_enc = 0;
double t_old_mot = 0;
double t_old_color = 0;
double t_old_scan = 0;

// SETUP VARIABLES
bool motor_setup = 0;
bool oled_setup = 0;
bool servo_setup = 0;
bool color_setup = 0;
bool system_setup = 0;
bool ir_setup = 0;
bool queue_setup = 0;
bool he_setup = 0;
bool button_setup = 0;
bool comm_setup = 0;

// TEST VARIABLES
char userInput = 'z';
bool testBool = 0;

void setup() {
  setupFun();
  Serial.println();
  PrintMenu();
}

void loop() {
  while (Serial.available() == 0) {}  // Wait for available serial
  if (Serial.available() > 0) {       // Read user input
    userInput = Serial.read();
    while (Serial.available() > 0) {  // Clear serial
      Serial.read();
    }
    Serial.print("User input was ");
    Serial.println(userInput);
    Serial.println();
    delay(250);
  }
  
  // Run Corresponding TestHardware Function
  switch (userInput) {
    case 'a':
      testOLED();
      Serial.println("\nOLED test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'b':
      testStatusLED();
      Serial.println("\nStatus LED test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'c':
      //testEstop();
      Serial.println("\nEstop test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'd':
      testServos();
      Serial.println("\nServo test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'e':
      //testColorSensor();
      Serial.println("\nClosed loop motor test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'f':
      testMotorOpenLoop();
      Serial.println("\nOpen loop motor test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'g':
      testQueue();
      Serial.println("\nQueue test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'h':
      alignFun();
      Serial.println("\nAlignment function complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'i':
      testColorSensor();
      Serial.println("\nColor Sensor test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'j':
      alignFun();
      delay(1000);
      rotate();
      Serial.println("\nRotation test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'k':
      testMetalDetector();
      Serial.println("\nMetal detection test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;

    case 'l':
      testButton();
      Serial.println("\nButton test complete.\n\n");
      Serial.println("\nEnter 'z' to print menu.\n");
      break;



    case 'z':
      PrintMenu();
      break;
  }

}



void PrintMenu(void) {
  Serial.println("a = Test OLED");
  Serial.println("b = Test Status Light");
  Serial.println("c = Test Estop");
  Serial.println("d = Test Servos");
  Serial.println("e = Test Color Sensor");
  Serial.println("f = Test Open Loop Motor");
  Serial.println("g = Test Queue");
  Serial.println("h = Test Align Function");
  Serial.println("i = Test Color Sensor");
  Serial.println("j = Test Rotation");
  Serial.println("k = Test Metal Detection");
  Serial.println("l = Test Button");
  Serial.println("z = Print Menu");
  return;
}
