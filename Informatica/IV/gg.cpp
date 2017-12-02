#include "gg.h"
#include <iostream>
#include <cmath>
using namespace std;

int t = 0;

//constructor
grootgetal::grootgetal ( ) {
   ingang = NULL;
   uitgang = NULL;
   cout << "Welkom bij het programma Grote Getallen." << endl;
}//grootgetal
//destructor
grootgetal::~grootgetal ( ) {
}

//FUNCTIES GG
//print grote getallen
void grootgetal::printVA ( ) {
   cijfervakje* p = ingang; //hulppointer gaat lijst af ->
   cout << "||" ;
   while ( p != NULL ) {
      cout << p->info << " " ;
      p = p->volgende;
   }//while
   cout << "||" << endl;
} //printVA

void grootgetal::printAV ( ) {
	cijfervakje* p = uitgang; //hulppointer gaat lijst af <-
   cout << "||" ;
   while ( p != NULL ) {
      cout << p->info << " " ;
      p = p->vorige;
   }//while
   cout << "||" << endl;
} //printAV

//lees groot getal in
void grootgetal::leesin ( ) {
	int k = 4, getal = 0;
	char getalinvoer = '\n';
	while ( getalinvoer != '\n' ) {
		getalinvoer = cin.get();
		cout << "Ja" << endl;
		getal = getal * 10 + (getalinvoer - '0');
		if ( (getal*10) >= (pow(10, k)) ) {
			t++;
			voegachter(getal);
			getal = 0;
		}//if
	}//while
}//leesin

//HULPFUNCTIES GG
//voeg een cijfervakje met gegeven getal achteraan reeds gebouwde grote getal toe
void grootgetal::voegachter (int getal) {
	cijfervakje* hulp = new cijfervakje;
	hulp->info = getal;
	if (uitgang==NULL) {				//als lijst nog niet gemaakt is
		hulp->volgende = NULL;
		hulp->vorige = NULL;
		uitgang = hulp;
		ingang = hulp;
	}//if
	else {
		uitgang->volgende = hulp;
		hulp->vorige = uitgang;
		uitgang = hulp;
	} //else
}//voegachter

void grootgetal::voegvoor (int getal) {
	cijfervakje* hulp = new cijfervakje;
	hulp->info = getal;
	if (ingang==NULL) {
		hulp->volgende = NULL;
		hulp->vorige = NULL;
		ingang = hulp;
		uitgang = hulp;
	}//if
	else {
		ingang->vorige = hulp;
		hulp->volgende = ingang;
		ingang = hulp;
	}//else
}//voegvoor

//gooi alle door het grote getal gebruikte cijfervakjes weg
void grootgetal::vernietig ( ) {
}//vernietig

void grootgetal::kopieer ( ) {
}//kopieer

//FUNCTIES OVERIG

//optie inlezen
char inlees ( ) {
   char invoer = '\n';
   while (invoer == '\n') {
      invoer = cin.get( );
	}//while
	return invoer;
} //inlees

//INVOER MENU
void invoermenu (grootgetal & A) {
	cout << "Welk grote getal moet worden ingevoerd? Kies... [A] [B] [C]" << endl;
	switch (inlees ( )) {
		case 'a': case 'A':
			cout << "A:" << endl;
			A.leesin ( );
			break;
		case 'b': case 'B':
			cout << "B:" << endl;
			break;
		case 'c': case 'C':
			cout << "C:" << endl;
			break;
	}//switch
} //invoermenu

//PRINT MENU
void printmenu (grootgetal & A) {
	cout << "Welk grote getal moet worden geprint? Kies... [A] [B] [C]" << endl;
	switch (inlees ( )) {
		case 'a': case 'A':
			cout << "A:" << endl;
			A.printVA ( );
			break;
		case 'b': case 'B':
			cout << "B:" << endl;
			break;
		case 'c': case 'C':
			cout << "C:" << endl;
			break;
	}//switch
} //printmenu

//MENU
void menu (grootgetal & A) {
   while (true) {
      cout << "Kies uit... [i]nvoeren, [a]fdrukken, [o]ptellen, ";
      cout << "[v]ermenigvuldigen, [f]ibonacci, [s]toppen" << endl;
      switch (inlees ( )) {
         case 'i': case 'I':
         	invoermenu (A);
            break;
         case 'a': case 'A':
         	printmenu (A);
            break;
         case 'o': case 'O':
            cout << "Hier wordt opgeteld." << endl;
            break;
         case 'v': case 'V':
            cout << "Hier wordt vermenigvuldigd." << endl;
            break;
         case 'f': case 'F':
            cout << "Dit is de fibonacci functie." << endl;
            break;
         case 's': case 'S':
            cout << "Programma wordt ge-exit." << endl;
            return;
            break;
      } //switch MENU
   } //while
}//menu

