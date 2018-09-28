Hinweis: Um den reibungslosen Ablauf des Programms zu gewährleisten, müssen die angefragten Dateien Adressliste.xml und Bestellungsliste.cpp im build-Ordner vorhanden sein, ansonsten läuft das Programm nicht richtig ab.

Entwurf und Beschreibung

Idee:

Bei einer Online-Bestellung sind die Adressen in einer XML-Instanz hinterlegt. Für die bessere Weiterverarbeitung, z.B. 
im Lager, werden die Bestellungen in einer Textdatei hinterlegt, die den Produktnamen, die Produktnummer, den Preis und die Menge beinhalten. Eine Software führt anhand einer Bestellnummer, Bestelladresse und weiterer Details über das Produkt 
aus der Textdatei zusammen. So können mit Hilfe der Software unter anderem alle zusammengeführten Datens‰tze angezeigt 
werden. 

Software-Entwurf:

Die Software soll im ersten Schritt aus zwei Datenquellen Informationen einlesen und zwischenspeichern. Die zwei 
Datenquellen beinhalten einmal die Adressinformationen und die Bestellinformationen, deshalb werden zwei Klassen erstellt, 
die ein Objekt Adresse und ein Objekt Bestellung erzeugen können. Der Konstruktor erstellt jeweils aus einem String
die entsprechenden Objekte, da der String (z.B. eine Textdatei bestehend aus Strings) die Informationen für das Objekt 
beinhaltet. Damit aber komplette Datenquellen analysiert werden können, müssen zwei weitere Klassen erstellt werden, und zwar eine Bestellliste und eine Adressliste, dessen Objekte die kompletten Daten aus den Datenquellen als Vektor
zwischenspeichern können. Dabei wird der Parsevorgang in den jeweiligen Konstruktoren vorgenommen. Dabei unterscheidet sich
der Parsevorgang, da es sich hier um zwei unterschiedliche Datenquellen handelt. Doch mit den ensprechenden Klassen
Bestellung und Adresse können beim Parsen deren Objekte erzeugt und in jeweilige Vektoren zwischengespeichert
werden. Da die so gewonnenen Informationen nun als Vektoren ungeordnet vorliegen, müssen die Daten anhand einer
Bestellnummer sotiert werden. Dieser Vorgang ist wichtig für die Konvertierung und Zusammenführung der Datenquelle in 
eine XML-Datei. Weiterhin wird für eine Menüführung ein CLI erstellt, z.B. in der Main, so können verschiedene Auswahlmöglichkeiten getroffen werden.

Parsung:

Die Textdatei stellt ein CSV-Format dar und ist somit einfach zu parsen, da CSV-Dateien aus Strings bestehen, die alle
Informationen für ein Objekt Bestellung beinhalten. Jede einzelne Zeile enthält somit die Werte für ein Objekt Bestellung 
und kann über den Stringstream (Konstruktor) eingelesen werden.
Die XML-Datei hingegen muss genauer analysiert werden, damit die relevanten Werte gefiltert werden können. Dafür müssen
zunächst die ensprechenden Zeilen gefunden und zusammengehörige Werte als String gespeichert werden; erst dann kann 
der Stringstream (Konstruktor) wie oben verwendet werden, um ein Objekt Adresse zu erstellen.        
