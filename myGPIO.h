/*
 * myGPIO.h
 *
 *  Created on: 3/2/2020
 *      Author: Mahdi Alkafawi
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

// inputs
#define L1      BIT1    // Launchpad Button 1
#define L2      BIT4    // Launchpad Button 2
#define B1      BIT1    // Boosterpack Button 1
#define B2      BIT5    // Boosterpack Button 2
// outputs
#define LED1    BIT0    // LED1 (red)
#define LED2Red BIT0    // LED2 (red)
#define LED2Grn BIT1    // LED2 (green)
#define LED2Blu BIT2    // LED2 (blue)
#define BLEDRed BIT6    // Boosterpack LED (red)
#define BLEDGrn BIT4    // Boosterpack LED (green)
#define BLEDBlu BIT6    // Boosterpack LED (blue)
// constants
#define PRESSED     0
#define UNPRESSED   1


#endif /* MYGPIO_H_ */
