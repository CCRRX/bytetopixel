const bool ShiftPWM_invertOutputs = false; 
const bool ShiftPWM_balanceLoad = false;
const int ShiftPWM_latchPin=3; 
#include <ShiftPWM.h>
#define DEBUG false
#define DEBUG2 false

int numRegisters = 12;
int numRGBleds = numRegisters*8/3;
int enable = 9; //Grün

int ton = 50;
int toff = 200;
int tbreak = 200;
int i = 0;

int hold = 0;

int incomingByte = 0;


const byte numChars = 96;
unsigned char receivedChars[numChars];   // an array to store the received data
//int Pixel[32][3];

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    
    pinMode(enable, OUTPUT);
 
    digitalWrite(enable,LOW);

    ShiftPWM.SetAmountOfRegisters(numRegisters);
    ShiftPWM.SetPinGrouping(8);
    ShiftPWM.Start(60,255);
    ShiftPWM.SetAll(0);

}

void loop() {
    recvWithEndMarker();
    showNewData();
}

void recvWithEndMarker() {
    static int ndx = 0;
    char endMarker = '\n';
    char rc;
   
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.println("This just in ... ");
        //for(int i = 0; i< numChars-2; i++){
            i = 0;
          for(int y =0;y < 32 ; y++){
            if(DEBUG){
            Serial.println(receivedChars[i],HEX);
            Serial.println(receivedChars[i+1],HEX);
            Serial.println(receivedChars[i+2],HEX);
            Serial.print("y: ");
            Serial.println(y);
            Serial.print("i: ");
            Serial.println(i);
            }
            ShiftPWM.SetRGB(y, receivedChars[i], receivedChars[i+1], receivedChars[i+2], 0);
            //Pixel[y][i]=i;
            //Pixel[y][i+1]=i+1;
            //Pixel[y][i+2]=i+2;
            i++;
            i++;
            i++;
            }
        //}
        newData = false;
    }
}


 
