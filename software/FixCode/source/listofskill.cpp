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
 * Nama File            : listofskill.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#include <iostream>
#include <fstream>
#include <list>
#include "listofskill.h"
#include "skill.h"
#include "elementype.h"
using std::ifstream;
using std::list;
using std::cout;
using std::cin;
using std::endl;

ListOfSkill::ListOfSkill() {}
ListOfSkill::~ListOfSkill()
{
    tabelSkill.clear();
    tabelSkill.~list();
}
ListOfSkill::ListOfSkill(const ListOfSkill& LS)
{
    list<Skill>::iterator it;
    list<Skill> tSkill;
    
    // tSkill = LS.tabelSkill;
    // for(it = tSkill.begin(); it != tSkill.end(); ++it)
        // this->tabelSkill.push_back(*it);
}
ListOfSkill& ListOfSkill::operator=(ListOfSkill& LS)
{
    list<Skill>::iterator it;
    list<Skill> tSkill;
    
    this->tabelSkill.clear();
    // tSkill = LS.tabelSkill;
    // for(it = tSkill.begin(); it != tSkill.end(); ++it)
        // this->tabelSkill.push_back(*it);
    return *this;
}
void ListOfSkill::ReadFromFile()
{
    ifstream myfile("skill/skill.txt",ifstream::in);
    
    tabelSkill.clear();
    if(myfile.is_open())
    {
        while(myfile.good())
        {	
            int i = 0;
            char cur_stream[100];
            myfile.getline(cur_stream,100);
            
            // .:: operasi terhadap cur_stream ::.
            // -> tambah nomor skill
            unsigned int SkillNumber = 0;
            while(cur_stream[i] != ' ')
            {
                SkillNumber = SkillNumber*10 + (cur_stream[i] - '0');
                i++;
            }
            i++; // Lewati 1 spasi
            // -> ambil nama skill
            char Name[21];
            int j = 0;
            while(cur_stream[i] != ' ')
            {
                Name[j] = cur_stream[i];
                i++;
                j++;
            }
            while(j < 21) // 21 adalah panjang nama skill
            {
                Name[j] = '\0';
                j++;
            }
            i++; // Lewati 1 spasi
            // -> Target
            int Target = 0;
            Target = cur_stream[i] - '0';
            i+=2; // lewati 1 karakter target dan 1 spasi
            // -> Elemen
            int Element = 0;
            Element = cur_stream[i] - '0';
            i+=2; // lewati 1 karakter elemen dan 1 spasi
            // -> StrWeak
            int StrWeak[2];
            StrWeak[0] = 0;
            StrWeak[1] = 0;
            i++; // Lewati karakter '{'
            while(cur_stream[i] != ',')
            {
              StrWeak[0] = 10*StrWeak[0] + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter ','
            while(cur_stream[i] != '}')
            {
              StrWeak[1] = 10*StrWeak[1] + cur_stream[i] - '0';
                i++;
            }
            i+=2; // lewati karakter '}' dan karakter ','
            // -> Power
            short Power = 0;
            while(cur_stream[i] != ' ')
            {
                Power = 10*Power + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            // -> PowerEffect
            int PowerEffect = 0;
            while(cur_stream[i] != ' ')
            {
                PowerEffect = 10*PowerEffect + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            // -> Accuracy
            int AccuracySkill = 0;
            while(cur_stream[i] != ' ')
            {
                AccuracySkill = 10*AccuracySkill + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            // -> Effect
            int Effect = 0;
            while(cur_stream[i] != ' ')
            {
                Effect = 10*Effect + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            
            // -> Prpobability Effect
            int ProsenEfek = 0;
            while(cur_stream[i] != ' ')
            {
                ProsenEfek = 10*ProsenEfek + cur_stream[i] - '0';
                i++;
            }
            i++; // lewati karakter spasi
            // -> PPMax
            int PPMax = 0;
            while(cur_stream[i] != ',')
            {
              PPMax = 10*PPMax + cur_stream[i] - '0';
              i++;
            }
			cout<<PPMax<<endl;
            
            //Memasukkan ke skill
			Skill TSkill(SkillNumber,Name,Target,Element,StrWeak,Power,PowerEffect,AccuracySkill,Effect,float(ProsenEfek),PPMax);//(SkillNumber, Name, Target, Element, StrWeak, Power, PowerEffect, AccuracySkill, Effect, float(ProsenEfek));
            tabelSkill.push_back(TSkill);
        }
        myfile.close();
    }
    // else
        // throw(2);
}

void ListOfSkill::PrintList()
{	
	list<Skill>::iterator _S1; //membuat iterator untuk list of struct Skill
    Skill tSkill;
    cout<<"NoSkill  |  Nama  |  Target | Elemen | StrWeak | Power | PowerEffect | Accuracy | Effect | ProsenEfek | PPMax :" << endl;
	_S1 = tabelSkill.begin();
	while (_S1 != tabelSkill.end()) {
        tSkill = *_S1;
		cout<<tSkill.GetSkillNumber()<<" "<<tSkill.GetName()<<" "<<tSkill.GetTarget()<<" "<<tSkill.GetElement()<<" {"<<tSkill.GetStrWeak(1)<<","<<tSkill.GetStrWeak(2)<<"} "<<tSkill.GetPower()<<" "<<tSkill.GetPowerEffect()<<" "<<tSkill.GetAccuracy()<<" "<<tSkill.GetEffect()<<" "<<tSkill.GetProsenEfek()<<" "<<tSkill.GetPPMax()<<endl;
		_S1++;
	}
}

void ListOfSkill::DataList(int _SkillNumber)
{	
	list<Skill>::iterator _S1; //membuat iterator untuk list of struct Skill
    Skill tSkill;
    
	_S1 = tabelSkill.begin();
	while (_S1 != tabelSkill.end()) {
        tSkill = *_S1;
		if (_SkillNumber==tSkill.GetSkillNumber()){
		cout<<tSkill.GetSkillNumber()<<" "<<tSkill.GetName()<<" "<<tSkill.GetTarget()<<" "<<tSkill.GetElement()<<" {"<<tSkill.GetStrWeak(1)<<","<<tSkill.GetStrWeak(2)<<"} "<<tSkill.GetPower()<<" "<<tSkill.GetPowerEffect()<<" "<<tSkill.GetAccuracy()<<" "<<tSkill.GetEffect()<<" "<<tSkill.GetProsenEfek()<<" "<<tSkill.GetPPMax()<<endl;
		}
		_S1++;
	}
}

unsigned int ListOfSkill::GetPPMaxFromNumberSkill(int _SkillNumber)
{
	list<Skill>::iterator _S1; //membuat iterator untuk list of struct Skill
    Skill tSkill;
    unsigned int temp=0;
	_S1 = tabelSkill.begin();
	while ((_S1 != tabelSkill.end()) && (temp == 0)) {
        tSkill = *_S1;
		if (_SkillNumber==tSkill.GetSkillNumber()){
			temp=tSkill.GetPPMax();
		}
		
		++_S1;
	}
	return temp;
}

char* ListOfSkill::GetNameSkillFromNumberSkill(int _SkillNumber)
{	list<Skill>::iterator _S1; //membuat iterator untuk list of struct Skill
    Skill tSkill;
    bool cek=false;
	char * No=new char[20];
	No[0] = 'N';
	No[1] = 'o';
	No[2] = ' ';
	No[3] = 'S';
	No[4] = 'k';
	No[5] = 'i';
	No[6] = 'l';
	No[7] = 'l';
	No[8] = '\0';
	_S1 = tabelSkill.begin();
	while ((_S1 != tabelSkill.end()) && (!cek)) {
        tSkill = *_S1;
		if (_SkillNumber==tSkill.GetSkillNumber()){
			cek=true;
		} else
			++_S1;
	}
	if (cek)
	{
		return tSkill.GetName();
	}
	else
		return No;
}

Skill& ListOfSkill::GetSkill(int _SkillNumber) //tidak boleh diluar masukkan diluar SkillNumber
{	list<Skill>::iterator _S1; //membuat iterator untuk list of struct Skill
    Skill tSkill;
	bool cek=false;
	_S1 = tabelSkill.begin();
	while ((_S1 != tabelSkill.end()) && (!cek)) {
        tSkill = *_S1;
		if (_SkillNumber==tSkill.GetSkillNumber()){
			cek=true;
		}
		else
		++_S1;
	}
	if (cek)
	{
		return *_S1;
	}


}
