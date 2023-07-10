#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void DefaultHandler(void){
    while(1);
}

void ResetHandler(void){
    uint32_t *psrc = &_sidata;
    uint32_t *pdst = &_sdata;
    while(pdst < &_edata){
        *pdst = *psrc;
        ++psrc;
        ++pdst;
    }
    pdst = &_sbss;
    while(pdst < &_ebss){
        *pdst = 0;
        ++pdst;
    }
    main();
    while(1);
}

uint32_t vectorTable[] __attribute__((section(".isrVector"))) = {
    (uint32_t)&_estack,             //initial start pointer
    (uint32_t)&ResetHandler,        //initial program counter
    (uint32_t)&DefaultHandler,      //non-maskable interrupt
    (uint32_t)&DefaultHandler,      //hard fault
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)&DefaultHandler,      //Supervisor call
    (uint32_t)0,                    //...
    (uint32_t)0,                    //...
    (uint32_t)&DefaultHandler,      //pendable request for system service
    (uint32_t)&DefaultHandler,      //system tick timer
    (uint32_t)&DefaultHandler,      //DMA channel 0 transfer complete and error
    (uint32_t)&DefaultHandler,      //DMA channel 1 transfer complete and error
    (uint32_t)&DefaultHandler,      //DMA channel 2 transfer complete and error
    (uint32_t)&DefaultHandler,      //DMA channel 3 transfer complete and error
    (uint32_t)0,                    //...
    (uint32_t)&DefaultHandler,      //command complete and read collision
    (uint32_t)&DefaultHandler,      //Low voltage detect, low voltage wrnning
    (uint32_t)&DefaultHandler,      //Low leakage wakeup
    (uint32_t)&DefaultHandler,      //I2C 0
    (uint32_t)&DefaultHandler,      //I2C 1
    (uint32_t)&DefaultHandler,      //Single interrupt vector for all sources (SPI 0)
    (uint32_t)&DefaultHandler,      //Single interrupt vector for all sources (SPI 1)
    (uint32_t)&DefaultHandler,      //Status and error (UART 0)
    (uint32_t)&DefaultHandler,      //Status and error (UART 1)
    (uint32_t)&DefaultHandler,      //Status and error (UART 2)
    (uint32_t)&DefaultHandler,      //ADC 0
    (uint32_t)&DefaultHandler,      //CMP 0
    (uint32_t)&DefaultHandler,      //TPM 0
    (uint32_t)&DefaultHandler,      //TPM 1
    (uint32_t)&DefaultHandler,      //TPM 2
    (uint32_t)&DefaultHandler,      //Alarm interrupt (RTC)
    (uint32_t)&DefaultHandler,      //Seconds interrupt (RTC)
    (uint32_t)&DefaultHandler,      //Single interrupt vector for all channels (PIT)
    (uint32_t)0,                    //...
    (uint32_t)&DefaultHandler,      //USB OTG
    (uint32_t)&DefaultHandler,      //DAC 0
    (uint32_t)&DefaultHandler,      //TSI 0
    (uint32_t)&DefaultHandler,      //MCG
    (uint32_t)&DefaultHandler,      //LPTMR 0
    (uint32_t)0,                    //...
    (uint32_t)&DefaultHandler,      //Pin detect (Port A) port control module
    (uint32_t)&DefaultHandler       //Pin detect (Port D) port control module
};