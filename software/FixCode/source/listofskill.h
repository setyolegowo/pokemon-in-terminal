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
 * Nama File            : listofskill.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
 
#ifndef __LISTOFSKILL_H
#define __LISTOFSKILL_H

#include <list>
#include "skill.h"

using std::list;

class ListOfSkill
{
    private:
        list<Skill> tabelSkill;
    public:
        ListOfSkill();
        ~ListOfSkill();
        ListOfSkill(const ListOfSkill&);
        ListOfSkill &operator=(ListOfSkill&);
        void ReadFromFile();
		void PrintList();
		void DataList(int);
		unsigned int GetPPMaxFromNumberSkill(int);
		char* GetNameSkillFromNumberSkill(int);
		Skill& GetSkill(int);
};

#endif // __LISTOFSKILL_H