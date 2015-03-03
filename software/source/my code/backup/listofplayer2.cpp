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
 * Nama File            : listofplayer.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#include "listofplayer2.h"

//Default Constructor
ListOfPlayer::ListOfPlayer() 
{ 
	
}

//Destructor
ListOfPlayer::~ListOfPlayer()
{
	tabelPlayer.clear();
}

//Copy Constructor
ListOfPlayer::ListOfPlayer(const ListOfPlayer& LP)
{
}	

//Operator Assignment