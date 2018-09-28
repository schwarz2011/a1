TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    AdressListe.cpp \
    Adresse.cpp \
    BestellungsListe.cpp \
    Bestellung.cpp

HEADERS += \
    AdressListe.h \
    BestellungsListe.h \
    Adresse.h \
    Bestellung.h

DISTFILES += \
    ausgabe.xml \
    AdressListe.xml \
    AdressListe.txt \
    Bestellungsliste.txt
