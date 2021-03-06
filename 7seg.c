/*
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_ssp.h"
#include "lpc17xx_i2c.h"
#include "lpc17xx_spi.h"
#include "LPC17xx.h"

#include "rgb.h"
#include "temp.h"
#include "led7seg.h"

//init for buttons
static void init_GPIO(void)
{

	// Initialize button SW4 and SW3
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 0;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 2;
	PinCfg.Pinnum = 10;
	PINSEL_ConfigPin(&PinCfg);
	GPIO_SetDir(2, 1<<10, 0);

	PINSEL_CFG_Type PinCfg2;
	PinCfg2.Funcnum = 0;
	PinCfg2.OpenDrain = 0;
	PinCfg2.Pinmode = 0;
	PinCfg2.Portnum = 1;
	PinCfg.Pinnum = 31;
	PINSEL_ConfigPin(&PinCfg2);
	GPIO_SetDir(1, 1<<31, 0);

}

//init for ssp(7 segment uses SPI/SSP)
static void init_ssp(void)
{
	SSP_CFG_Type SSP_ConfigStruct;
	PINSEL_CFG_Type PinCfg;

	/*
	 * Initialize SPI pin connect
	 * P0.7 - SCK;
	 * P0.8 - MISO
	 * P0.9 - MOSI
	 * P2.2 - SSEL - used as GPIO

	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 7;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 8;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 9;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Funcnum = 0;
	PinCfg.Portnum = 2;
	PinCfg.Pinnum = 2;
	PINSEL_ConfigPin(&PinCfg);

	SSP_ConfigStructInit(&SSP_ConfigStruct);

	// Initialize SSP peripheral with parameter given in structure above
	SSP_Init(LPC_SSP1, &SSP_ConfigStruct);

	// Enable SSP peripheral
	SSP_Cmd(LPC_SSP1, ENABLE);

}

int main (void) {

    uint8_t btn1 = 1;
    uint8_t btn2 = 1;

    init_GPIO();
    rgb_init();
    init_ssp();
    //init_spi();
    led7seg_init();

    while (1)
    {
    	btn1 = (GPIO_ReadValue(2) >> 10) & 0x01;
    	btn2 = (GPIO_ReadValue(1) >> 31) & 0x01;
        if (btn1 == 0 && btn2==0)
        {
        	GPIO_ClearValue(2,1);
            GPIO_SetValue(0,1<<26);

            led7seg_setChar(0x24, TRUE); //display 0, secondary value always set to TRUE
        } else {
        	GPIO_ClearValue(0, (1<<26));
        	GPIO_SetValue(2,1);
            led7seg_setChar(0xFF, TRUE);
        }
    }
} */
