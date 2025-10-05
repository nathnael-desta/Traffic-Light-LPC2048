#include<lpc21xx.h>
#define green4 31
#define yellow4 30
#define red4 29
#define green3 28
#define yellow3 27
#define red3 26
#define green2 25
#define yellow2 24
#define red2 23
#define green1 22
#define yellow1 21
#define red1 20
unsigned char swstatus;
unsigned char crosswalk1 = 0;
unsigned char crosswalk2 = 0;
unsigned char crosswalk3 = 0;
unsigned char crosswalk4 = 0;

void init_ext_interrupt(void);
__irq void Ext_ISR(void);

void wait(unsigned int count) { 
	unsigned int i,j;
	
	for(j=0; j< count; j++) {
		for(i = 0; i< 2000; i++);
	}
}


int main()
{
	PINSEL2 = 0x000000; //Configure the P1 Pins for GPIO;
  IO1DIR = 0xffffffff; //Configure the P1 pins as OUTPUT;
	
	init_ext_interrupt();   // initialize the external interrupt
	
	
	while(1) 
	{
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		
			
		
		// status 1
		IOSET1 |= (1<<green1);
		IOCLR1 |= (1<<red1);
		IOSET1 |= (1<<red2);
		IOSET1 |= (1<<red3);
		IOSET1 |= (1<<red4);
		wait(3000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		

		
		// status 2
		IOCLR1 |= (1<<green1);
		IOSET1 |= (1<<yellow1);
		wait(1000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);


		// check crosswalk
		
		if (crosswalk1 == 1) {
			IO0SET |= (1<<7); // Turn ON LED
			IOCLR1 |= (1<<yellow1);
			IOSET1 |= (1<<red1);
			wait(5000);
			IO0CLR |= (1<<7); 
			IOCLR1 |= (1<<red1);
			crosswalk1 = 0;
		} else if (crosswalk2 == 1) {
			IO0SET |= (1<<8); // Turn ON LED
			IOCLR1 |= (1<<yellow1);
			IOSET1 |= (1<<red1);
			wait(5000);
			IO0CLR |= (1<<8);
			IOCLR1 |= (1<<red1);
			crosswalk2 = 0;
		} else if (crosswalk3 == 1) {
			IO0SET |= (1<<9); // Turn ON LED
			IOCLR1 |= (1<<yellow1);
			IOSET1 |= (1<<red1);
			wait(5000);
			IO0CLR |= (1<<9);
			IOCLR1 |= (1<<red1);
			crosswalk3 = 0;
		} else if (crosswalk4 == 1) {
			IO0SET |= (1<<10); // Turn ON LED
			IOCLR1 |= (1<<yellow1);
			IOSET1 |= (1<<red1);
			wait(5000);
			IO0CLR |= (1<<10);
			IOCLR1 |= (1<<red1);
			crosswalk4 = 0;
		}

		
		
		// status 3
		IOCLR1 |= (1<<yellow1);
		IOSET1 |= (1<<red1);
		IOCLR1 |= (1<<red2);
		IOSET1 |= (1<<green2);
		wait(3000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		
		
		
		
		
		// status 4
		IOCLR1 |= (1<<green2);
		IOSET1 |= (1<<yellow2);
		wait(1000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		
		
		
		// check crosswalk
		
		if (crosswalk1 == 1) {
			IO0SET |= (1<<7); // Turn ON LED
			IOCLR1 |= (1<<yellow2);
			IOSET1 |= (1<<red2);
			wait(5000);
			IO0CLR |= (1<<7);
			IOCLR1 |= (1<<red2);
			crosswalk1 = 0;
		} else if (crosswalk2 == 1) {
			IO0SET |= (1<<8); // Turn ON LED
			IOCLR1 |= (1<<yellow2);
			IOSET1 |= (1<<red2);
			wait(5000);
			IO0CLR |= (1<<8);
			IOCLR1 |= (1<<red2);
			crosswalk2 = 0;
		} else if (crosswalk3 == 1) {
			IO0SET |= (1<<9); // Turn ON LED
			IOCLR1 |= (1<<yellow2);
			IOSET1 |= (1<<red2);
			wait(5000);
			IO0CLR |= (1<<9);
			IOCLR1 |= (1<<red2);
			crosswalk3 = 0;
		} else if (crosswalk4 == 1) {
			IO0SET |= (1<<10); // Turn ON LED
			IOCLR1 |= (1<<yellow2);
			IOSET1 |= (1<<red2);
			wait(5000);
			IO0CLR |= (1<<10);
			IOCLR1 |= (1<<red2);
			crosswalk4 = 0;
		}
		
		
		
		
		// status 5
		IOCLR1 |= (1<<yellow2);
		IOSET1 |= (1<<red2);
		IOCLR1 |= (1<<red3);
		IOSET1 |= (1<<green3);
		wait(3000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);

		
		
		// status 6
		IOCLR1 |= (1<<green3);
		IOSET1 |= (1<<yellow3);
		wait(1000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		
		
		
		// check crosswalk
		
		if (crosswalk1 == 1) {
			IO0SET |= (1<<7); // Turn ON LED
			IOCLR1 |= (1<<yellow3);
			IOSET1 |= (1<<red3);
			wait(5000);
			IO0CLR |= (1<<7);
			IOCLR1 |= (1<<red3);
			crosswalk1 = 0;
		} else if (crosswalk2 == 1) {
			IO0SET |= (1<<8); // Turn ON LED
			IOCLR1 |= (1<<yellow3);
			IOSET1 |= (1<<red3);
			wait(5000);
			IO0CLR |= (1<<8);
			IOCLR1 |= (1<<red3);
			crosswalk2 = 0;
		} else if (crosswalk3 == 1) {
			IO0SET |= (1<<9); // Turn ON LED
			IOCLR1 |= (1<<yellow3);
			IOSET1 |= (1<<red3);
			wait(5000);
			IO0CLR |= (1<<9);
			IOCLR1 |= (1<<red3);
			crosswalk3 = 0;
		} else if (crosswalk4 == 1) {
			IO0SET |= (1<<10); // Turn ON LED
			IOCLR1 |= (1<<yellow3);
			IOSET1 |= (1<<red3);
			wait(5000);
			IO0CLR |= (1<<10);
			IOCLR1 |= (1<<red3);
			crosswalk4 = 0;
		}
		
		
		
		
		// status 7
		IOCLR1 |= (1<<yellow3);
		IOSET1 |= (1<<red3);
		IOCLR1 |= (1<<red4);
		IOSET1 |= (1<<green4);
		wait(3000);
		
		// check which power supply to use
		swstatus = (IOPIN0 & (1<<0));
		if (swstatus == 1) 
			IOSET1|=(1<<19);
		else
			IOCLR1|=(1<<19);	
		
		
		// status 8
		IOCLR1 |= (1<<green4);
		IOSET1 |= (1<<yellow4);
		wait(1000);
		
		// check crosswalk
		
		if (crosswalk1 == 1) {
			IO0SET |= (1<<7); // Turn ON LED
			IOCLR1 |= (1<<yellow4);
			IOSET1 |= (1<<red4);
			wait(5000);
			IO0CLR |= (1<<7);
			IOCLR1 |= (1<<red4);
			crosswalk1 = 0;
		} else if (crosswalk2 == 1) {
			IO0SET |= (1<<8); // Turn ON LED
			IOCLR1 |= (1<<yellow4);
			IOSET1 |= (1<<red4);
			wait(5000);
			IO0CLR |= (1<<8);
			IOCLR1 |= (1<<red4);
			crosswalk2 = 0;
		} else if (crosswalk3 == 1) {
			IO0SET |= (1<<9); // Turn ON LED
			IOCLR1 |= (1<<yellow4);
			IOSET1 |= (1<<red4);
			wait(5000);
			IO0CLR |= (1<<9);
			IOCLR1 |= (1<<red4);
			crosswalk3 = 0;
		} else if (crosswalk4 == 1) {
			IO0SET |= (1<<10); // Turn ON LED
			IOCLR1 |= (1<<yellow4);
			IOSET1 |= (1<<red4);
			wait(5000);
			IO0CLR |= (1<<10);
			IOCLR1 |= (1<<red4);
			crosswalk4 = 0;
		}
		
		// status 9
		IOCLR1 |= (1<<yellow4);
		
		
	}
} 

void init_ext_interrupt(void)  //Initialize Interrupt
{
  EXTMODE = (1<<2);     //Edge sensitive mode on EINT2 
  EXTPOLAR &= ~(1<<2);  //Falling Edge Sensitive
  PINSEL0 = 0x80000000; //Select Pin function P0.15 as EINT2 
  /* initialize the interrupt vector */
  VICIntSelect &= ~(1<<16);        // EINT2 selected as IRQ 16
  VICVectAddr5 = (unsigned)Ext_ISR; // address of the ISR
  VICVectCntl5 = 0x20 | 16;           
  VICIntEnable = (1<<16);           // EINT2 interrupt enabled

  EXTINT &= ~(1<<2);    //Set interrupt
}

__irq void Ext_ISR(void) // Interrupt Service Routine-ISR 
{
	IO0DIR&=~(1<<14);  // set 11-14 to input
	IO0DIR&=~(1<<13); 
	IO0DIR&=~(1<<12);
	IO0DIR&=~(1<<11);
	IO0DIR|=(1<<10);  // set 7-10 to output
	IO0DIR|=(1<<9);
	IO0DIR|=(1<<8);
	IO0DIR|=(1<<7);
	
	if (IOPIN0 & (1<<13))   // when buttons are pressed turn on crosswalks
		crosswalk3 = 1;
	if (IOPIN0 & (1<<14))
		crosswalk4 = 1;
	if (IOPIN0 & (1<<12))
		crosswalk2 = 1;
	if (IOPIN0 & (1<<11))
		crosswalk1 = 1;

 EXTINT |= (1<<2);  //clear interrupt
 VICVectAddr = 0;   // End of interrupt execution
}

