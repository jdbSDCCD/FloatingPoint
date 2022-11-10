#include <xc.h>   
.data  
.global working2 // Location to store your reslut.

.text
.align
/*********************************************************
* Subroutine to turn the LED on and off. 
* If R0 contains a 0 the LED is turned off.
* If R0 <> 1 the led is turned on. 
 *********************************************************/        
 
/*************************************************************
* This subroutine retruns the value on the pin connected to
* the push button.
* A 1 in R0 means the push button is up.
* A 0 in R0 means that the push button is down.
*************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************  
   
/********************************************************************
R0 Base address of the vector.
R1 Size of the vector.
********************************************************************/    
.global asmFunction
asmFunction:  
/* Sample section: add the first two values in the vector.  */ 
                   
    ldr R2,[R0]         // Get the first value.
    vmov.f32 S0,R2      // Move it to a FP register.
    ldr R2,[R0,#4]      // Get the second value  
    vmov.f32 S1,R2      // Move it to a FP register.
    vadd.f32 s2,s0,s1   // FP add
    vmov R0,S2          // Move the result to R0
    ldR R2, = #working2 // Get location to store the result
    str R0,[R2]         // Save the value.
    mov PC,LR           // Return to home.
    
.end asmFunction
 
/**********************************************************************/   
.end
           
