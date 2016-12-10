#ifndef __BIOS_H__
#define __BIOS_H__

#include <stdint.h>

struct bios {
    uint8_t *data;
    size_t data_length;

    size_t length;
};

int parse_bios(struct bios *bios);

#define EFAULT -1

static inline int bios_u16(struct bios *bios, unsigned int offset, uint16_t *ret) {
    if (offset + 1 >= bios->length) {
        *ret = 0;
        perror("out of bios range");
        return EFAULT;
    }
    *ret = bios->data[offset] | bios->data[offset+1] << 8;
    return 0;
}

#endif
