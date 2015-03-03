#include "item.h"

Item::Item() : MaxNameLength(12){

}

Item::Item(unsigned int _ItemNumb, char *_Name, unsigned int _Tipe, unsigned int _Price, unsigned int _ItemValue, char *_desc) : MaxNameLength(12) {
	Name = new char[MaxNameLength];
	ItemNumber = _ItemNumb;
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=_Name[i];
	}
	Desc = new char[100];
	for (int k=0;k<=100;k++)
	{	
		Desc[k]=_desc[k];
	}
	// Desc = _desc;
	Tipe=_Tipe;
	// Tipe.SetIndeks(_Tipe);
	Price = _Price;
	ItemValue = _ItemValue;

}

Item::Item(const Item& I) : MaxNameLength(I.MaxNameLength) {
	Name = new char[MaxNameLength];
	ItemNumber=I.ItemNumber;
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=I.Name[i];
	}
	Desc = new char[100];
	for (int k=0;k<=100;k++)
	{	
		Desc[k]=I.Desc[k];
	}
	Tipe = I.Tipe;
	Price = I.Price;
	ItemValue = I.ItemValue;
}

Item& Item::operator= (const Item& I) {
	delete [] Name;
	delete [] Desc;
	Name = new char[I.MaxNameLength];
	ItemNumber=I.ItemNumber;
	for (int i=0;i<=I.MaxNameLength;i++)
	{	
		Name[i]=I.Name[i];
	}
	Desc = new char[100];
	for (int k=0;k<=100;k++)
	{	
		Desc[k]=I.Desc[k];
	}
	Tipe = I.Tipe;
	Price = I.Price;
	ItemValue = I.ItemValue;
	return *this;
}

unsigned int Item::GetItemNumber() {
	return ItemNumber;
}

Item::~Item() {
	delete [] Name;
	delete [] Desc;
}

char* Item::GetName() {
	return Name;
}

int Item::GetTipe() {
	return Tipe;
}

unsigned int Item::GetPrice() {
	return Price;
}

unsigned int Item::GetItemValue() {
	return ItemValue;
}

char* Item::GetDesc() {
	return Desc;
}
