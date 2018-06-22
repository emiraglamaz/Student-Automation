#include <stdio.h>//standart c k�t�phanesi
#include <stdlib.h>//atoi() fonksiyonu i�in
#include <string.h>//strcmp() fonksiyonu i�in 
struct ogrenci{
char ogrNo[12];
char isim[15];
char soyisim[15];
char basYili[13];
char bolum[30];
char sinif[2];
};
struct ogretmen{//��retim eleman�n� tutan yap�
	char sicilNo[10];
	char isim[15];
	char soyisim[20];
	char bolum_og[20];
};
struct ders {//Ders mod�l�n� tutan yap�
	char dersId[11];
	char dersAdi[20];
};
struct dersVer {//Ders verme mod�l�n� tutan yap�
	char ogr_no[12];
	char ders1[20];
	char ders2[20];
	char ders3[20];
	char ders4[20];
	char ders5[20];
};
struct notVer{//Not verme mod�l�n� tutan yap�
	char ogrno[12];
	char not1[3];
	char not2 [3];
	char not3[3];
	char not4[3];
	char not5[3];
};



//Ogrenci fonksiyonlar�
//****************************************************************
//Ogrenci Ana fonksiyonu
void ogrenci_fonk(struct ogrenci student[1000],struct dersVer derslerim[20],struct notVer notlarim[6]);
//Ogrenci Listeleme Fonksiyonu
void ogrenci_listele(struct ogrenci student[1000],int sayac);
//Ogrenci Kayit Arama Fonksiyonu
void ogrenci_kayitAra(struct ogrenci student[1000],int sayac);
//Ogrenci Kayit Ekleme Fonksiyonu
void ogrenci_kayitEkle(struct ogrenci student[1000],int sayac,int sayac1,struct dersVer derslerim[20]);
//Ogrenci Kayit Guncelleme Fonksiyonu
void ogrenci_kayitGuncellestir(struct ogrenci student[1000],int sayac);
//Ogrenci Fonksiyonlar� Bitti
//******************************************************************










//Ogretmen fonksiyonlar�
//*******************************************************************
void ogretmen_fonk(struct ogretmen teacher[1000]);
//ogretmen kay�tlar�n� listeleme
void ogretmen_listele(struct ogretmen teacher[1000],int sayac);
//Ogretmen kay�lar� arama fonksiyonu
void ogretmen_ara(struct ogretmen teacher[1000],int sayac);
//Ogretmen Kayit Ekleme Fonksiyonu
void ogretmen_kayitEkle(struct ogretmen teacher[1000],int sayac);
//Ogretmen Kayit Guncelleme
void ogretmen_kayitGuncelle(struct ogretmen teacher[1000],int sayac);
//Ogretmen Fonksiyonlari Bitti
//******************************************************************





//Ders Fonksiyonlari Baslama
//********************************************************
//Dersler icin ana fonksiyon
void ders_fonk(struct ders dersler[10]);
//ders listeleme fonksiyonu
void ders_listele(struct ders dersler[10],int sayac);
//ders arama fonksiyonu
void ders_ara(struct ders dersler[10],int sayac);
//ders ekleme fonksiyonu
void ders_ekle(struct ders dersler[10],int sayac);
//Ders Guncelleme Fonksiyonu
void ders_guncelle(struct ders dersler[10],int sayac);
//Ders Fonksiyonlar� Bitti
//*******************************************************




//Not Islemleri
void not_ver_fonk(struct dersVer derslerim[20],int sayac1,struct notVer notlarim[3],int sayac2,struct ogrenci student[1000],int sayac);
//Transkript
void transkript_fonk(struct dersVer derslerim[20],int sayac1,struct notVer notlarim[6],int sayac2,struct ogrenci student[1000],int sayac);





