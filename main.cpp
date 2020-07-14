#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include "add_htol.h"



int main(int argc, char* argv[]){
    FILE *first = fopen(argv[1], "rb"); //open first binary file as first
    FILE *second = fopen(argv[2], "rb"); //open second binary file as second

    uint32_t first_part;
    uint32_t second_part;

    fread(&first_part, sizeof(first_part),1, first); //read first and save to first_part
    fread(&second_part, sizeof (second_part), 1, second); //read second and save to second_part

    first_part = my_ntohl(first_part); //little endian to big endian
    second_part = my_ntohl(second_part); //little endian to big endian
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",first_part,first_part, second_part,  second_part,  first_part+second_part, first_part+second_part); //print result of sum


    fclose(second); //close second
    fclose(first); //close first

    return 0;
}
