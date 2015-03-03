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
 
#ifndef __COMBINATORIUM_H
#define __COMBINATORIUM_H
#include "monster.h"
#include "listofmonster.h"
#include "playerofmonster.h"

class Combinatorium
{
    private:
        
    public:
        Combinatorium();
        ~Combinatorium();
        Combinatorium(const Combinatorium&);
        Combinatorium& operator= (Combinatorium&);

        // bool IsCombineable(Monster,Monster);
        // Monster& DoCombine(Monster,Monster,ListOfMonster);
};

#endif // __COMBINATORIUM_H