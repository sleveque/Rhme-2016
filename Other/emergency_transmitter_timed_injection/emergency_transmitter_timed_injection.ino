/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
unsigned int mydelay = 20000;
//unsigned int mymillidelay = 22;
unsigned int mymillidelay = 24;
unsigned int mymicrodelay = 0;

byte in[17];
byte firstbytefault[2];
byte secondbytefault[3];
byte thirdbytefault[4];
byte fourthbytefault[5];
byte i = 0;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
}

void loop() // run over and over
{
  byte val = 0;
  Serial.print("Current delay: ");
  Serial.println(mydelay);

/*
  // Injection last round 20000µs => 35000µs

  in[0] = val;
  in[1] = val;
  in[2] = val;
  in[3] = val;
  in[4] = val;
  in[5] = val;
  in[6] = val;
  in[7] = val;
  in[8] = val;
  in[9] = val;
  in[10] = val;
  in[11] = val;
  in[12] = val;
  in[13] = val;
  in[14] = val;
  in[15] = val;
  in[16] = '\n';

  // Pick a random delay to target last round
  mydelay = 20000 + random(0, 15000);

  mySerial.write(in, sizeof(in));
//  delay(2000 + mydelay);

  //i += 1;


  delayMicroseconds(mydelay);
  //delay(mydelay);

//  mySerial.write(in, 1);
  mySerial.write(in, sizeof(in));
*/

/*
  // Injection last round 20000µs => 35000µs
  mymillidelay = 22;
  in[0] = val;
  in[1] = val;
  in[2] = val;
  in[3] = val;
  in[4] = val;
  in[5] = val;
  in[6] = val;
  in[7] = val;
  in[8] = val;
  in[9] = val;
  in[10] = val;
  in[11] = val;
  in[12] = val;
  in[13] = val;
  in[14] = val;
  in[15] = val;
  in[16] = '\n';

  firstbytefault[0] = val;
  firstbytefault[1] = '\n';

  // Safe error if first byte is 10
  secondbytefault[0] = 10;
  secondbytefault[1] = 1; // For some reason, this ends up in first byte of the AES state
  secondbytefault[2] = '\n';

  // Safe error if first byte is 10
  thirdbytefault[0] = 10;
  thirdbytefault[1] = '\n'; // For some reason, this ends up in first byte of the AES state
  thirdbytefault[2] = 0;
  thirdbytefault[3] = '\n';

  // Pick a random delay to target last round
  // No more than 16384 to be precise, according to Arduino website
  mymicrodelay += 5 ; //random(0, 3500);
  //i+= 1;

  Serial.print("Current delay: ");
  Serial.println(mymillidelay + mymicrodelay);

  // Push the message
  mySerial.write(in, sizeof(in));

  delay(mymillidelay);
  delayMicroseconds(mymicrodelay);

  // Faulting just the first byte
//  mySerial.write(firstbytefault, sizeof(firstbytefault));
  // Faulting just the second byte
  mySerial.write(secondbytefault, sizeof(secondbytefault));
  // Faulting just the second byte
  //mySerial.write(thirdbytefault, sizeof(thirdbytefault));

  if (mymicrodelay > 3500)
  {
    while(1);
//    i++;
  }

//  if(i==0)
//  {
//    while(1);
//  }

*/
/*
  // FIRST BYTE

  // Injection last round 20000µs => 35000µs
  in[0] = val;
  in[1] = val;
  in[2] = val;
  in[3] = val;
  in[4] = val;
  in[5] = val;
  in[6] = val;
  in[7] = val;
  in[8] = val;
  in[9] = val;
  in[10] = val;
  in[11] = val;
  in[12] = val;
  in[13] = val;
  in[14] = val;
  in[15] = val;
  in[16] = '\n';

  firstbytefault[0] = i;
  firstbytefault[1] = '\n';

  // Pick a random delay to target last round
  // No more than 16384 to be precise, according to Arduino website
  //mymicrodelay += 10 ; //random(0, 3500);
  i+= 1;

  Serial.print("Current delay: ");
  Serial.println(mymillidelay + mymicrodelay);

  // Push the message
  mySerial.write(in, sizeof(in));

  delay(mymillidelay);
  //delayMicroseconds(mymicrodelay);

  // Faulting just the first byte
  mySerial.write(firstbytefault, sizeof(firstbytefault));

  // Stop after 256 injections
  if (i == 0)
  {
    while(1);
  }

  delay(1500);
}

