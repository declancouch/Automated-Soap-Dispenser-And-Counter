# Automated-Soap-Dispenser-Counter

This repository contains my project for the Embedded Systems Design course. It involves an Arduino-based automated soap dispenser that counts usage and has an LED indicator system for operational status.

![frontcopyof design](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/2f70f679-c081-4c33-a307-164ccd1e6e60)

**Demonstration Video:** https://youtu.be/p4MaiMroa_E

---

### Demonstration Hardware
- Arduino Board (Model)
- Arduno Board to PC wire
- 2 breadboard (1 for Arduino + HEX display and the other for the external power supply)
- 4 Male To Female Wires (Used to Hold The LED's)
- 25+ Male to Male Wires
- ANNIMOS Digita RC Servo Motor (20kg)
- Infrared Obstacle Avoidance Sensor
- 4 Digit HEX Display (For usage count)
- LEDs (Green for ready, Yellow for in use)
- 4 1kΩ-5kΩ resistors (Any resistors in that range will do)
- 9V power supply cord
- Power Supply Breadboard
- Crafting materials: tape, super glue, plastic straw, hook screw, rectangular soap bottle, and wood

  ---


## Easiest Process To Follow When Building The Automated Soap Dispenser And Counter
The best way to go about building the Automated Soap Dispenser And Counter is through a 3-step process.

1. Build the software and ensure that everything is compiling correctly.

2. Using the Arduino hardware, wire your microprocessor based on your software arrangements so the pins and signals communicate in rhythm with the code. Next, download the code onto the board and ensure that when an object activates the infrared sensor the yellow LED, HEX display, and servo motor all activate as well.

3. Once you know that your code and hardware are working properly, go ahead and assemble the physical soap dispenser so the components can come together to form an automated soap dispenser that counts the number of times it has been used.

**NOT following this process will make the debugging process much more difficult!** 



---





### 1. Software Instructions for The Automated Soap Dispenser & Counter


[Download this code onto your Arduino compiler system](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/blob/34ed45a4a5e10d7ac9d816b988eacd39e0801649/Arduino%20Completed%20Soap%20Dispensor%20Code.ino)




---





### 2. Hardware Instructions for The Automated Soap Dispenser & Counter

Using the schematic shown below wire the Arduino exactly how it's shown.
![Servo Motor (1)](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/8a729bc1-4a63-4fd9-bb49-1413506816e6)
![hardschematic](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/cff6ab99-e802-40eb-b9fc-b542e1ba81ac)



#### Setting up power supply(Use the image below as reference):
- Snap the power supply board into your breadboard.
- Plug your 9V power supply cord into the outlet, then the other end into your power supply board. 
- Using a wire, plug one end of the wire into the ground side of the power supply and the other end into the ground of the Arduino. You must incorporate this or there will be a short circuit within your hardware and it won't work.
- Press the white button on the power supply to turn it on.
  
![9vbatterysetup](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/96e0f5af-a386-4aa5-b7e9-33c16bc0f541)


#### Servo:
- On the servo motor connect the white wire to analog Pin A2, this way you can establish a way to communicate with the servo.
- Connect the red wire to the voltage pin on the 9V power supply. Just know if you connect this wire to the 5V on the Arduino, the servo will not run because the Arduino doesn't provide enough current to support a 20kg servo.
- Connect the black wire to the ground point of the 9V power supply.

#### Infrared Sensor:
- Connect the "+Out" pin on the sensor analog Pin A0.
- Connect the "GND" pin on the sensor to the ground pin on the Arduino.
- Connect the "Vcc" pin on the sensor to the 5V pin on the Arduino.

#### Red LED:
- Connect the anode side (longer side) of the LED to the analog Pin A5.
- Connect the cathode side (short side) of the LED to the ground on the Arduino.

#### Yellow LED:
- Connect the anode side (longer side) of the LED to the analog Pin A5.
- Connect the cathode side (short side) of the LED to the ground on the Arduino.

#### 4 Digit HEX Display (Use the image below to understand which segment/digit corresponds to each pin on the HEX display):
- Connect Segment E on the HEX display to Pin 13 on the Arduino. 
- Connect Segment D on the HEX display to Pin 2 on the Arduino. 
- Connect Segment Decimal Pin (D.P.) on the HEX display to Pin 3 on the Arduino. 
- Connect Segment C on the HEX display to Pin 4 on the Arduino. 
- Connect Segment G on the HEX display to Pin 5 on the Arduino. 
- Connect Segment Digit Pin 4 (D4) on the HEX display to Pin 6 on the Arduino. 
- Connect Segment B on the HEX display to Pin 7 on the Arduino. 
- Connect Segment Digit Pin 3 (D3) on the HEX display to Pin 8 on the Arduino. 
- Connect Segment Digit Pin 2 (D2) on the HEX display to Pin 9 on the Arduino. 
- Connect Segment F on the HEX display to Pin 10 on the Arduino. 
- Connect Segment A on the HEX display to Pin 11 on the Arduino. 
- Connect Segment Digit Pin 1 (D1) on the HEX display to Pin 12 on the Arduino.

![7segmentdisplayconfig](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/cad3d61c-df9f-4155-98bd-dc3fbb7fc742)




---




### 3. Assembly Instructions for Automated Soap Dispenser

1. **Select a Soap Container:** Choose a soap container with flat sides and top for easier component attachment.

![Desiredbottletype](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/0ef27fcd-a874-435c-8deb-c3e7793db2c9)

  
2. **Attach the Servo Motor:** Secure the 20kg servo motor to the left side of the bottle using super glue and duct tape (let it sit in this position for at least an hour). Ensure the motor is oriented correctly for its 270-degree rotation limit, so it doesn't rotate into the bottle (Mimic the gluing process shown below and you can avoid this issue). Use a servo arm with a half-arm design to prevent interference with the bottle.

![IMG_4395](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/fb1e66d5-dede-4321-a990-4c1cfa667348)

3. **Prepare a Block:** Find a soft material block and cut it into the dimensions of 1 inch x 1 inch x 1 inch. Next, find a "hook screw" and manually screw it into the block.

![hookandblockofwoodpic](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/8303619c-750a-4c06-8b6c-8b6c7232a46c)
   
4. **Mount the Block:** Attach the block to the right side of the bottle at a height similar to the servo motor, using super glue and duct tape. This ensures balanced force distribution (Let it sit in this position for at least an hour).

![IMG_4396](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/f494530b-09e0-49bb-a87b-4828d22d06d0)

5. **Measure and Mark the String:** Find a sewing string that has a lot of strength. Measure the required length for tension from the servo arm to the hook, marking it with a red marker.
  
6. **Prepare the Straw:** Cut a small section of a plastic straw, ensuring it's not too long to avoid imbalance. Attach it to the top of the soap pump with duct tape. This straw piece prevents the string from slipping off during operation.

![strawpic](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/6d084921-055d-4fce-a632-5788f5b4a444)

7. **Attach the String:** Tie one end of the string to the hook at the marked spot. Thread the other end through the straw and tie it to the servo arm at the designated mark. Ensure the knots are tight to prevent slippage. Additionally, make sure the tension on the string is tight.

![wirepic](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/c2da657a-3c39-4fc0-9f76-19115bdc8461)
   
8. **Position the Infrared Sensor:** Duct tape the infrared sensor at the top base level of the pump, where it can easily detect a hand. Ensure the tape does not cover the sensor's LEDs and the string does not obstruct its field of view. (You may need to use a screwdriver to adjust the sensitivity of the sensor to your desired needs) 

![IMG_4403](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/e7099a8d-2045-4c5f-a6b9-e8746fb746ab)
   
10. **Install LED Indicators:** Get two sets of male-to-female wires (4 total). Duct tape the female ends to the sides of the bottle—one set on each side. Insert the yellow and green LEDs into these connectors, while ensuring the duct tape does not touch the LED diodes, to maintain optimal brightness. Additionally, make sure you insert the anode side of the LED (longer side) into the wire going to the pins, and the cathode side (shorter side) into the wire connected to the ground.

![LEDsystem](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/cd89e52e-af60-45b1-bd00-6c66b2e9075d)

11. **Rewrite The Circuit:** During the assembly process it's inevitable that wires will fall out during the process. So using the schematic from part 2, rewire everything that came apart. After that, you're officially done, and you have your own automatic soap dispenser and LED system which counts the number of times it has been used. Enjoy.

![IMG_4435](https://github.com/declancouch/Automated-Soap-Dispenser-And-Counter/assets/145140758/5618ce4a-39ae-4a3a-9f56-6e685d8cad63)


