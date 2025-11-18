/**
* @file main.cpp
* @description Odevde istenen fonksiyonları ve ana ekranı gosterir
* @course 2-C(ikinci öğretim C şubesi)
* @assignment Birinci Odev
* @date 24.11.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include "BagliListe.hpp"
using namespace std;
const string Dnatxt = "Dna.txt";
const string Islemlertxt = "Islemler.txt";

void caprazlama(int istenenSatir,int istenenSatir2,bool cEkranaYazdirilsinMi){
    //Bagli liste sınıfından birinci kromozom olusturulmasi
    BagliListe* birinciKromozom = new BagliListe();
    //Bagli liste sınıfından ikinci kromozom olusturulmasi
    BagliListe* ikinciKromozom = new BagliListe();
    //Bagli liste sınıfından caprazlanan1 kromozom olusturulmasi
    BagliListe* caprazlananKromozom1 = new BagliListe();
    //Bagli liste sınıfından caprazlanan2 kromozom olusturulmasi
    BagliListe* caprazlananKromozom2 = new BagliListe();
    //Birinci ikinci kromozomları istenen satırlar için bagli liste oluşturup caprazlama oncesi hazirlik islemi,Ve ekrana yazdirilmasi
    birinciKromozom->satiriGetirBagliListeYap(istenenSatir);
    //gen sayisi 2den küçük olursa caprazlama yapilamayacagi icin boyle bir kosul ekliyoruz ve eger listede kromozom yoksa 0 dugum sayisi olacagi icin bunuda bi yandan kontrol etmiş oluyoruz
    if(birinciKromozom->dugumSayisi<2){
        cout<<"Birinci Kromozomun gen sayisi 2den kucuk yada belirtilen kromozom bulunamadigi icin caprazlama Basarisiz oldu islem yapilamadi"<<endl;
        delete birinciKromozom;
        delete ikinciKromozom;
        delete caprazlananKromozom1;
        delete caprazlananKromozom2;
        return;  
    }
    //eger ekrana yazdirilmasi isteniorsa yazdiracak kosul ifadesi
    if (cEkranaYazdirilsinMi==true)
    {
        cout<<"Kromozom-1: ";
        birinciKromozom->yazdirChar();
    }
    
    
    ikinciKromozom->satiriGetirBagliListeYap(istenenSatir2);
     //gen sayisi 2den küçük olursa caprazlama yapilamayacagi icin boyle bir kosul ekliyoruz ve eger listede kromozom yoksa 0 dugum sayisi olacagi icin bunuda bi yandan kontrol etmiş oluyoruz
    if(ikinciKromozom->dugumSayisi<2){
        cout<<"Ikinci Kromozomun gen sayisi 2den kucuk yada belirtilen kromozom bulunamadigi icin caprazlama Basarisiz oldu islem yapilamadi"<<endl;
        delete birinciKromozom;
        delete ikinciKromozom;
        delete caprazlananKromozom1;
        delete caprazlananKromozom2;
        return;
    }
    //eger ekrana yazdirilmasi isteniorsa yazdiracak kosul ifadesi
    if (cEkranaYazdirilsinMi==true)
    {
        cout<<"Kromozom-2: ";
        ikinciKromozom->yazdirChar();
    }

    //Islem karmasasini onlemek adina birinci kromozomun dugum sayisinin degiskene atamasi
    int birinciDS=birinciKromozom->dugumSayisi;
    //Islem karmasasini onlemek adina ikinci kromozomun dugum sayisinin degiskene atamasi
    int ikinciDS = ikinciKromozom->dugumSayisi;
    //caprazlanan kromozomlardan birincisinin olusturulma islemi
    if(birinciDS % 2 == 0){
        for (int i = 0; i < birinciDS/2; i++)
        {
            caprazlananKromozom1->ekle(birinciKromozom->dugumGetir(i)->veriChar);  
        }
    }else{
        for (int i = 0; i < birinciDS/2; i++)
        {
            caprazlananKromozom1->ekle(birinciKromozom->dugumGetir(i)->veriChar);
        }

    }

    if(ikinciDS % 2 == 0){
        for (int i = ikinciDS/2; i < ikinciDS; i++)
        {
            caprazlananKromozom1->ekle(ikinciKromozom->dugumGetir(i)->veriChar);
        }
    }else{
        for (int i = ikinciDS/2+1; i < ikinciDS; i++)
        {
            caprazlananKromozom1->ekle(ikinciKromozom->dugumGetir(i)->veriChar);
        }
    }

    //caprazlanan kromozomlardan ikincisinin olusturulma islemi
    if(birinciDS % 2 == 0){

        for (int i = birinciDS/2; i < birinciDS; i++)
        {
            caprazlananKromozom2->ekle(birinciKromozom->dugumGetir(i)->veriChar);
        }
        
    }else{
        for (int i = birinciDS/2+1; i < birinciDS; i++)
        {
            caprazlananKromozom2->ekle(birinciKromozom->dugumGetir(i)->veriChar);
        }

    }

    if(ikinciDS % 2 == 0){

        for (int i = 0; i < ikinciDS/2; i++)
        {
            
            caprazlananKromozom2->ekle(ikinciKromozom->dugumGetir(i)->veriChar);
            
        }      

    }else{
        for (int i = 0; i < ikinciDS/2; i++)
        {
            caprazlananKromozom2->ekle(ikinciKromozom->dugumGetir(i)->veriChar);
        }

    }
    //eger ekrana yazdirilmasi isteniorsa caprazlanan kromozomlarin ekrana yazilisi ve dosyaya ekleme isleminin kosul ifadesi
    if (cEkranaYazdirilsinMi==true)
    {
        cout<<"Caprazlanan 1.Kromozom: ";
        caprazlananKromozom1->yazdirChar();
        cout<<"Caprazlanan 2.Kromozom: ";
        caprazlananKromozom2->yazdirChar();
    }
    //bagli listelerin satir sonuna eklenme islemi
    caprazlananKromozom1->bagliListeyiSatiraEkle();
    caprazlananKromozom2->bagliListeyiSatiraEkle();
    //Alanlarla isimiz kalmadigi icin serbest birakiorz
    delete birinciKromozom;
    delete ikinciKromozom;
    delete caprazlananKromozom1;
    delete caprazlananKromozom2;
  
}
/*void mutasyon(int istenenSatir,int istenenGen){
    //mutasyon islemi icin listedeki elemanlari bi listenin icine atiorz
    BagliListe* listem= new BagliListe();
    ifstream okuMutasyon(Dnatxt);
    string satir;
    char gen;
    //ilk satiri yazmasi için ilk satir için bir kez çaliştiriorz
    while(okuMutasyon.get(gen))
        {
            //ilk indeksi seçmesi için gerekli koşul ifadesi
        if(gen=='\n'){
             
        }
        if(gen== ' '){

        }else{
            listem->ekle(gen);
        }
         
        }

        listem->ekle('\n');
        //satir satir gezip listeye ekleyip \n ile beraber birden fazla listeymis gibi goruyoruz bu sayede tek bi liste ile tum elemanlari yonetebiliyoruz
    while(getline(okuMutasyon,satir))
    {

        while(okuMutasyon.get(gen))
        {
        if(gen== ' '){

        }else{
            listem->ekle(gen);
        }

        }
        listem->ekle('\n');     
    }
    //son satira gereksiz \n fonksiyonu eklememsi için son satirdaki \n ifadesini görünce cikar islemini calistiriorz
        while(listem->dugumGetir(listem->dugumSayisi-1)->veriChar == ' ' || listem->dugumGetir(listem->dugumSayisi-1)->veriChar == '\n')
        {
            listem->cikar();
        }

    //isimiz bitince dosyayi kapatiyoruz.
    okuMutasyon.close();
    //ilgili mutasyon degisikligini yapip tekrar dosyayi guncelliyoruz ve bunlari ekrana yaziyoruz
    listem->mutasyonDegisikligi(istenenSatir,istenenGen);
    //listem->dosyayaYaz();
    //listem->yazdirChar();
    delete listem;

}
*/
void mutasyonv2(int istenenSatir,int istenenGen,bool mEkranaYazdirilsinmi){
    //mutasyon islemi icin bagli listeden yer alimi
    BagliListe* secilenKromozom= new BagliListe();
    //secilen kromozomu istenen satirdan bulup bagli liste yapiyoruz
    secilenKromozom->satiriGetirBagliListeYap(istenenSatir);
    //hata kontrollerini yapioruz
    if (secilenKromozom->dugumSayisi<=0)
    {
        cout<<"Kromozom Limitleri icerisinde secim yapmadiginiz icin mutasyon islemi yapilamadi"<<endl;
        delete secilenKromozom;
        return;
    }
    if (secilenKromozom->dugumSayisi-1<istenenGen || istenenGen<0)
    {
        cout<<"Gen Limitleri icerisinde secim yapmadiginiz icin mutasyon islemi yapilamadi"<<endl;
        delete secilenKromozom;
        return;
    }
    //eger ekrana yazdirilmasi isteniorsa yazdiracak kosul ifadesi
    if(mEkranaYazdirilsinmi==true){
        cout<<"Secilen Kromozom: ";
        secilenKromozom->yazdirChar();
    }

    //ilgili mutasyon degisikligi yapilmasi icin cagrilan fonksiyon
    secilenKromozom->mutasyonDegisikligiv2(istenenSatir,istenenGen);
    //eger ekrana yazdirilmasi isteniorsa yazdiracak kosul ifadesi
    if(mEkranaYazdirilsinmi==true){
        cout<<"Mutasyon Kromozom: ";
        secilenKromozom->yazdirChar();
    }
    //isimiz bitince alani serbest birakiorz
    delete secilenKromozom;

}
void otomatikIslemler(bool otomatikIslemlerYazdirilsinmi)
{
    //otomatik islemler icin Islemler Txt yi okuyup yazilmis formatina gore atamasını yapiyoruz
    ifstream okuIslem(Islemlertxt);
    char yazilanIslem,islem;
    int istenenSatir,satir;
    int istenenSutun,sutun;
    bool hataVarmi=false;

    //Dongu ile tum elemanlarini kontrol ediyoruz ve islem caprazlama mi mutasyon mu ogreniyoruz ve istenen islemi gerceklesitriorz
    while(okuIslem >> yazilanIslem >> istenenSatir >> istenenSutun)
    {
        islem=yazilanIslem;
        satir=istenenSatir;
        sutun=istenenSutun;
       
        if(islem=='C'){
            caprazlama(istenenSatir,istenenSutun,otomatikIslemlerYazdirilsinmi);
        }else if(islem=='M'){
            mutasyonv2(istenenSatir,istenenSutun,otomatikIslemlerYazdirilsinmi);
        }else{
             //varsa sorun bildiriyoruz yoksa islemler tamamlandi yazisini gosteriorz
            cout<<"Belirtilen "<<islem<<" islemi bulunamadi"<<endl;
            hataVarmi=true;
        }
        
    }
    if (hataVarmi==true)
    {
        cout<<"Belirtilen islemlerde hata olan Islemler Tamamlanamadi"<<endl;
        cout<<"Sorunsuz islemler Tamamlandi"<<endl;
    }
    if(hataVarmi==false)
    {
        cout<<"Islemler Tamamlandi"<<endl;
    }
    
        
    //dosya ile isimiz bitince dosyayi kapatiorz
    okuIslem.close();

}
void ekranaYaz(){
    //ekrana yaz fonksiyonu icin oncelikle bir isaretci atamasi yapiorz
    ifstream oku(Dnatxt);
    BagliListe* satirim = new BagliListe();
    string satirOkuma;
    //listedeki satirlara erismek icin kullanilan sayac
    int sayac =0;
    //Hangi genin yazilacagini belirlemek icin atanan degisken
    char genKarsilastirma;
    //satirlari gezmek icin kullanilan while yapisi
    while (getline(oku,satirOkuma))
    {
        //satirlari tek tek bagli liste yapip for dongusune hazirlayan degisken
        satirim->satiriGetirBagliListeYap(sayac);
        if (satirim->dugumSayisi<=0)
        {
            sayac++;
            genKarsilastirma = 0; 
            continue;
        }
        
        //hazirlanmis bagli listelerin genlerini karsilastiran for dongusu   
        for(int i = satirim->dugumSayisi-1;i>0;i--)
        {
            if(satirim->dugumGetir(0)->veriChar > satirim->dugumGetir(i)->veriChar)
            {
                genKarsilastirma = satirim->dugumGetir(i)->veriChar;
                
                satirim->cikarHepsini();
                break;
            }  
        }
        if(genKarsilastirma ==0){
            
            genKarsilastirma=satirim->dugumGetir(0)->veriChar;    
            satirim->cikarHepsini();
        }

        sayac++;
        cout<<genKarsilastirma<<' ';
        genKarsilastirma = 0;     
    }
    cout<<endl;
    //isimiz bitince dosyayi kapatiyoruz
    oku.close();
    //isimiz bitince alani serbest birakiorz
    delete satirim;
}

int main()
{
    //Programin acik kalmasi icin while dongusu icinde islemlerin yazdirilmasi islemi
    //islemi sonlandiracak bool atamasi
    bool islemSonlandir=false;
    //kullanicidan istenecek satir sutun bilgisi
    int satir,sutun;
    //caprazlama ayari
    bool caprazlamaEkranaYazdirilsinmi=true;
    //caprazlama verilen icin girilicek deger atamasi
    char caprazlamaC='E';
    //mutasyon ayari
    bool mutasyonEkranaYazdirilsinmi=true;
    //mutasyon verilen icin girilicek deger atamasi
    char mutasyonC='E';
    //otomatik islem ayari
    bool otomatikIslemlerYazdirilsinmi=false;
    //otomatik islemler verilen icin girilicek deger atamasi
    char otomatikIslemlerC='H';
    //ayarlar dongusu icin gerekli bool
    bool ayarlar=false;
    //Hangi islemin secilecegi ile ilgili int
    int islem,ayarlarIslem;

    while (islemSonlandir==false)
    {

        cout<<"1-)Caprazlama"<<endl;
        cout<<"2-)Mutasyon"<<endl;
        cout<<"3-)Otomatik islemler"<<endl;
        cout<<"4-)Ekrana yaz"<<endl;
        cout<<"5-)Ayarlar"<<endl;
        cout<<"0-)Cikis"<<endl;
        cout<<"Yapmak Istediginiz Islemi Giriniz: ";
        cin>>islem;
        cout<<endl;
        if(islem==1){
            cout<<"Ilk kromozom seciminizi yapin: ";
            cin>>satir;
            cout<<"Ikinci kromozom seciminizi yapin: ";
            cin>>sutun;
            caprazlama(satir,sutun,caprazlamaEkranaYazdirilsinmi);
        }
        if(islem==2){
            cout<<"Kromozom seciminizi yapin: ";
            cin>>satir;
            cout<<"Gen seciminizi yapin: ";
            cin>>sutun;
            mutasyonv2(satir,sutun,mutasyonEkranaYazdirilsinmi);      
        }
        if(islem==3){
            otomatikIslemler(otomatikIslemlerYazdirilsinmi);  
        }
        if(islem==4){
            ekranaYaz();  
        }
        if(islem==5){
            ayarlar=true;
            while (ayarlar==true)
            {
                cout<<"1-)Caprazlama Ayari"<<endl;
                cout<<"2-)Mutasyon Ayari"<<endl;
                cout<<"3-)Otomatik islemler Ayari"<<endl;
                cout<<"0-)Geri"<<endl;
                cout<<"Yapmak Istediginiz Islemi Giriniz: ";
                cin>>ayarlarIslem;
                if (ayarlarIslem==1)
                {
                    cout<<"Guncel Hali :"<<caprazlamaC<<endl;
                    cout<<"Caprazalama Ekrana Yazdirilsin mi E/H: ";
                    cin>>caprazlamaC;
                    if (caprazlamaC=='E' || caprazlamaC=='e')
                    {
                        caprazlamaEkranaYazdirilsinmi=true;
                    }else if(caprazlamaC=='H' || caprazlamaC=='h'){
                        caprazlamaEkranaYazdirilsinmi=false;
                    }else{
                        cout<<"Hatali giris Yaptiniz"<<endl;
                    }
                
                }
                if (ayarlarIslem==2)
                {
                    cout<<"Guncel Hali :"<<mutasyonC<<endl;
                    cout<<"Mutasyon Ekrana Yazdirilsinmi E/H: ";
            
                    cin>>mutasyonC;
                    if (mutasyonC=='E' || mutasyonC=='e')
                    {
                        mutasyonEkranaYazdirilsinmi=true;
                    }else if(mutasyonC=='H' || mutasyonC=='h'){
                        mutasyonEkranaYazdirilsinmi=false;
                    }else{
                        cout<<"Hatali giris Yaptiniz"<<endl;
                    }
                }
                if (ayarlarIslem==3)
                {
                    cout<<"Guncel Hali :"<<otomatikIslemlerC<<endl;
                    cout<<"Otomatik Islemler Ekrana Yazdirilsinmi E/H: ";
                    cin>>otomatikIslemlerC;
                    if (otomatikIslemlerC=='E' || otomatikIslemlerC=='e')
                    {
                        otomatikIslemlerYazdirilsinmi=true;
                    }else if(otomatikIslemlerC=='H' || otomatikIslemlerC=='h'){
                        otomatikIslemlerYazdirilsinmi=false;
                    }else{
                        cout<<"Hatali giris Yaptiniz"<<endl;
                    }
                }
                if (ayarlarIslem==0)
                {
                    ayarlar=false;
                }
            }   
        }
        if(islem==0){
            islemSonlandir=true;
        }
    }
}
