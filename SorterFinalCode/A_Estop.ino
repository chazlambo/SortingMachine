/*-------------------------------------
      ESTOP PINS & INCLUDES
  ---------------------------------------*/
const int ESTOP = 42;
const int ESTOP_OUT = 4;
const int ESTOP_IN = 5;

/*-------------------------------------
      ESTOP VARIABLES
  ---------------------------------------*/


/*-------------------------------------
    ESTOP FUNCTIONS
  ---------------------------------------*/

 bool EstopCheck(void) {
  int estop = 0;
  if(digitalRead(ESTOP)){
    estop += 1;
  }
  
  if(digitalRead(ESTOP_IN)) {
    estop += 1;
  }

  estop += 1; // DELETE LATER
  
  if (estop == 2) {
    digitalWrite(ESTOP_OUT, HIGH);
    return 0;
  }
  else {
    digitalWrite(ESTOP_OUT, LOW);
    return 1;
  }
 }
