#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#define	ARRAY_SIZE(a) sizeof a / sizeof a[0]

char* decToBinary(int n) { 
   static char binaryNum[32]; 
   char i = 0; 
   while (n > 0) { 
        binaryNum[i] = n % 2;  // storing remainder in binary array 
        n = n / 2; 
        i++; 
    } 
	for(; i<32; i++) //fill end with missing zeros
		binaryNum[i]=0;
	
	printf("em binario: \n");
	i=31;
    for(int j = 0; j <= 31; ++j, --i){
        //binaryNum[i]=binaryNum[j]; inverter ordem, deixei como invertido para no far abaixo ser mais simples
		printf("%d ", binaryNum[j]);
	}
	printf("\n");
	return binaryNum;
} 

unsigned long get_bits(unsigned long value, int msp, int lsp){
	int decimal = value & 0b11111111111111111111111111111111;
	printf("val em decimal: %d\n", decimal);
	char* str=decToBinary(decimal);
	//printf("TESTE %d %d %d %d %d %d %d", str[0], str[1], str[2], str[3], str[4], str[5], str[6]);
	unsigned long res = 0b0;
	for(char i = lsp; i<=msp; i++){ 
		if(str[i]==1) {
			res=res<<1;						//shift para ceitar o prox bit
			res=res + 0b01;		
		} else {
			res<<1;
		}
	}
	printf("mask: %lu\n", res);
	return res;
}

unsigned long set_bits(unsigned long value, int msp, int lsp, int newvalue){
	int decimal = value & 0b11111111111111111111111111111111;
	char* str=decToBinary(decimal);
	short valbit = 0;
	for(char i = lsp; i<=msp; i++){ 
		valbit=newvalue&0b01;
		str[i]=valbit;
		newvalue=newvalue>>1;
	}
	unsigned long finalnum = 0x0;
	for(char i =0; i<31; i=i+4){
		int nibble=0b0;
		for(int j=0+i; j<=3+i; j=j+1+i){
			if(str[j]==1) {
			nibble=nibble<<1;						
			nibble=nibble + 0b01;		
			} else {
			nibble<<1;
			}
		}
		finalnum=nibble<<4;
		finalnum=nibble & 0x0F;
	}
	printf("setbits:");
	for(char i = 31; i>=0; i--){
		printf("%d ", str[i]);
		if((i)%4==0) printf("___");
	}
	return finalnum;
}

  int main(){
	printf("Valor retornado: %lu\n", get_bits(0x2AD555BC, 6, 3));
	printf("Valor retornado: %lu\n", set_bits(0x2AD555BC, 11, 8, 2));
   return 0;
}