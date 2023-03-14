#include <iostream>
#include <bitset>

int main(int argc, char** argv) {
	int a = 5;
	int result;
	std::cout << a << std::endl;
	result = a << 1;  // a * 2^1
	std::cout << result << std::endl;
	a = 10;
	result = a << 4;  // a * 2^4
	std::cout << result << std::endl;
	a = 5;
	result = a >> 1;  // a / 2^1
	std::cout << result << std::endl;
	
	//AND Operator - Bitmask (remove bits or inspect a bit)
	
	//OR Operator - Add bits
	int b = 0b101;
	int c = 0b10110;
	c <<= 4;
	int d = b | c;
	std::cout << std::bitset<9>(d) << std::endl;
	
	//NOT Operator - Useful with AND operator to toggle bits on or off
	
	//XOR Operator - Hashing (eg. set a variable to zero)
	int e = 5;
	int f = e ^ e;  //Set a variable to 0
	std::cout << f << std::endl;
	
} 
