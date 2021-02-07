#include <stdio.h>

/*
 * to get the flag, provide the array of bytes
 */
#ifndef BYTES
#warning to get the flag, provide the CTF input via -DBYTES=
#define BYTES \
	'p', 'l', 'e', 'a', 's', 'e', ' ', 'p', 'r', 'o', 'v', 'i', 'd', 'e', ' ', 'm', 'y', 'B', 'y', 't', 'e', 's'
#endif

int main() {

	char myBytes[] = { BYTES };

	printf("picoCTF{");
	for (int i=0 ; i<32; i++) {
		printf("%c", myBytes[i]);
	}
	printf("}\n");

	return 0;
}
