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

#include "combinatorium.h"
#include "monster.h"
Combinatorium::Combinatorium(){}
Combinatorium::~Combinatorium(){}
Combinatorium::Combinatorium(const Combinatorium&){}
Combinatorium& Combinatorium::operator= (Combinatorium&){}

// bool Combinatorium::IsCombineable(Monster *M1,Monster *M2){
//  return (M1->getMonsterNumber()==M2->getMonsterNumber())&&(M1->IsCombined==M2->IsCombined)
// }

// Monster& Combinatorium::DoCombine(Monster *M1,Monster *M2,char *Name,ListOfMonster *LM){
	// algoritma : 
	// kalau bisa
	// ambil dari list player monster
	// push_back ke belakang level = 2 kali level yang erbesar dairi M2 / M1
	//  skill diambil dari M1
// 	// Nama baru

// 	if (IsCombineable(*M1,*M2))
// 	 {
// 	 	/* code */
		// Monster Mtemp;
		// int L1=M1->GetCurLevel();
		// int L2=M2->GetCurLevel();
		// int TargetLevel; // level yang akan di set menjadi level selanjutnya dari monster baru 
		// if(L1>=L2){
		// 		TargetLevel=L1;
		// }else{
		// 		TargetLevel=L2;
		// }
		// TargetLevel=TargetLevel*2;
		// int NextEvoNotemp=M1->GetNextEvoNo();
		// Mtemp=LM->getMonster(NextEvoNotemp);
		// for(int i=0; i<TargetLevel; i++){
				// if (Mtemp->GetCurLevel()<TargetLevel)
				// {
				// 	Add the level untill reach the target level
				// }
		// }
		
		// LM.push_back(Mtemp);
		// Remove the player monster that owned before (M1 , M2)
// 	 } 
// }