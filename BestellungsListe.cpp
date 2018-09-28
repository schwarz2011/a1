#include "BestellungsListe.h"


using namespace std;

BestellungsListe::BestellungsListe(string Pfad){
	
	ifstream datei(Pfad.c_str());
	
	
	string zeile;
	while(!datei.eof())
	{
		getline(datei, zeile);
		
		Bestellung b(zeile);
		bestellungen.push_back(b);
	}
	datei.close();
	
	
}
vector<Bestellung> BestellungsListe::getBestellung(int bestellnummer){
	
	vector<Bestellung> b; 
	
	for(int i=0; i<bestellungen.size();i++){
	
	if(bestellnummer==bestellungen.at(i).getBestellnummer())
    {
    b.push_back(bestellungen.at(i));
    } 
		
    }
     return b;
	
}

vector<Bestellung> BestellungsListe::getBestellungenSort(){

     int i=0;
     int j=0;
	 int n=0;
	vector<Bestellung> b; 
	 
	 n=bestellungen.size();
	 
	 for(i=0;i<n;++i)
        b.push_back(bestellungen.at(i));
	 
	 	
 for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(b.at(j).getBestellnummer()>b.at(j+1).getBestellnummer())
            {

                  Bestellung temp=b.at(j);
                  b.at(j)=b.at(j+1);
                  b.at(j+1)=temp;

             
            }
    }
    return b;
}

int BestellungsListe::bestellungenLaenge(){
	
	return bestellungen.size();
	
}


