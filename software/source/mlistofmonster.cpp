#include "listofmonster.h"

int main () {
	int tekan;	
	ListOfMonster ListMons;
	printf("\n\n\t\tJUMLAH MONSTER YANG TERSIMPAN DI LIST: %d\n",ListMons.getNMonster());
	
	ayotekan:
	printf("\n\nTekan 5 untuk mencetak daftar monster: ");
	scanf("%d",&tekan);
	if (tekan == 5) {
		ListMons.LookUpTableMonster();
		printf("\nselesai...");
	}
	else
		goto ayotekan;
		
	int i;
	mantaaap:
	printf("\n\nMasukkan integer: ");
	scanf("%d",&i);
	ListMons.printMonsterNoX(i);
	goto mantaaap;
	getchar();
return 0;
}