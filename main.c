/*
#########################################

-- Selman Borkluce - 430589

-- Beyza Nur Celebi - 425475

-- Murat Aydin - 425434

#########################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
char kullanici_adi[25];
char kullanici_adi_tutan_dosyanin_adi[25];
int giris;


// kullanicinin verdiği siparis sayisini tutmak icin olusturulmus struct
struct kullanicilar{
    char kullanici_adi[25];
    int siparis_sayisi;
};

//  yemek bilgilerini tutmak icin olusturulmus struct
struct yemekler{
    char ad[25];
    int fiyat;
    int sure;
    char mevcut[25];
    int stok;
    int yemek_sayisi;
};

// bilgisayarin tarih bilgilerini tutmak icin kullanılan struct
struct tarih{
    char gun_adi[10];
    char ay_adi[10];
    int gun;
    int ay;
    int saat;
    int dakika;
    int saniye;
    int yil;
};

//siparis bilgilerini tutmak icin kullanilan struct
struct siparis_bilgiler{
    char ID[25];
    char ad[25];
    int fiyat;
    int gun;
    int ay;
    int yil;
    int saat;
    int dakika;
    char kullanici[25];
    int teslim_saat;
    int teslim_dakika;
    char onay[25];
};


int ay_cevir(char dizi[25]);    //char gelen ay bilgisini integera cevirir
void buyuk_harf(char dizi[25]);  //kullanicnin girdigi kucuk harfle baslayan bilginin ilk harfini buyuk yapar
void bosluk_sil(char dizi[25]);  // txt den alinan ifadenin sonndaki bosluklari siler

void musteri_exe();

void yeni_siparis();    //yeni siparis verilerini alir
void mevcut_siparis();   //mevcut siparis bilgilerini goruntuler
void gecmis_siparis();   //kullaniciya ait butun siparisleri goruntuler

void yemekleri_goster();

void restoran_exe();

void yemek_islemleri();
void yemek_ekle();      //yemek listesine yeni yemek ekler
void yemek_guncelle();  //yemek listesindeki mevcut yemek bilgilerini gunceller
void yemek_sil();       //yemek listesinden yemek siler

void siparis_onayla();    //kullanicidan gelen siparisleri onaylar veya reddeder
void stok_azalt(char yemek_adi[25]);    //onaylanan siparislerin stogunu azaltir
void gunluk_rapor();       //istenilen gunun siparis gecmisini goruntuler
void hasilat();
void gunluk_kazanc();       //istenilen gunun kazancini hesaplar
void aylik_kazanc();        //istenilen ayin kazancini hesaplar
void donemlik_kazanc();     //istenilen donem araligindaki kazanci hesaplar
void en_cok_tuketim();      //en cok tuketilen yemek ve en cok siparis veren kullaniciyi goruntuler


int main(){
    printf("\n\n\n\n\n\t\t\t\t\tKTUCENGSEPETI\n\n\n\nHAZIRLAYANLAR:\nBeyza Nur Celebi\nMurat Aydin\nSelman Borkluce");
    printf("\n\n\n\n\t\t\t\t\tKULLANICI ADI: ");
    fgets(kullanici_adi,sizeof(kullanici_adi),stdin);

    kullanici_adi[strcspn(kullanici_adi,"\n")] = '\0';       // kullanici adinin sonuntaki '\n' karakterini '\0' yaptik

    system("cls");
    program();

    return 0;
}


int ay_cevir(char dizi[25]){
    if(strcmp(dizi,"Jan")==0){
        return 1;
    }else if(strcmp(dizi,"Feb")==0){
        return 2;
    }else if(strcmp(dizi,"Mar")==0){
        return 3;
    }else if(strcmp(dizi,"Apr")==0){
        return 4;
    }else if(strcmp(dizi,"May")==0){
        return 5;
    }else if(strcmp(dizi,"Jun")==0){
        return 6;
    }else if(strcmp(dizi,"Jul")==0){
        return 7;
    }else if(strcmp(dizi,"Aug")==0){
        return 8;
    }else if(strcmp(dizi,"Sep")==0){
        return 9;
    }else if(strcmp(dizi,"Oct")==0){
        return 10;
    }else if(strcmp(dizi,"Nov")==0){
        return 11;
    }else if(strcmp(dizi,"Dec")==0){
        return 12;
    }
}
void buyuk_harf(char dizi[25]){
    char c = dizi[0];
    if(c>='a' && c<='z'){
        int fark = c - 'a';       //dizinin ilk harfi kucukse buyuk yapar
        c = 'A' + fark;
        dizi[0] = c;
    }
}
void bosluk_sil(char dizi[25]){
    int i=23;
    while(dizi[i] == ' '){      //dizinin donundan baslayarak bosluklari siler
        dizi[i] = '\0';
        i--;
        if(dizi[i] != ' '){
            break;
        }
    }
}

void program(){
    printf("\n\n\n-------------------\n0- Cikis\n-------------------\n1- Musteri.exe\n-------------------\n2- Restoran.exe\n-------------------\n\n");
    printf("GIRECEGINIZ UYGULAMAYI SECINIZ: ");
    scanf("%d",&giris);                // giris en basta global tanimlandi

    switch(giris){
        case 1:
            system("cls");
            musteri_exe();
            break;
        case 2:
            system("cls");
            restoran_exe();
            break;
        case 0:
            break;
        default:
            program();
    }
}
void musteri_exe(){
    printf("\n\n\nHOSGELDIN %s !!\n",kullanici_adi);
    printf("\nISLEMLER\n**********************\n0- Ana menu\n-------------------\n1- Yeni siparis\n-------------------\n2- Mevcut siparis durumu\n-------------------\n3- Onceki siparis\n-------------------\n**********************\n\nIslem secin: ");
    scanf("%d",&giris);

    switch (giris){
        case 1:
            yeni_siparis();
            system("cls");
            musteri_exe();
        case 2:
            system("cls");
            mevcut_siparis();
            getch();
            system("cls");
            musteri_exe();
        case 3:
            system("cls");
            gecmis_siparis();
            getch();
            musteri_exe();
        case 0:
            system("cls");
            program();
            break;
        default:
            musteri_exe();
    }
}


void yeni_siparis(){

    struct yemekler yemek[50];     // dizi seklinde struct olusturduk
    FILE *yemek_listesi_txt;

    char satir[300];               // her satir aldigimizda satiri tutacak bi dizi
    int i = 0;                     // structa aldigimiz yemek sayisi

    yemek_listesi_txt = fopen("yemeklistesi.txt","r");   // okuma modunda actik

    printf("\nSiparis verilebilecek yemekler:\n\nYemek Adi\t  Fiyat\t\tHazirlanma suresi\n");
    printf("---------------------------------------------------------\n");

    while(fgets(satir,sizeof(satir),yemek_listesi_txt)){    // satir okuyabildigi surece devam edecek

        sscanf(satir,"%24[^0-9] %d %d %d %24[^\n]",yemek[i].ad,&yemek[i].fiyat,&yemek[i].sure,&yemek[i].stok,yemek[i].mevcut);    //satiri alip diziye attiktan sonra dizideki verileri böluyoruz

        bosluk_sil(yemek[i].ad);
        bosluk_sil(yemek[i].mevcut);             //isim ve mevcut sonundaki bosluklari sildik

        if(strcmp(yemek[i].mevcut,"Mevcut") == 0){       //mevcut degiskeninin "Mevcut" a esit oldugunu kontrol ediyor esitse 0 olur

           printf("%-15s %5d TL%15d dk\n",yemek[i].ad,yemek[i].fiyat,yemek[i].sure);   //esit olanlari ekrana yadirdik
        }
        i++;
    }

    fclose(yemek_listesi_txt);

    //siparis almamiz gerekiyor

    char siparis[50][25];  //siparisleri ayirdigimizda yemek isimlerini tutmak için 2 boyutlu dizi

    char *karakter;        //aldigimiz satirda kontrol etmek için pointer (dizi de kullanilir direkt farketceigini zannetmiyorum

    printf("\nSiparisiniz(lutfen ',' kullanarak ayiriniz):\n");
    fgets(satir,sizeof(satir),stdin);                  // giris almadan bitiriyor diye iki tane
    fgets(satir,sizeof(satir),stdin);                  // önceden olusturdugumuz satir dizisine satiri aldik stdin klavye girisini aliyor

    satir[strcspn(satir,"\n")] = '\0';                 // aldigimiz satirin son karakteri olan \n yi \0 yapiyoruz
                                                        // strcspn  verdigin dizinin içine verdigin karakteri ariyor onun nerede oldugunu veriyor
    karakter = satir;           //pointeri satirin basina aldik
    int j=0,k=0;

    while(*karakter != '\0'){       //satirin sonuna koydugumuz \0 a kadar dönecek
        if(*karakter == ','){           //her virgül gördügünde o 25lik bölümdeki yemek isminin sonuna \0 koyup sonraki 25lik bölüme geçiyo
            siparis[j][k] = '\0';
            j++;
            k=0;
        }else{
            siparis[j][k] = *karakter;          //virgül olmadigi sürece her bi harfi geçiriyo
            k++;
        }
        karakter++;         //pointer kaydiriyo
    }
    siparis[j][k] = '\0';   //en son yazilan yemegin sonuna \0 koyuyo

    //aldigimiz siparileri siparisler.txt ye yazacaz

    FILE *siparisler_txt;
    siparisler_txt = fopen("siparisler.txt","a");    //ekleme modunda aciyoz

    //zamani aldik zaman structina attik
    time_t zaman_1;
    zaman_1 = time(NULL);
    struct tarih zaman;
    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);

    zaman.ay = ay_cevir(zaman.ay_adi);          //ay adini sayiya cevirdik

    int x,z;
    for(x = 0;x <= j;x++){         // j aldigimiz siparislerin sayisi
        buyuk_harf(siparis[x]);     // girilen yemek küçük harfle baslarsa ilk harfini büyük yapiyor
        for(z = 0;z < i;z++){      // i yemeklistesi.txt den aldigimiz yemek sayisi
            if(strcmp(siparis[x],yemek[z].ad) == 0){         //strcmp  aldigimiz siparisteki yemegin adi ile structa attigimiz yemek adlarini karsilastiriyor
                                                            // ayni oldugunda 0 veriyor
                if(strcmp(yemek[z].mevcut,"Mevcut Degil")==0){
                    fprintf(siparisler_txt,"SIP%02d%02d%02d_%-14s %-25s %-10d %02d.%02d.%d-%02d.%02d     %-21s %s\n",zaman.gun,zaman.ay,(zaman.yil%100),kullanici_adi,yemek[z].ad,yemek[z].fiyat,zaman.gun,zaman.ay,zaman.yil,zaman.saat,zaman.dakika,"stokta yok",kullanici_adi);
                    printf("Stokta kalmadi\n");
                    continue;
                }

                //siparisteki yemek adi ile dosyadaki ad uyustugunda bilgileri çekip siparisler.txt ye yazdik

                fprintf(siparisler_txt,"SIP%02d%02d%02d_%-13s %-25s%-24d %02d.%02d.%d-%02d.%02d\t     %-25s \t     %s\n",zaman.gun,zaman.ay,(zaman.yil%100),kullanici_adi,yemek[z].ad,yemek[z].fiyat,zaman.gun,zaman.ay,zaman.yil,zaman.saat,zaman.dakika,"onay_bekliyor",kullanici_adi);
                printf("\nSiparisiniz alindi...\n");
            }
        }
    }
    fclose(siparisler_txt);
    getch();
}

void mevcut_siparis(){

    char satir[300];        //satirlar icin dizi
    char bos[100];          //satir icinde kullanmicagimiz yerleri almak icin

    FILE *siparisler_txt;

    struct siparis_bilgiler sip;

    siparisler_txt = fopen("siparisler.txt","r");


    //guncel zaman bilgilerini alip structa attik
    time_t zaman_1;
    zaman_1 = time(NULL);
    struct tarih zaman;
    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);

    printf("Siparis bilgileri: \n\n");
    printf("Yemek adi\t  Yemek Fiyati     Siparis zamani\t\t Siparis durumu\n");
    printf("---------------------------------------------------------------------------------\n");
    int toplam=0;
    while(fgets(satir,sizeof(satir),siparisler_txt)){       //her bir satiri aldik

        sscanf(satir, "%s %24[^0-9] %d %s %s %s", sip.ID, sip.ad, &sip.fiyat, bos,sip.onay, sip.kullanici);     //siparisler.txt den gelen satiri bolduk
        bosluk_sil(sip.ad);

    //(siparisteki kullanici adiyla giris yapilan kullanici adi)
        if(strcmp(sip.kullanici, kullanici_adi) == 0) {

            if((strcmp(sip.onay,"onay_bekliyor") != 0) && (strcmp(sip.onay,"iptal") != 0)){

                sscanf(sip.onay,"%d.%d.%d-%d.%d",&sip.gun,&sip.ay,&sip.yil,&sip.teslim_saat,&sip.teslim_dakika);    //onaylanan siparişlerin teslim zamanini bolduk ve ve henuz hazırlanmayanları gosterdik

                if(zaman.saat < sip.teslim_saat || (zaman.saat == sip.teslim_saat && zaman.dakika <= sip.teslim_dakika)){   //hazirlanamasi tamamlanmayan siparisleri gosterir

                    printf("%-20s %-10d %-20s %s\n",sip.ad,sip.fiyat,bos,sip.onay,sip.kullanici);
                    toplam += sip.fiyat;
                }
            }else if(strcmp(sip.onay,"onay_bekliyor") == 0){
                printf("%-20s %-10d %-30s %s\n",sip.ad,sip.fiyat,bos,sip.onay,sip.kullanici);
                toplam += sip.fiyat;
            }else{
                printf("%-20s %-10d %-20s %s\n",sip.ad,sip.fiyat,bos,sip.onay,sip.kullanici);       //iptal olan siparisleri gosterir
            }
        }
    }
    printf("\nToplam tutar:  %d TL\n",toplam);
    fclose(siparisler_txt);
}

void gecmis_siparis(){
    char tarih[15];
    char satir[300];
    char bos[100];     //kullanilmayan gereksiz yerleri tutmak icin bir dizi
    struct siparis_bilgiler sip;
    struct tarih zaman;
    int baslangic_gun = 01;
    int baslangic_ay = 05;
    int baslangic_yil = 2024;
    int i,j,k;            //gun,ay,yil degiskenleri

    FILE* siparis_sayaci;
    FILE *siparisler_txt;

    siparisler_txt = fopen("siparisler.txt","r");

    //bilgisayardan zaman degerlerini cektik
    time_t zaman_1;
    zaman_1 = time(NULL);
    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);
    zaman.ay=ay_cevir(zaman.ay_adi);

    printf("Siparis ID\tYemek Adi\tYemek Fiyati\tSiparis zamani\t   Teslim zamani\tKullanici adi\t  Asci\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    while(fgets(satir,sizeof(satir),siparisler_txt)){

        sscanf(satir,"%s %24[^0-9] %d %s %d.%d.%d-%d.%d %s",sip.ID,sip.ad,&sip.fiyat,bos,&sip.gun,&sip.ay,&sip.yil,&sip.saat,&sip.dakika,sip.kullanici);    //aldigimiz satirlari bolduk
        bosluk_sil(sip.ad);

        if(strcmp(sip.kullanici,kullanici_adi) == 0){

            if(strstr(satir,"iptal")!= NULL)    //iptal olan siparisleri yazdirdik
            {
                printf("%-15s %-20s %-10d %-20s %-15s\t    %s\n",sip.ID,sip.ad,sip.fiyat,bos,"iptal edildi!",sip.kullanici);
                continue;
            }
            if(sip.saat < zaman.saat || (sip.saat == zaman.saat && sip.dakika < zaman.dakika))  //hazirlanma zamani gecmis olan siparisleri yazdirdik
            {
                printf("%-15s %-20s %-10d %-20s %02d.%02d.%d-%02d.%02d\t    %s\n",sip.ID,sip.ad,sip.fiyat,bos,sip.gun,sip.ay,sip.yil,sip.saat,sip.dakika,sip.kullanici);
            }
        }
    }
    fclose(siparisler_txt);

    //gecmis gunlerin dosyalarindaki kullaniciya ait siparisleri yazdirdik
    for(i = baslangic_yil; i<=zaman.yil;i++){
        for(j = baslangic_ay; j<= zaman.ay;j++){
            for(k = baslangic_gun; k<=zaman.gun;k++){
                snprintf(tarih,sizeof(tarih),"%02d.%02d.%d.txt",k,j,i); //tarih parametrelerini dosya ismine donusturmek icin diziye attik
                siparis_sayaci =fopen(tarih,"r");

                while(fgets(satir,sizeof(satir),siparis_sayaci)){
                    if (strstr(satir,kullanici_adi)!= NULL){
                    printf("%s",satir);
                    }
                }
                fclose(siparis_sayaci);
            }
        }
    }
}

void yemekleri_goster(){

    struct yemekler yemek[50];     // dizi seklinde struct olusturduk
    FILE *yemek_listesi_txt;

    char satir[300];               // her satir aldigimizda satiri tutacak bi dizi
    int i = 0;                     // structa aldigimiz yemek sayisi


    yemek_listesi_txt = fopen("yemeklistesi.txt","r");   // okuma modunda actik

    printf("\nMevcut Yemek Listesi\n\nYemek Adi\t\tFiyat\t\t    Hazirlanma suresi\t\t   Stok\t\t\t   Durum\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");

    while(fgets(satir,sizeof(satir),yemek_listesi_txt)){    // satir okuyabildigi surece devam edecek
        printf("%s",satir);
    }
    fclose(yemek_listesi_txt);
}


void restoran_exe(){
    printf("\nISLEMLER\n**********************\n-------------------\n0- Ana menu\n-------------------\n1- Yemek islemleri\n-------------------\n2- Siparis onayla\n-------------------\n3- Gunluk rapor\n-------------------\n4- Gun sonu\n-------------------\n5- Istatistik\n-------------------\n**********************\n\nIslem secin: ");
    scanf("%d",&giris);

    switch(giris){
        case 1:
            system("cls");
            yemek_islemleri();
            restoran_exe();
        case 2:
            system("cls");
            siparis_onayla();
            restoran_exe();
        case 3:
            system("cls");
            gunluk_rapor();
            restoran_exe();
        case 4:
            system("cls");
            gun_sonu();
            restoran_exe();
        case 5:
            system("cls");
            hasilat();
            restoran_exe();
        case 0:
            system("cls");
            program();
            break;
        default:
            system("cls");
            restoran_exe();
    }
}

void yemek_islemleri(){

    printf("\nISLEMLER\n**********************\n-------------------\n0- Geri don\n-------------------\n1- Yemek ekle\n-------------------\n2- Yemek guncelle\n-------------------\n3- Yemek sil\n-------------------\n**********************\n\nIslem secin: ");
    scanf("%d",&giris);

    switch(giris){
        case 1:
            system("cls");
            yemek_ekle();
            system("cls");
            yemek_islemleri();
        case 2:
            system("cls");
            yemek_guncelle();
            system("cls");
            yemek_islemleri();
        case 3:
            system("cls");
            yemek_sil();
            system("cls");
            yemek_islemleri();
        case 0:
            system("cls");
            restoran_exe();
        default:
            system("cls");
            yemek_islemleri();
    }
}

void yemek_ekle(){

    yemekleri_goster();     //mevcut yemek bilgilerini gosterdik

    char satir[300];

    struct yemekler yemek;

    FILE *yemek_listesi_txt;

    yemek_listesi_txt = fopen("yemeklistesi.txt","a");

    while(fgets(satir,sizeof(satir),yemek_listesi_txt));      //pointeri dosyanin sonuna esitledik

    printf("\nyemek bilgileri:\n\n");
    printf("yemek adi: ");
    fgets(yemek.ad,sizeof(yemek.ad),stdin);
    fgets(yemek.ad,sizeof(yemek.ad),stdin);     //birinci fgets onceki giristen sonraki '\n' karakterini aldigi icin ikinci bir fgets yazdik

    buyuk_harf(yemek.ad);

    yemek.ad[strcspn(yemek.ad,"\n")] = '\0';    //fgets in alip en sona koydugu '\n' karakterini '\0' karakterine cevirdik

    printf("yemek fiyati: ");
    scanf(" %d",&yemek.fiyat);
    printf("hazirlanma suresi: ");
    scanf(" %d",&yemek.sure);
    printf("stok: ");
    scanf(" %d",&yemek.stok);

    if(yemek.stok > 0){
        strcpy(yemek.mevcut,"Mevcut");
    }else{                                      //eklenen yemegin stok durumuna gore mevcut ya da mevcut degil yazdik
        strcpy(yemek.mevcut,"Mevcut Degil");
    }

    fprintf(yemek_listesi_txt,"%-24s %-24d %-24d %-24d %s\n",yemek.ad,yemek.fiyat,yemek.sure,yemek.stok,yemek.mevcut); //eklenen yemek bilgilerini yemek listesine yazdik

    fclose(yemek_listesi_txt);

    printf("Yemek eklendi...");
    getch();
}

void yemek_guncelle(){

    yemekleri_goster();     //mevcut yemek bilgilerinin goruntuledik

    char satir[300];         //okunan satirlari tutmak icin dizi
    struct yemekler yemek;

    FILE *yemek_listesi_txt,*temp;

    yemek_listesi_txt = fopen("yemeklistesi.txt","r");
    temp = fopen("temp.txt","w");

    char eski_yemek[25];    //listeden okunacak yemek
    char yeni_yemek[25];    //kullanicidan alinacak yemek

    printf("\nGuncellenecek yemek: \n");
    fgets(yeni_yemek,sizeof(yeni_yemek),stdin);
    fgets(yeni_yemek,sizeof(yeni_yemek),stdin);     //birinci fgets onceki giristen sonraki '\n' karakterini aldigi icin ikinci bir fgets yazdik

    yeni_yemek[strcspn(yeni_yemek,"\n")] = '\0';    //fgets in alip en sona koydugu '\n' karakterini '\0' karakterine cevirdik

    buyuk_harf(yeni_yemek);

    printf("yemek fiyati: ");
    scanf(" %d",&yemek.fiyat);
    printf("hazirlanma suresi: ");
    scanf(" %d",&yemek.sure);
    printf("stok: ");
    scanf(" %d",&yemek.stok);

    if(yemek.stok > 0){
        strcpy(yemek.mevcut,"Mevcut");
    }else{                                      //eklenen yemegin stok durumuna gore mevcut ya da mevcut degil yazdik
        strcpy(yemek.mevcut,"Mevcut Degil");
    }

    while(fgets(satir,sizeof(satir),yemek_listesi_txt)){
        sscanf(satir,"%24[^0-9]",eski_yemek);
        bosluk_sil(eski_yemek);

        if(strcmp(eski_yemek,yeni_yemek) == 0){
            fprintf(temp,"%-24s %-24d %-24d %-24d %s\n",yeni_yemek,yemek.fiyat,yemek.sure,yemek.stok,yemek.mevcut); //degisen satiri yeni dosyaya yazdik
        }else{
            fprintf(temp,"%s",satir);       //degismeyen satirlari aynen yeni dosyaya yazdik
        }
    }
    fclose(yemek_listesi_txt);
    fclose(temp);

    remove("yemeklistesi.txt");                 //eski dosyayi sildik
    rename("temp.txt","yemeklistesi.txt");      //yeni dosyanin adini degistirdik

    printf("Yemek guncellendi...");
    getch();
}

void yemek_sil(){

    yemekleri_goster();     //mevcut yemekleri gosterdik

    char satir[300];        //okunan satirlari tutar

    FILE *yemek_listesi_txt,*temp;

    yemek_listesi_txt = fopen("yemeklistesi.txt","r");
    temp = fopen("temp.txt","w");

    char yemek[25];         //listeden aldigimiz yemek adi
    char silinecek[25];     //kullanicidan alinan silinecek yemek adi

    printf("\nSilinecek yemek: \n");
    fgets(silinecek,sizeof(silinecek),stdin);
    fgets(silinecek,sizeof(silinecek),stdin);   //birinci fgets onceki giristen sonraki '\n' karakterini aldigi icin ikinci bir fgets yazdik

    silinecek[strcspn(silinecek,"\n")] = '\0';  //fgets in alip en sona koydugu '\n' karakterini '\0' karakterine cevirdik

    buyuk_harf(silinecek);

    while(fgets(satir,sizeof(satir),yemek_listesi_txt)){
        sscanf(satir,"%24[^0-9]",yemek);
        bosluk_sil(yemek);

        if(strcmp(yemek,silinecek) == 0){
            continue;
        }else{
            fprintf(temp,"%s",satir);
        }
    }

    fclose(yemek_listesi_txt);
    fclose(temp);

    remove("yemeklistesi.txt");                 //eski dosyayi sildik
    rename("temp.txt","yemeklistesi.txt");      //yeni dosyanin adini degistirdik

    printf("yemek silindi..");
    getch();
}


void siparis_onayla(){

    char satir[300];        //siparisler.txt deki satirlari tutar
    char satir2[300];       //yemeklistesi.txt deki satirlari tutar
    char bos[50];           //kullanilmayan gereksiz yerleri tutar
    struct siparis_bilgiler sip;
    struct yemekler yemek;
    struct tarih zaman;

    FILE *siparisler_txt, *temp, *yemek_listesi_txt;

    siparisler_txt = fopen("siparisler.txt","r");
    temp = fopen("temp.txt","w");
    yemek_listesi_txt = fopen("yemeklistesi.txt","r");

    while(fgets(satir,sizeof(satir),siparisler_txt)){

        sscanf(satir,"%s %24[^0-9] %d %s %s %s",sip.ID,sip.ad,&sip.fiyat,bos,sip.onay,sip.kullanici);   //siparisler.txt den alinan satiri bolduk
        bosluk_sil(sip.ad);

        if(strcmp(sip.onay,"onay_bekliyor")==0){
            printf("%s\nonaylamak icin 1 \\ Iptal etmek icin 0'i tuslayiniz!\n",satir);
            scanf("%d",&giris);         //onay veya red girisi aldik
            int teslim_saat;
            int teslim_dakika;

            if(giris == 1){
                while(fgets(satir2,sizeof(satir2),yemek_listesi_txt)){
                    sscanf(satir2,"%24[^0-9] %d %d",yemek.ad,&yemek.fiyat,&yemek.sure);     //yemeklistesi.txt den alinan satirlari bolduk
                    bosluk_sil(yemek.ad);

                    //bilgisayardan zaman bilgilerini aldik
                    time_t zaman_1;
                    zaman_1 = time(NULL);
                    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);

                    zaman.ay = ay_cevir(zaman.ay_adi);

                    if(strcmp(yemek.ad,sip.ad) == 0){

                        teslim_dakika = zaman.dakika + yemek.sure;        //yemek hazirlanma suresinin siparis verilen zamanla topladik
                        teslim_saat = zaman.saat;

                        while(teslim_dakika>=60){                          //olusan dakikayi saate bolduk ve ekledik
                            teslim_saat++;
                            teslim_dakika = teslim_dakika - 60;
                        }
                    }
                }
                fclose(yemek_listesi_txt);
                fprintf(temp,"%-24s %-25s %-10d %-20s %02d.%02d.%d-%02d.%02d \t %s\n",sip.ID,sip.ad,sip.fiyat,bos,zaman.gun,zaman.ay,zaman.yil,teslim_saat,teslim_dakika,sip.kullanici);
                stok_azalt(sip.ad);     //onaylanan siparisdeki yemegin stogunu azalttik

            }else{
                fprintf(temp,"%-24s %-25s %-10d %-20s %-20s %s\n",sip.ID,sip.ad,sip.fiyat,bos,"iptal",sip.kullanici);     //iptal edilen siparisleri dosyaya yazdik
            }
        }else{
            fprintf(temp,"%s",satir);       //islem yapilmayan gecmis siparisleri dosyaya yazdik
        }
    }


    fclose(siparisler_txt);
    fclose(temp);

    rename("siparisler.txt","silinecek.txt");
    remove("silinecek.txt");
    rename("temp.txt","siparisler.txt");
}

void stok_azalt(char yemek_adi[25]){    //stogu azaltilacak yemegin adini aldik

    char satir[300];
    struct yemekler yemek;

    FILE *yemeklistesi, *gecici;


    yemeklistesi = fopen("yemeklistesi.txt","r");
    gecici = fopen("gecici.txt","w");

    //yemeklistesinde o yemegin bulundugu satiri bulduk ve stok degerini 1 azaltarak dosyayi guncelledik
    while(fgets(satir,sizeof(satir),yemeklistesi)){

        sscanf(satir,"%24[^0-9] %d %d %d %24[^\n]",yemek.ad,&yemek.fiyat,&yemek.sure,&yemek.stok,yemek.mevcut);
        bosluk_sil(yemek.ad);
        bosluk_sil(yemek.mevcut);

        if(strcmp(yemek.ad,yemek_adi)==0){

            yemek.stok--;

            if(yemek.stok == 0){

                strcpy(yemek.mevcut,"Mevcut Degil");
            }

            fprintf(gecici,"%-24s %-24d %-24d %-24d %s\n",yemek.ad,yemek.fiyat,yemek.sure,yemek.stok,yemek.mevcut);
        }else{

            fprintf(gecici,"%s",satir);
        }
    }

    fclose(yemeklistesi);
    fclose(gecici);

    remove("yemeklistesi.txt");
    rename("gecici.txt","yemeklistesi.txt");
}

void gun_sonu(){
    char satir[300];
    char tarih_sayac[25];   //ilgili dosyayi cagirmak icin tarih bilgilerini dosya adi seklinde tutar
    struct tarih zaman;

    //bilgisayardan guncel zaman degerlerini aldik
    time_t zaman_1;
    zaman_1 = time(NULL);
    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);
    zaman.ay=ay_cevir(zaman.ay_adi);

    // zaman degerlerini dosya adina donnusturmek icin snprintf ile diziye yazdik
    snprintf(tarih_sayac, sizeof(tarih_sayac), "%02d.%02d.%d.txt",zaman.gun,zaman.ay,zaman.yil);

    printf("Gun sonu alinacak tarih icerigi: %s\n",tarih_sayac);

    FILE* siparisler_txt;
    FILE* gun_sonu;

    siparisler_txt = fopen("siparisler.txt","r");
    gun_sonu = fopen(tarih_sayac,"a");

    //butun satirlari aynen yeni dosyaya yazdik
    while(fgets(satir,sizeof(satir),siparisler_txt)){
        fprintf(gun_sonu,"%s",satir);
    }
    fclose(siparisler_txt);
    fclose(gun_sonu);
    remove("siparisler.txt");   //eski bilgilerin bulundugu siparisler.txt dosyasini sildik
    getch();
}

void gunluk_rapor(){

    int istenen_gun_kazanci;
    int istenen_ay_kazanci;
    int istenen_yil_kazanci;

    char satir[300];
    char kazanc_gunu[15];   //kazanci hesaplanacak gunun dosya adini tutar

    FILE* kazanc_dosya;

    printf("Kazancini goruntulemek istediginiz tarihi giriniz...\n");
    printf("istenen gun\n");
    scanf("%d",&istenen_gun_kazanci);
    printf("istenen ay\n");
    scanf("%d",&istenen_ay_kazanci);
    printf("istenen yil kazanci\n");
    scanf("%d",&istenen_yil_kazanci);

    snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",istenen_gun_kazanci,istenen_ay_kazanci,istenen_yil_kazanci);    //girilen zaman bilgilerini diziye attik

    kazanc_dosya=fopen(kazanc_gunu,"r");

    system("cls");
    printf("Siparis ID \t\t Yemek adi \t      Yemek fiyati \t Siparis zamani    teslim zamani \t Kullanici Adi\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n\n");

    //istenilen gunun siparislerini ekrana yazdirir
    while(fgets(satir,sizeof(satir),kazanc_dosya))
    {
        printf("%s\n",satir);
    }
    fclose(kazanc_dosya);
    getch();
}



void hasilat()//analizler
{
    printf("Hasilat Turunu seciniz\n-------------------\n1- Gunluk\n-------------------\n2- Aylik\n-------------------\n3- Donemlik\n-------------------\n4- En cok tuketim\n-------------------\n0-Geri don\n-------------------\n");
    scanf("%d",&giris);
    switch(giris)
    {
    case 1:
        gunluk_kazanc();
        system("cls");
        hasilat();
    case 2:
        aylik_kazanc();
        system("cls");
        hasilat();
    case 3:
        donemlik_kazanc();
        system("cls");
        hasilat();
    case 4:
        en_cok_tuketim();
        system("cls");
        hasilat();
    case 0:
        restoran_exe();
    }
}

void gunluk_kazanc()
{
    int istenen_gun_kazanci;
    int istenen_ay_kazanci;
    int istenen_yil_kazanci;
    int toplam_gelir=0;
    int ucret;
    char gereksiz[100];     //kullanilmayan gereksiz yerleri tutmak icin dizi tanimladik
    char satir[300];        //alinan satirlari tutmak icin dizi tanimladik
    char kazanc_gunu[15];   //istenilen gunun dosya adini tutmak icin dizi tanimladik

    FILE* kazanc_dosya;

    printf("Kazancini goruntulemek istediginiz tarihi giriniz...\n");
    printf("istenen gun\n");
    scanf("%d",&istenen_gun_kazanci);
    printf("istenen ay\n");
    scanf("%d",&istenen_ay_kazanci);
    printf("istenen yil kazanci\n");
    scanf("%d",&istenen_yil_kazanci);

    //istenilen gunu dosya adi olusturarak diziye attik
    snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",istenen_gun_kazanci,istenen_ay_kazanci,istenen_yil_kazanci);
    kazanc_dosya=fopen(kazanc_gunu,"r");

    //her satirdaki iptal edilmeyen siparislerin ucretlerini topladik
    while(fgets(satir,sizeof(satir),kazanc_dosya))
    {
        if (strstr(satir,"iptal")==NULL)
        {
               sscanf(satir,"%s %24[^0-9] %d",gereksiz,gereksiz,&ucret);
               toplam_gelir+=ucret;
        }
    }
    printf("\n\n-------------------------------------%02d.%02d.%d gunune ait kazanc: %d TL'dir-----------------------------\n\n\n\n\n",istenen_gun_kazanci,istenen_ay_kazanci,istenen_yil_kazanci,toplam_gelir);
    fclose(kazanc_dosya);
    getch();
}

void aylik_kazanc(){

    int gun;
    int istenen_ay;
    int istenen_yil;
    int toplam=0;
    int ucret;

    char satir[300];        //dosyadaki satirlari tutar
    char gereksiz[20];      //kullanilayan gereksiz bilgileri tutar
    char kazanc_gunu[15];   //kazanci hesaplanacak gunun dosya adini tutar

    FILE *kazanc_dosya;

    printf("Kazancini goruntulemek istediginiz tarihi giriniz...\n");
    printf("istenen ay\n");
    scanf("%d",&istenen_ay);
    printf("istenen yil kazanci\n");
    scanf("%d",&istenen_yil);

    for(gun = 1; gun <= 30; gun++){ //aylik oldugundan 30 gun icin for dongusu

        //her gunun tarih degerleri ile dosya adi olusturup diziye attik
        snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",gun,istenen_ay,istenen_yil);
        kazanc_dosya = fopen(kazanc_gunu,"r");

        //acilan dosyadaki iptal edilmeyen siparislerin ucretlerini toplar
        while(fgets(satir,sizeof(satir),kazanc_dosya))
        {
            if (strstr(satir,"iptal")==NULL)
            {
               sscanf(satir,"%s %24[^0-9] %d",gereksiz,gereksiz,&ucret);            //ıd ve yemek adiyla isimiz olmasigi icin gereksize attik
               toplam+=ucret;
            }
        }
        fclose(kazanc_dosya);
    }
    printf("\nistenen aydaki elde edilen toplam gelir: %d TL\n",toplam);
    getch();
}

void donemlik_kazanc(){

    int baslangic_gun;
    int bitis_gun;
    int baslangic_ay;
    int bitis_ay;
    int baslangic_yil;
    int bitis_yil;
    int toplam=0;
    int ucret;
    int i,j,k;      //yil,ay,gun degiskenleri

    char satir[300];            //dosyadan alinan satirlari tutar
    char gereksiz[20];          //satirlardaki kullanilmaya gereksiz bilgileri tutar
    char kazanc_gunu[15];       //kazanci hesaplanacak gunun dosya adını tutar

    FILE *kazanc_dosya;

    printf("baslangic gunu: ");
    scanf("%d",&baslangic_gun);
    printf("baslangic ayi: ");
    scanf("%d",&baslangic_ay);
    printf("baslangic yili: ");
    scanf("%d",&baslangic_yil);

    printf("bitis gunu: ");
    scanf("%d",&bitis_gun);
    printf("bitis ayi: ");
    scanf("%d",&bitis_ay);
    printf("bitis yili: ");
    scanf("%d",&bitis_yil);

    for(i = baslangic_yil; i<= bitis_yil;i++){
        //baslangic ayindaki baslangic gununden ay sonun kadar donduk
        for(j = baslangic_ay; j==baslangic_ay; j++){
            for(k = baslangic_gun; k<=30; k++){
                snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",k,j,i);
                kazanc_dosya = fopen(kazanc_gunu,"r");

                while(fgets(satir,sizeof(satir),kazanc_dosya))
                {
                    if (strstr(satir,"iptal")==NULL)
                    {
                        sscanf(satir,"%s %24[^0-9] %d",gereksiz,gereksiz,&ucret);            //ıd ve yemek adiyla isimiz olmasigi icin gereksize attik
                        toplam+=ucret;
                    }
                }
                fclose(kazanc_dosya);
            }
        }
        //aradaki aylarin basindan sonun kadar donduk
        for(j = baslangic_ay + 1; j < bitis_ay;j++){
            for(k = 1;k<=30;k++){
                snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",k,j,i);
                kazanc_dosya = fopen(kazanc_gunu,"r");

                while(fgets(satir,sizeof(satir),kazanc_dosya))
                {
                    if (strstr(satir,"iptal")==NULL)
                    {
                        sscanf(satir,"%s %24[^0-9] %d",gereksiz,gereksiz,&ucret);            //ıd ve yemek adiyla isimiz olmasigi icin gereksize attik
                        toplam+=ucret;
                    }
                }
                fclose(kazanc_dosya);
            }
        }
        //bitis ayinin basindan bitis gunune kadar donduk

        if(baslangic_ay != bitis_ay){           //eger baslangic ay ve bitis ay esit degilse
            for(j=bitis_ay; j == bitis_ay ;j++){
                for(k=1; k<= bitis_gun; k++){
                    snprintf(kazanc_gunu,sizeof(kazanc_gunu),"%02d.%02d.%d.txt",k,j,i);
                    kazanc_dosya = fopen(kazanc_gunu,"r");

                    while(fgets(satir,sizeof(satir),kazanc_dosya))
                    {
                        if (strstr(satir,"iptal")==NULL)
                        {
                            sscanf(satir,"%s %24[^0-9] %d",gereksiz,gereksiz,&ucret);            //ıd ve yemek adiyla isimiz olmasigi icin gereksize attik
                            toplam+=ucret;
                        }
                    }
                    fclose(kazanc_dosya);
                }
            }
        }

    }
    printf("istenen tarih araligindaki elde edilen toplam gelir: %d TL\n",toplam);
    getch();
}

void en_cok_tuketim(){
    struct siparis_bilgiler sip;
    struct yemekler yemek[50];              //yemeklerin kac kere siparis edildigini tutmak icin
    struct kullanicilar kullanici[50];      //kullanicilerin kac kere siparis verdigini tutmak icin
    struct tarih zaman;

    char gereksiz[50];          //kullanilmayan gereksiz yerleri tutmak icin
    char satir[300];            //dosyadan okunan satirlari tutmak icin
    int baslangic_gun = 01;
    int baslangic_ay = 05;      //analizin yapilacagi baslangic parametreleri
    int baslangic_yil = 2024;

    int i,j,k,x,max;           //yil,ay,gun ve en yuksek degerleri tutacak degiskenler

    FILE *siparis_sayaci;

    char tarih[15];             //aranacak tarihli dosya ismni tutar

    time_t zaman_1;
    zaman_1 = time(NULL);
    sscanf(ctime(&zaman_1),"%s %s %d %d:%d:%d %d",zaman.gun_adi,zaman.ay_adi,&zaman.gun,&zaman.saat,&zaman.dakika,&zaman.saniye,&zaman.yil);

    zaman.ay = ay_cevir(zaman.ay_adi);

    for(x =0; x < (sizeof(yemek) / sizeof(yemek[0]));x++){
        yemek[x].ad[0] = '\0';
        yemek[x].yemek_sayisi = 0;              //structların baslangic degerlerini sifirladik
    }
    for(x =0; x < (sizeof(kullanici) / sizeof(kullanici[0]));x++){
        kullanici[x].kullanici_adi[0] = '\0';
        kullanici[x].siparis_sayisi = 0;        ////structların baslangic degerlerini sifirladik
    }

    for(i = baslangic_yil; i <= zaman.yil;i++){
        for(j = baslangic_ay; j <= zaman.ay;j++){
            for(k = baslangic_gun; k <= zaman.gun;k++){
                snprintf(tarih,sizeof(tarih),"%02d.%02d.%d.txt",k,j,i);     //tarihi dosya adina donusturduk

                siparis_sayaci =fopen(tarih,"r");

                while(fgets(satir,sizeof(satir),siparis_sayaci)){
                    if(strstr(satir,"iptal") != NULL){
                        continue;                           //iptal edilen siparisleri atladik
                    }else{
                        sscanf(satir,"%s %24[^0-9] %d  %s %s %s",sip.ID,sip.ad,&sip.fiyat,gereksiz,gereksiz, sip.kullanici);
                        bosluk_sil(sip.ad);

                        for(x = 0; x < (sizeof(yemek) / sizeof(yemek[0])); x++){    //structta karsilasilan yemegin sayisini arttırdık
                            if(strcmp(sip.ad,yemek[x].ad)==0){
                                yemek[x].yemek_sayisi++;
                                break;
                            }else if(yemek[x].ad[0] == '\0'){   //yemek structta yoksa ekledik
                                strcpy(yemek[x].ad,sip.ad);
                                yemek[x].yemek_sayisi++;
                                break;
                            }
                        }
                        for(x = 0; x < (sizeof(kullanici) / sizeof(kullanici[0]));x++){
                            if(strcmp(kullanici[x].kullanici_adi,sip.kullanici) == 0){  //structta karsilasilan kullanicinin siparis sayisinin arttırdık
                                kullanici[x].siparis_sayisi++;
                                break;
                            }else if(kullanici[x].kullanici_adi[0] == '\0'){        //kullanici structta yoksa ekledik
                                strcpy(kullanici[x].kullanici_adi,sip.kullanici);
                                kullanici[x].siparis_sayisi++;
                                break;
                            }
                        }
                    }
                }
                fclose(siparis_sayaci);
            }
        }
    }
    max = 0;

    for(x =1; x < (sizeof(yemek) / sizeof(yemek[0]));x++){
        if(yemek[x].yemek_sayisi > yemek[max].yemek_sayisi){    //en cok siparis verilen yemegi arar
            max = x;
        }
    }
    printf("\nEn fazla siparis edilen yemek: %s %d tane siparis verildi\n",yemek[max].ad,yemek[max].yemek_sayisi);

    max = 0;

    for(x=1;x<sizeof(kullanici) / sizeof(kullanici[0]);x++){
        if(kullanici[x].siparis_sayisi > kullanici[max].siparis_sayisi){      //en cok siparis veren kullaniciyi arar
            max = x;
        }
    }
    printf("\nEn fazla siparis veren kullanici: %s %d tane siparis verdi\n",kullanici[max].kullanici_adi,kullanici[max].siparis_sayisi);
    getch();
}






