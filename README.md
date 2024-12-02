<div align="center">
    <h1>Arduino Paint</h1>
</div>

---

# Project setup

- Print everything found in `models/`

- Construct a lego frame 48x24 studs, (41.2 x 20.6 cm), and place 2 sensors in
  each insert, 6 studs diagonally from each corner.
  - You must also place a 17.8 x 8.9 cm rectangle oriented vertically in the
    center of the lego frame

- In the arduino IDE, copy all the `.h` files and their respective `.cpp` file into
  the arduino library folder into the folder called `math_lib/`.

- You must wire the proximity sensors all together on 2 breadboards.
    - The trigger and echo pins of each sensor will be connected to the same
      rail on the breadboard

- You must also wire the LED matrix together to the arduino

# Using and interacting the project

- Plug the arduino into a computer and compile and upload the sketch.

- Once it is on, you will be able to trace on the central rectangle and see the
  same trace appear on the LED screen.
