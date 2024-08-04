#include <stdio.h>
#include <math.h>
#define ULONG_BIT sizeof(unsigned long)*8 //64
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#include <math.h>

const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

int dataSize = 0;
int linedUpDataSize = 0;

unsigned long getOnes(char numOfOnes){ //if numOfOnes==3, returns 111, if its ==8, returns 1111 1111 ...
	if(numOfOnes<1) return 0;
	unsigned long res = 1;
	for(char i = 0; i<numOfOnes-1; i++){ 
		res = res << 1;
		res = res+1;
	}
	return res;
} 

unsigned long getbits(unsigned long data[], size_t idx, size_t len){
	if(len>ULONG_BIT || len<1 || idx>dataSize*64 - 1 || idx<0) return 0;
	unsigned long theNumber;
	int i = 0;
	for(; i<dataSize; ){ //if idx is 64 or bigger, then just go to the next number
		if(idx>63){ //se for por exemplo 64
			idx-64; //idx=0
			i=i+1; //aponta para o prox elemento do array
		} else break;
	}
	printf("Indice do numero no array: %d e idx inicial: %ld . length = %ld. Somando, vai até ao idx %ld \n", i, idx, len, idx+len-1);
	
	theNumber = data[i]; //ja temos o idx apropriado para o idx inicial que queriamos
	
		
	theNumber = theNumber >> idx; //limpar todos  os numeros da direita do indice
	if((idx+len-1)>63){ //se a length for demasiado grande para o indice que temos vamos para o prox numero
		unsigned long followup = data[i+1]; //nesse caso o theNumber tem uns bits a zeros no seu lado esquerdo por preencher, que o followup vai preencher
		followup = followup  << idx;
		printf("followup(left(more significant) part from superior index): %lx \n", followup);
		theNumber = theNumber + followup;
		
	} 
	unsigned long mask = getOnes(len);
	printf("mask: %ld \n", mask);
	theNumber = theNumber & mask; //operaçao final em qualquer dos casos.
	
	return theNumber;
}

void setbits(unsigned long data[], size_t idx, size_t len, unsigned long val){
	if(len>ULONG_BIT || len<1 || idx>dataSize*64 - 1 || idx<0) return;
	unsigned long theNumber;
	int i = 0;
	for(; i<dataSize; ){ //if idx is 64 or bigger, then just go to the next number
		if(idx>63){ //se for por exemplo 64
			idx-64; //idx=0
			i=i+1; //aponta para o prox elemento do array
		} else break;
	}
	printf("Indice do numero no array: %d e idx inicial: %ld . length = %ld. Somando, vai até ao idx %ld \n", i, idx, len, idx+len-1);
	printf("Num to write: %lx \n", val);
	theNumber = data[i]; //o numero para alterar
	
	if((idx+len-1)>63){ 
		unsigned long firstHalf = val << idx; //for the current index
		unsigned long original = theNumber & getOnes(64-idx); //save the contents that will not be touched
		data[i] = firstHalf + original; //first split done
		
		printf("Next part of the next index in hexa: %lx \n", data[i+1]);
		len = len - (63-idx);
		unsigned long followup = val >> (63 - (63-idx)); //for the index
		unsigned long original2 = data[i+1] & ((getOnes(64-len))<<len); //save the contents that will not be touched(aqueles de maior peso e que length nao alcanca)
		
		data[i+1] = 0;
		printf("Next part NOW ready to receive number to set to. next index in hexa: %lx \n", original2);
		data[i+1] = followup + original2;
		
		printf("firstHalf:          %ld hexa: %lx \n", firstHalf,firstHalf);
		printf("followup(2nd and leftmost half): %ld hexa: %lx \n RESULT:\n", followup,followup);
		
		printf("Data[i] %lx \n", data[i]);
		printf("Data[i+1] %lx \n", data[i+1]);
	} else {
	unsigned long mask = getOnes(len);
	printf("mask: %ld \n", mask);
	val = val & mask;
	val = val << idx;
	
	unsigned long originalBackup = theNumber & getOnes(64-idx+len);
	data[i] = val + originalBackup;
	printf("SET BITS DONE \n");
	}
}

/* 
O conceito:
Consuante o indice, ir ao índice do array data mais apropriado. Enquanto for superior a 63, avançar para o proximo indice do array e reduzir o valor do indice dado como input
Quando se estiver no indice do array data apropriado, fazer shift para direita vezes indice que se queria localizar.
E fazer uma mask própria para o "len" que foi dado como input para fazer uma operaçao AND com o que se obteve anteiormente e filtar apenas os bits que queremos. 
Mas se esta "len" ultrapassar a dimensao total do nosso numero, entao vamos pegar no numero do proximo indice do array data, fazer shift left do seu valor vezes len que faltava processar 
e fazer uma operaçao OR(de adiçao) para juntar o que se queria
*/

void print_byte(char byte){
    printf("%s%s", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}

void print_data(unsigned long data[], size_t dataSize){
	
	printf("\nOur data array (from left(most significant) to right (most significant) bit):\n");
	printf("In hexa and binary:\n    ");
	for(char i = dataSize-1; i>=0; i--){
		unsigned long n = data[i];
		size_t mask = 0xF000000000000000; //nao consigo meter <<(ULONG_BIT-4)...
		size_t maskResult = n & mask;
		while(maskResult==0){ //skip zeros
			n = n<<4;
			maskResult = n & mask;
		}
		while(maskResult!=0){
			size_t maskResultIsolated = maskResult>>(ULONG_BIT-4);
			if(maskResultIsolated!=0) printf("  %lx  ",maskResultIsolated); 
			n = n<<4;
			maskResult = n & mask;
		}
	}
	printf("\n    ");
	unsigned char index = 0;
	for(char i = dataSize-1; i>=0; i--){
		unsigned long n = data[i];
		size_t mask = 0xF000000000000000; //nao consigo meter <<(ULONG_BIT-4)...
		size_t maskResult = n & mask;
		while(maskResult==0){ //skip zeros
			n = n<<4;
			maskResult = n & mask;
		}
		while(maskResult!=0){
			size_t maskResultIsolated = maskResult>>(ULONG_BIT-4);
			printf("%s ",bit_rep[maskResultIsolated]);
			index++;
			n = n<<4;
			maskResult = n & mask;
		}
	}
	index=index*4-1;
	printf("\nidx:");
	for(unsigned char x=index; x>0;x--){
		
		if(x/10!=0) printf("%hhu",x%10);
		else printf("%hhu",x);
		if(x%4==0 && x>0) printf(" ");
		
	}
	printf("0\n    ");
	for(unsigned char x=index; x>0;x--){
		if(x%4==0) printf(" ");
		if(x%10==0) printf("%hhu",x/10);
		else printf(" ");
	}
	printf("\n\n");
}

int main() {
	//unsigned long data[] = {0xBFFFFFECABCD1234, 0xA00000000000000C, 2, 3};
	unsigned long data[] = {0xBFFFFFECABCD1234, 0xC, 2, 3};
	dataSize = ARRAY_SIZE(data);
	print_data(data,dataSize);
	
	
	
	
	
	
	printf("\nA fazer get bits: \n");
	unsigned long getBits = getbits(data, 29, 8);
	printf("getbits(decimal): %ld hexa: %lx \n", getBits, getBits);
	
	printf("\nA fazer set bits: \n ");
	setbits(data, 32, 64,0xFFFFFFFFFFFFFFFF);
	
	printf("\n A fazer get bits: \n");
	unsigned long getBits2 = getbits(data, 32, 64);
	printf("getbits(decimal): %ld hexa: %lx \n", getBits2, getBits2);
	
	
	print_data(data,dataSize);
	
	
    return 0;
}
