/*-------------------------------------
      SYSTEM PINS & INCLUDES
  ---------------------------------------*/

const int STATUS_RED = 35;
const int STATUS_GREEN = 37;
const int STATUS_BLUE = 39;



/*-------------------------------------
    SYSTEM FUNCTIONS
  ---------------------------------------*/

void systemSetup(void) {
  // Status LED Setup
  pinMode(STATUS_RED, OUTPUT); digitalWrite(STATUS_RED, LOW);
  pinMode(STATUS_GREEN, OUTPUT); digitalWrite(STATUS_GREEN, LOW);
  pinMode(STATUS_BLUE, OUTPUT); digitalWrite(STATUS_BLUE, LOW);

  // E-Stop Setup
  pinMode(ESTOP, INPUT);

  system_setup = 1;
}

void pauseLED(void) {
  digitalWrite(STATUS_RED, LOW);
  digitalWrite(STATUS_GREEN, LOW);
  digitalWrite(STATUS_BLUE, HIGH);
}

void readyLED(void) {
  digitalWrite(STATUS_RED, HIGH);
  digitalWrite(STATUS_GREEN, LOW);
  digitalWrite(STATUS_BLUE, HIGH);
}

void sortingLED(void) {
  digitalWrite(STATUS_RED, LOW);
  digitalWrite(STATUS_GREEN, HIGH);
  digitalWrite(STATUS_BLUE, LOW);
}

void stopLED(void) {
  digitalWrite(STATUS_RED, HIGH);
  digitalWrite(STATUS_GREEN, LOW);
  digitalWrite(STATUS_BLUE, LOW);
}
