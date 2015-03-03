all: PokeRanch

PokeRanch: main.o pokeranch.o listofitem.o item.o listofskill.o skill.o listofmonster.o monster.o listofplayer.o playerofmonster.o player.o area.o point.o outarea.o city.o combinatorium.o store.o stadium.o home.o
    g++ source/main.cpp source/pokeranch.cpp source/listofitem.cpp source/item.cpp source/listofskill.cpp source/skill.cpp source/listofmonster.cpp source/monster.cpp source/listofplayer.cpp source/playerofmonster.cpp source/player.cpp source/area.cpp source/point.cpp source/outerarea.cpp source/city.cpp source/combinatorium.cpp source/store.cpp source/stadium.cpp source/home.cpp -o executable/PokeRanch
    
main.o: main.cpp
    g++ -c source/main.cpp

pokeranch.o: pokeranch.cpp
    g++ -c source/pokeranch.cpp

listofitem.o: listofitem.cpp
    g++ -c source/listofitem.cpp

item.o: item.cpp
    g++ -c source/item.cpp

listofskill.o: listofskill.cpp
    g++ -c source/listofskill.cpp

skill.o: skill.cpp
    g++ -c source/skill.cpp

listofmonster.o: listofmonster.cpp
    g++ -c source/listofmonster.cpp

monster.o: monster.cpp
    g++ -c source/monster.cpp

listofplayer.o: listofplayer.cpp
	g++ -c source/listofplayer.cpp
    
playerofmonster.o: playerofmonster.cpp
	g++ -c source/playerofmonster.cpp
	
player.o: player.cpp
	g++ -c source/player.cpp
	
area.o: area.cpp
	g++ -c source/area.cpp
	
point.o: point.cpp
	g++ -c source/point.cpp
	
outerarea.o: outerarea.cpp
	g++ -c source/outerarea.cpp

city.o: city.cpp
	g++ -c source/city.cpp
	
combinatorium.o: combinatorium.cpp
	g++ -c source/combinatorium.cpp

store.o: store.cpp
	g++ -c source/store.cpp
	
stadium.o: stadium.cpp
	g++ -c source/stadium.cpp

home.o: home.cpp
	g++ -c source/home.cpp

clear:
    rm -rf *.o

run:
    ./executable/test100