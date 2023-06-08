#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>


/* right now:::
done: switch & left & right buttons work & leds & chara movement
waiting: speaker output!

Currently working on making sure left and right button work.
*/

int time = 0;
int charac = 0;
int hiddenPoint, distanceInt;
float soundMs;
volatile bool switchFlag = 0;
volatile bool switchState = 0;
volatile bool leftButtonFlag = 0;
volatile bool rightButtonFlag = 0;

//sound-stuff (taken from week 5 lecture mon)
float midi[127];
int A_four = 440; // a is 440 hz...



void onOff() {
  switchFlag = 1;
}

void leftButton() {
  leftButtonFlag = 1;
}
void rightButton() {
  rightButtonFlag = 1;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
  switchState = digitalRead(7);
  attachInterrupt(digitalPinToInterrupt(7), onOff, CHANGE);
  attachInterrupt(digitalPinToInterrupt(4), leftButton, RISING);
  attachInterrupt(digitalPinToInterrupt(5), rightButton, RISING);

  generateMIDI(); // Custom function for calculating and storing the frequency value associated for each MIDI pitch number

  randomSeed(analogRead(0)); // Seed random with garbage unknown analog reading

//temporarily in setup function, will be in loop later
  charac = random(9);
  hiddenPoint = random(9);
  while (hiddenPoint == charac) {
    hiddenPoint = random(9);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (switchFlag) {
    delay(5);
    switchState = digitalRead(7);
    switchFlag = 0;
  }
  if (switchState) { //if switch on left, game plays



  

  for (int i=0; i<10; i++) {
    
    if (i != charac) {
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
    } else {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  
  distanceInt = abs(charac - hiddenPoint);
  AsyncDelay soundDelay;
  soundMs = map(distanceInt, 0, 9, 50, 2000);
  soundDelay.start(distanceInt, AsyncDelay::MILLIS);

  // if (soundDelay.isExpired()) {
  //   CircuitPlayground.playTone(midi[65], soundMs);
  //   delay(1);
  // }

    CircuitPlayground.playTone(midi[65], soundMs);
    delay(1);


  if (leftButtonFlag) {
    delay(15);

    Serial.println(hiddenPoint);
    Serial.println(distanceInt);
    if ((charac >= 0) && (charac < 9)) {
      charac++;
    } else {
      charac = 0;
    }
    // CircuitPlayground.playTone(midi[mapSoil], 500);
    // delay(1);
    leftButtonFlag = 0;
  }
  if (rightButtonFlag) {
    delay(15);
    if ((charac > 0) && (charac <= 9)) {
      charac--;
    } else {
      charac = 9;
    }
    // CircuitPlayground.playTone(midi[mapSoil], 500);
    // delay(1);
    rightButtonFlag = 0;
  }


  }
}

void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}


/* 

    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
(test code)
*/
