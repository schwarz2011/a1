#ifndef __AdressInformationsAnalyse__AdressListe__
#define __AdressInformationsAnalyse__AdressListe__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "Adresse.h"

class AdressListe 
{
	public:
        AdressListe(std::string Pfad,std::vector<std::string> elemente);	
	    std::vector<Adresse> getAdresse(int Bestellnummer);
	    std::vector<Adresse> getAdressenSort();
	    int adressenLaenge();
	    std::string getDTD(int i);
	    int getDTDLaenge();
	    
	private:
		std::vector<Adresse> adressen;
	    std::vector<std::string> dtd;
};


#endif 
