#include "listofitem.h"
#include <iostream>
using namespace std;

int main() {
ListOfItem L;
L.ReadFromFile();

L.PrintListItem();
int x;
cin >> x;
return 0;

}
