#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "lib/sysfs_gpio.h"


int main(int argc, char*argv []) {
    // get pin from command line
    if (argc < 2) {
        printf("Usage: %s <pin>\n", argv[0]);
        return 1;
    }
    int Pin = atoi(argv[1]);
    printf("Hello, raspi-gpio-c! use pin %d\n", Pin);
    SYSFS_GPIO_Export(Pin);
    SYSFS_GPIO_Direction(Pin, 1);
    SYSFS_GPIO_Write(Pin, 1);
    // sleep for some seconds
    sleep(5);
    // assert pin value is high
    assert(SYSFS_GPIO_Read(Pin) == 1);
    SYSFS_GPIO_Write(Pin, 0);
    SYSFS_GPIO_Unexport(Pin);
    return 0;
}
