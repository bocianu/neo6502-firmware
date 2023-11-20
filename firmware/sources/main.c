#include "hardware/gpio.h"
#include "bsp/board.h"
#include "tusb.h"
#include "memory.h"

int startVideo();
void writeCharacter(int n);

int main() {
    initmemory();
    startVideo();    
    board_init();
    tusb_init();
    init6502();
//    loop1();
}

void sync() {
    tuh_task();
}
