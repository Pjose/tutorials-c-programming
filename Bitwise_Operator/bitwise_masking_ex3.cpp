#include <cstdint>
#include <iostream>

int main()
{
    // Define a bunch of physical/emotional states
	constexpr std::uint8_t isHungry{   1 << 0 }; // 0000 0001
	constexpr std::uint8_t isSad{	   1 << 1 }; // 0000 0010
	constexpr std::uint8_t isMad{	   1 << 2 }; // 0000 0100
	constexpr std::uint8_t isHappy{	   1 << 3 }; // 0000 1000
	constexpr std::uint8_t isLaughing{ 1 << 4 }; // 0001 0000
	constexpr std::uint8_t isAsleep{   1 << 5 }; // 0010 0000
	constexpr std::uint8_t isDead{	   1 << 6 }; // 0100 0000
	constexpr std::uint8_t isCrying{   1 << 7 }; // 1000 0000

	std::uint8_t me{};  // all flags/options turned off to start
	me |= (isHappy | isLaughing);  // I am happy and laughing
	me &= ~isLaughing;  // I am no longer laughing

	// Query a few states
	// (we'll use static_cast<bool> to interpret the results as a boolean value)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';

	return 0;
} 
