#ifndef ADD_HTOL_H
#define ADD_HTOL_H
#include <stdint.h>
uint32_t my_ntohl(uint32_t n) {
    uint32_t n1 = (n & 0xFF000000) >> 24; // 0x78563412 -> 0x78000000 -> 0x00000078
    uint32_t n2 = (n & 0x00FF0000) >> 8;// 0x78563412 -> 0x00560000 -> 0x00005600
    uint32_t n3 = (n & 0x0000FF00) << 8; // 0x78563412 -> 0x00003400 -> 0x00340000
    uint32_t n4 = (n & 0x000000FF) << 24; // 0x78563412 -> 0x00000012 ->0x12000000
    return (n4| n3| n2 | n1); //0x12345678
}
#endif // ADD_HTOL_H
