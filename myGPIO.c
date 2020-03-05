/*
 * GPIO.c
 *
 *  Created on: 3/2/2020
 *      Author: Mahdi Alkafawi
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Input: Launchpad button 1
    P1DIR = P1DIR & ~L1;
    P1REN = P1REN | L1;
    P1OUT = P1OUT | L1;
    // Input: Launchpad button 2
    P1DIR = P1DIR & ~L2;
    P1REN = P1REN | L2;
    P1OUT = P1OUT | L2;
    // Input: Boosterpack button 1
    P5DIR = P5DIR & ~B1;
    P5REN = P5REN | B1;
    P5OUT = P5OUT | B1;
    // Input: Boosterpack button 2
    P3DIR = P3DIR & ~B2;
    P3REN = P3REN | B2;
    P3OUT = P3OUT | B2;

    // Output: LED 1
    P1DIR = P1DIR | LED1;
    P1OUT = P1OUT & ~LED1;
    // Output: LED 2 (red)
    P2DIR = P2DIR | LED2Red;
    P2OUT = P2OUT & ~LED2Red;
    // Output: LED 2 (green)
    P2DIR = P2DIR | LED2Grn;
    P2OUT = P2OUT & ~LED2Grn;
    // Output: LED 2 (blue)
    P2DIR = P2DIR | LED2Blu;
    P2OUT = P2OUT & ~LED2Blu;
    // Output: Boosterpack LED  (red)
    P2DIR = P2DIR | BLEDRed;
    P2OUT = P2OUT & ~BLEDRed;
    // Output: LED 2 (green)
    P2DIR = P2DIR | BLEDGrn;
    P2OUT = P2OUT & ~BLEDGrn;
    // Output: LED 2 (blue)
    P5DIR = P5DIR | BLEDBlu;
    P5OUT = P5OUT & ~BLEDBlu;
}

// Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    if (P1IN & L1)
    {
        return UNPRESSED;
    }
    else
    {
        return PRESSED;
    }
}

// Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    if (P1IN & L2)
    {
        return UNPRESSED;
    }
    else
    {
        return PRESSED;
    }
}

// Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    if (P5IN & B1)
    {
        return UNPRESSED;
    }
    else
    {
        return PRESSED;
    }
}

// Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    if (P3IN & B2)
    {
        return UNPRESSED;
    }
    else
    {
        return PRESSED;
    }
}

// Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT |  LED1;
}

// Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LED1;
}

// Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT |  LED2Red;
}

// Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2Red;
}

// Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT |  LED2Grn;
}

// Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2Grn;
}

// Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT |  LED2Blu;
}

// Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2Blu;
}

// Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT |  BLEDRed;
}

// Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BLEDRed;
}

// Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT |  BLEDGrn;
}

// Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLEDGrn;
}

// Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT |  BLEDBlu;
}

// Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLEDBlu;
}
