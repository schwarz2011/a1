#include "AdressListe.h"

using namespace std;


AdressListe::AdressListe(string Pfad,vector<string> elemente){
	
	
	int i=0;
	int j=0;
	int q=0;
	int adresscount=0;
	bool p=false,b=true,c=true;
	string adresse;
    stringstream s;

	string::size_type pos =string::npos;
	ifstream datei(Pfad.c_str());
	
	
	
	string zeile;
	
	while(!datei.eof())
	{
		getline(datei, zeile);
		
	
       	if(i==7)
		{
		 
		 if(zeile.find("/")!=string::npos)
		 {
		 p=false;
		 j++;
	     }
		 else
		 {
	     p=true;
		 if(j==2)
		 {	
		 j=0;
		 i=0;
	     }
		 if(j==1)
		 {
		 j=0; 
		 i=1;
		 s << adressen.at(adresscount-1).getBestellnummer();
		 adresse.append(s.str());
		 adresse.append(" ");
		 s.str("");
	     }
	    }
	   
	    if(b)
	    {
	    adresscount++;	
	    Adresse a(adresse);
		adressen.push_back(a);
		adresse.clear();
		b=false;
	    }
		
	    }
	     
		 if(zeile.find("]>")!=string::npos)
	     {
		 p=true;
	     dtd.push_back(zeile);
	     c=false;
		 }
		 else
		 {
		 if(c)
	     dtd.push_back(zeile);
	     }
		
		if((zeile.find(elemente.at(i))!=string::npos) && p)
		{
			zeile.erase(remove(zeile.begin(), zeile.end(),' '), zeile.end());
			zeile.erase(remove(zeile.begin(), zeile.end(),'\n'), zeile.end());
		    if(i<2)
	      	{
			zeile.erase(remove(zeile.begin(), zeile.end(), '"'), zeile.end());
               while ((pos = zeile.find_first_of("<>=")) != string::npos) {
                      
                    
					   if(pos>0)
					   {
					   	 q++;
					     string str = zeile.substr(0, pos);
					      if(q==2)
                         {
                     	  adresse.append(str);
                          adresse.append(" ");
                          break;
					     }
                     	
                       
					   }
					   zeile.erase(0, pos + 1);
               }
            }
            else
            {
             zeile.erase(remove(zeile.begin(), zeile.end(), '/'), zeile.end());
              pos = string::npos;
              while ((pos = zeile.find_first_of("<>")) != string::npos) {
                    
                    
					if(pos>0)
                    {
                    q++;	
                     string str = zeile.substr(0, pos);
                     
		            
                     if(q==2)
                     {
                     	adresse.append(str);
                        adresse.append(" ");
                        break;
					 }
                     
                    }
		            zeile.erase(0, pos + 1);
                    }
					
		     }
        
		q=0;
		i++;
		if(i==7) 
		b=true;
		
		}
		
	   
		zeile.clear();
	
	
	}
	datei.close();
	
}



vector<Adresse> AdressListe::getAdresse(int Bestellnummer){
	
	vector<Adresse> b; 
	
	for(int i=0; i<adressen.size();i++){
	
	if(Bestellnummer==adressen.at(i).getBestellnummer())
    {
    b.push_back(adressen.at(i));
    } 
		
    }
     return b;
}

vector<Adresse> AdressListe::getAdressenSort(){

     int i=0;
     int j=0;
	 int n=0;
	vector<Adresse> b; 
	 
	 n=adressen.size();
	 
	 for(i=0;i<n;++i)
        b.push_back(adressen.at(i));
	 
	 	
 for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(b.at(j).getBestellnummer()>b.at(j+1).getBestellnummer())
            {

                  Adresse temp=b.at(j);
                  b.at(j)=b.at(j+1);
                  b.at(j+1)=temp;

             
            }
    }
    return b;
}

int AdressListe::adressenLaenge(){
	
	return adressen.size();
	
}

string AdressListe::getDTD(int i)
{
	return dtd.at(i);
}

int AdressListe::getDTDLaenge()
{
	return dtd.size();
}


