#include <stdio.h>

int asm1(int input) {
	int ret=0;
	
	if (!(input > 0x3fb) ) /* +3 */  {
		/* +12 */
		if (!(input != 0x280)) /* +12 */ {

		} else {
			/* +29 */
			ret = input;
			ret -= 0xa;
		}
	} else {
		if (!(input != 0x559)) /* +37 */ {
		} else {
			/* +54 */
		}
	}
	return ret;
}

int main() {
	printf("0x%x\n",asm1(0x2e0));

	return 0;
}
