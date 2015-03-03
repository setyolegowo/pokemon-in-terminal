#include "playerofmonster.h"

int main () {
	system("cls");
	PlayerMonster PM;
	char NamaMons[20] = {'M','o','n','s','G','a','n','t','e','n','g'};
	PlayerMonster PM2(5, NamaMons, 20, 11, 230, 1000, 1532, 5, 50, 6, 54, 7, 34, 8, 41, 1, 2, 3, 4, 52, 51, 43, 60, 1);
	printf("\n\n\nMonster 1 - Default constructor\n-------------------------------");
	PM.tulisPM();	
	printf("\n\n\nMonster 2 - Constructor dengan parameter\n----------------------------------------");
	PM2.tulisPM();
	PlayerMonster PM3 = PM2;
	printf("\n\n\nMonster 3 - Hasil copy contructor dengan monster 2\n--------------------------------------------------");
	PM3.tulisPM();
	PlayerMonster PM4;
	printf("\n\n\nMonster 4 - Default constructor\n-------------------------------");
	PM4.tulisPM();
	printf("\n\n\nMonster 4 setelah di-operator-assignment-kan dengan monster 3\n-------------------------------------------------------------");
	PM4 = PM3;
	PM4.tulisPM();
	printf("\n\n\n");
	getchar();
	return 0;
}