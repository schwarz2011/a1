

#include "Bestellung.h"


using namespace std;

Bestellung::Bestellung(string BestellungsInformation){
	
	
	stringstream bestellungStream(BestellungsInformation);
	
	bestellungStream >> Bestellnummer;
	bestellungStream >> Produktnummer;
	bestellungStream >> Produktname;
	bestellungStream >> Menge;
	bestellungStream >> Preis;	
	
}

int Bestellung::getBestellnummer(){
 	return Bestellnummer;
 }
int Bestellung::getProduktnummer()
{
	return Produktnummer;
}
string Bestellung::getProduktname(){
	return Produktname;
}
int Bestellung::getMenge(){
	return Menge;
		}
double Bestellung::getPreis(){
	return Preis;
} 
