#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned int previousState = UNPRESSED;
    unsigned int currentState = UNPRESSED;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired())
        {
            count0++;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired())
        {
            previousState = currentState;
            currentState = checkStatus_BoosterpackS1();
        }


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        if (fsmBoosterpackButtonS1(currentState, previousState))
        {
            // If a completed, debounced button press has occurred, increment count1.
            count1++;
        }
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch(count%8)
    {
        case 0:
            turnOff_LaunchpadLED2Blue();    // LED is off
            turnOff_LaunchpadLED2Green();
            break;
        case 1:
            turnOn_LaunchpadLED2Red();      // Red
            break;
        case 2:
            turnOn_LaunchpadLED2Green();    // Yellow
            break;
        case 3:
            turnOff_LaunchpadLED2Red();     // Green
            break;
        case 4:
            turnOn_LaunchpadLED2Red();      // White
            break;
        case 5:
            turnOff_LaunchpadLED2Green();   // Magenta
            break;
        case 6:
            turnOff_LaunchpadLED2Red();     // Blue
            break;
        case 7:
            turnOn_LaunchpadLED2Green();    // Cyan
            break;
        }
}

// Map the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch(count%8)
    {
        case 0:
            turnOff_BoosterpackLEDGreen();  // LED is off
            break;
        case 1:
            turnOn_BoosterpackLEDRed();     // Red
            break;
        case 2:
            turnOn_BoosterpackLEDGreen();   // Yellow
            break;
        case 3:
            turnOn_BoosterpackLEDBlue();    // White
            break;
        case 4:
            turnOff_BoosterpackLEDRed();    // Cyan
            break;
        case 5:
            turnOff_BoosterpackLEDGreen();  // Blue
            break;
        case 6:
            turnOn_BoosterpackLEDRed();     // Magenta
            break;
        case 7:
            turnOff_BoosterpackLEDRed();    // Green
            turnOff_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDGreen();
            break;
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int currentState, unsigned int previousState)
{
    bool pressed = false;
    switch (currentState)
    {
        case PRESSED:
            if (previousState == UNPRESSED)
            {
                pressed = true;
            }
            break;
        case UNPRESSED:
            break;
    }
    return pressed;
}
