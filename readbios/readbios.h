#ifndef __READBIOS_H__
#define __READBIOS_H__

#include <stdio.h>
#include <stdint.h>

int read_vbios(const char *filename, uint8_t **vbios, size_t *length);

#endif
