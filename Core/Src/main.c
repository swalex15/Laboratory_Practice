#include "init.h"

#define RCC_EN *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x02UL + 0x04UL;


int main(void)
{
  GPIO_Init_With_Myself_Macros();
  GPIO_Init_CMSIS();
    
 //   RCC_EN;
 //   *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x02UL + 0x04UL; // Включение тактирования для переферии GPIO, регистр AHB1ENR

 //   *(uint32_t *)(0x40020400UL + 0x00UL) |= 0x4000UL; // Настройка редима работы порта на выход, регистр MODER
 //   *(uint32_t *)(0x40020400UL + 0x04UL) &= ~0x80UL;   // Настройка режима выхода пина PB7 на push-pull, регистр OTYPER
 //   *(uint32_t *)(0x40020400UL + 0x08UL) |= 0x4000UL; // Настройка сокрости работы порта на среднюю, регистр OSPEED

 //   *(uint32_t *)(0x40020400UL + 0x18UL) |= 0x800000UL; // Предаварительное отключение светодиода, регистр BSRR

    while (1)   
    {
 //         if (*(uint32_t *)(0x40020800UL + 0x10UL) & 0x2000UL)
        /*---Чтение кнопки с помощью CMSIS---*/
        if(READ_BIT(GPIOG->IDR, GPIO_IDR_ID0)){
            SET_BIT(GPIOE->BSRR, GPIO_BSRR_BR0); // Включение светододов PE0
            }
        else{
            SET_BIT(GPIOE->BSRR, GPIO_BSRR_BR0);  // Отключение светододов PE0
        }    

        /*---Чтение кнопки с помощью собственных макросов---*/
        if(BIT_READ(GPIOC_IDR, GPIO_PIN_13)){
 //           *(uint32_t *)(0x40020400UL + 0x18UL) |= 0x80UL; // Влючение светодиода, регистр BSRR
            BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_7); // Включение светододов PB7, регистр BSRR
         }
         else
         {
//             *(uint32_t *)(0x40020400UL + 0x18UL) |= 0x800000UL; // Отключение светодиода, регистр BSRR
            BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_7);// Отключение светододов PB7, регистр BSRR
         }
    }
}