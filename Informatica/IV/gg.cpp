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
void grootgetal::print ( ) {
    cout << "Welk grote getal moet worden geprint? Kies... [A] [B] [C]" << endl;
} //print

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
   cijfervakje* hulp;
   hulp = new cijfervakje;

}//voegachter

//grote getal stelt het (kleine) getal 1 voor: een cijfervakje
void grootgetal::maakeen ( ) {
}//maakeen

//maak een "groot getal" bestaande uit m cijfervakjes met 0 erin
//void grootgetal::maaknullen (m) {
//}//maaknullen

//gooi alle door het grote getal gebruikte cijfervakjes weg
void grootgetal::vernietig ( ) {
}//vernietig

//
void grootgetal::kopieer ( ) {
}//kopieer

//FUNCTIES CIJFERVAKJE

//FUNCTIES OVERIG

//optie inlezen
char inlees ( ) {
   char invoer, uitvoer;
   while (invoer != '\n') {
      invoer = cin.get( );
      if (invoer != '\n') {
         uitvoer = invoer;
      }//if
   } //while
   return uitvoer;
} //inlees

//dit is het MENU
void menu (grootgetal & gg) {
   while (true) {
      cout << "Kies uit... [i]nvoeren, [a]fdrukken, [o]ptellen, ";
      cout << "[v]ermenigvuldigen, [f]ibonacci, [s]toppen" << endl;
      switch (inlees ( )) {
         case 'i': case 'I':
            gg.leesin ( );
            break;
         case 'a': case 'A':
            gg.print ( );
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

