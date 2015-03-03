/* ************************************************************************** */
/*                                MAIN SKILL                                  */
/* ************************************************************************** */

#include "listofskill.h"
#include "skill.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{	int a;
    /* *** KAMUS *** */
    ListOfSkill LISTSkill;
    
    /* *** ALGORITMA *** */
    LISTSkill.ReadFromFile();
    LISTSkill.PrintList();
	LISTSkill.DataList(30);
	Skill apa;
	apa=LISTSkill.GetSkill(30);
	cout<<apa.GetName();
	cout<<"PPMAX skill no 30: "<<LISTSkill.GetPPMaxFromNumberSkill(30)<<endl;
	cout<<"Nama Skill no 30: "<<LISTSkill.GetNameSkillFromNumberSkill(30)<<endl;
	cin>>a;
    return 0;
}