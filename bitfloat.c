#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include<stdint.h>

// Return the bit value (0 or 1) at position pos of unsigned int n
// Note that the least significant bit position is 0. 
int get_bit_at_pos(unsigned int n, int pos)
{
	return 1 & (n >> pos);
}

// Set the bit value to 1 at position pos of unsigned int n,
// while leaving other bits unchanged. 
// Return the changed integer.
// Note that the least significant bit position is 0. 
int set_bit_at_pos(unsigned int n, int pos)
{
	return (1 << pos) | n;
}

// Return the most significant byte of unsigned int n
char get_most_significant_byte(unsigned int n)
{
	return (char)(n >> 24);
}

// Return true if n1+n2 causes overflow, return false otherwise
bool sum_overflowed(int n1, int n2)
{
	int sum = n1 + n2;
	if(n1 > 0 && n2 > 0 && sum < 0)
		return true;
	else if(n1 < 0 && n2 < 0 && sum > 0)
		return true;
	else
		return false;;
}

//Extract the 8-bit exponent field of single precision floating point number f 
//and return it as an unsigned byte
unsigned char get_exponent_field(float f) 
{
	uint32_t *ptr = (uint32_t *)&f;
	return (unsigned char)((*ptr >> 23) & 255);
}

