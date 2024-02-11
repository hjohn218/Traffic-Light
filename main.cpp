/*
 * Traffic Light System.cpp
 *
 * Created: 1/21/2022 12:58:01 PM
 * Author : Heidi Johnson
 *
 *North South(NS) - Green for 10 seconds, Yellow 2 seconds, and Red/Blue for 12 seconds. 
 *East West(EW) - Red/Blue for 12 seconds, Green 10 seconds, and YEllow for 2 seconds.
 *When the Red lights up so does the Blue light.
 *Blue light is for pedestrians.
 */ 


//Defines the speed of the clock that is being used.
#define F_CPU 16000000L

//Libraries that are being used for the code to run.
//Lets you write to the pins, ports, etc. input or output.
#include <avr/io.h>
//Lets you delay the time/or make it wait.
#include <util/delay.h>

int main(void)
{
	//Sets all D registers to outputs.
	DDRD = 0xff;
	
	//Event Loop/ Main loop
	while(1)
	{
		//NS is green and EW is red/blue.
		PORTD = 0b00101001;
		//Delays the green light for 10 seconds
		_delay_ms(10000);
		//NS is yellow and EW is red/blue.
		PORTD = 0b01001001;
		//Delays the yellow light for 2 seconds.
		_delay_ms(2000);
		//EW is green and NS is red/blue.
		PORTD = 0b10010010;
		//delays the green light for 10 seconds.
		_delay_ms(10000);
		//EW is yellow and NS is red/blue.
		PORTD = 0b10010100;
		//Delays the yellow light for 2 seconds.
		_delay_ms(2000);
	}//End of while Event Loop
}//End of int main(void)



/*Defines the clock that we are using
#define F_CPU 16000000L
//delays time in milliseconds
#define DELAYTIME 85
//Defining the LED Port D
#define LED_PORT PORTD
//Defining LED Pin D
#define LED_PIN PIND
//Defining the LED Data Direction Resistor for D
#define LED_DDR DDRD

//The libraries that the code will be drawing from
//This defines pins, ports, etc.
#include <avr/io.h>
//This one stops time or delays the code for how ever long you specify.
//Let's the function to waste time.
#include <util/delay.h>



int main(void)
{
     //Initializing 
  uint8_t i=0;
  //Data Direction Register D: all set up for output.
  //LED_DDR = 0xff;//using hexadecimal
  LED_DDR = 0b11111111;//Using binary          
  
    while (1) 
    {
		while(i < 7)
		{
			//illuminates only i pin
			LED_PORT = (1 << i);
			//Delays time/waits
			_delay_ms(DELAYTIME);
			//Moves to the next LED
			i = i+1;
		}//End of while loop shifting the LED left to right.
		
		while (i > 0)
		{
			//Illuminates only i pin 
			LED_PORT = (1 << i);
			//Delays time/wait.
			_delay_ms(DELAYTIME);
			//Moves to the previous LED
			i = i-1;
		}//End of while loop shifting LED right to left.
    }//End of the main loop
	//return 0; You don't need this line because you are passing void through the main function.
}//End of the main function
*/

/* Cyclone Eyes */

/*Libraries need for the code
//Defines pins, ports, etc 
#include <avr/io.h>
//Functions to waste time                         
#include <util/delay.h>                     

// milliseconds
#define DELAYTIME 45                                    
#define LED_PORT                PORTD
#define LED_PIN                 PIND	
#define LED_DDR                 DDRD

int main(void) 
{

  //Initializing
  uint16_t x = 0x1234;
  uint8_t y;
   //Data Direction Register D: all set up for output 
  LED_DDR = 0b11111111;              
                                   
  while (1) 
  {
	 // "random" number generator
    x = 2053 * x + 13849;  
	//pick three bits from high byte              
    y = (x >> 8) & 0b00000111;  
	 //toggle one bit     
    LED_PORT ^= (1 << y);                           
    _delay_ms(100);

  }//End event loop
  //return 0; Dont need this
}// End of main function
*/
