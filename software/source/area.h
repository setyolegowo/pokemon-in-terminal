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
 * Nama File            : areas.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */


#ifndef __AREA_H
#define __AREA_H

#include "point.h"

class Area
{
    private:
        // MaxUnstapablePoint
        const int MaxUnstapablePoint;
        
        unsigned char Width;
        unsigned char Height;
        unsigned char PlayerPositionPlace;

        
        
        // Point *UnstapableP;
        // unsigned char *UnstapableActive;
        
        
    public:
        Area();
        ~Area();
        Area(const Area&);
        Area &operator=(Area&);
        bool firststep;

        int *area;//sengaja ditaruh di public agar bisa telanjang bugil dan diakses dari luar
        // Area adalah array dari boolean yang menggambarkan kondisi peta dari atas
        // indeks 0 menyatakan kondisi koordinat di titik paling kiri atas, dan indeks ke-Height*Width
        // menyatakan kondisi koordinat di paling kanan bawah. 
        // Jika suatu indeks bernilai 1 berarti unstepable dan jika 0 berarti stepable
        // misal area[0] bernilai 1, maka koordinat titik paling kiri atas tidak bisa di step
        Point PlayerPosition;
        int LastStepped;
        int NextStepped;
        int stepped;
        // dibutuhkan untuk "temporary variable" untuk array of unsigne char area

        // Setter getter
        unsigned char GetWidth();
        unsigned char GetHeight();
        void SetWidth(unsigned char);
        void SetHeight(unsigned char);
        int GetMaxUnstapablePoint() const;
        int GetStepped();
        int GetLastStepped();
        int GetNextStepped();
        //converter
        int ConvertPointToIdxArea(Point&);
        Point ConvertIdxAreaToPoint(int);


        
        bool UpdatePlayerPosition(unsigned char,unsigned char);
        // Untuk melakukan update player position 
        // TIDAK PERLU DIPANGGIL MAIN
        void PrintMap();
        bool ValidMoves(unsigned char,unsigned char);
        //Parameter 1 adalah arah(direction) dan parameter 2 adalah jumlah stepsnya
        //Parameter 1 bernilai 1 => move direction ke atas
        //Parameter 1 bernilai 2 => move direction ke kanan
        //Parameter 1 bernilai 3 => move direction ke bawah
        //Parameter 1 bernilai 4 => move direction ke kiri
        //Parameter 2 berniali 0..Width
        //return 1 valid moves

        int Restorepointstepped(int);        
        // Mengembalikan jenis "floor" apa yang harus ditampilkan di layar
        // input masukan adalah koordinat terakhir player 
        // TIDAK PERLU DIPANGGIL MAIN
        void DrawPlayerPosition();
        // Gambar player position
        void MovePlayerPosition(unsigned char,unsigned char);
        // Move the player poisttion 
        void EnableMoves();


        void Teleport(int);
        // Teleport to the closest array area value which equal to destination type 
        // example telepor(4) means teleport to area where the value of floor type is equal to 4
        // MUNGKIN DIPANGGIL TAPI TIDAK PERLU TAHU ISINYA APA

        void ResetMap();
        // bool* GetArea();
        // void SetArea(bool Area);
};
// __AREA_H
#endif 