/*-------------------------------------
      BUTTON PINS & INCLUDES
  ---------------------------------------*/  
  const int BUTTON = 43;

  /*-------------------------------------
      BUTTON VARIABLES
  ---------------------------------------*/

  bool buttonState = 0;
  
  /*-------------------------------------
      BUTTON FUNCTIONS
  ---------------------------------------*/

  void buttonSetup(void) {
    pinMode(BUTTON, INPUT);

    button_setup = 1;
  }

  int buttonRead(void) {
    buttonState = digitalRead(BUTTON);
    return buttonState;
  }
