#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include "add_htol.h"



int main(int argc, char* argv[]){

    uint32_t first_part = filecheck(argv[1]);
    uint32_t second_part = filecheck(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",first_part,first_part, second_part,  second_part,  first_part+second_part, first_part+second_part); //print result of sum


    return 0;
}
