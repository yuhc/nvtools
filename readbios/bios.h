#ifndef __BIOS_H__
#define __BIOS_H__

#include <stdint.h>

struct bios {
    uint8_t *data;
    size_t data_length;

    size_t length;
};

#endif
