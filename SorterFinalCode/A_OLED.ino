/*-------------------------
      OLED INCLUDES
---------------------------*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/*-------------------------
      OLED FUNCTIONS
---------------------------*/

void oledSetup(void) {
  Wire.begin();
  Wire.beginTransmission(60);
  byte error = Wire.endTransmission();
  if (error == 0) {

  }
  else {
    Serial.println("ERROR: OLED was not detected by Arduino.");
    return;
  }


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    return;
  }


  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  oled_setup = 1;
}

void configWaitDisplay(void) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Waiting\nfor config\ninput");
  display.display();
}

void startDisplay(void) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Press\nStart");
  display.display();
}

void sortingDisplay(void) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Assigned Color: ");
  switch (desColor) {
    case 'r':
      display.println("Red");
      break;
    case 'g':
      display.println("Green");
      break;
    case 'b':
      display.println("Blue");
      break;
    case 'y':
      display.println("Yellow");
      break;
    case 'o':
      display.println("Orange");
      break;
    case 'w':
      display.println("Brown");
      break;
    case 'e':
      display.println("Empty");
      break;
    default:
      display.println("Unknown");
      break;
  }
  display.print("Queue Size: ");
  display.println(queueSize);
  display.print("Current Queue: ");
  display.println(numMM);
  display.print("# M&M's Sorted: ");
  display.println(numMMSorted);
  display.print("# M&M's Passed: ");
  display.println(numMMPassed);
  display.print("# Contams: ");
  display.println(numContam);

  display.display();
}
