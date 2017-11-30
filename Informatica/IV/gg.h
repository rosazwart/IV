//struct cijfervakje
struct cijfervakje {
   public:
      cijfervakje* vorige;
      int info;
      cijfervakje* volgende;
}; //cijfervakje

//class grootgetal
class grootgetal {
   private:
      cijfervakje* ingang;      //begin vd rij cijfervakjes
      cijfervakje* uitgang;     //eind vd rij cijfervakjes
      int teller;              //aantal gebruikte cijfervakjes
   public:
      grootgetal ( );           //constructor declaratie
      ~grootgetal ( );          //destructor declaratie
      void print ( );
      void leesin ( );
      //void telop (gg1, gg2);
      //void fibonacci (n);
      //void vermenigvuldig (gg1, gg2);
      void maakaan (x);
      void voegachter ( );
      void maakeen ( );
      //void maaknullen (m);
      void vernietig ( );
      void kopieer ( );
}; //grootgetal
