#include "init.h"
//#include "../core/inc/init.h" - другой вид подключния файла

void GPIO_Init_With_Myself_Macros(void){
    BIT_SET(RCC_AHB1ENT, RCC_GPIOB_EN | RCC_GPIOC_EN);

}