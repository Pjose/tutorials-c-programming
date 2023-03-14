#include <iostream>
using namespace std;
/*
Bit Masking - Achieved by using Bitwise operators - AND, OR, and XOR
ANDing: Extract a subset of the bits in the value.
 ORing: Set a subset of the bits in the value.
XORing: Toggle a subset of the bits in the value. 
*/

void more_stuff(uint32_t value) {                   // Example value: 0x01020304
	printf("\nvalue = %i", value);
	
    uint32_t byte1 = (value >> 24);                 // 0x01020304 >> 24 is 0x01 so
    printf("\n(value >> 24) = %i", byte1);         // no masking is necessary
    
    uint32_t byte2 = (value >> 16) & 0xff;          // 0x01020304 >> 16 is 0x0102 so
    printf("\n(value >> 16) & 0xff = %i", byte2);  // we must mask to get 0x02
    
    uint32_t byte3 = (value >> 8)  & 0xff;          // 0x01020304 >> 8 is 0x010203 so
    printf("\n(value >> 8)  & 0xff = %i", byte3);  // we must mask to get 0x03
    
    uint32_t byte4 = value & 0xff;                  // here we only mask, no shifting
    printf("\nvalue & 0xff = %i", byte4);          // is necessary
}

int main()
{
	int value = 0x04030201;  //32 bit number
	
	//Shifting Bytes from value from MSB to LSB
	int a = (value >> 24);  // 04 (bits 24-31) MSB
	int b = (value >> 16);  // 03 (bits 16-23)
	int c = (value >> 8) ;  // 02 (bits 8-15)
	int d = value        ;  // 01 (bits 0-7)   LSB
	
	printf("\na = %x", a);
	printf("\nb = %x", b);
	printf("\nc = %x", c);
	printf("\nd = %x", d);
	
	//Extracting each Byte from value from MSB to LSB
	a = (value >> 24) & 0xff;  // 04 (bits 24-31) MSB
	b = (value >> 16) & 0xff;  // 03 (bits 16-23)
	c = (value >> 8)  & 0xff;  // 02 (bits 8-15)
	d = value         & 0xff;  // 01 (bits 0-7)   LSB
	
	printf("\na = %x", a);
	printf("\nb = %x", b);
	printf("\nc = %x", c);
	printf("\nd = %x", d);
	
	more_stuff(0x01020304);
	
	return 0;
}

