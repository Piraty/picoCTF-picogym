#include <limits.h>
#include <stdio.h>

#define FLAG_PRICE 900
#define INITIAL_BALANCE 1100

int main() {
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX/900: %d\n", INT_MAX/900);

	int account_balance = INITIAL_BALANCE;

	for (int n=(INT_MAX/900); n<INT_MAX && account_balance<=INITIAL_BALANCE ; n++) {

		int number_flags = n;
		int total_cost = 900*number_flags;
		account_balance = INITIAL_BALANCE - total_cost;

		printf("number_flags: %d\n", number_flags);
		printf("account_balance: %d\n", account_balance);
		printf("\n");
	}
}
