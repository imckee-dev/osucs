# osucs

# Author
Ian McKee

## What does the .ino file do?
This includes a game code for Arduino Circuit Playground Express.

### Game specifications:

You are randomly placed in the circle indicated with a green LED. There's a hidden point that you need to find.

Press left and right buttons to go around the circle, the speaker will continuously beep faster and faster the closer you are to the defined point (randomly selected.) 

When you get to the point, it will beep a different note very shortly and flash blue to indicate ready for next.

Three rounds, and when the third is over you are given your time (in serial.)

### Inputs and outputs: 

inputs:
1. left button
To move counterclockwise around the circle.
2. right button
To move clockwise around the circle.
3. switch 
(If left, game is on loop and if starting on right, nothing happens)
	

outputs:
1. individual **LED** telling where your character is (range 0-9) [the rest of the LEDs 0-9 used as background]

2. **speaker** beeping faster for when you're closer (beep for 50-1000ms [depending on distance between character and hidden (range 0-9)]) & async delay 1 sec between beeps.
Mapped function: convert [abs(char-hidden)] from 0-9(LED values) to 50-1000 (ms).

3. Serial tells you when each round starts, and your final time in seconds.
