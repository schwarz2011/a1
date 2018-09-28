#ifndef __BestellungsInformationsAnalyse__Bestellung__
#define __BestellungsInformationsAnalyse__Bestellung__

//Diese Klasse erzeugt ein Objekt aus Bestellungsinformationen die in der Bestellungsliste hinterlegt sind


#include <string>
#include <sstream>

class Bestellung 
{
	public:
        Bestellung(std::string BestellungsInformation);	
	    
	    int getBestellnummer();
		int getProduktnummer();
		std::string getProduktname();
		int getMenge();
		double getPreis();  
	
	private:
		
		int Bestellnummer;
		int Produktnummer;
		std::string Produktname;
		int Menge;
		double Preis;   
		
	
};


#endif 


