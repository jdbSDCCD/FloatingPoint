/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <xc.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

/* 
 * File:  main.c
 * Author: Jim Broesch
 *
 * Created on May 13, 2022, 9:16 PM
 */

// Multiply the first two arguments and add the third argument to the result.
// Function signature
extern uint32_t asmFunction(uint32_t, uint32_t, uint32_t, uint32_t);

float working1 = 0;
float working2 = 0;

#define dataSize 2
float data[dataSize];

int main(void) 
{
    
    for (int32_t j = 0; j< dataSize; j++)
    {
        data[j] = ((float)rand() / (float)RAND_MAX)- (float)1/2;
        data[j] *= 2.0;
    }
    
    for (int32_t j = 0; j< dataSize; j++)
    {
        working1 +=data[j];
    }
    // Invoke the assembly language function.
    asmFunction((int32_t)data, dataSize, 0, 0);
  
    while(1);
}

/*******************************************************************************
 End of File
*/

