#include "Adresse.h"

using namespace std;



Adresse::Adresse(std::string AdressInformation){

 stringstream	adressstream(AdressInformation);
 
 adressstream >> Bestellnummer;
 adressstream >> adressTyp;
 adressstream >> Name;
 adressstream >> Strasse;
 adressstream >> Stadt;
 adressstream >> Plz;
 adressstream >> Bundesland;
 
	
	
}


int Adresse::getBestellnummer(){
	return Bestellnummer;	
}

string Adresse::getName(){
	return Name;
}
string Adresse::getStrasse(){
	return Strasse;
}
string Adresse::getStadt(){
	return Stadt;
}
int Adresse::getPlz(){
	return Plz;
}
string Adresse::getBundesland(){
	return Bundesland;
}  
string Adresse::getadressTyp(){
	return adressTyp;
}
	    
