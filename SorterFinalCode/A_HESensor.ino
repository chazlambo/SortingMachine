/*-------------------------------------
      HE SENSOR PINS & INCLUDES
  ---------------------------------------*/  
  const int HE = A3;

  /*-------------------------------------
      HE SENSOR VARIABLES
  ---------------------------------------*/

  
  
  /*-------------------------------------
      HE SENSOR FUNCTIONS
  ---------------------------------------*/

  void HESetup(void) {
    pinMode(HE, INPUT);

    he_setup = 1;
  }

  int metalDetect(void) {
    int metalDet = 0;
    if(digitalRead(HE)) {
      metalDet = 0;
    }
    else {
      metalDet = 1;
    }

    return metalDet;
  }
