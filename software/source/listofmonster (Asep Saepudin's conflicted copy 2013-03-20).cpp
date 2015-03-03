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
 * Nama File            : listofmonster.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
 #include "listofmonster.h"
 #include "monster.h"
 
//Default Constructor
ListOfMonster::ListOfMonster() : MaxMonsterList(1000) {
	tabelMonster = new Monster[MaxMonsterList];
	nMonster = 0;
	//readFromFile(tabelMonster, nMonster);
	
	char getInfo[60];
	unsigned int noMonster;
	char nameMonster[20];
	ElemenType Elemen1;
	ElemenType Elemen2;
	unsigned int HPMon;
	unsigned int AttackMon;
	unsigned int DefenseMon;
	unsigned int SpeedMon;
	unsigned int defaultLevelMon;
	unsigned int defaultSkillMon[4];	
	unsigned int isCombinedMon;
	unsigned int NextEvolutionLevelMon;
	unsigned int NextEvoNoMon;
	//tabelMonster = new Monster[MaxMonsterList];
	FILE * data;
	data = fopen("monster/monster.txt", "r");
	
	while (!feof(data)) {
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		Monster SMonster(noMonster, nameMonster, Elemen1, Elemen2, HPMon, AttackMon, DefenseMon, SpeedMon, defaultLevelMon, defaultSkillMon, isCombinedMon, NextEvolutionLevelMon, NextEvoNoMon);
		//printf("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n", SMonster.getMonsterNumber(), SMonster.getSpesies(), SMonster.getElemen0(), SMonster.getElemen1(), SMonster.getHP(), SMonster.getAttack(), SMonster.getDefense(), SMonster.getSpeed(), SMonster.getDefaultLevel(), SMonster.getDefaultSkills1(), SMonster.getDefaultSkills2(), SMonster.getDefaultSkills3(), SMonster.getDefaultSkills4(), SMonster.getIsCombined(), SMonster.getNextEvolutionLevel(), SMonster.getNextEvoNo());	
		tabelMonster[nMonster] = SMonster;
		nMonster++;	
	}
	
}

//Desturctor
ListOfMonster::~ListOfMonster() {
	delete [] tabelMonster;
}

//Copy Constructor
ListOfMonster::ListOfMonster(const ListOfMonster& LM) : MaxMonsterList(LM.MaxMonsterList) {  
    this->nMonster = LM.nMonster;
    tabelMonster = new Monster[MaxMonsterList];
    for(int i=0;i<nMonster;i++) {
        tabelMonster[i] = LM.tabelMonster[i];
	}
}


//Operator Assignment
ListOfMonster ListOfMonster::operator=(const ListOfMonster& LM) {
    if(MaxMonsterList != LM.MaxMonsterList)
        throw(1);
    else
    {
        delete [] tabelMonster;
        this->nMonster = LM.nMonster;
        tabelMonster = new Monster[MaxMonsterList];
        for(int i=0; i<nMonster;i++)
            tabelMonster[i] = LM.tabelMonster[i];
    }
    return *this;
}

/*
void ListOfMonster::readFromFile(Monster* TM, int nMons) {
	char getInfo[60];
	unsigned int noMonster;
	char nameMonster[20];
	ElemenType Elemen1;
	ElemenType Elemen2;
	unsigned int HPMon;
	unsigned int AttackMon;
	unsigned int DefenseMon;
	unsigned int SpeedMon;
	unsigned int defaultLevelMon;
	unsigned int defaultSkillMon[4];	
	unsigned int isCombinedMon;
	unsigned int NextEvolutionLevelMon;
	unsigned int NextEvoNoMon;
	//tabelMonster = new Monster[MaxMonsterList];
	FILE * data;
	data = fopen("../executable/monster/monster.txt", "r");
	
	while (!feof(data)) {
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		Monster SMonster(noMonster, nameMonster, Elemen1, Elemen2, HPMon, AttackMon, DefenseMon, SpeedMon, defaultLevelMon, defaultSkillMon, isCombinedMon, NextEvolutionLevelMon, NextEvoNoMon);
		//printf("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n", SMonster.getMonsterNumber(), SMonster.getSpesies(), SMonster.getElemen0(), SMonster.getElemen1(), SMonster.getHP(), SMonster.getAttack(), SMonster.getDefense(), SMonster.getSpeed(), SMonster.getDefaultLevel(), SMonster.getDefaultSkills1(), SMonster.getDefaultSkills2(), SMonster.getDefaultSkills3(), SMonster.getDefaultSkills4(), SMonster.getIsCombined(), SMonster.getNextEvolutionLevel(), SMonster.getNextEvoNo());	
		TM[nMons] = SMonster;
		nMons++;
		SMonster.tulisMonster();		
	}
}
*/
void ListOfMonster::tulisMonster  (int i) {
	Monster tempMons;
	tempMons = this->tabelMonster[i];
	printf("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n", tempMons.getMonsterNumber(), tempMons.getSpesies(), tempMons.getElemen0(), tempMons.getElemen1(), tempMons.getHP(), tempMons.getAttack(), tempMons.getDefense(), tempMons.getSpeed(), tempMons.getDefaultLevel(), tempMons.getDefaultSkills1(), tempMons.getDefaultSkills2(), tempMons.getDefaultSkills3(), tempMons.getDefaultSkills4(), tempMons.getIsCombined(), tempMons.getNextEvolutionLevel(), tempMons.getNextEvoNo());	
}

int ListOfMonster::getNMonster () {
	return nMonster;
}

void ListOfMonster::LookUpTable() {
	FILE * data;
	FILE * datamonster;
	data = fopen("../executable/monster/monster.txt", "r");
	data = fopen("../executable/monster/datamonster.txt", "w");
	while (!feof(data)) {
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		fputs("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n", SMonster.getMonsterNumber(), SMonster.getSpesies(), SMonster.getElemen0(), SMonster.getElemen1(), SMonster.getHP(), SMonster.getAttack(), SMonster.getDefense(), SMonster.getSpeed(), SMonster.getDefaultLevel(), SMonster.getDefaultSkills1(), SMonster.getDefaultSkills2(), SMonster.getDefaultSkills3(), SMonster.getDefaultSkills4(), SMonster.getIsCombined(), SMonster.getNextEvolutionLevel(), SMonster.getNextEvoNo(), datamonster);
	}
}
