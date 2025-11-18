# Veri Yapıları Ödev 1: Gen Çaprazlama

Bu proje, C++ dilinde çift yönlü bağlı listeler kullanılarak genetik çaprazlama ve mutasyon operasyonlarını simüle eden bir komut satırı uygulamasıdır. Program, DNA dizilerini bir metin dosyasından okur, belirtilen işlemleri uygular ve sonuçları günceller.

## Genel Bakış

Uygulama, temel olarak `Dna.txt` dosyasındaki kromozomlar üzerinde çalışır. Her satır bir kromozomu, her karakter ise bir geni temsil eder. `Islemler.txt` dosyasından okunan komutlarla veya kullanıcı tarafından interaktif olarak girilen komutlarla genetik operasyonlar gerçekleştirilir.

## Özellikler

- **Gen Çaprazlama (`Caprazlama`):** Belirtilen iki kromozomu (satırı) alır, bu kromozomları orta noktalarından bölerek parçalarını değiştirir ve sonuçta oluşan iki yeni kromozomu `Dna.txt` dosyasının sonuna ekler.
- **Gen Mutasyonu (`Mutasyon`):** Belirtilen bir kromozomdaki belirli bir geni 'X' karakteri ile değiştirir. Bu işlem bellekte gerçekleştirilir ve sonucu isteğe bağlı olarak ekranda gösterilir.
- **Otomatik İşlemler:** `Islemler.txt` dosyasında tanımlanan çaprazlama ('C') ve mutasyon ('M') komutlarını sırayla otomatik olarak çalıştırır.
- **Etkileşimli Konsol Arayüzü:** Kullanıcının işlemleri menü üzerinden seçerek manuel olarak tetiklemesine olanak tanır.
- **Yapılandırılabilir Çıktı:** Ayarlar menüsü üzerinden, yapılan çaprazlama ve mutasyon işlemlerinin sonuçlarının konsola yazdırılıp yazdırılmayacağı ayarlanabilir.

## Dosya Yapısı

```
.
├── Dna.txt                 # Kromozom verilerini içeren girdi dosyası
├── Islemler.txt            # Otomatik işlemler için komutları içeren dosya
├── makefile                # Projeyi derlemek ve çalıştırmak için talimatlar
├── bin/
│   └── program             # Derlenmiş çalıştırılabilir dosya
├── include/
│   ├── BagliListe.hpp      # Çift Yönlü Bağlı Liste sınıfının başlık dosyası
│   └── Dugum.hpp           # Bağlı Liste düğüm sınıfının başlık dosyası
└── src/
    ├── BagliListe.cpp      # Bağlı Liste sınıfının uygulama dosyası
    ├── Dugum.cpp           # Düğüm sınıfının uygulama dosyası
    └── main.cpp            # Ana program mantığını ve menüyü içeren dosya
```

## Derleme ve Çalıştırma

Projeyi derlemek ve çalıştırmak için bir `make` aracına ve `g++` derleyicisine ihtiyacınız vardır. Reponun ana dizinindeyken aşağıdaki komutu çalıştırabilirsiniz.

Bu komut, kaynak dosyaları derler, nesne dosyalarını bağlayarak `bin/program` çalıştırılabilir dosyasını oluşturur ve programı başlatır.

```bash
make
```

```cmd
mingw32-make
```

Alternatif olarak, adımları ayrı ayrı çalıştırabilirsiniz:
- **Derleme:** `make derleme`
- **Bağlama:** `make baglama`
- **Çalıştırma:** `make calistirma`

## Kullanım

Program çalıştırıldığında, kullanıcıya bir menü sunulur:

```
1-)Caprazlama
2-)Mutasyon
3-)Otomatik islemler
4-)Ekrana yaz
5-)Ayarlar
0-)Cikis
Yapmak Istediginiz Islemi Giriniz:
```

- **1) Çaprazlama:** Kullanıcıdan çaprazlanacak iki kromozomun satır numaralarını alır ve çaprazlama işlemini gerçekleştirir.
- **2) Mutasyon:** Kullanıcıdan bir kromozomun satır numarasını ve mutasyona uğrayacak genin indeksini alır.
- **3) Otomatik İşlemler:** `Islemler.txt` dosyasındaki tüm komutları sırayla çalıştırır.
- **4) Ekrana Yaz:** `Dna.txt` dosyasındaki her kromozom için özel bir kurala göre bir karakteri ekrana basar. Kural: Her kromozomun ilk geninden alfabetik olarak daha küçük olan son geni bulur; eğer bulamazsa ilk geni basar.
- **5) Ayarlar:** Çaprazlama, mutasyon ve otomatik işlemlerin sonuçlarının ekrana yazdırılıp yazdırılmayacağını (`E/H`) ayarlamanızı sağlar.
- **0) Çıkış:** Programı sonlandırır.

### Girdi Dosyası Formatları

#### Dna.txt
Her satır bir kromozomu temsil eder. Genler (karakterler) boşluklarla ayrılmıştır.

*Örnek:*
```
A C F Y U D K R
D E V U
O L Z E R Q W X A C
```

#### Islemler.txt
Her satırda bir işlem komutu bulunur.
- **Çaprazlama:** `C <satır1> <satır2>`
- **Mutasyon:** `M <satır> <gen_indeksi>`

*Örnek:*
```
C 1 3
C 0 6
M 5 1