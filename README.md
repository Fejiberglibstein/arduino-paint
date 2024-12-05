<div align="center">
    <h1>Arduino Paint</h1>
</div>

---


# Project setup

### Buy these

- [Arduino `x1`](https://store-usa.arduino.cc/products/arduino-uno-rev3?gad_source=1)
- [Proximity Sensors `x8`](https://www.adafruit.com/product/4019)
- [LED screen `x1`](https://www.adafruit.com/product/2601?gad_source=1)
- [Matrix Shield `x1`](https://www.adafruit.com/product/2601?gad_source=1)
- [Breadboard `x2`](https://www.adafruit.com/product/239)
- [Male-Female Jumper Wires `x1`](https://store-usa.arduino.cc/products/40-colored-male-female-jumper-wires)
- [Male-Male Jumper Wires `x1`](https://store-usa.arduino.cc/products/40-colored-male-male-jumper-wires)


### Printing
- Print everything found in `models/`
  
  - sensor_frame.stl `x8` (When slicing, orient so the front face is down)
  - back_bracket.stl `x8`
  - lego_base1.stl `x2` (Oriented so the lego fitting faces outwards)
  - lego_base2.stl `x2` (Oriented so the lego fitting faces outwards)


### Constructing the frame
- Construct a lego frame 48x24 studs, (41.2 x 20.6 cm)
  - Add a bridge extending width-wise across the middle to support the platform

- Place a 17.8 x 8.9 cm rectangle oriented vertically in the center of the lego
  frame (see picture below if you're confused)


### Wiring

- Place a sensor in each sensor frame and slot a bracket into the groove at the
  top of the bracket
  - Take each sensor frame and put 2 inside of each sensor base so the pins are face up
    (`./models/lego_base1.stl` and `./models/lego_base2.stl`)
  - Each sensor base will go on the lego frame  (refer to the picture below for details)
    - Each should be 4 studs diagonally backwards from each corner
    - Ensure the mount is angled towards the opposite corner of the frame

- You must wire the proximity sensors all together on 2 breadboards.
    - The breadboards should be placed on opposite ends of the frame
    - Connect 5 volts and GND to the +/- rails
    - The trigger and echo pins of each sensor will be connected to the same
      rail on the breadboard
    - You can follow the diagram found in `./documentation/circuit_design.pdf`

- The matrix shield pins must be soldered before use
    - Either solder wires to the pins to be used for trigger/echo or connect a jumper wire
      to the base of the pin
      
- Insert the pins on the matrix shield into the Arduino pin holes and
  connect the LED matrix to the shield
- Connect all wires on the Arduino to the circuit made on the breadboards, ensuring each sensor gets the correct pin


> <details>
>  <summary><b><code>  SPOILER  </code> Picture of setup</b></summary>
>
>  ![setup image](./documentation/setup.jpg)
> </details>


# Using and interacting with the project

### Compiling & Uploading

- Plug the arduino into a computer and compile and upload the sketch by simply
  running `make`, assuming you are on mac/linux and have arduino-cli installed.
    - Prior to this step, disconnect the sensors on pins 0 and 1. Once the sketch is uploaded, connect the wires again

> [!WARNING] 
> ### Using the arduino IDE
> If you are on windows and/or using the Arduino IDE, follow these steps:
> - In the arduino IDE, copy all the `.h` files and their respective `.cpp` files into
>   the arduino library folder into a folder called `math_lib/`.
> - In `arduino-paint.ino`, change the first #include line to the following
> ```diff
> - #include "point_translation.h"
> + #include <point_translation.h>
> ```

- Once it is on, you will be able to trace on the central rectangle and see the
  same trace appear on the LED screen.

- Press the `reset` button on the arduino to clear the screen
