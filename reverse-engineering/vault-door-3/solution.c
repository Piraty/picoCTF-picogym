#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * to get the flag, provide the mutated buffer as found in the java code
 * and compile like this: clang -DCTF_BUFFER=\"foo bar\" -o solution solution.c
 */
#ifndef CTF_BUFFER
#warning to get the flag, provide the CTF input via -DCTF_BUFFER="foo"
#endif

/*
 * re-implement the java stuff
 */
void pwd_gen_buffer(char *password, char *buffer) {
	size_t i; 

	// initialize
	for (i=0 ; i<32; i++)
		buffer[i] = ' ';

	for (i=0; i<8; i++)
		buffer[i] = password[i];

	for (; i<16; i++)
		buffer[i] = password[23-i];

	for (; i<32; i+=2)
		buffer[i] = password[46-i];

	for (i=31; i>=17 ; i-=2)
		buffer[i] = password[i];
}

/*
 * retrieve the pw from a given buffer by applying permutations in reverse
 * order
 */
void pwd_reverse(char *buffer, char *password) {
	size_t i = 0;

	// initialize
	for (i=0 ; i<32; i++)
		password[i] = ' ';

	for (i=17; i<32; i+=2)
		password[i] = buffer[i];

	for (i=30; i>=16 ;i-=2)
		password[46-i] = buffer[i];

	for (i=16; i>=8; i--)
		password[23-i] = buffer[i];

	for (i=7; (i+1)>0 ; i--) {
		password[i] = buffer[i];
	}
}

/* 
 * test pwd_reverse against the hashing function by feeding the result
 */
void test_reverse(char *password) {

	printf("Test: %s (len: %lu)\n", password, strlen(password));

	char buffer[32+1] = "";
	char reversed_pw[32+1] = "";

	pwd_gen_buffer(password, buffer);
	pwd_reverse(buffer, reversed_pw);

	if (strcmp(password, reversed_pw) != 0 ) {
		printf("FAILED\n");

		printf("  buffer: %s\n", buffer);
		printf("  pw:     %s\n", password);
		printf("  rev_pw: %s\n", reversed_pw);
	}
}

int main() {

#ifndef CTF_BUFFER
	printf("Run tests\n");
	test_reverse("abcdefghijklmnopqrstuvwxyz123456");
	test_reverse("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	test_reverse("deadbeefdeadbeefdeadbeefdeadbeef");
	test_reverse("lorem ipsum hic dolor amicus est");
#else
	char buffer[32+1] = CTF_BUFFER;
	char password[32+1] = "";

	pwd_reverse(buffer, password);
	printf("picoCTF{%s}\n", password);
#endif

	return 0;
}
