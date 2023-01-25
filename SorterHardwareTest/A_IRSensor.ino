/*-------------------------------------
      IR SENSOR PINS & INCLUDES
  ---------------------------------------*/  
  const int ALIGN_LED = 40;
  const int DETECT_LED = 41;
  
  const int IR_ALIGN = A1;
  const int IR_DETECT = A2;
  

  /*-------------------------------------
      IR SENSOR VARIABLES
  ---------------------------------------*/

  int detectVal = 0;
  int detectThreshold = 600;
  
  /*-------------------------------------
      IR SENSOR FUNCTIONS
  ---------------------------------------*/

  void IRSetup(void) {
    pinMode(ALIGN_LED, OUTPUT);
    pinMode(DETECT_LED, OUTPUT);

    ir_setup = 1;
  }
