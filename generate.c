//Generate monster.txt ke bentuk sql

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int no, el, hp, at, de, sp, ds1, ds2, ds3, ds4, evl, evn;
	char buf[100], na[30];
	FILE *src;
	FILE *out;
	int ele[] = {0,1};
	int randnum, randnum2;
	
	src = fopen ("monster.txt", "r");
	out = fopen ("outputxxx.txt", "a");
	while (!feof(src)) {
		randnum = rand() % 2;
		randnum2 = rand() % 2;
		fgets(buf, 100, src);
		sscanf(buf, "%d %s %d %d %d %d %d %d %d %d %d %d %d", &no, na, &el, &hp, &at, &de, &sp, &ds1, &ds2, &ds3, &ds4, &evl, &evn);
		//" UNION SELECT   1, 'Turtwig'   ,  3,  55,  68,  64,  31,  52,  43,   3,   5,  18,   1" + 
		if (ele[randnum] == 0) {
			ds1 = 0;
			ds3 = 0;
		} else {
			ds2 = 0;
			ds4 = 0;
		}
		fprintf(out, "\" UNION SELECT %d, '%s', %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\" +\n", no, na, el, hp, at, de, sp, ds1, ds2, ds3, ds4, evl, evn, ele[randnum2]);
	}
	return 0;

}