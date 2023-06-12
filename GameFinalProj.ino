#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

int charac = 0;
int hiddenPoint, distanceInt;
float soundMs;
volatile bool switchFlag = 0;
volatile bool switchState = 0;
volatile bool leftButtonFlag = 0;
volatile bool rightButtonFlag = 0;
volatile bool initialize;

//sound-stuff (taken from week 5 lecture mon)
float midi[127];
int A_four = 440; // a is 440 hz...

AsyncDelay soundDelay;

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
  
  soundDelay.start(1000, AsyncDelay::MILLIS);

  generateMIDI(); // Custom function for calculating and storing the frequency value associated for each MIDI pitch number

  randomSeed(analogRead(0)); // Seed random with garbage unknown analog reading

//(was probably for setting random function thing
//(temporarily in setup function, will be in loop later

}

void loop() {
  // put your main code here, to run repeatedly:
  if (switchFlag) {
    delay(5);
    switchState = digitalRead(7);
    switchFlag = 0;
  }

  if (switchState) { //if switch on left, game plays


    //to calculate time: https://www.tutorialspoint.com/calculate-time-of-operation-in-arduino
    long int start_time = millis();

    // Running three rounds
    for (int r=0; r<3; r++) {
      charac = random(10);
      hiddenPoint = random(10);
      while (hiddenPoint == charac) hiddenPoint = random(10);
      Serial.print("Round ");
      Serial.print(r+1);
      Serial.println(" starting:");

      bool round_running = 1;


      while(round_running) {

        // draw locations
        for (int i=0; i<10; i++) {
          if (i != charac) {
            CircuitPlayground.setPixelColor(i, 255, 0, 0);
          } else {
            CircuitPlayground.setPixelColor(i, 0, 255, 0);
          }
        }

        if (leftButtonFlag) {
          delay(10);
          if ((charac >= 0) && (charac < 9)) {
            charac++;
          } else {
            charac = 0;
          }
          leftButtonFlag = 0;
        }

        if (rightButtonFlag) {
          delay(10);
          if ((charac > 0) && (charac <= 9)) {
            charac--;
          } else {
            charac = 9;
          }
          rightButtonFlag = 0;
        }
        
        distanceInt = abs((charac+1) - (hiddenPoint+1));
        soundMs = map(distanceInt, 0, 9, 50, 1000);

        if (soundDelay.isExpired()) {
          //Sound function ACTUALLY being used
          CircuitPlayground.playTone(midi[65], soundMs, false);
          soundDelay.repeat();
        }


        // Checking if round ended
        if (charac == hiddenPoint) {
          CircuitPlayground.playTone(midi[75], 100);
          for (int i=0; i<2; i++) {
            // Flashing blue twice to indicate round ended
            for (int j=0; j<10; j++) {
              CircuitPlayground.setPixelColor(j, 0, 0, 255);
            }
            delay(100);
            CircuitPlayground.clearPixels();
            delay(100);
          }
          round_running = 0;
        }
      }
    } //round end

    // Three rounds finished, print game time
    Serial.print("You took a solid ");

    //to calculate time: https://www.tutorialspoint.com/calculate-time-of-operation-in-arduino
    long int end_time = millis();
    Serial.print((end_time-start_time)/1000);
    Serial.println(" seconds!");


    Serial.println("Starting again in 5 seconds! ");
    delay(5000);
  } //switchstate end
} //loop end

void generateMIDI() {
  for (int x = 0; x < 127; ++x) {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}
