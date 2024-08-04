#include <stdio.h>
#include <stdlib.h> //in order to use malloc
#include <string.h> //for strcat
typedef struct block { 
	size_t size;
	char *data;
} Block;

typedef struct stream { 
    size_t n_blocks;
	Block **blocks;
} Stream;

size_t stream_read(Stream *stream, size_t offset, size_t size, char *buffer){
	if(offset>=(stream->n_blocks)) return -1; // 0, 1, 2 (size=3) offset max = 2
	size_t sizeUsed = 0;
	Block currentBlock;
	while(offset<(stream->n_blocks)){
		currentBlock = **(stream->blocks);
		if((sizeUsed+currentBlock.size)>size) return 0;

		sizeUsed += currentBlock.size;
		strcat(buffer, currentBlock.data);

		(*stream->blocks)++;
		offset++;
	}
	buffer[size-1] = '\0';
	return 1;
}

int main(){
	Block* blocks = malloc(2 * sizeof(Block));

	Block one = {
		one.size = 5,
		one.data = "ola1 "
	};

	Block two;
	two.size = 5;
	two.data = "ola22";

	*blocks = one;
	blocks[1] = two;

	Stream myStream = {
		myStream.n_blocks = 2,
		myStream.blocks = &blocks
	};

	char buffer[10] = "";
	char status = stream_read(&myStream, 0, 10, buffer);
	printf("Status: %hhu\n", status);
	printf("Result: %s\n", buffer);

	//-------------------Test of when buffer is smaller than contents in stream -----------------------------

	Block one1 = {
		one1.size = 5,
		one1.data = "ola1 "
	};

	Block two2;
	two2.size = 6;
	two2.data = "ola22_";

	*blocks = one1;
	blocks[1] = two2;

	Stream myStream2 = {
		myStream2.n_blocks = 2,
		myStream2.blocks = &blocks
	};

	char buffer2[10] = "";
	char status2 = stream_read(&myStream2, 0, 10, buffer2);
	printf("Status: %hhu\n", status2);
	printf("Result: %s\n", buffer2);

	return 0;
}
