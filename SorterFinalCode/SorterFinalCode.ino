// TIME VARIABLES
unsigned long t_ms = 0;
double t = 0;

// INTERVAL VARIABLES
double T_mot = 0.01;
double T_enc = 0.005;
double T_color = 0.5;
double T_scan = 0.5;
double T_pause = 0.05;
double T_button = 0.1;
double T_queue = 0.1;
double T_oled = 0.1;

// TIME UPDATE VARS
double t_old_enc = 0;
double t_old_mot = 0;
double t_old_color = 0;
double t_old_scan = 0;
double t_old_pause = 0;
double t_old_button = 0;
double t_old_queue = 0;
double t_old_oled = 0;

// SETUP FUNCTION BOOLEAN VARIABLES
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

// STATE BOOLEAN VARIABLES
bool startBool = 0;
bool configBool = 0;
bool pauseToggle = 0;
bool pauseBool = 0;
bool estopBool = 0;


// PID Error Variables
double error;           // error
double derror;          // derivative error
double ierror = 0;      // integral error
double error_old = 100
double derror_raw;      // derivative error before filter
double derror_old;

// INITIALIZE SYSTEM VARIABLES
  // Initialize sorting varibles to be zero and empty
char pos4Color = 'e'; 
char pos5Color = 'e'; 
bool pos5Metal = 0;   
int numMM = 0;
int numMMSorted = 0;
int numContam = 0;
int numMMPassed = 0;

// IMPORTANT SORTING VARIABLES
char desColor = 'g';  // Set the desired color to sort out
int queueSize = 5;    // Set the maximum desired queue size

void setup() {
  // Start timer
  t_ms = micros();
  t = t_ms / 1000000.0;

  // Run setup function
  setupFun();

  // Set LED to stop color
  stopLED();

  // Align motor
  alignFun();

  // Set LED to ready color
  readyLED();

  while (!startBool) {  // Wait for start button and configuration
    
    while (!configBool) { // If config settings hvae not been recieved
      configWaitDisplay();  // Set display to waiting for config
      // configBool = configGet();       // Get config settings
      delay(2000);
      configBool = 1;
      }

    // Set display to the start button display
    startDisplay();
    if (buttonRead()) {       // If button is being pressed
      while (buttonRead()) {} // Buffer button press until released
      t_ms = micros();        // Update time
      t = t_ms / 1000000.0;   // Convert to ms
      startBool = 1;          
      t_old_button = t;       // Update time values
      t_old_mot = t;
      t_old_enc = t;
    }
  }
}

void loop() {
  // Update Time
  t_ms = micros();
  t = t_ms / 1000000.0;

  // Check for pause/unpause button press
  if (buttonRead() && t > t_old_button + T_button) {
    while (buttonRead()) {}     // Buffer button read until unpressed
    pauseToggle = !pauseToggle; // Change pause state to pause/resume
  }

  if (t > t_old_pause + T_pause) {  // Check for pause conditions
    int pause = 0;
    if (pauseToggle == 1) {   // Check if pause button was pressed
      pause++;
    }

    if (pause == 0) { // If no pause conditions
      pauseBool = 0;
    }
    else {
      pauseFun(); // Set to pause state
    }
    t_old_pause = t;
  }

  // Check Estop
  if (EstopCheck()) {
    estopBool = 1;
    stopLED();
  }
  else{
    estopBool = 0;
  }

  // Read Queue
  if (t > t_old_queue + T_queue) {
    readQueue();
    t_old_queue = t;
  }

  // Update OLED
  if (t > t_old_oled + T_oled) {
    sortingDisplay();
    t_old_oled = t;
  }

  // Sorting State
  if (!pauseBool && !estopBool) {
    sortingLED();

    // Update Encoder
    if (t > t_old_enc + T_enc) {
      updateEncoder();
    }

    // Update PID control variables
    if (t > t_old_mot + T_mot) {
      pidMotor();
    }

    // Scan and Sort
    if (abs(error) < 0.02 && t > t_old_scan + T_scan) { // If in correct position
      updateNextPosition(); // Update position variabels
      scanfun();            // Scan M&Ms in each position
      setServo();           // Set sorting servos for next M&M drop

      t_old_scan = t;
    }
  }
}
