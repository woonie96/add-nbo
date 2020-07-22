#ifndef ADD_HTOL_H
#define ADD_HTOL_H
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
uint32_t my_ntohl(uint32_t n) {
    uint32_t n1 = (n & 0xFF000000) >> 24; // 0x78563412 -> 0x78000000 -> 0x00000078
    uint32_t n2 = (n & 0x00FF0000) >> 8;// 0x78563412 -> 0x00560000 -> 0x00005600
    uint32_t n3 = (n & 0x0000FF00) << 8; // 0x78563412 -> 0x00003400 -> 0x00340000
    uint32_t n4 = (n & 0x000000FF) << 24; // 0x78563412 -> 0x00000012 ->0x12000000
    return (n4| n3| n2 | n1); //0x12345678
}

uint32_t filecheck(char *filename) {
    FILE *first = fopen(filename, "rb");
    if (first == NULL){ printf("[ERROR!] There is no file %s\n", filename); exit(1);}
    uint32_t first_part;
    fread(&first_part, sizeof(first_part),1, first);
    fclose(first);

    return my_ntohl(first_part);
}
#endif // ADD_HTOL_H
