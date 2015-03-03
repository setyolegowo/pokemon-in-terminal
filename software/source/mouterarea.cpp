// Test case main file program untuk outer area

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "outerarea.h"

using namespace std;

int main()
{
	OuterArea O;
	char CC;
	O.RandomMonster();
	O.RandomUnstapable();
	O.DrawTeleport();
	int N;	
	
	do
	{
		printf(" Apakah battle lawan monster  saat ini %d?\n", O.IsBattleWithMonster());
		
		O.PrintMap();
		N=0;

		if (O.GetLastStepped()==2)
		{
			O.EnableMoves();
		}

		cout <<"\n" <<endl;
		scanf("%c %d" , &CC,&N);
		switch(CC)
		{
			case 'w':
				O.MovePlayerPosition(1,N);
				// O.UpdatePlayerPosition(1,1);
				// // if (O.UpdatePlayerPosition(1,1))
				// // {
				// // 	printf("Berhasil dipindahkan");
				// // }else{
				// // 	printf("Gagal dipindahkan ");
				// // }
				break;
			case 'a':
				O.MovePlayerPosition(4,N);
				// O.UpdatePlayerPosition(4,1);
				break;
			case 's':
				O.MovePlayerPosition(3,N);
				// O.UpdatePlayerPosition(3,1);
				break;
			case 'd':
				O.MovePlayerPosition(2,N);
				// O.UpdatePlayerPosition(2,1);
				break;
			case 't':
				// cout << "masukan stepsnya " <<endl;
				// scanf("Isinya : %d",&N);
				break;
			default:
				break;
		}
		// system("cls");
		
		printf("Battle gak ? : %d \n", O.IsBattleWithMonster());
	} while (CC!='c');

	printf(" ");
	return 0;
}

//a function that move the palyer position in natural way
