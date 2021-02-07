/*
 * useful resources
 * 	* https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/15AssemblyFunctions.pdf
 *
 * Compile this with -m32 to get comparable asm output
 */
#include <stdio.h>

int asm2(int p1, int p2) {
	int b = p2;
	int a = p1;

	while (a <= 0x5fa1) {
		b += 0x1;
		a += 0xd1;
	}
	
	return b;
}

int main() {
	printf("Flag: 0x%x\n", asm2(0x4, 0x2d));

	return 0;
}
