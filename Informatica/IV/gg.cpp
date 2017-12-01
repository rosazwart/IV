#include "gg.h"
#include <iostream>
using namespace std;

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
	cijfervakje* p = uitgang; //hulppointer gaat lijst af <-+
   cout << "||" ;
   while ( p != NULL ) {
      cout << p->info << " " ;
      p = p->vorige;
   }//while
   cout << "||" << endl;
} //printAV

//lees groot getal in
void grootgetal::leesin ( ) {
   int letterteller = 0;
   cout << "Als welk groot getal moet de invoer worden ingelezen? Kies..." ;
   cout << " [A] [B] [C]" << endl;
   int invoer_info = cin.get ( );
   maakaan (invoer_info);
   while ( invoer_info != '\n') {
      letterteller++;
      voegachter ( );
      invoer_info = cin.get;
   }//while
}//leesin

//HULPFUNCTIES GG
//voeg een cijfervakje met gegeven getal achteraan reeds gebouwde grote getal toe
void grootgetal::voegachter ( ) {
	element* hulp = new element;
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

void grootgetal::voegvoor ( ) {
	element* hulp = new element;
	hulp->info = n;
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
} //inlees

//PRINT MENU
void printmenu (grootgetal & A, & B, & C) {
	cout << "Welk grote getal moet worden geprint? Kies... [A] [B] [C]" << endl;
	case 'a': case 'A':
		cout << "A:" << endl;
		A.printAV ( );
		break;
	case 'b': case 'B':
		cout << "B:" << endl;
		B.printAV ( );
		break;
	case 'c': case 'C':
		cout << "C:" << endl;
		C.printAV ( );
		break;
} //printmenu

//MENU
void menu (grootgetal & A, & B, & C) {
   while (true) {
      cout << "Kies uit... [i]nvoeren, [a]fdrukken, [o]ptellen, ";
      cout << "[v]ermenigvuldigen, [f]ibonacci, [s]toppen" << endl;
      switch (inlees ( )) {
         case 'i': case 'I':
         
            break;
         case 'a': case 'A':
         	printmenu (A, B, C);
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

