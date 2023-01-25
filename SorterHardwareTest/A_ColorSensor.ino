/*-------------------------------------
      COLOR SENSOR PINS & INCLUDES
  ---------------------------------------*/

// Color Sensor Pins
const int COLOR = A0;
const int COLOR_RED = 34;
const int COLOR_GREEN = 36;
const int COLOR_BLUE = 38;

/*-------------------------------------
      COLOR SENSOR VARIABLES
  ---------------------------------------*/

// Color Sensor Values
int vals[] = {0, 0, 0};
int avgVals[] = {0, 0, 0};
int colordelay = 10;       // delay between readings to allow phototransistor to come to steady state
int numScans = 8;         // number of scans to average together

//Calibration Variables (CALIBRATED AT HOME AT 1 AM)
const int tol = 40;
const int redCal[] = {399, 232, 189};
const int greenCal[] = {272, 383, 221};
const int blueCal[] = {253, 301, 424};
const int yellowCal[] = {556, 395, 208};
const int orangeCal[] = {506, 216, 174};
const int brownCal[] = {271, 243, 214};
const int emptyCal[] = {299, 309, 385};
const int plateCal[] = {570, 583, 540};

/*-------------------------------------
      COLOR SENSOR FUNCTIONS
  ---------------------------------------*/

void colorSetup(void) {
  pinMode(COLOR_RED, OUTPUT); digitalWrite(COLOR_RED, LOW);
  pinMode(COLOR_GREEN, OUTPUT); digitalWrite(COLOR_GREEN, LOW);
  pinMode(COLOR_BLUE, OUTPUT); digitalWrite(COLOR_BLUE, LOW);

  color_setup = 1;
}

char colorScan(void) {
  int avgRed = 0;
  int avgBlue = 0;
  int avgGreen = 0;

  for (int i = 0; i < numScans; i++) {

    // Set LED color to Red
    digitalWrite(COLOR_RED, HIGH);
    digitalWrite(COLOR_GREEN, LOW);
    digitalWrite(COLOR_BLUE, LOW);
    delay(colordelay);
    vals[0] = analogRead(COLOR);

    // Set LED color to Green
    digitalWrite(COLOR_RED, LOW);
    digitalWrite(COLOR_GREEN, HIGH);
    digitalWrite(COLOR_BLUE, LOW);
    delay(colordelay);
    vals[1] = analogRead(COLOR);

    // Set LED color to Blue
    digitalWrite(COLOR_RED, LOW);
    digitalWrite(COLOR_GREEN, LOW);
    digitalWrite(COLOR_BLUE, HIGH);
    delay(colordelay);
    vals[2] = analogRead(COLOR);

    // Update Average
    avgRed += vals[2];
    avgGreen += vals[1];
    avgBlue += vals[0];
  }

  // Turn off LED
  digitalWrite(COLOR_RED, LOW);
  digitalWrite(COLOR_GREEN, LOW);
  digitalWrite(COLOR_BLUE, LOW);

  // Calculate average value
  avgRed = avgRed / numScans;
  avgGreen = avgGreen / numScans;
  avgBlue = avgBlue / numScans;
  avgVals[2] = avgRed;
  avgVals[1] = avgGreen;
  avgVals[0] = avgBlue;
}

char parseColor(void) {
  char colorchar = 'u';
  int red = 0;
  int green = 0;
  int blue = 0;
  int yellow = 0;
  int orange = 0;
  int brown = 0;
  int empty = 0;
  int plate = 0;
  int unknown = 0;
  int color = 0;

  for (int i = 0; i < 3; i++) {
    // Detect Red
    if (redCal[i] - tol <= avgVals[i] && avgVals[i] <= redCal[i] + tol) {
      red += 1;
      color += 1;
    }
    if (greenCal[i] - tol <= avgVals[i] && avgVals[i] <= greenCal[i] + tol) {
      green += 1;
      color += 1;
    }
    if (blueCal[i] - tol <= avgVals[i] && avgVals[i] <= blueCal[i] + tol) {
      blue += 1;
      color += 1;
    }
    if (yellowCal[i] - tol <= avgVals[i] && avgVals[i] <= yellowCal[i] + tol) {
      yellow += 1;
      color += 1;
    }
    if (orangeCal[i] - tol <= avgVals[i] && avgVals[i] <= orangeCal[i] + tol) {
      orange += 1;
      color += 1;
    }
    if (brownCal[i] - tol <= avgVals[i] && avgVals[i] <= brownCal[i] + tol) {
      brown += 1;
      color += 1;
    }
    if (emptyCal[i] - (tol + 40) <= avgVals[i] && avgVals[i] <= emptyCal[i] + (tol + 40)) {
      empty += 1;
      color += 1;
    }
    if (plateCal[i] - (tol + 80) <= avgVals[i] && avgVals[i] <= plateCal[i] + (tol + 40)) {
      plate += 1;
      color += 1;
    }
    if (color == 0) {
      unknown += 1;
    }
    color == 0;
  }
  if (empty >= 3) {
    colorchar = 'e';
  }
  if (plate >= 3) {
    colorchar = 'p';
  }
  if (unknown >= 3) {

  }
  if (red >= 3) {
    colorchar = 'r';
  }
  if (green >= 3) {
    colorchar = 'g';
  }
  if (blue >= 3) {
    colorchar = 'b';
  }
  if (yellow >= 3) {
    colorchar = 'y';
  }
  if (orange >= 3) {
    colorchar = 'o';
  }
  if (brown >= 3) {
    colorchar = 'w';
  }
  
  
  return colorchar;
}
