#ifndef __AdressInformationsAnalyse__Adresse__
#define __AdressInformationsAnalyse__Adresse__

//Diese Klasse erzeugt ein Objekt aus Bestellungsinformationen die in der Bestellungsliste hinterlegt sind


#include <string>
#include <sstream>

class Adresse 
{
	public:
        Adresse(std::string AdressInformation);	
	    
	    int getBestellnummer();
	    std::string getName();
		std::string getStrasse();
		std::string getStadt();
		int getPlz();
		std::string getBundesland();  
	    std::string getadressTyp();
	
	private:
		
		int Bestellnummer;
		std::string Name;
		std::string Strasse;
		std::string Stadt;
		int Plz;
		std::string Bundesland;
		std::string adressTyp;   
};


#endif 

