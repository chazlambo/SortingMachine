/*--------------------------------
      QUEUE PINS & INCLUDES
----------------------------------*/
#include <QTRSensors.h>

const uint8_t REFARRAY[] = {32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22};

/*-------------------------
      QUEUE VARIABLES
---------------------------*/
QTRSensors qtr;
const uint8_t sensorCount = 11;
uint16_t sensorValues[sensorCount];

int queueSize = 5;
int numMM = 0;

/*-------------------------
      QUEUE FUNCTIONS
---------------------------*/

void queueSetup(void) {

  qtr.setTypeRC();
  qtr.setSensorPins(REFARRAY, sensorCount);

  queue_setup = 1;
}

void readQueue(void) {
  qtr.read(sensorValues);

  numMM = 0;
  
  if (sensorValues[0] < 600) {
    numMM++;
    if (sensorValues[2] < 1000) {
      numMM++;
      if (sensorValues[3] < 500) {
        numMM++;
        if (sensorValues[5] < 600) {
          numMM++;
          if (sensorValues[6] < 600) {
            numMM++;
            if (sensorValues[8] < 600) {
              numMM++;
              if (sensorValues[10] < 1000) {
                numMM++;
              }
            }
          }
        }
      }
    }
  }

}
