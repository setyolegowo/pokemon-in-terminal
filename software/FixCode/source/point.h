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


#ifndef __POINT_H
#define __POINT_H

class Point
{
    private:
        unsigned char x;
        unsigned char y;
    public:
        Point();
        ~Point();
        Point(const Point&);
        Point &operator=(Point&);
        
        // Getter Setter
        unsigned char GetX();
        unsigned char GetY();
        unsigned char SetX(unsigned char);
        unsigned char SetY(unsigned char);
        
        // Operasi perpindahan posisi
        void IncLeft(int);
        void IncRight(int);
        void IncTop(int);
        void IncBottom(int);
};
// __POINT_H
#endif 