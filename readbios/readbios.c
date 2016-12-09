#include <stdlib.h>

#include "readbios.h"
#include "bios.h"

struct bios *bios;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [bios.rom]\n", argv[0]);
        return 0;
    }

    bios = (struct bios *)malloc(sizeof(struct bios));
    if (read_vbios(argv[1], &bios->data, &bios->data_length)) {
        perror("read_vbios");
        return 1;
    }

    return 0;
}

int read_vbios(const char *filename, uint8_t **vbios, size_t *length) {
    FILE *fd_bios;

    *vbios = NULL;
    *length = 0;

    /* open file */
    fd_bios = fopen(filename, "rb");
    if (!fd_bios) {
        perror("fopen");
        return 1;
    }

    /* get size */
    fseek(fd_bios, 0, SEEK_END);
    *length = ftell(fd_bios);
    fseek(fd_bios, 0, SEEK_SET);
    if (*length <= 0) {
        perror("fseek");
        return 1;
    }

    /* read vbios */
    *vbios = malloc(*length * sizeof(char));
    if (!*vbios) {
        perror("malloc");
        return 1;
    }
    if (fread(*vbios, 1, *length, fd_bios) < *length) {
        free(*vbios);
        perror("fread");
        return 1;
    }

    if (fclose(fd_bios)) {
        free(*vbios);
        perror("fclose");
        return 1;
    }

    return 0;
}
