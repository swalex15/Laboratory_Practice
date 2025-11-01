#ifndef INIT_H
#define INIT_H

#include "stm32f4xx.h"
#include "stm32f429xx.h"
// второй способ подключения библиотеки - #include "../../CMSIS/Devices/STM32F4xx/Inc/STM32F429xx/stm32f429xx.h"

// *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x02UL + 0x04UL; // Включение тактирования для переферии GPIO, регистр AHB1ENR
// присваеваем значения к макросам

// #include <stdint.h>

#define RCC_AHB1ENT             *(uint32_t *)(0x40023800UL + 0x30UL)
#define RCC_GPIOB_EN            0x02UL
#define RCC_GPIOC_EN            0x04UL

//*(uint32_t *)(0x40020400UL + 0x00UL) |= 0x4000UL; // Настройка редима работы порта на выход, регистр
//*(uint32_t *)(0x40020400UL + 0x04UL) &= ~0x80UL;   // Настройка режима выхода пина PB7 на push-pull, регистр
//*(uint32_t *)(0x40020400UL + 0x08UL) |= 0x4000UL; // Настройка сокрости работы порта на среднюю, регистр OSPEED
//*(uint32_t *)(0x40020400UL + 0x18UL) |= 0x800000UL; // Предаварительное отключение светодиода, регистр BSRR
// присваеваем значения к макросам

#define GPIOB_MODER             *(uint32_t *)(0x40020400UL + 0x00UL)
#define GPIOB_OTYPER            *(uint32_t *)(0x40020400UL + 0x04UL)
#define GPIOB_OSPEEDR           *(uint32_t *)(0x40020400UL + 0x08UL)
#define GPIOB_BSRR              *(uint32_t *)(0x40020400UL + 0x18UL)

//*(uint32_t *)(0x40020800UL + 0x10UL) & 0x2000UL
//на макросы

#define GPIOC_IDR               *(uint32_t *)(0x40020800UL + 0x10UL)

#define GPIO_OUTPUT_MODE_PIN_7  0x4000UL
#define GPIO_SPEED_MEDIUM_PIN_7 0x4000UL
#define GPIO_PP_PIN_7           0x80UL
#define GPIO_PIN_SET_7          0x80UL
#define GPIO_PIN_RESET_7       0x800000UL
#define GPIO_PIN_13             0x2000UL

// универскальные маркросы (директива пред-процессора)
#define BIT_SET(REG, BIT)       ((REG) |= (BIT))
#define BIT_READ(REG, BIT)      ((REG) & (BIT))
#define BIT_CLEAR(REG, BIT)     ((REG) &= ~(BIT))

void GPIO_Init_With_Myself_Macros(void);
void GPIO_Init_CMSIS(void);

#endif