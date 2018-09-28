#ifndef __BestellungsInformationsAnalyse__BestellungsListe__
#define __BestellungsInformationsAnalyse__BestellungsListe__

//Die Bestellinformationen liegen als einfache Textdatei vor  

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
#include <algorithm>

#include "Bestellung.h"

class BestellungsListe 
{
	public:
        BestellungsListe(std::string Pfad);	
	    std::vector<Bestellung> getBestellung(int bestellnummer);
	    std::vector<Bestellung> getBestellungenSort();
	    int bestellungenLaenge();
	private:
		std::vector<Bestellung> bestellungen;
	
};

//class NoBestellnummermatchException : public std::exception
//{
//	
//	public:
//		const char *what() const throw()
//		{
//			return "kein wert";
//		}
//	
//	
//};

#endif 


