#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <fstream>


#include "Bestellung.h"
#include "BestellungsListe.h"
#include "Adresse.h"
#include "AdressListe.h"

using namespace std;



//Gibt die Daten für eine Bestellung aus
void printBestellung(Bestellung bestell)
{
	
	cout << "Bestellnummer:" << bestell.getBestellnummer() << endl;
	cout << "Produktnummer:" << bestell.getProduktnummer() << endl;
	cout << "Produktname:" << bestell.getProduktname() << endl;
    cout << "Menge:" << bestell.getMenge() << endl;
    cout << "Preis:" << bestell.getPreis() << endl;
    cout << endl;
}

//Gibt die Daten für eine Adresse aus
void printAdresse(Adresse adress)
{
	
	cout << "Bestellnummer:" << adress.getBestellnummer() << endl;
	cout << "Typ:" << adress.getadressTyp() << endl;
	cout << "Name:" << adress.getName() << endl;
    cout << "Strasse:" << adress.getStrasse()<< endl;
    cout << "Plz:" << adress.getPlz() << endl;
    cout << "Stadt:" << adress.getStadt() << endl;
	cout << "Bundesland:" << adress.getBundesland()<< endl;
	cout << endl;
}

//Gibt die Daten für einen vereinigten Datensatz aus. Über den Wert der Bestellnummer könne die Daten zusammen geführt werden  
void printData(AdressListe a,BestellungsListe b)
{

	int i=0,j=0,lenb=0,lena=0,q=0,nummer=0;
	vector <int> tempa;
	vector <int> tempb;

	lena=a.adressenLaenge();
	
	lenb=b.bestellungenLaenge();
    
    
	if(lena!=0 && lenb!=0)
    {
		
	tempa.push_back(a.getAdressenSort().at(0).getBestellnummer());
	
	tempb.push_back(b.getBestellungenSort().at(0).getBestellnummer());
    

	for(i=1;i<lena;i++)
	{
	
	if(tempa.at(j)!=a.getAdressenSort().at(i).getBestellnummer())
	{
	j++;
	tempa.push_back(a.getAdressenSort().at(i).getBestellnummer());
	
    }
    }
	
	j=0;
	for(i=1;i<lenb;i++)
	{
	
	if(tempb.at(j)!=b.getBestellungenSort().at(i).getBestellnummer())
	{
	j++;
	tempb.push_back(b.getBestellungenSort().at(i).getBestellnummer());
	
    }
    }
	
	lena=tempa.size();
	lenb=tempb.size();

	
	for(i=0;i<lena;i++)
	{
		
		
		for(j=0;j<lenb;j++)
		{
			
			if(tempa.at(i)==tempb.at(j))
			{
			   cout << "Datensatz mit Bestellnummer:" << tempa.at(i)<< endl;
               cout << "----------------------------" << endl;
			   cout << endl;
				for(q=0;q < a.getAdresse(tempa.at(i)).size();q++)
				{
				
			     printAdresse(a.getAdresse(tempa.at(i)).at(q));
				
		
				
			   }
				
			    for(q=0;q<b.getBestellung(tempa.at(i)).size();q++)
				{
				
				printBestellung(b.getBestellung(tempa.at(i)).at(q));
		
  	
			    }
				
		
			  
			    break;
			}
			
		}
		
		
	}
}

}
//Führt zwei Datenquellen zusammen und legt eine neue Datei an 
void konvertieren(string Pfad,AdressListe a,BestellungsListe b)
{

    //string Pfad="ausgabe.txt";	
    ofstream myfile;
    myfile.open(Pfad.c_str());

	
	int i=0,j=0,lenb=0,lena=0,q=0,nummer=0;
	vector <int> tempa;
	vector <int> tempb;

	lena=a.adressenLaenge();
	
	lenb=b.bestellungenLaenge();
	if(lena!=0 && lenb!=0)
	{
	tempa.push_back(a.getAdressenSort().at(0).getBestellnummer());
	
	tempb.push_back(b.getBestellungenSort().at(0).getBestellnummer());
    
	
	
	for(i=1;i<lena;i++)
	{
	
	if(tempa.at(j)!=a.getAdressenSort().at(i).getBestellnummer())
	{
	j++;
	tempa.push_back(a.getAdressenSort().at(i).getBestellnummer());
	
    }
    }
	
	j=0;
	for(i=1;i<lenb;i++)
	{
	
	if(tempb.at(j)!=b.getBestellungenSort().at(i).getBestellnummer())
	{
	j++;
	tempb.push_back(b.getBestellungenSort().at(i).getBestellnummer());
	
    }
    }
	
	lena=tempa.size();
	lenb=tempb.size();
	
	for(i=0;i<(a.getDTDLaenge()-1);i++){
	
	if(i==10)
	myfile <<"<!ELEMENT Bestellung (Produktummer,Produktname,Menge,Preis)>\n<!ATTLIST Bestellung \n xmlns CDATA #FIXED ''>"<< endl;
	if(i==2)
	myfile << "<!ELEMENT Onlinebestellung (Adresse+,Bestellung+)>"<< endl;
	else
	myfile << a.getDTD(i) << endl;
	
	}
	
	myfile <<"<!ELEMENT Produktummer (#PCDATA)>\n<!ATTLIST Produktummer\n xmlns CDATA #FIXED ''>" <<endl;
    myfile <<"<!ELEMENT Produktname (#PCDATA)>\n<!ATTLIST Produktname\n xmlns CDATA #FIXED ''>" <<endl;
    myfile <<"<!ELEMENT Menge (#PCDATA)>\n<!ATTLIST Menge\n xmlns CDATA #FIXED ''>" <<endl;
    myfile <<"<!ELEMENT Preis (#PCDATA)>\n<!ATTLIST Preis\nxmlns CDATA #FIXED ''>\n]>" <<endl;
    myfile << "<OnlinebestellListe>"<< endl;
	
	for(i=0;i<lena;i++)
	{
		
		
		for(j=0;j<lenb;j++)
		{
			
			if(tempa.at(i)==tempb.at(j))
			{
			 
               myfile << "<Onlinebestellung Bestellnummer=\"" << tempa.at(i)  << "\">" << endl; 	
					
				for(q=0;q < a.getAdresse(tempa.at(i)).size();q++)
				{
				
	
				
				 myfile << "<Adresse Type=\" " <<a.getAdresse(tempa.at(i)).at(q).getadressTyp() << "\">" << endl;   
                 myfile <<  "<Name>" << a.getAdresse(tempa.at(i)).at(q).getName() << "</Name>" << endl;  
                 myfile <<  "<Strasse>"  <<a.getAdresse(tempa.at(i)).at(q).getStrasse()<< " </Strasse> " << endl; 
                 myfile <<   "<Stadt>"<<a.getAdresse(tempa.at(i)).at(q).getStadt()<<"</Stadt>" << endl;    
                 myfile <<   "<Plz>" <<a.getAdresse(tempa.at(i)).at(q).getPlz()<< "</Plz>" << endl;  
                 myfile <<   "<Bundesland>"<< a.getAdresse(tempa.at(i)).at(q).getBundesland()<< "</Bundesland>"  << endl;
                 myfile << "</Adresse>" << endl;
				
			   }
				
			    for(q=0;q<b.getBestellung(tempa.at(i)).size();q++)
				{
		
				
				 myfile << "<Bestellung>" << endl;   
                 myfile <<  "<Produktummer>" << b.getBestellung(tempa.at(i)).at(q).getProduktnummer()<< "</Produktummer>" << endl;  
                 myfile <<  "<Produktname>"  << b.getBestellung(tempa.at(i)).at(q).getProduktname()<< "</Produktname>" << endl; 
                 myfile <<   "<Menge>"<<b.getBestellung(tempa.at(i)).at(q).getMenge()<<"</Menge>" << endl;    
                 myfile <<   "<Preis>" <<b.getBestellung(tempa.at(i)).at(q).getPreis()<< "</Preis>"  << endl;  
                 myfile << "</Bestellung>" << endl; 
  	
			    }
				
				myfile << "</Onlinebestellung>" << endl;
			  
			    break;
			}
			
		}
		
		
	}
	 myfile << "</OnlinebestellListe>";
}
   
	myfile.close();
  
}


int main(int argc, char** argv) {
     
     char eingabe;
     bool p=true;
     string Pfad;
	//string element[7]={"Onlinebestellung","Adresse","Name","Strasse","Stadt","Plz","Bundesland"};	
    vector<string> element;
    //Elemente dessen Werte aus der Xml datei entnommen werden müssen
	element.push_back("Onlinebestellung");
    element.push_back("Adresse");
    element.push_back("Name");
    element.push_back("Strasse");
    element.push_back("Stadt");
    element.push_back("Plz");
    element.push_back("Bundesland");
    element.push_back("");
    
    cout << "Bitte geben Sie den Pfad zur Adressliste (Adressliste.xml) ein:";
    cin >> Pfad;

    AdressListe a(Pfad,element);

    cout << "Bitte geben Sie den Pfad zur Bestellliste (Bestellungsliste.cpp) ein:";
    cin >> Pfad;

    BestellungsListe b(Pfad);



do{

   cout << "Onlinebestellungen:" << endl;
   cout << endl;
   cout << endl;
   cout << "(a)nzeigen von vereinten Datensätzen" << endl;
   cout << "(k)onvertieren in neues Xml Format" << endl;
   cout << "(b)eenden" << endl;
   cin >> eingabe;
   system("clear");

   
   if(eingabe=='k')
   {
   cout << "Ausgabepfad:";	
   cin >> Pfad;
   konvertieren(Pfad,a,b);
   }
   if(eingabe=='a')
   {
   printData(a,b); 
   }
   if(eingabe=='b')
   {
    	break;
   }


cout<< "Wollen Sie eine weitere Auswahl treffen?j/n?";
cin >> eingabe;
system("clear");
if(eingabe=='j')
p=true;
else
p=false;

}while(p);
	
	return 0;
} 
