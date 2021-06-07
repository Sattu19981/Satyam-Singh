// Adafruit IO Publish Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

int IR_1=D3;
int IR_2=D4;
int IR_3=D8;
int IR_4=D6;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
/************************ Example Starts Here *******************************/


// set up the 'counter' feed
AdafruitIO_Feed *CAR_1 = io.feed("CAR 1");
AdafruitIO_Feed *CAR_2 = io.feed("CAR 2");
AdafruitIO_Feed *CAR_3 = io.feed("CAR 3");
AdafruitIO_Feed *CAR_4 = io.feed("CAR 4");
AdafruitIO_Feed *STATUS_1 = io.feed("STATUS 1");
AdafruitIO_Feed *STATUS_2 = io.feed("STATUS 2");
AdafruitIO_Feed *STATUS_3 = io.feed("STATUS 3");
AdafruitIO_Feed *STATUS_4 = io.feed("STATUS 4");

void setup() {
  pinMode(IR_1,INPUT);
  pinMode(IR_2,INPUT);
  pinMode(IR_3,INPUT);
  pinMode(IR_4,INPUT);
  

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

    buttonState1 = digitalRead(IR_1);
    buttonState2 = digitalRead(IR_2);
    buttonState3 = digitalRead(IR_3);
    buttonState4 = digitalRead(IR_4);

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
  
  if (buttonState1 == HIGH) {
    // turn LED on:
    CAR_1->save(0);
    STATUS_1->save("window-close");
  } else {
    // turn LED off:
    CAR_1->save(1);
    STATUS_1->save("car");
  }
  if (buttonState2 == HIGH) {
    // turn LED on:
    CAR_2->save(0);
    STATUS_2->save("window-close");
  } else {
    // turn LED off:
    CAR_2->save(1);
    STATUS_2->save("car");
  }
  if (buttonState3 == HIGH) {
    // turn LED on:
    CAR_3->save(0);
    STATUS_3->save("window-close");
  } else {
    // turn LED off:
    CAR_3->save(1);
    STATUS_3->save("car");
  }
  if (buttonState4 == HIGH) {
    // turn LED on:
    CAR_4->save(0);
    STATUS_4->save("window-close");
  } else {
    // turn LED off:
    CAR_4->save(1);
    STATUS_4->save("car");
  }

  Serial.println("sending -> ");


  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. In this example, we will wait three seconds
  // (1000 milliseconds == 1 second) during each loop.
  delay(17000);

}
