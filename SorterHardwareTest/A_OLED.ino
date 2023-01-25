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

void servoDisplayUpdate(int mode) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 32);
  if (mode == 1) {
    display.print("Contam");
  }
  else if (mode == 2) {
    display.print("Sorted");
  }
  else if (mode == 3) {
    display.print("Pass on");
  }
  else {
    display.print("wtf");
  }
  display.display();
}

void openLoopDisplay(void) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Speed Command: ");
  display.println(mSpdCmd);
  display.println();
  display.print("Time: ");
  display.println(t);
  display.println();
  display.print("Counts: ");
  display.println(counts);
  display.print("Rotations: ");
  display.print(int(motorPos / 2 / PI));
  display.println();
  display.print("Vel: ");
  display.print(int(motorVel / 2 / PI * 60));
  display.print(" rpm");
  display.println();
  display.display();
}

void colorDisplay(char col) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Color: ");
  switch (col) {
    case 'r':
      display.print("Red");
      break;
    case 'g':
      display.print("Green");
      break;
    case 'b':
      display.print("Blue");
      break;
    case 'y':
      display.print("Yellow");
      break;
    case 'o':
      display.print("Orange");
      break;
    case 'w':
      display.print("Brown");
      break;
    case 'p':
      display.println("Plate");
      display.setTextSize(1);
      display.print("(MISALIGNED)");
      display.setTextSize(2);
      break;
    case 'e':
      display.print("Empty");
      break;
    default:
      display.print("Unknown");
      break;
  }
  display.println();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println("  R  |  G  |  B  ");
  display.print(" "); display.print(avgVals[0]); display.print("   "); display.print(avgVals[1]); display.print("   "); display.print(avgVals[2]);
  display.display();
}
