#include <stdint.h>

#define SIM_SCGC5       (*(uint32_t *)0x40048038UL) //system clock gating control register 5
#define PORTB_PCR18     (*(uint32_t *)0x4004A048UL) //pin control register 18
//#define PORTB_GPCLR   (*(uint32_t *)0x4004A080UL) //global pin control low register
//#define PORTB_GPCHR   (*(uint32_t *)0x4004A084UL) //global pin control high register
//#define PORTB_ISFR    (*(uint32_t *)0x4004A0A0UL) //interrupt status flag register
#define GPIOB_PDOR      (*(uint32_t *)0x400FF040UL) //port data output register
//#define GPIO_PSOR       (*(uint32_t *)0x400FF044UL) //port set output register
//#define GPIO_PCOR       (*(uint32_t *)0x400FF048UL) //port clear output register
//#define GPIO_PTOR       (*(uint32_t *)0x400FF04CUL) //port toggle output register
//#define GPIO_PDIR       (*(uint32_t *)0x400FF050UL) //port data input register
#define GPIOB_PDDR      (*(uint32_t *)0x400FF054UL) //port data direction register

void delay(uint32_t cont){
    while(cont--);
}

int main(void){
    SIM_SCGC5 = 0x00000580UL;
    PORTB_PCR18 = 0x00000100UL;
    GPIOB_PDDR = 0x00040000UL;
    GPIOB_PDOR = 0x00000000UL;
    while(1){
        GPIOB_PDOR ^= 0x00040000UL;
        delay(1000000);
    }
    return 0;
}