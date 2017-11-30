//
// Programmeermethoden 2017
//
// http://www.liacs.nl/home/kosters/pm/dubbel.cc
// C++-programma om te oefenen in het gebruik van pointers, deel 2.
// Er moet een dubbelverbonden pointerlijst gefabriceerd worden,
// waarbij de "elementen" die met elkaar verbonden worden bestaan uit
//   1. Een int(eger)
//   2. Een pointer naar het vorige element (of NULL)
//   3. Een pointer naar het volgende element (of NULL)
// Schrijf de functies afdrukken (2x) en bouwlijst. Gebruik een eigen
// hulpfunctie voegvoor.
//
// Compiler: GNU g++
// Datum: 1 november 2017
// Auteur: Walter Kosters, Informatica Universiteit Leiden
//         email w.a.kosters@liacs.leidenuniv.nl
//

#include <iostream>
using namespace std;

class element {
  public:
    element* vorige;
    int info;
    element* volgende;
};//element

class lijst {
  private:
    element* ingang;
    element* uitgang;
  public:
    lijst ( );
    void afdrukkenVA ( );
    void afdrukkenAV ( );
    void bouwlijst (int n);
    void bouwachter (int n);
    void grabstuff ( );
};//lijst

//   +-----+      +-----+----+-----+        +-----+----+-----+      +-----+
//   |   --+----> | NULL| 10 |   --+------> |  |  | 20 | NULL| <----+--   |
//   +-----+      +-----+--+-+-----+        +-----+--+-+-----+      +-----+
//  L.ingang                    ^---------------                   L.uitgang
//
// L.ingang (L van klasse lijst) wijst dus het eerste element uit een serie
// elementen aan, waarbij ieder element informatie bevat (het info-veld),
// en twee pointers: naar het vorige en volgende element;
// voor het voorbeeld hierboven zijn in totaal twee new's nodig.

//constructor
lijst::lijst ( ) {
  ingang = NULL;
  uitgang = NULL;
}//lijst::lijst

// druk lijst af, van voor naar achter
void lijst::afdrukkenVA ( ) {
   element* p = ingang; //hulppointer gaat lijst af ->
   cout << "ingang->uitgang" << endl;
   cout << "||" ;
   while ( p != NULL ) {
      cout << p->info << "|" ;
      p = p->volgende;
   }//while
   cout << "||" << endl;
}//lijst::afdrukkenVA

// druk lijst af, van achter naar voor
void lijst::afdrukkenAV ( ) {
   element* p = uitgang; //hulppointer gaat lijst af <-
   cout << "uitgang -> ingang" << endl;
   cout << "||" ;
   while ( p != NULL ) {
      cout << p->info << "|" ;
      p = p->vorige;
   }//while
   cout << "||" << endl;
}//lijst::afdrukkenAV

// maak lijst met n elementen, bevattende 10,20,...,10*n
void lijst::bouwlijst (int n) {
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
			}
}//lijst::bouwlijst


// maak lijst met n elementen, bevattende 10,20,...,10*n
void lijst::bouwachter (int n) {
	    element* hulp = new element;
	    hulp->info = n;
				if (uitgang==NULL) {
				hulp->volgende = NULL;
				hulp->vorige = NULL;
				uitgang = hulp;
				ingang = hulp;
			}//if
			else {
				uitgang->volgende = hulp;
				hulp->vorige = uitgang;
				uitgang = hulp;
			}
}//lijst::bouwlijst

void lijst::grabstuff()
{
	int test = 0;
	while(cin.get() != '\n'){
		test = cin.get();
		test = test * 10 + cin.get();
		bouwlijst(test);
		}
}

int main () {
  lijst L;
  L.grabstuff ();
  L.bouwlijst (5);
  L.bouwlijst (4);
  L.bouwlijst (5);
  L.bouwlijst (5);
  L.bouwlijst (2);
  L.bouwlijst (1);
    
	L.afdrukkenVA ( );
  L.afdrukkenAV ( );
  return 0;
}//main

