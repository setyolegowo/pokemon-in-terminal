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

Combinatorium::Combinatorium(){}
Combinatorium::~Combinatorium(){}
Combinatorium::Combinatorium(const Combinatorium&){}
Combinatorium& Combinatorium::operator= (Combinatorium&){}

// bool Combinatorium::IsCombinable(Monster *M1,Monster *M2){
// 	return ((M1->getIsCombined()==1)&&(M2->getIsCombined()))&&(M1->getNextEvoNo()==M2->getNextEvoNo());
// }

// Monster& Combinatorium::DoCombine(Monster *M1,Monster *M2,ListOfMonster LM){
// 	if (IsCombinable(M1,M2))
// 	{
// 		Monster Mtemp(LM.getMonster(M1->getNextEvoNo()));
// 		unsigned int HP=M1->getHP();
// 		unsigned int Attack=M1->getAttack();
// 		unsigned int Defense=M1->getDefense();
// 		unsigned int Speed=M1->getSpeed();
// 		unsigned int Level= ;//Ini diubah lagi woi levelnya 2 kali level maksimal//getDefaultLevel();
// 		unsigned int DefaultSkill=M1->getDefaultSkills(int);
// 		unsigned int Skill1=M1->getDefaultSkills1();
// 		unsigned int Skill2=M1->getDefaultSkills2();
// 		unsigned int Skill3=M1->getDefaultSkills3();
// 		unsigned int Skill4=M1->getDefaultSkills4();
// 		unsigned int NextEvoLevel=M1->getNextEvolutionLevel();
// 		unsigned int NextEvoNo=M1->getNextEvoNo();
// 		char* Elemen1=M1->getNameElemen1();
// 		char* Elemen2=M1->getNameElemen2();

// 		PlayerMonster PM();
// 	}
// }