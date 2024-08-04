#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

#define FLOATING_POINT_DIVIDER ','
#define EXPONENT_BIT_CONSTANT 127
#define INT_HIGH 0x40000000
#define MANTISSA_MAX_BITS 23
#define MANTISSA_BITS 0x7FFFFF
#define MANTISSA_HIGHER_BIT_VALUE 0x400000

struct ftype {
    unsigned m : 23;
    unsigned e : 8;
    unsigned s : 1;
};

union number {
    float f;
    struct ftype bits;
};

float string_to_float(char *string) {
    int comma = 0, len = strlen(string); //encontrar a virgula
    for (; comma < len && string[comma] != FLOATING_POINT_DIVIDER; ++comma);
    uint8_t is_negative = string[0] == '-';
    unsigned int integer_part = 0, decimal_part = 0; // convert de inteiro e decimal para int
    for (int i = is_negative; i < comma; ++i) {
        char digit = string[i];
        if (digit < '0' || digit > '9')
            return 0;

        integer_part *= 10;
        integer_part += digit - '0';
    }

    int mantissa_sbb = 1;
    for (int i = comma + 1; i < len; ++i) {
        char digit = string[i];
        if (digit < '0' || digit > '9')
            return 0;

        mantissa_sbb *= 10;
        decimal_part *= 10;
        decimal_part += digit - '0';
    }

    if (integer_part == 0 && decimal_part == 0)
        return 0;

    uint32_t mantissa = 0; // calcular a mantissa
    for (int i = 0; i < MANTISSA_MAX_BITS; ++i) {
        mantissa <<= 1;
        decimal_part *= 2;
        if (decimal_part >= mantissa_sbb) {
            decimal_part -= mantissa_sbb;
            mantissa |= 1;
        }
    }

    int exp = 0, error = 0;						//encontrar o expoente						
    if (integer_part == 0) {
        //significa que a parte decimaç é diferente de 0, logo o expoente é negativo
        exp = -1;
        for (int i = MANTISSA_HIGHER_BIT_VALUE; !(i & mantissa); i >>= 1, --exp);
        for (int i = 0; i < -exp + 1; ++i) {
            mantissa <<= 1;
            decimal_part *= 2;
            if (decimal_part >= mantissa_sbb) {
                decimal_part -= mantissa_sbb;
                mantissa |= 1;
            }
        }

        error = mantissa & 1;
        mantissa >>= 1;
        mantissa &= MANTISSA_BITS;
    } else {//integer_part != 0 -> expoente positivo
        int i = INT_HIGH;  //encontrar o mais significativo
        for (; !(i & integer_part); i >>= 1);
        for (int j = 1; j < i; j *= 2, ++exp);// apenas se afeta a mantissa se o expoente>0
        if (exp > 0) {// cortar o MSO off e meter os bits restantes
            mantissa >>= exp - 1; // salvar o bit de erro, para arredondar
            error = mantissa & 1;
            mantissa >>= 1;
            mantissa |= ((integer_part & ~i) << (MANTISSA_MAX_BITS - exp));
        }
    }

    // IEEE 754 (single point precision): 
    // [sign 1-bit][exponent 8-bits][mantissa 23-bits]
    union number num;
    num.bits.s = is_negative;
    num.bits.e = EXPONENT_BIT_CONSTANT + exp;
    num.bits.m = mantissa + error;
    return num.f;
}

int main(int argc, char *argv[]) {
    if (argc < 2) printf("Valor: \ne.g. ./stringtofloat 23,23\n");
    else printf("Formato em float: %f\n", string_to_float(argv[1]));
    return 0;
}  