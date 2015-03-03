#include "city.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	City C;
	char CC;
	char N;
	C.FixUnstapableArea();
	do
	{
		// printf("Apakah valid untuk teleport ? %d\n", C.ValidTeleport());
		// printf("Point diinjak (stepped) adalah : %d \n", C.GetStepped());
		// printf("Titik Last Stepped : %d \n",C.GetLastStepped());
		// printf("Titik Next Stepped : %d \n",C.GetNextStepped());
		C.DrawPlayerPosition();
		C.PrintMap();
		
		cout <<"\n" <<endl;
		cin >>CC;
		switch(CC)
		{
			case 'w':
				// printf(" Valid Teleport 2 : %d \n",C.ValidTeleport());			
				C.UpdatePlayerPosition(1,1);
				// if (C.UpdatePlayerPosition(1,1))
				// {
				// 	printf("Berhasil dipindahkan");
				// }else{
				// 	printf("Gagal dipindahkan ");
				// }
				break;
			case 'a':
				// printf(" Valid Teleport 2: %d \n",C.ValidTeleport());			
				C.UpdatePlayerPosition(4,1);
				break;
			case 's':
				// printf(" Valid Teleport 2: %d \n",C.ValidTeleport());			
				C.UpdatePlayerPosition(3,1);
				break;
			case 'd':
				// printf(" Valid Teleport 2: %d \n",C.ValidTeleport());			
				C.UpdatePlayerPosition(2,1);
				break;
			case 't':
				// C.UpdatePlayerPosition(1,0);
				// if (C.ValidTeleport()==4||C.ValidTeleport()==5||C.ValidTeleport()==6||C.ValidTeleport()==7)
				// {	

				// 	printf(" INI ISINYA APA YA ?: %d \n",C.ValidTeleport());			
				// 	C.Teleport(5);
				// 	C.LastStepped=(5);
				// }
				printf(" TELEPORT MODE :\n");
				scanf("%d",&N);
				C.DoTeleport(N);
				// printf("isinya NextStepped adalah teteret teteteeet: %d \n",C.GetNextStepped());
				// printf("isinya LastStepped adalah teteret teteteeet: %d \n",C.GetLastStepped());
				// C.area[C.ConvertPointToIdxArea(C.PlayerPosition)]=C.Restorepointstepped(C.ConvertPointToIdxArea(C.PlayerPosition));
				break;
			default:
				break;
		}
		// system("cls");
		// printf("Apakah valid untuk teleport ? %d\n", C.ValidTeleport());
		// printf("Point diinjak (stepped) adalah : %d \n", C.GetStepped());
		// printf("Titik Last Stepped : %d \n",C.GetLastStepped());
		// printf("Titik Next Stepped : %d \n",C.GetNextStepped());
		// C.DrawPlayerPosition();
		// C.PrintMap();
		// C.DrawPlayerPosition();
	} while (CC!='c');

	return 0;
}