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
 * Nama File            : combinatorium.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 //Created by : Fawwaz Muhammad

#include "stadium.h"
#include <iostream>


Stadium::Stadium(){
	// name = "Stadium";
}
Stadium::~Stadium(){}
Stadium::Stadium(const Stadium& S){
	// name=S.name;
}
Stadium& Stadium::operator= (Stadium& S){
	// name=S.name;
	// return *this;
}

// string Stadium::GetName(){return name;}
