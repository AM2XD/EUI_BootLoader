
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/flash.h"
#include "driverlib/interrupt.h"
#include "bootloader.h"







int main(void)
{

    /*pointer to read data from flash*/
    uint32_t* flag_pointer =  (uint32_t*)FLAG_APP_START;
    uint32_t flag_counter = 0;

    while(1)
    {
        /*check if there is an update pending*/
        check_update(10000);
        if(flag_pointer[0] == 0){
            jump_to_app(APP_START_1);
        }
        else if(flag_pointer[0] ==1){
            jump_to_app(APP_START_2);
        }
    }


}



//
//// Enable GPIOF clock
////    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
////    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
////    // Set push buttons pins as input (PF0,PF4)
////    GPIOPinTypeGPIOInput(SWBASE, SW1 | SW2);
////    // Enable pullup resistors on PF0,PF4
////    GPIOPadConfigSet(SWBASE,SW1 | SW2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
//
//
///*wait for downloading a version*/
//SysCtlDelay(50000000);
//
//
//
///*no application is present so flash it*/
//FlashErase(FLASH_APP_START_1);
//FlashProgram(myData,FLASH_APP_START_1,sizeof(myData));
///*increase flag by 1*/
//flag_counter = flag_pointer[0] + 1;
//FlashErase(FLAG_APP_START);
//FlashProgram(&flag_counter,FLAG_APP_START,sizeof(flag_counter));
//
//switch(flag_pointer[0])
//{
//case 0x00:
//{
//    /*there is a valid application in that address 1 jump to it*/
//    jump2app(FLASH_APP_START_1);
//}break;
//case 0x01:
//{
//    /*there is a valid application in that address 2 jump to it*/
//    jump2app(FLASH_APP_START_2);
//}break;
//case 0x02:
//{
//    /*change the flag to restart from 1 */
//    flag_counter = 0;
//    FlashErase(FLAG_APP_START);
//    FlashProgram(&flag_counter,FLAG_APP_START,sizeof(flag_counter));
//
//    /*a new version is now in 1 go back to 1*/
//    jump2app(FLASH_APP_START_1);
//
//}break;
//default:
//    break;
//}
//
//
//
//
//
//while (1) {
//
//    /*check if there is an update pending*/
//    if (checkUpdata(5))
//    {
//        update();
//    }
//    else
//    {
//        if(flag == 0){
//            jump2app(1);
//        }
//        else if(flage ==1){
//            jump2app(2);
//        }
//    }
//
//
//
//
//}
//
