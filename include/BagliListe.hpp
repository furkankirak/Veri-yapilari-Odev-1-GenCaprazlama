#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"
#include <string>

class BagliListe
{

public:
    BagliListe();
    ~BagliListe();
    void ekle(char veriChar);
    void cikar();
    void cikarHepsini();
    void yazdirChar();
    void satiriGetirBagliListeYap(int istenenSatir);
    void bagliListeyiSatiraEkle();
    void dosyayaYaz();
    //void mutasyonDegisikligi(int istenenSatir, int istenenGen);
    void mutasyonDegisikligiv2(int istenenSatir, int istenenGen);
    Dugum* dugumGetir(int sira);
    int dugumSayisi;

private:
    Dugum* ilk;
    
};
#endif