#include <iostream>
#include <fstream>
#include <iomanip> //required for access to stream manipulators

// Please don't judge me ... I know its shitty, but it works for me :p

using namespace std;

int main () {
    ofstream stripe;
    bondrucker.stripe ("/dev/ttyUSB1");

    unsigned char  blautest[96] ={0x00,0x01,0xF2,0x03,0x04,0xF5,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x01,0x02,0x03,0x0D,0x0E,0x0F};
    unsigned char blausrt[3] = {0x00,0x00,0xFF};

    stripe.write(blautest,96);
    stripe.close();
    return 0;
}


