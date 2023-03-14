#include <bitset>
#include <iostream>

/*
SUMMARY
=======
Summarizing how to evaluate bitwise operations utilizing the column method:

When evaluating bitwise OR, if any bit in a column is 1, the result for that column is 1.
When evaluating bitwise AND, if all bits in a column are 1, the result for that column is 1.
When evaluating bitwise XOR, if there are an odd number of 1 bits in a column, the result for that column is 1.

NB:
===
There is no bitwise NOT assignment operator.

*/

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void question1();
std::bitset<4> rotl(std::bitset<4> bits);

int main()
{
    example1();
    //example2();
    //example3();
    //example4();
    //example5();
    //example6();
    //question1();

    return 0;
}

void example1()
{
	std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n';  // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n';  // shift left by 1, yielding 1000
}

void example2()
{
	unsigned int x { 0b0100 };
    x = x << 1;  // use operator<< for left shift
    std::cout << std::bitset<4>{ x } << '\n';  // use operator<< for output
}

void example3()
{
	std::bitset<4> x { 0b0110 };
	
	std::cout << x << 1 << "\n";  // print value of x (0110), then 1
	std::cout << (x << 1) << "\n";  // print x left shifted by 1 (1100)
}

void example4()
{
	std::cout << ~std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8>{ 0b0100 } << '\n';
}

void example5()
{
	std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0001 } & std::bitset<4>{ 0b0011 } & std::bitset<4>{ 0b0111 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0110 } ^ std::bitset<4>{ 0b0011 }) << '\n';
	std::cout << (std::bitset<4>{ 0b0001 } ^ std::bitset<4>{ 0b0011 } ^ std::bitset<4>{ 0b0111 }) << '\n';
}

void example6()
{
	std::bitset<4> bits { 0b0100 };
    bits >>= 1;
    std::cout << bits << '\n';
    // There is no bitwise NOT assignment operator. x ~= x 
	// Bitwise NOT is unary not binary like the others
    bits = ~bits;
    std::cout << bits << '\n';
    
    bits <<= 1;
    std::cout << bits << '\n';
}

/*
Question #1
===========
A bitwise rotation is like a bitwise shift, except that any bits shifted off one end 
are added back to the other end. 
For example 0b1001u << 1 would be 0b0010u, but a left rotate by 1 would result in 
0b0011u instead. 
Implement a function that does a left rotate on a std::bitset<4>. 
For this one, it’s okay to use test() and set().
*/
void question1()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';
}

std::bitset<4> rotl(std::bitset<4> bits)
{
	const bool leftbit{ bits.test(3) };

	bits <<= 1; // do left shift

	if (leftbit)
		bits.set(0);

	return bits;
}
/*
// Rotate left but don’t use the test and set functions.
std::bitset<4> rotl(std::bitset<4> bits)
{
	// bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits<<1) | (bits>>3);
}
*/
