# a1

Den Inhalt in Word kopieren und eine PDF Datei erstellen
------------------------------------------------------------------------------------

Entwurf und Beschreibung

Idee:

Bei einer Online-Bestellung sind die Adressen in einer XML-Instanz hinterlegt. F¸r die bessere Weiterverarbeitung z.B. 
im Lager werden die Bestellungen in einer Textdatei hinterlegt die den Produktnamen, Produktnummer,Preis und Menge 
beinhaltet. Eine Software f¸hrt, anhand einer Bestellnummer, Bestelladresse und die weiteren Details ¸ber das Produkt 
aus der Textdatei zusammen. So kˆnnen mit Hilfe der Software unter anderem alle zusammengef¸hrten Datens‰tze angezeigt 
werden. 

Software-Entwurf:

Die Software soll im ersten Schritt aus zwei Datenquellen Informationen einlesen und zwischenspeichern. Die zwei 
Datenquellen beinhalten einmal die Adressinformationen und die Bestellinformationen. Deshalb werden zwei Klassen erstellt 
die einen Objekt Adresse und einen Objekt Bestellung erzeugen kˆnnen. Der Konstruktor erstellt jewals aus einem String
die entsprechenden Objekte, da der String (z.B. eine Textdatei bestehend aus Strings) die Informationen f¸r das Objekt 
beinhaltet. Damit aber komplette Datenquellen analysiert werden kˆnnen m¸ssen zwei weitere Klassen erstellt werden. 
Einmal eine Bestellliste und eine Adressliste, dessen Objekte die kompletten Daten aus den Datenquellen als Vektor
zwischenspeichern kˆnnen. Dabei wird der Parsevorgang in den jewaligen Konstruktoren vorgenommen. Dabei unterscheidet sich
der Parsevorgang da es sich hier um zwei unterschiedliche Datenquellen handelt. Doch mit den ensprechenden Klassen
Bestellung und Adresse kˆnnen beim Parsen deren Objekte erzeugt werden und in jewalige Vektoren zwischengespeichert
werden. Da die so gewonnen Informationen nun als Vektoren ungeordnet vorliegen m¸ssen die Daten anhand einer
Bestellnummer sotiert werden. Dieser Vorgang ist wichtig f¸r die Konvetierung und zusammenf¸hrung der Datenquelle in 
eine XML Datei. Weiterhin wird f¸r eine Men¸f¸hrung ein CLI erstellt z.B. in der Main, so kˆnnen verschiedene Auswahl-
mˆglichkeiten getroffen werden.

(Bild einf¸gen z.B. Klassendiagramm welche die Zusammenh‰nge der Klassen darstellt)

Parsung:

Die Textdatei stellt ein CSV Format dar und ist somit einfach zu parsen, da CSV Dateien aus Strings bestehen die alle
Informationen f¸r ein Objekt Bestellung beinhalten. Jede einzelne Zeile enth‰lt somit die Werte f¸r ein Objekt Bestellung 
und kann ¸ber den Stringstream(Konstruktor) eingelesen werden.

(Bild f¸r die Parsung der CSV Datei einf¸gen)

Die XML Datei hingegen muss genauer analysiert werden damit die relevanten Werte gefiltert werden kˆnnen, dazu m¸ssen
zun‰chst die ensprechenden Zeilen gefunden werden, zusammengehˆrige Werte als String gespeichert werden und dannach kann 
der Stringstream(Konstruktor) wie oben benutzt werden um ein Objekt Adresse zu erstellen.

(Bild f¸r die Parsung der XML Datei einf¸gen)         
