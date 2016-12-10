#include <stdlib.h>

#include "bios.h"

int parse_bios(struct bios *bios) {
    bios->length = bios->data_length;
    unsigned int curpos = 0;
    unsigned int num = 0;
    int next = 0;

    do {
        uint16_t sign; // ROM signiture, must be 0x55aa
        if (bios_u16(bios, curpos, &sign)) {
bios_broken:
            bios->broken = 1;
            break;
        }

    }

}

