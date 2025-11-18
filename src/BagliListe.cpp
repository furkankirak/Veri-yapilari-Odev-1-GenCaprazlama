/**
* @file BagliListe.cpp
* @description Bagli liste yapısı ve destek fonksiyonlari
* @course 2-C(ikinci öğretim C şubesi)
* @assignment Birinci Odev
* @date 24.11.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "BagliListe.hpp"
#include <iostream>
#include <fstream>
using namespace std;
const string Dnatxt = "Dna.txt";
BagliListe::BagliListe(){

    ilk=0;
    dugumSayisi=0;
}

BagliListe::~BagliListe(){

    Dugum* gec = ilk;

    while (gec!=0)
    {
        Dugum* sil=gec;
        gec=gec->sonraki;
        delete sil;
    }
    dugumSayisi=0;
    ilk=0;

}
//BagliListe elemanlarini eklemek icin kullanilan fonksiyon
void BagliListe::ekle(char veriChar){
    Dugum* yeni = new Dugum(veriChar);
    if (ilk ==0){
        ilk=yeni;
        dugumSayisi++;
        return;
    }else
    {
        Dugum* gec = ilk;
        while(gec->sonraki !=0){
            gec=gec->sonraki;
        }
        gec->sonraki =yeni;
        yeni->onceki=gec;
        dugumSayisi++;
    }
}
//BagliListe elemanlarini cikarmak icin kullanilan fonksiyon
void BagliListe::cikar(){
    if (ilk ==0){
        return ;
    }
    if (ilk->sonraki==0){
        delete ilk;
        ilk =0;
        dugumSayisi--;
    }else
    {
        Dugum* gec = ilk;
        while(gec->sonraki->sonraki !=0){
            gec=gec->sonraki;
        }
        delete gec->sonraki;
        gec->sonraki=0;
        dugumSayisi--;
    }
}
//BagliListe elemanlarinin hepsini cikarmak icin  ihtiyaca yonelik olusturulmus fonksiyon
void BagliListe::cikarHepsini(){

    while(ilk!=0)
    {
        if (ilk ==0)
        {
        return ;
        }
        if (ilk->sonraki==0)
        {
        delete ilk;
        ilk =0;
        }
        else
        {
        Dugum* gec = ilk;
        while(gec->sonraki->sonraki !=0){
            gec=gec->sonraki;
        }
        delete gec->sonraki;
        gec->sonraki=0;
        }
    }
    dugumSayisi=0;
    ilk=0;
    
    
}
//BagliListe elemanlarinin icerigini gosterip ekrana yansitan fonksiyon
void BagliListe::yazdirChar(){
    Dugum* gec = ilk;
        while(gec!=0){
            
            cout<<gec->veriChar<<' ';
            gec=gec->sonraki;
        }
        cout<<endl;

}
//BagliListe elemanlarinin dugumlerinden istenilen dugumun getirilmesini saglayan fonksiyon
Dugum* BagliListe::dugumGetir(int sira){

    if (sira<0 || sira>dugumSayisi)
    {
        return 0;
    }
    else{
        Dugum* gec = ilk;
        int sayac=0;
        while (gec !=0)
        {
            if(sira==sayac){
                return gec;
            }
            gec=gec->sonraki;
            sayac++;
        }

    }

}
//BagliListe elemanlarinin okunan txt dosyasindan istenen satirin getirilip onu bagliliste yapilmasini saglayan fonksiyon
void BagliListe::satiriGetirBagliListeYap(int istenenSatir){
    ifstream oku(Dnatxt);
    //genlerin kontrolu ve eklenmesi icin gerekli olan atama
    char gen;
    string satir;
    int satirSayisi =1;
    if(istenenSatir==0){

    }else{
        //istenen satiri bulmak icin gerekli dongu
        while(getline(oku,satir))
        {
            if (satirSayisi==istenenSatir)
            {
                break;
            }
        satirSayisi++;    
        }
    }
        //satiri bulduktan sonra gen gen kromozom ekleme islemi    
        while(oku.get(gen))
        {
        if(gen=='\n'){
             break;
        }
        if(gen== ' '){

        }else{
            ekle(gen);
        }
         
        }
    //isimiz bitince dosyayi kapatiyoruz
    oku.close();
}
//BagliListe olusturulmus satiri dosyanin sonuna ekleme islemini yapan fonksiyon
void BagliListe::bagliListeyiSatiraEkle(){

    ofstream yaz(Dnatxt,ios::app);
    //bir alt satira gecip yazma islemi yapmasi icin eklenmesi gerekiyor aksi taktirde listenin sonundaki kromozomun sonuna dogrudan ekleyecekti
    yaz.put('\n');
    //elemeanlari dongu seklinde listeye geri yaziyoruz istenen format CHAR BOSLUK oldugu icin her chardan sonra bi bosluk atamasiyla duzeni bozmuyoruz
    for(int i=0;i<dugumSayisi;i++)
    {
        yaz.put(dugumGetir(i)->veriChar);
        yaz.put(' ');
    }
    //isimiz bitince dosyayi kapatiyoruz
    yaz.close();
}
//BagliListe olusturulmus listeyi dosyaya yazan fonksiyon
void BagliListe::dosyayaYaz(){
    ofstream yaz(Dnatxt);
    Dugum* gec = ilk;
    //olusturulmus listeyi dosyaya yazma dongusu
    while (gec!=0){
        if(yaz.eof()){
            break;
        }
        yaz << gec->veriChar;
        //satir sonundan sonra ekstra bosluk yapip dosya duzeni bozmasını engellememesi icin gerekli kontrol
        if(gec->veriChar != '\n'){
            yaz << ' ';
        } 
        gec=gec->sonraki;
    }
    //isimiz bitince dosyayi kapatiyoruz
    yaz.close();
}
//Mutasyon fonksiyonu icin gerekli degisikligi yapan fonksiyon
void BagliListe::mutasyonDegisikligiv2(int istenenSatir, int istenenGen){
    //gecici degisken atamasi
    Dugum* gec = ilk;
    //istenen gen sirasini bulmak icin gerekli destek atamasi
    int indeks = 0;
    bool hataVarmi=true;
    //istenen sutundaki geni bulmayi ve degistirmek saglayan dongu
    while (gec !=0)
    {
        if(indeks == istenenGen)
        {
            gec->veriChar = 'X';
            hataVarmi=false;
            return; 
        }
      
            indeks++;
    //eger satir sonuna gelmissek satir sayisini arttirip sutunu sifirliyoruz ki dongu dogru bi sekilde ilerlesin

    gec= gec->sonraki;
    }
    //eger gen limitlerini asiyorsak bunu bildirmek icin gerekli koşul ifadesi
    // if(hataVarmi=true || indeks<0)
    // {
    //     cout<<"Gen Limitleri icerisinde secim yapmadiginiz icin mutasyon islemi yapilamadi"<<endl;
    //     return;
    // }

}
//Mutasyon fonksiyonu icin gerekli degisikligi yapip dosyaya tekrar yazan fonksiyon
/*void BagliListe::mutasyonDegisikligi(int istenenSatir, int istenenGen)
{
    //gecici degisken atamasi
    Dugum* gec = ilk;
    //istenen satir sayini bulmak icin gerekli destek atamasi
    int satirSayisi =0;
    //istenen gen sirasini bulmak icin gerekli destek atamasi
    int indeks = 0;
    bool hataVarmi=true;
    //istenen sutundaki geni bulmayi ve degistirmek saglayan dongu
    while (gec !=0)
    {
        if(satirSayisi== istenenSatir)
        {
            if(indeks == istenenGen)
            {
                gec->veriChar = 'X';
                hataVarmi=false;
                return; 
            }
      
            indeks++;
        }
    //eger satir sonuna gelmissek satir sayisini arttirip sutunu sifirliyoruz ki dongu dogru bi sekilde ilerlesin
    if (gec->veriChar=='\n')
    {
        satirSayisi++;
        indeks=0;
        
    }
    gec= gec->sonraki;
    }
    //eger kromozom limitlerini asiyorsak bunu bildirmek icin gerekli koşul ifadesi
    if(istenenSatir>satirSayisi || satirSayisi<0){
        bool hataVarmi=false;

        cout<<"Kromozom Limitleri icerisinde secim yapmadiginiz icin mutasyon islemi yapilamadi"<<endl;
        return;
    }
    //eger gen limitlerini asiyorsak bunu bildirmek icin gerekli koşul ifadesi
    if(hataVarmi=true || indeks<0)
    {
        cout<<"Gen Limitleri icerisinde secim yapmadiginiz icin mutasyon islemi yapilamadi"<<endl;
        return;
    }

    
}
*/