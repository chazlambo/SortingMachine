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
    // Button setup function
    pinMode(BUTTON, INPUT);

    button_setup = 1;
  }

  int buttonRead(void) {
    // Read the button state
    buttonState = digitalRead(BUTTON);
    return buttonState;
  }
