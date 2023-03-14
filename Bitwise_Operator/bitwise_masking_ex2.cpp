#include <cstdint>
#include <iostream>
#include <bitset>

void test_bit();
void set_bit();
void reset_bit();
void flipping_bit();
void bitset_functions();
void std_bitset_example();

int main()
{
	test_bit();
	//set_bit();
	//reset_bit();
	//flipping_bit();
	//bitset_functions();
	//std_bitset_example();

	return 0;
}

/*
Testing a bit (to see if it is on or off).
==========================================
- To determine if a bit is on or off, we use bitwise AND in conjunction with the 
bit mask for the appropriate bit.
*/
void test_bit()
{
	constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
	
	/*
	constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
	constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
	constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
	constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
	constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
	constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
	constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
	constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000
	*/

	// hex for 0000'0101 
	// 8 bits in size means room for 8 flags
	std::uint8_t flags{ 0x05 }; 

	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
}

/*
Setting a bit.
=============
- To set (turn on) a bit, we use bitwise OR equals (operator |=) in conjunction with 
the bit mask for the appropriate bit.
*/
void set_bit()
{
	constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
	
	std::uint8_t flags{ 0x05 };  // hex for 0000'0101

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
}

/*
Resetting a bit.
================
- To clear a bit (turn off), we use Bitwise AND and Bitwise NOT together:
*/
void reset_bit()
{
	constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
	
	std::uint8_t flags{ 0x05 };  // hex for 0000'0101

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags &= ~mask2; // turn off bit 2

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
}

/*
Flipping a bit.
===============
- To toggle a bit state, we use Bitwise XOR:
*/
void flipping_bit()
{
	constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
	
	std::uint8_t flags{ 0x05 };  // hex for 0000'0101
	
	std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
}

/*
Though it’s easier to use the functions (test, set, reset, and flip) to modify 
individual bits. The functions only allow you to modify individual bits. The bitwise 
operators allow you to modify multiple bits at once.
*/
void std_bitset_example()
{
	constexpr std::bitset<8> mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::bitset<8> mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::bitset<8> mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::bitset<8> mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::bitset<8> mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::bitset<8> mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::bitset<8> mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::bitset<8> mask7{ 0x80 }; // hex for 1000 0000
	
	std::bitset<8> flags{ 0x05 };  // hex for 0000'0101
	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

	flags ^= (mask1 | mask2); // flip bits 1 and 2
	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

	flags |= (mask1 | mask2); // turn bits 1 and 2 on
	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

	flags &= ~(mask1 | mask2); // turn bits 1 and 2 off
	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
}

/*
Use of std::bitset functions (test, set, reset, and flip) to modify individual bits.
*/
void bitset_functions()
{
	constexpr std::bitset<8> mask0{ 0x01 }; // hex for 0000 0001
	constexpr std::bitset<8> mask1{ 0x02 }; // hex for 0000 0010
	constexpr std::bitset<8> mask2{ 0x04 }; // hex for 0000 0100
	constexpr std::bitset<8> mask3{ 0x08 }; // hex for 0000 1000
	constexpr std::bitset<8> mask4{ 0x10 }; // hex for 0001 0000
	constexpr std::bitset<8> mask5{ 0x20 }; // hex for 0010 0000
	constexpr std::bitset<8> mask6{ 0x40 }; // hex for 0100 0000
	constexpr std::bitset<8> mask7{ 0x80 }; // hex for 1000 0000
	
	std::bitset<8> flags{ 0x05 };  // hex for 0000'0101
	
	// TEST
	std::cout << "test()\n"; 
	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	
	//SET
	//flags |= mask1; // turn on bit 1
	flags.set(1);
	std::cout << "set()\n";
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	
	//RESET
	flags.reset(1);
	std::cout << "reset()\n";
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	
	//FLIP
	flags.flip(1);
	std::cout << "flip()\n";
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
}
