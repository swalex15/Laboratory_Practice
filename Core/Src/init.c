#include "init.h"
//#include "../core/inc/init.h" - другой вид подключния файла

void GPIO_Init_With_Myself_Macros(void){
    BIT_SET(RCC_AHB1ENT, RCC_GPIOB_EN | RCC_GPIOC_EN);   // Включение тактирования для переферии GPIO, регистр AHB1ENR

BIT_SET(GPIOB_MODER, GPIO_OUTPUT_MODE_PIN_7);            // Настройка редима работы порта на выход, регистр MODER
BIT_CLEAR(GPIOB_OTYPER, GPIO_PP_PIN_7);                  // Настройка режима выхода пина PB7 на push-pull, регистр OTYPER
BIT_SET(GPIOB_OSPEEDR, GPIO_SPEED_MEDIUM_PIN_7);         // Настройка сокрости работы порта на среднюю, регистр OSPEED

BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_7);                   // Предаварительное отключение светодиода, регистр BSRR

}

void GPIO_Init_CMSIS(void){
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOGEN);

    SET_BIT(GPIOE->MODER, GPIO_MODER_MODER0_0);            // Настройка режима работы пина PE0 на выход
    SET_BIT(GIPOE->OSPEEDR, GPIO_OSPEEDR_OSPEED0_0);       // настрока скорости работы пина PE0 на среднюю скорость
    SET_BIT(GPIOE->BSRR, GPIO_BSRR_BR0);                   // Выключение светодиода на пине PE0


}