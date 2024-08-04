#include <stdio.h>

void out_float(float f){ //extra method to print info
  size_t size = sizeof(f);
  unsigned char * p = (unsigned char *) &f;
  p += size-1;
  while (size--) {
    int n;
    for (n=0; n<8; n++) {
      if(n==1) putchar(' ');
      putchar('0' + (*p & 128 ? 1 : 0));  
      *p <<= 1;
    }
    p--;
  }
  printf("\n");
}

int round_to_int(float value) {
  char buffer[33];
  char* pBuffer = buffer;
  unsigned char pos = 0;
  
  size_t size = sizeof(value);
  unsigned char * p = (unsigned char *) &value;
  p += size-1;
  while (size--) {
      int n;
      for (n=0; n<8; n++) {
          buffer[pos++] = *p & 128 ? 1 : 0;
          *p <<= 1;
      }
      p--;
  }

  unsigned char isNegative = buffer[0];
  unsigned char mult = buffer[1]; //if mult = 0, then the float is between ]-2, +2[
  unsigned char isZero = buffer[2];
  pos = 2;

  if(!isNegative && !mult && !isZero) return 0;
  
  int result = 0;
  char index = 6;

  if(mult==1){
    while(pos!=9){
      if(buffer[pos]==1) {
        result = result + (1 << index);
      }
    index--;
    pos++;
    }
    char indexOfBitOfZeroDot5 = result;
    result = (1 << result+1); //pow version -> pow(2,result+1);

 
    while(indexOfBitOfZeroDot5!=-1){
      if(buffer[pos]==1) {
        result = result + (1 << indexOfBitOfZeroDot5);// pow version -> pow(2,indexOfBitOfZeroDot5);
      }
      indexOfBitOfZeroDot5--;
      pos++;
    }

    char round = 0;
    if(buffer[pos]==1) round++;
    if(isNegative) {
      result = 0 - result;
      result = result - round;
      return result;
    }
    return result+round;


  } else { //mult = 0, float is between ]-2, 2[
    if(buffer[8]==1 && buffer[9]==1) { //when mult = 0, this condition is always true for ]-2, -1.5] and [1.5, 2[
      if(isNegative) return -2;
      return 2;
    } else if(buffer[3]==1 && buffer[4]==1 && buffer[5]==1 && buffer[6]==1 && buffer[7]==1){ //then float is between ]-1.5, 0[ or ]0, 1.5[
        if(isNegative) return -1;
        return 1;
      } 
      else return 0;
  }
}

int main(){

  float a1 = -118.625;
  printf("%f -> %d |", a1, round_to_int(a1)); out_float(a1); 

  float a2 = -100.5;
  printf("%f -> %d |", a2, round_to_int(a2)); out_float(a2); 

  float a3 = -50.5;
  printf("%f -> %d   |", a3, round_to_int(a3)); out_float(a3); 

  float a4 = -50.0;
  printf("%f -> %d   |", a4, round_to_int(a4)); out_float(a4); 

  float a5 = -3.5;
  printf("%f -> %d     |", a5, round_to_int(a5)); out_float(a5); 

  float a6 = -3.0;
  printf("%f -> %d     |", a6, round_to_int(a6)); out_float(a6); 

  float a7 = -2.5;
  printf("%f -> %d     |", a7, round_to_int(a7)); out_float(a7); 

  float a8 = -2.3;
  printf("%f -> %d     |", a8, round_to_int(a8)); out_float(a8); 

  float a9 = -2.0;
  printf("%f -> %d     |", a9, round_to_int(a9)); out_float(a9); 

  float a10 = -1.8;
  printf("%f -> %d     |", a10, round_to_int(a10)); out_float(a10); 

  float a11 = -1.5;
  printf("%f -> %d     |", a11, round_to_int(a11)); out_float(a11); 

  float a12 = -1.3;
  printf("%f -> %d     |", a12, round_to_int(a12)); out_float(a12); 

  float a13 = -1.25;
  printf("%f -> %d     |", a13, round_to_int(a13)); out_float(a13); 

  float a14 = -1.0;
  printf("%f -> %d     |", a14, round_to_int(a14)); out_float(a14); 

  float a15 = -0.8;
  printf("%f -> %d     |", a15, round_to_int(a15)); out_float(a15); 
  
  float a16 = -0.5;
  printf("%f -> %d     |", a16, round_to_int(a16)); out_float(a16); 

  float a17 = -0.25;
  printf("%f -> %d      |", a17, round_to_int(a17)); out_float(a17); 

  float a18 = -0.125;
  printf("%f -> %d      |", a18, round_to_int(a18)); out_float(a18); 

  float a19 = 0.0;
  printf("%f -> %d       |", a19, round_to_int(a19)); out_float(a19); 

  float a20 = 0.125;
  printf("%f -> %d       |", a20, round_to_int(a20)); out_float(a20); 

  float a21 = 0.25;
  printf("%f -> %d       |", a21, round_to_int(a21)); out_float(a21); 

  float a22 = 0.5;
  printf("%f -> %d       |", a22, round_to_int(a22)); out_float(a22); 

  float a23 = 1.0;
  printf("%f -> %d       |", a23, round_to_int(a23)); out_float(a23); 

  float a24 = 1.3;
  printf("%f -> %d       |", a24, round_to_int(a24)); out_float(a24); 

  float a25 = 1.5;
  printf("%f -> %d       |", a25, round_to_int(a25)); out_float(a25); 

  float a26 = 1.7;
  printf("%f -> %d       |", a26, round_to_int(a26)); out_float(a26); 

  float a27 = 2.0;
  printf("%f -> %d       |", a27, round_to_int(a27)); out_float(a27); 

  float a28 = 2.5;
  printf("%f -> %d       |", a28, round_to_int(a28)); out_float(a28); 

  float a29 = 4.0;
  printf("%f -> %d       |", a29, round_to_int(a29)); out_float(a29); 

  float a30 = 4.5;
  printf("%f -> %d       |", a30, round_to_int(a30)); out_float(a30); 

  float a31 = 8.0;
  printf("%f -> %d       |", a31, round_to_int(a31)); out_float(a31); 

  float a32 = 8.5;
  printf("%f -> %d       |", a32, round_to_int(a32)); out_float(a32); 

  float a33 = 9.0;
  printf("%f -> %d       |", a33, round_to_int(a33)); out_float(a33); 

  float a34 = 9.5;
  printf("%f -> %d      |", a34, round_to_int(a34)); out_float(a34); 

  float a35 = 10.0;
  printf("%f -> %d     |", a35, round_to_int(a35)); out_float(a35); 

  float a36 = 11.0;
  printf("%f -> %d     |", a36, round_to_int(a36)); out_float(a36); 

  float a37 = 11.0245;
  printf("%f -> %d     |", a37, round_to_int(a37)); out_float(a37); 

  float a38 = 11.5;
  printf("%f -> %d     |", a38, round_to_int(a38)); out_float(a38); 

  float a39 = 11.85;
  printf("%f -> %d     |", a39, round_to_int(a39)); out_float(a39); 

  float a40 = 12.0;
  printf("%f -> %d     |", a40, round_to_int(a40)); out_float(a40); 

  float a41 = 13.0;
  printf("%f -> %d     |", a41, round_to_int(a41)); out_float(a41); 

  float a42 = 14.0;
  printf("%f -> %d     |", a42, round_to_int(a42)); out_float(a42); 

  float a43 = 14.5;
  printf("%f -> %d     |", a43, round_to_int(a43)); out_float(a43); 

  float a44 = 15.0;
  printf("%f -> %d     |", a44, round_to_int(a44)); out_float(a44); 

  float a45 = 15.5;
  printf("%f -> %d     |", a45, round_to_int(a45)); out_float(a45); 

  float a46 = 16.0;
  printf("%f -> %d     |", a46, round_to_int(a46)); out_float(a46); 

  float a47 = 16.03125;
  printf("%f -> %d     |", a47, round_to_int(a47)); out_float(a47); 

  float a48 = 16.0625;
  printf("%f -> %d     |", a48, round_to_int(a48)); out_float(a48); 

  float a49 = 16.125;
  printf("%f -> %d     |", a49, round_to_int(a49)); out_float(a49); 

  float a50 = 16.25;
  printf("%f -> %d     |", a50, round_to_int(a50)); out_float(a50); 

  float a51 = 16.5;
  printf("%f -> %d     |", a51, round_to_int(a51)); out_float(a51); 

  float a52 = 16.75;
  printf("%f -> %d     |", a52, round_to_int(a52)); out_float(a52); 

  float a53 = 17.0;
  printf("%f -> %d     |", a53, round_to_int(a53)); out_float(a53); 

  float a54 = 17.5;
  printf("%f -> %d     |", a54, round_to_int(a54)); out_float(a54); 

  float a55 = 23.4;
  printf("%f -> %d     |", a55, round_to_int(a55)); out_float(a55); 

  float a56 = 25.5;
  printf("%f -> %d     |", a56, round_to_int(a56)); out_float(a56); 

  float a57 = 32.0;
  printf("%f -> %d     |", a57, round_to_int(a57)); out_float(a57); 

  float a58 = 32.25;
  printf("%f -> %d     |", a58, round_to_int(a58)); out_float(a58); 

  float a59 = 32.5;
  printf("%f -> %d     |", a59, round_to_int(a59)); out_float(a59); 

  float a60 = 32.75;
  printf("%f -> %d     |", a60, round_to_int(a60)); out_float(a60); 

  float a61 = 50.0;
  printf("%f -> %d     |", a61, round_to_int(a61)); out_float(a61); 

  float a62 = 50.5;
  printf("%f -> %d     |", a62, round_to_int(a62)); out_float(a62); 

  float a63 = 63.0;
  printf("%f -> %d     |", a63, round_to_int(a63)); out_float(a63); 

  float a64 = 63.5;
  printf("%f -> %d     |", a64, round_to_int(a64)); out_float(a64); 

  float a65 = 64.0;
  printf("%f -> %d     |", a65, round_to_int(a65)); out_float(a65); 

  float a66 = 64.5;
  printf("%f -> %d     |", a66, round_to_int(a66)); out_float(a66); 

  float a67 = 128.0;
  printf("%f -> %d   |", a67, round_to_int(a67)); out_float(a67); 

  float a68 = 128.5;
  printf("%f -> %d   |", a68, round_to_int(a68)); out_float(a68); 

  float a69 = 256.0;
  printf("%f -> %d   |", a69, round_to_int(a69)); out_float(a69); 

  float a70 = 268.8;
  printf("%f -> %d   |", a70, round_to_int(a70)); out_float(a70); 

  float a71 = 2777.89;
  printf("%f -> %d |", a71, round_to_int(a71)); out_float(a71); 

  float a72 = 2777.223;
  printf("%f -> %d |", a72, round_to_int(a72)); out_float(a72); 

  return 0;
}

/*
What Is a Floating-point Operation?
A floating-point operation is any mathematical operation such as +, -, *, /
https://developer.arm.com/documentation/ka004288/latest

Also, cannot use (int) value. 

https://www.codeproject.com/Questions/678447/Can-any-one-tell-me-how-to-convert-a-float-to-bina

https://it.wikipedia.org/wiki/IEEE_754
*/