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
      int teller;               //aantal gebruikte cijfervakjes
   public:
      grootgetal ( );           //constructor declaratie
      ~grootgetal ( );          //destructor declaratie
      int getal;
      void print ( );
      void leesin ( );
      void voegachter ( );
      void voegvoor ( );
      void vernietig ( );
      void kopieer ( );
}; //grootgetal
