/* ************************************************************************** */
/*                                  POKERANCH                                 */
/* ************************************************************************** */

/*
 * Nama / NIM           : Lubis Sucipto / 13511025
 *                        Muhammad Rizky W / 13511037
 *                        Andreas Dwi Nugroho / 13511051
 *                        Setyo Legowo / 13511071
 *                        Fawwaz Muhammad / 13511083
 *                        Asep Saepudin / 13511093
 * Nama File            : point.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 // Created By Fawwaz Muhammad

 #include <iostream>
 #include <stdio.h>
 #include "area.h"
 #include <stdlib.h>
 // untuk ngetes doang
 // #include "outerarea.h"

using namespace std;

Area::Area():MaxUnstapablePoint(100)
{	
	int size;
	Width=39;
	Height=9;
	size = Width*Height;
	area = new int [size];
	
	// Set nilai default array
	for (int i = 0; i <= size; ++i)
	{
		area[i]=0;
	}

	PlayerPosition.SetX(5);
	PlayerPosition.SetY(6);
	// temporary configurable 
	firststep=true;
	LastStepped=0;
	NextStepped=0;
	// stepped = area[ConvertPointToIdxArea(PlayerPosition)];
	PlayerPositionPlace = 0;
}

Area::~Area()
{
	delete area;
}

Area::Area(const Area& A):MaxUnstapablePoint(A.MaxUnstapablePoint)
{
	int size;
	Width=A.Width;
	Height=A.Height;
	size = Width*Height;
	area = new int [size];
	
	// Set nilai default array
	for (int i = 0; i <= size; ++i)
	{
		area[i]=A.area[i];
	}
	Point p=A.PlayerPosition;
	PlayerPosition.SetX(p.GetX());
	PlayerPosition.SetY(p.GetY());
	PlayerPositionPlace = A.PlayerPositionPlace;
}

Area& Area::operator=(Area& A)
{
	int size;
	Width=A.Width;
	Height=A.Height;
	size = Width*Height;
	area = new int [size];
	
	// Set nilai default array
	for (int i = 0; i <= size; ++i)
	{
		area[i]=A.area[i];
	}

	PlayerPosition.SetX(A.PlayerPosition.GetX());
	PlayerPosition.SetY(A.PlayerPosition.GetY());
	PlayerPositionPlace = A.PlayerPositionPlace;
	return *this;
}

unsigned char Area::GetWidth(){return Width;}
unsigned char Area::GetHeight(){return Height;}
void Area::SetWidth(unsigned char W){ Width=W;}
void Area::SetHeight(unsigned char H){ Height=H;}


int Area::ConvertPointToIdxArea(Point& P)
{
	return GetWidth()*P.GetY()+P.GetX();
}


Point Area::ConvertIdxAreaToPoint(int I)
{
	Point P;
	P.SetY(I / GetWidth());
	P.SetX(I % GetWidth());
	return P;
}

int Area::GetMaxUnstapablePoint()const{return MaxUnstapablePoint;}









// DIATAS INI INSYA ALLAH GAK BAKAL DIUBAH LAGI STANDAR CCTOR CTOR DTOR DAN SETTER GETTER





bool Area::UpdatePlayerPosition(unsigned char direction,unsigned char steps)
{
	unsigned char tempx,tempy;
	int tempidx;
	tempx=PlayerPosition.GetX()+1;
	tempy=PlayerPosition.GetY()+1;
	Point Ptemp(PlayerPosition);
	//if this is the first step
	if (firststep)
	{
		stepped=LastStepped;
		firststep=false;
	}else{
		stepped=LastStepped;
	}
	printf(" STEPPED %d - %d \n", PlayerPosition.GetX(),PlayerPosition.GetY());

	tempidx=ConvertPointToIdxArea(PlayerPosition);

	switch(direction)
	{
		case 1:
			// cek kondisi dulu apakah valid moves
			if (!ValidMoves(direction,steps))
			{
				if (LastStepped==2)
				{
					cout << "Battle mode on !" <<endl;
				}else{
					cout << "Invalid moves" <<endl;
				}
				return false;
				/* code */
			}else{				
				// LastStepped=area[ConvertPointToIdxArea(Ptemp.IncTop(steps))]
				PlayerPosition.IncTop(steps);
				LastStepped=area[ConvertPointToIdxArea(PlayerPosition)];
				area[tempidx]=Restorepointstepped(stepped);
				return true;
			}
			break;
		case 2:
			if (!ValidMoves(direction,steps))
			{
				if (LastStepped==2)
				{
					cout << "Battle mode on !" <<endl;
				}else{
					cout << "Invalid moves" <<endl;
				}
				return false;
				/* code */
			}else{
				PlayerPosition.IncRight(steps);
				LastStepped=area[ConvertPointToIdxArea(PlayerPosition)];
				area[tempidx]=Restorepointstepped(stepped);
				return true;
			}
			break;
		case 3:
			if (!ValidMoves(direction,steps))
			{
				if (LastStepped==2)
				{
					cout << "Battle mode on !" <<endl;
				}else{
					cout << "Invalid moves" <<endl;
				}
				return false;
				/* code */
			}else{
				// area[tempidx]=Restorepointstepped(stepped);
				PlayerPosition.IncBottom(steps);
				LastStepped=area[ConvertPointToIdxArea(PlayerPosition)];
				area[tempidx]=Restorepointstepped(stepped);
				return true;
			}
			break;
		case 4:
			if (!ValidMoves(direction,steps))
			{
				if (LastStepped==2)
				{
					cout << "Battle mode on !" <<endl;
				}else{
					cout << "Invalid moves" <<endl;
				}
				return false;
				/* code */
			}else{
				printf(" Stepped adalah %d\n", stepped);
				// area[tempidx]=Restorepointstepped(stepped);
				PlayerPosition.IncLeft(steps);
				// added
				LastStepped=area[ConvertPointToIdxArea(PlayerPosition)];
				area[tempidx]=Restorepointstepped(stepped);
				return true;
			}
			break;
		default:
			break;
	}

	// VALIDATE AGAIN
	NextStepped=LastStepped;

	//Draw the player after updated player position
	area[ConvertPointToIdxArea(PlayerPosition)]=3;
	if (LastStepped==2)
	{
		LastStepped=0;
	}else{
		// LastStepped=NextStepped;

	}

	printf(" Nilai Stepped  :%d \n",GetStepped());
	printf(" Nilai Last Stepped  :%d \n",GetLastStepped());
	printf(" Nilai Next Stepped  :%d \n",GetNextStepped());
}

void Area::PrintMap(){
	int size=int(GetHeight())*int(GetWidth())- 1; // minus satu karena C++ memulai indeks dari angka 0
	for (int i = 0; i <=size; ++i)
	{
		// bool* A=GetArea();
		// If i modulo width != 0 means the current lines is still as same
		// ase before
		if ( (i % GetWidth()) != 0)
		{
			switch(area[i])
			{
				case 0:
					printf(". ");
					break;
				case 1:
					printf("# ");
					break;
				case 2:
					printf("M ");
					break;
				case 3:
					printf("O ");
					break;
				case 4: // 4 untuk teleport rumah
					printf("+ ");
					break;
				case 5:	// 5 untuk teleport combinatorium
					printf("+ ");
					break;
				case 6:	// 6 untuk teleport stadium
					printf("+ ");
					break;
				case 7: // 7 untuk teleport milik store
					printf("+ ");
					break;
				case 8: // 8 untuk gate ke luar kota 
					printf("X ");
					break;
				case 9: // 8 untuk gate ke level sebelumnya
					printf("<=");
					break;
				case 10: // 8 untuk gate ke level setelahnya 
					printf("=>");
					break;
				default:
					printf("  ");
					break;
			}
		}else{
			printf("\n ");
			switch(area[i])
			{
				case 0:
					printf(". ");
					break;
				case 1:
					printf("# ");
					break;
				case 2:
					printf("M ");
					break;
				case 3:
					printf("O ");
					break;
				case 4: // 4 untuk teleport rumah
					printf("+ ");
					break;
				case 5:	// 5 untuk teleport combinatorium
					printf("+ ");
					break;
				case 6:	// 6 untuk teleport stadium
					printf("+ ");
					break;
				case 7: // 7 untuk teleport milik store
					printf("+ ");
					break;
				case 8: // 8 untuk gate ke luar kota 
					printf("X ");
					break;
				case 9: // 8 untuk gate ke level sebelumnya
					printf("<=");
					break;
				case 10: // 8 untuk gate ke level setelahnya 
					printf("=>");
					break;
				default:
					printf("  ");
					break;
			}
		}
	}
} 




bool Area::ValidMoves(unsigned char direction, unsigned char steps)
{
	unsigned char tempx,tempy;
	int tempidx,tempidx2;
	tempx=PlayerPosition.GetX()+1;//tambah satu karena indeks dimulai dari 0
	tempy=PlayerPosition.GetY()+1;//tambah satu karena indeks dimulai dari 0
	// tempidx=ConvertPointToIdxArea(PlayerPosition);
	Point Ptemp(PlayerPosition); //copy constructor called


	switch(direction)
	{
		case 1:
			// cek kondisi dulu apakah valid moves
			Ptemp.IncTop(steps);
			tempidx2=ConvertPointToIdxArea(Ptemp);
			// printf("Ini nilainya %d\n", tempidx2);
			// printf("Ini isi X: %d Y:%d \n", Ptemp.GetX(),Ptemp.GetY());
			if ((tempy-steps)<=0)
			{
				return false;
			}else if(area[tempidx2]==1)
			{
				return false;
			}else if(LastStepped==2){ // kalau berhenti sama monster blcok
				return false;
			}else{
				return true;
			}
			break;
		case 2:
			Ptemp.IncRight(steps);
			tempidx2=ConvertPointToIdxArea(Ptemp);
			// printf("Ini nilainya %d\n", tempidx2);
			// printf("Ini isi X: %d Y:%d \n", Ptemp.GetX(),Ptemp.GetY());
			if ((tempx+steps)>=(GetWidth()+1))
			{
				return false;
			}else if(area[tempidx2]==1){
				return false;
			}else if(LastStepped==2){ // kalau berhenti sama monster blcok
				return false;
			}else {
				return true;
			}
			break;
		case 3:
			Ptemp.IncBottom(steps);
			tempidx2=ConvertPointToIdxArea(Ptemp);
			// printf("Ini nilainya %d\n", tempidx2);
			// printf("Ini isi X: %d Y:%d \n", Ptemp.GetX(),Ptemp.GetY());
			if ((tempy+steps)>=(GetHeight()+1))
			{
				return false;
			}else if(area[tempidx2]==1){
				return false;
			}else if(LastStepped==2){ // kalau berhenti sama monster blcok
				return false;
			}else{
				return true;
			}
			break;
		case 4:
			Ptemp.IncLeft(steps);
			tempidx2=ConvertPointToIdxArea(Ptemp);
			// printf("Ini nilainya %d\n", tempidx2);
			// printf("Ini isi X: %d Y:%d \n", Ptemp.GetX(),Ptemp.GetY());
			if ((tempx-steps)<=0)
			{
				return false;
			}else if(area[tempidx2]==1){
				return false;
			}else if(LastStepped==2){ // kalau berhenti sama monster blcok
				return false;
			}else{
				return true;
			}
			break;
		default:
			break;
	}	

	printf("Ini isi X: %d Y:%d \n", Ptemp.GetX(),Ptemp.GetY());
}

int Area::Restorepointstepped(int stepped)
{
	switch(stepped){
		case 0:
			return 0; // mengembalikan stack biasa
			break;
		case 2:
			return 0;
			break;
		case 3:
			return 0; //mengembalikan stack biasa
			break;
		case 4:
			return 4; // kalau pintu return nya harus pintu juga
			break;
		case 5:
			return 5; // kalau pintu return nya harus pintu juga
			break;
		case 6:
			return 6; // kalau pintu return nya harus pintu juga
			break;
		case 7:
			return 7; // kalau pintu return nya harus pintu juga
			break;
		case 8:
			return 8; // kalau pintu return nya harus pintu juga
			break;
		case 9:
			return 9; // kalau pintu return nya harus pintu juga
			break;
		case 10:
			return 10; // kalau pintu return nya harus pintu juga
			break;
		default:
			return stepped;
			break;
	}
}


void Area::DrawPlayerPosition(){
	int tempidx=ConvertPointToIdxArea(PlayerPosition);	
	area[tempidx]=3;
}


void Area::MovePlayerPosition(unsigned char direction,unsigned char steps)
{
	for (int i = 0; i < steps; ++i)
	{
		UpdatePlayerPosition(direction,1);
	}
	DrawPlayerPosition();
}

void Area::Teleport(int dest)
{
	int tempidx;
	int size =GetWidth()*GetHeight()-1; // array dimulai dari 0
	for (int i = 0; i < size; ++i)
	{
		if (area[i]==dest)
		{
			tempidx=i;
			break;
		}
	}
	Point Ptemp(ConvertIdxAreaToPoint(tempidx));
	PlayerPosition.SetX(Ptemp.GetX());
	PlayerPosition.SetY(Ptemp.GetY());
}

//Debugging only
int Area::GetStepped(){return stepped;}
int Area::GetLastStepped(){return LastStepped;}
int Area::GetNextStepped(){return NextStepped;}
void Area::EnableMoves(){
	stepped=0;
	LastStepped=0;
	NextStepped=0;
}

void Area::ResetMap(){
	int size = GetHeight()*GetWidth()-1; // array started fro, 0
	for (int i = 0; i < size; ++i)
	{
		area[i]=0;
	}
}
// bool* Area::GetArea(){return area;}
// void Area::SetArea(bool &A){area=A;}