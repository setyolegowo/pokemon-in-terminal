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
 #include "point.h"

using namespace std;

Point::Point(){
	x=0;
	y=0;
}
Point::~Point(){}//cout << "mati dah gw " <<endl;}
Point::Point(const Point& P){
	x=P.x;
	y=P.y;
}
Point& Point::operator=(Point& P){
	x=P.x;
	y=P.y;
	return *this;
}

// Getter Setter
unsigned char Point::GetX(){return x;}
unsigned char Point::GetY(){return y;}
unsigned char Point::SetX(unsigned char _x){x=_x;}
unsigned char Point::SetY(unsigned char _y){y=_y;}

// Operasi perpindahan posisi
void Point::IncLeft(int N){
	for (int i = 0; i < N; ++i)
	{
		x--;
	}
}
void Point::IncRight(int N){
	for (int i = 0; i < N; ++i)
	{
		x++;
	}
}
void Point::IncTop(int N){
	for (int i = 0; i < N; ++i)
	{
		y--; // Karena koordinat 0,0 di titik kiri atas maka kalau naik di decrement
	}
}
void Point::IncBottom(int N){
	for (int i = 0; i < N; ++i)
	{
		y++;// Karena koordinat 0,0 di titik kiri atas maka kalau turun di increment
	}
}
