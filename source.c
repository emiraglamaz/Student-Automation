


#include "header.h"
//Ogenci Modulu Fonksiyonlari Baslama
//******************************************************************************************
int i;
void ogrenci_fonk(struct ogrenci student[1000],struct dersVer derslerim[20],struct notVer notlarim[6])
{
			int secim,i;
		    tekrar:
		    printf("\t\nOgrenci Kayit Programi\n");
		    printf("\t--------------------------\n");
		    printf("\t1- Ogrenci Listele\n");
		    printf("\t2- Ogrenci Ara\n");
		    printf("\t3- Ogrenci Ekle\n");
		    printf("\t4- Ogrenci Guncellestir\n");
		    printf("\t5- Not Verme Islemleri\n");
		    printf("\t6- Transkript.\n");
		    printf("\t7- Programdan Cikis.\n");
		    printf("\t--------------------------\n");
		    printf("\tSeciminiz:");
		    scanf("%d",&secim);//Kullanýcýdan deðer bekleniyor
		    printf("\n\n");
		FILE *fp = fopen("ogrenci.txt","r");//dosya okunup fp deðiþkenine atýlýyor.
        int sayac=0;//Ogrenci.txt dosyasýndaki satýr sayýsýný tutan deðiþken
        for(i=0;!feof(fp);i++){ //Dosyadan satýr satýr veri okunup student adlý structure dolduruluyor.
            fscanf(fp,"%s %s %s %s %s %s",&student[i].ogrNo,&student[i].isim,&student[i].soyisim,&student[i].basYili,&student[i].bolum,&student[i].sinif);
            sayac++;
        }//Ogrenci Ders ekleme dosyasi okunuyor eger yeni bir ogrenci eklenecekse dersleride eklenmelidir
        FILE *fn = fopen("alinan_dersler.txt","r");//dosya okunup fp deðiþkenine atýlýyor.
        int sayac1=0;//alinan_dersler.txt dosyasýndaki satýr sayýsýný tutan deðiþken tutan deðiþken
        for(i=0;!feof(fn);i++){//Dosyadan satýr satýr veri okunup derslerim adlý structure dolduruluyor
            fscanf(fn,"%s %s %s %s %s %s",&derslerim[i].ogr_no,&derslerim[i].ders1,&derslerim[i].ders2,&derslerim[i].ders3,&derslerim[i].ders4,&derslerim[i].ders5);
            sayac1++;
        }
        FILE *fnot = fopen("notlar.txt","r");//dosya okunup fp deðiþkenine atýlýyor.
        int sayac2=0;//dersler.txt
        for(i=0;!feof(fnot);i++){
            fscanf(fnot,"%s %s %s %s %s %s",&notlarim[i].ogrno,&notlarim[i].not1,&notlarim[i].not2,&notlarim[i].not3,&notlarim[i].not4,&notlarim[i].not5);
            sayac2++;//notlar.txt
        }
        fclose(fp); //okuma iþleminden sonra dosyalar kapatýlýyor
        fclose(fn);
        fclose(fnot);
        //Kullanýcýnýn yaptýðý seçime göre program dallandýrýlýyor
        switch(secim){
        	case 1:
        		ogrenci_listele(student,sayac);
        		break;
        	case 2:
        		ogrenci_kayitAra(student,sayac);
				break;
			case 3:
				ogrenci_kayitEkle(student,sayac,sayac1,derslerim);
				break;	
			case 4:
				ogrenci_kayitGuncellestir(student,sayac);
				break;
			case 5:
				not_ver_fonk(derslerim,sayac1,notlarim,sayac2,student,sayac);
				break;		
			case 6:
				 transkript_fonk(derslerim,sayac1,notlarim,sayac2,student,sayac);
				break;	
			case 7:
				exit(1);
				break;				
		}
		goto tekrar;

}
//Ogrenci kayit listeleme Fonksiyonu
void ogrenci_listele(struct ogrenci student[1000],int sayac){
	char cumle[40];//Bolum Adýný tutacak deðiþken
	int sec,sinif,bul=0;
		printf("\t--------------------------\n");
		printf("\t1- Bolume Gore Listele\n");
		printf("\t2- Sinifa Gore Listele\n");
		printf("\t--------------------------\n");
        scanf("%d",&sec);
        //Kullanýcý seçimi
        switch(sec){
        	case 1:
        		printf("Bolum Adini Giriniz:");
        		gets(cumle);//Kullanýýcýdan Bolum adý girilmesi bekleniyor
        		gets(cumle);
        		printf("%-16s %-16s %-16s %-16s %-16s %-16s\n","Ogrenci No","Isim","Soyisim","Baslama yili","Bolum","Sinif");
        		for(i=0;i<sayac-1;i++){//structure içinde dolaþýlýyor
        		//strcmp() metodu iki string deðeri karþýlaþtýrýr eþitlerse 0 döner
        			if(strcmp(student[i].bolum ,cumle)==0){//Kullanýcýný girdiði bolum ogrenci dosyasýnda varsa koþul saðlanýyor							
        				bul=1;//kayýt bulundu
        				//ekrana yazdýrýlýyor
        				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
   		    		}
				}
				if(bul==0){//bul=0 ise kayýt bulunamamýstýr
					printf("Bolumde Ogrenci Bulunmamaktadir\n");
				}
				break;//case 1: ait olan 
				
			case 2:
				printf("Sinif Numarasini Giriniz");
				scanf("%d",&sinif);//sýnýf numarasý alýnýyor
				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n","Ogrenci No","Isim","Soyisim","Baslama yili","Bolum","Sinif");
        		for(i=0;i<sayac-1;i++){
        			//atoi() metodu char olarak tutulan sayýlarý integer olarak dönüþtürür
        			if(atoi(student[i].sinif)==sinif){
        				bul=1;//Kayýt bulundu
        				//ekarana yazdýrýlýyor
        				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
   		    		}
   		    	}
   		    	if(bul==0){//kayýt Bulunamadý
   		    		printf("Bu Sinifta Ogrenci Bulunmamaktadir\n");
				}
				break;//case 2: ye ait plan
		}
}


//Ogrnci kayit arama Fonksiyonu
void ogrenci_kayitAra(struct ogrenci student[1000],int sayac){
		char ad[20];//Öðrenci adýný tutan dizi deðiþkeni
        int no,sec,bul=0;//öðrenci numarasýný tutan  no kullanýcýseçimi için sec ve kayýt bulunduðuna dair bul deðiþkenleri
        printf("\t--------------------------\n");
		printf("\t1- Ogrenci Numarasina Gore Ara\n");
		printf("\t2- Ogrenci Adina Gore Ara\n");
		printf("\t--------------------------\n");
        scanf("%d",&sec);//Kullanýcýdan deðer bekleniyor.
        //Kullanýcý seçimi
        switch(sec){
        	case 1://Kullanýcý 1'i seçerse
        		printf("\tAramak Istediginiz Kaydin Ogrenci Numarasinini Giriniz:");
        		scanf("%d",&no);
		        for(i=0;i<sayac;i++){
		        	//atoi() fonksiyonu char olarak tanýmlanan bir tam sayý deðiþkenini integer'a dönüþtürür.
		           if(atoi(student[i].ogrNo)==no){//Koþul saðlanýrsa kayýt bulunmuþ demektir.
		                printf("Aradiginiz Kayit:\n");
		                //Kayýt ekrana basýlýyor.
		            	printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
		            	break;//Döngükýrýlýyor
		           }
		           else if(i==sayac-1)//Kayýt bulunmadýysa
		                printf("\tAradiginiz Kayit Bulunmamaktadir.");
		        }
		        break;//case 1: e ait olan break
		     case 2:
		     	//Kullanýcý 2'yi seçerse öðrenci adýna göre arama yapýlýyor.
		     		printf("\tAramak Istediginiz Ogrencinin Adini Giriniz:");
//gets() fonksiyonu girilen karakter dizisini birleþtirerek iþleme tabi tutar
        			gets(ad);//Kullanýcýdan isim alýnýyor.
        			gets(ad);
		        	for(i=0;i<sayac;i++){//structure içinde geziliyor.
		        	//strcmp() fonksiyonu iki string deðiþkeni karþýlaþtýrýr eðer stringler eþiþtse 0 döne.
		          		 if(strcmp(student[i].isim,ad)==0){//kullanýcýnýn girdiði isim ile structure daki isimler karþýlaþtýrýlýyor
		          		 	 bul=1;//Kayýt bulundu
		               		 printf("Aradiginiz Kayit:\n");
		               		 //kayýt ekrana basýlýyor
		            		 printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
		           		}
		        	}
		        	if(bul==0)//Kayýt bulunamazsa
		               printf("\tAradiginiz Kayit Bulunmamaktadir.");       		
		}     
}	
	
//Ogrenci kayit ekleme Fonksiyonu
void ogrenci_kayitEkle(struct ogrenci student[1000],int sayac, int sayac1,struct dersVer derslerim[20]){
	//ogrenci_fonk fonksiyonunda dosyadan veri okunurken sayac dosyadaki satýr sayýsýný tutmuþtu þimdi bu satýr numarasýný kullanmanýn vakti.
        printf("Ogrenci  Numarasini Giriniz:");
        scanf("%s",&student[sayac].ogrNo);//Öðrenci no 
        printf("Ismini Giriniz:");
        scanf("%s",&student[sayac].isim);//isim
        printf("Soyismini Giriniz:");
        scanf("%s",&student[sayac].soyisim);//soyisim
        printf("Baslangic yilini Giriniz:");
        scanf("%s",&student[sayac].basYili);//baþalam yýlý
        printf("Bolumunu Giriniz:");
        scanf("%s",&student[sayac].bolum);//bölüm
        printf("Ogrenci Sinifini Giriniz");
        scanf("%s",&student[sayac].sinif);//sýnýf 
        
        //Ogrenci Ders Ekleme Islemleri
       	printf("ogrenci numarasini tekrar giriniz");
       	scanf("%s",&derslerim[sayac1].ogr_no);//öðrenci no
        printf("grencinin alacagi 1. dersi  Giriniz:");
         scanf("%s",&derslerim[sayac1].ders1);//ders1
         printf("grencinin alacagi 2. dersi  Giriniz:");
        scanf("%s",&derslerim[sayac1].ders2);//ders2
         printf("grencinin alacagi 3. dersi  Giriniz:");
        scanf("%s",&derslerim[sayac1].ders3);//ders3
         printf("grencinin alacagi 4. dersi  Giriniz:");
        scanf("%s",&derslerim[sayac1].ders4);//ders4
         printf("grencinin alacagi 5. dersi  Giriniz:");
        scanf("%s",&derslerim[sayac1].ders5);//ders5
        

 FILE *fp;
fp = fopen("ogrenci.txt","a");//Dosya açýlýyor
//Eklenen kayýt dosyaya yazýlýyor.
fprintf(fp,"%-10s %-10s %-10s %-10s %-10s %-10s\n",student[sayac].ogrNo,student[sayac].isim,student[sayac].soyisim,student[sayac].basYili,student[sayac].bolum,student[sayac].sinif);
fclose(fp);//dosya kapatýlýyor
FILE *fn;
fn = fopen("alinan_dersler.txt","a");//alýnan dersler dosyasý açýlýyor
//Alýnan dersler dosyaya yazýlýyor
fprintf(fn,"%-10s %-10s %-10s %-10s %-10s %-10s\n",derslerim[sayac1].ogr_no,derslerim[sayac1].ders1,derslerim[sayac1].ders2,derslerim[sayac1].ders3,derslerim[sayac1].ders4,derslerim[sayac1].ders5);
fclose(fn);
        

}


//Ogrenci kayit guncelleme Fonksiyonu
void ogrenci_kayitGuncellestir(struct ogrenci student[1000],int sayac){
        int no,yedek;//Kulllanýcýn girdiði deðeri tutan deðiþken no güncellenecek kaydýn konumunu tutan deðþken yedek
        printf("\tGuncellestirmek Istediginiz Kaydin Ogrenci Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
        	//structure içinde geziliyor
           if(atoi(student[i].ogrNo)==no){//Kullanýcýnýn girdiði numara ile structure daki deðerler karþýlaþtýrýlýyor
                yedek=i;//güncellenecek kaydýn konumu daha sonra dosyaya yazmak için yedek adlý deðiþkene akatrýlýyor.
                printf("Aradiginiz Kayit:\n");
                //Kayýt ekrana basýlýyor
            printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
            break;//Döngü kýrýlýyor
           }
           else if(i==sayac-1){//Kayýt bulunamazsa
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);//Program sonlandýrýlýyor.
           }
        }
        
        //Program buraya gelmiþse demekki güncelleme yapacak kaydý bulmuþtur.
        int sec;
        printf("Ogrenci Numarasini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ogrenci Numarasini Giriniz:");
            scanf("%s",&student[yedek].ogrNo);
        }
        printf("Ismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ismi Giriniz:");
            scanf("%s",&student[yedek].isim);
        }
        
        printf("Soyismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Soyismi Giriniz:");
            scanf("%s",&student[yedek].soyisim);
        }


        printf("Baslama Yilini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Baslama Yilini Giriniz:");
            scanf("%s",&student[yedek].basYili);
        }

        printf("Bolumunu Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Bolumu Giriniz:");
            scanf("%s",&student[yedek].bolum);
        }
        printf("Sinifi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Sinifi Giriniz:");
            scanf("%s",&student[yedek].sinif);
        }

        FILE *fp;
        fp=fopen("ogrenci.txt","w");
        for(i=0;i<sayac-1;i++){
        	//Kayýt dosyaya ayný konumda yazýlýyor
            fprintf(fp,"%15s\t%15s\t%15s\t%15s\t%15s\t%15s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
        }
        fclose(fp);
}
//Ogrenci Modulu Fonksiyonlarý Bitti
//********************************************************************



//Ogretmen Islemleri Baslama
//****************************************************
void ogretmen_fonk(struct ogretmen teacher[1000])
{
		int i,sec,sayac;
		tekrar:
			 sayac=0;
			 
			printf("\t\Ogretim Elemani Kayit Programi\n");
		    printf("\t--------------------------\n");
		    printf("\t1- Ogretim Elemani Listele\n");
		    printf("\t2- Öðretim Elemani Ara\n");
		    printf("\t3- Ogretim Elemani Ekle\n");
		    printf("\t4- Ogretim Elemani Guncellestir\n");
		    printf("\t5- Programdan Cikis.\n");
		    printf("\t--------------------------\n");
		    printf("\tSeciminiz:");
		    scanf("%d",&sec);
		    printf("\n\n");
		    FILE *fo = fopen("öðretmen.txt","r");//Öðretmen dosyasý okunmak için açýlýyor
		    for(i=0;!feof(fo);i++){
		    	//okunan deðerler teacher structure'na atýlýyor
		    	fscanf(fo,"%s %s %s %s",&teacher[i].sicilNo,&teacher[i].isim,&teacher[i].soyisim,&teacher[i].bolum_og);
		    	sayac++;
			}
			fclose(fo);
			switch(sec){
				case 1:
					ogretmen_listele(teacher,sayac);
					break;
				case 2:
					ogretmen_ara(teacher,sayac);
					break;
				case 3:
					ogretmen_kayitEkle(teacher,sayac);
					break;
				case 4:
					 ogretmen_kayitGuncelle(teacher,sayac);
					 break;
				case 5:
					 exit(1);	 			
			}
			goto tekrar;
}


//Ogretmen kayýtlarýný Listeleme
void ogretmen_listele(struct ogretmen teacher[1000],int sayac){
	char cumle[20];//Bölüm adýný tutan dizi deðiþkeni
	int bul=0;
	printf("Bolum Adini Giriniz:");
	gets(cumle);//Bolum adý kullanýcýdan alýnýyor
	gets(cumle);
	printf("%-16s %-16s %-16s %-16s\n","Sicil No","Isim","Soyisim","Bolumu");
        for(i=0;i<sayac-1;i++){
        	if(strcmp(teacher[i].bolum_og,cumle)==0){//Bolum adý bulunarak ekrana basýlýyor
        		bul=1;//Kayýt bulundu
        		printf("%-16s %-16s %-16s %-16s\n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
			} 
        }
        if(bul==0){//Kayýt bulunmazsa
        	printf("Bu Bolumde Egitim Görevlisi Bulunmamaktadir");
		}
}


//ogretmen Kayitlarini Arama

void ogretmen_ara(struct ogretmen teacher[1000],int sayac){
	 int no,bul=0;
        printf("\tAramak Istediginiz Ogretmenin Sicil  Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
           if(atoi(teacher[i].sicilNo)==no){//Kullanýcýnýn girdiði deðer ile kayýtlar arasýndaki numaralar karþýlaþtýrýlýyor
           		bul=1;
                printf("Aradiginiz Kayit:\n");
                //Bulunan kayýt ekrana basýlýyor.
             printf("\t%s\t%s\t%s\t%s \n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
            break;//Döngü kýrýlýyor
           }
        }
        if(bul!=1){
        	printf("\tAradiginiz Kayit Bulunmamaktadir.");
		}
}
                

//ogretmen Kayit Ekleme
void ogretmen_kayitEkle(struct ogretmen teacher[1000],int sayac){
	 printf("Ogretmen sicil numarasini  Giriniz:");
        scanf("%s",&teacher[sayac].sicilNo);
        printf("Ismini Giriniz:");
        scanf("%s",&teacher[sayac].isim);
        printf("Soyismini Giriniz:");
        scanf("%s",&teacher[sayac].soyisim);
        printf("Bolumunu Giriniz:");
        scanf("%s",&teacher[sayac].bolum_og);
        FILE *fp;
        fp = fopen("öðretmen.txt","a");
        fprintf(fp,"%-15s %-15s %-15s %-15s\n",teacher[sayac].sicilNo,teacher[sayac].isim,teacher[sayac].soyisim,teacher[sayac].bolum_og);
        fclose(fp);

}

//Ogretmen Kayit Guncelleme
void ogretmen_kayitGuncelle(struct ogretmen teacher[1000],int sayac){
	  int no,yedek;
        printf("\tGuncellestirmek Istediginiz Kaydin sicil Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
           if(atoi(teacher[i].sicilNo)==no){//Güncelleþtirilmek istenen kayýt aranýyor
                yedek=i;//bulunan kayhdýn konumu korunuyor.
                printf("Aradiginiz Kayit:\n");
                //kayýt ekrana basýlýyor.
            printf("%s\t%s\t%s\t%s\n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
            break;//döngü kýrýlýyor
           }
           else if(i==sayac-1){//kayýt bulunamazsa 
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);//program sonlandýrýlýyor
           }
        }

	//Eðer program buraya gelmiþse kullanýcý günclleyecek kaydý bulmuþ demektir.
        int sec;
        printf("Ogretmenin Sicil  Numarasini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Sicil Numarasini Giriniz:");
            scanf("%s",&teacher[yedek].sicilNo);
        }

        printf("Ismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ismi Giriniz:");
            scanf("%s",&teacher[yedek].isim);
        }

        printf("Soyismi Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Soyismi Giriniz:");
            scanf("%s",&teacher[yedek].soyisim);
        }
        printf("Bolumunu Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Bolumu Giriniz:");
            scanf("%s",&teacher[yedek].bolum_og);
        }


        

        FILE *fp;
        fp=fopen("öðretmen.txt","w");//Dosya açýlýyor
        for(i=0;i<sayac-1;i++){
        	//Güncellenen kayýt dosyaya yazýlýyor
            fprintf(fp,"%15s\t%15s\t%15s\t%15s\n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
        }
        fclose(fp);
}

//Ogretmen Modulu Fonksiyonlari Bitti
//*********************************************************************


//********************************************************************
//Ders Modulu Fonksiyonlari Baslama
void ders_fonk(struct ders dersler[10]){
	int sec ;
	tekrar:
	printf("\t\nDers Islemleri\n");
	printf("\t--------------------------\n");
	printf("\t1- Ders Listele\n");
	printf("\t2- Ders Ara\n");
	printf("\t3- Ders Ekle \n");
	printf("\t4- ders Guncelle\n");
	printf("\t5- Programdan Cikis.\n");
	printf("\t--------------------------\n");
	 printf("\tSeciminiz:");
	scanf("%d",&sec);
	printf("\n\n");
			FILE *fd = fopen("ders.txt","r");//dosya okunup fp deðiþkenine atýlýyor.
        	int sayac=0;
        	for(i=0;!feof(fd);i++){
        		//Desr.txt dosyasýndaki veriler okunarak derrler adlý structure'a atýlýyor
            fscanf(fd,"%s %s ",&dersler[i].dersId,&dersler[i].dersAdi);
            sayac++;
        }
        fclose(fd);//dosya kapatýlýyor
        switch(sec){
        	case 1:
        		ders_listele(dersler,sayac);
        		break;
        	case 2:
				 ders_ara(dersler,sayac);
				 break;
			case 3:
				 ders_ekle(dersler,sayac);
				 break;
			case 4:
				 ders_guncelle(dersler,sayac);
				 break;
			case 5:
				 exit(1);	 
					 		 		
		}
		goto tekrar;
}

//ders Listeleme Fonksiyonu
void ders_listele(struct ders dersler[10],int sayac){
	printf("%-16s %-16s\n","Ders Id","Ders Adi");
        for(i=0;i<sayac;i++){
            printf("%-16s %-16s \n",dersler[i].dersId,dersler[i].dersAdi);
        }
}


//Ders Arama Fonksiyonu
void ders_ara(struct ders dersler[10],int sayac){
	int bul=0;
	char ara[20];//ders adýný tutan dizi deðiþkeni
	     printf("\tAramak Istediginiz Dersin Adini Giriniz:");
        gets(ara);//kullanýcýdan ders adý alýnýyor
        gets(ara);
        for(i=0;i<sayac;i++){
            if(strcmp(dersler[i].dersAdi,ara)==0){//kullnýcýnýn girdiði ders adý ile dosyadaki ders adlarý karþýlaþtýrýlýyor.
            		bul=1;//kayýt bulundu
                printf("Aradiginiz Ders:\n");
             printf("\t%s\t%s \n",dersler[i].dersId,dersler[i].dersAdi);
            break;//döngü kýrýlýyor
			}
           	
           }
        
        if(bul==0){
        	printf("\tAradiginiz Ders Bulunmamaktadir.");
		}
}

//Ders Ekleme fonkssiyonu
void ders_ekle(struct ders dersler[10],int sayac){
	 printf("Dersin Id sini Giriniz:");
        scanf("%s",&dersler[sayac].dersId);
        printf("Dersin Ismini Giriniz:");
        scanf("%s",&dersler[sayac].dersAdi);
        FILE *fp;
        fp = fopen("ders.txt","a");
        fprintf(fp,"\n %-15s %-15s",dersler[sayac].dersId,dersler[sayac].dersAdi);
        fclose(fp);
}

//Ders Guncelleme
void ders_guncelle(struct ders dersler[10],int sayac){
	 int no,yedek;
        printf("\tGuncellestirmek Istediginiz Dersin kodunu Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
           if(atoi(dersler[i].dersId)==no){//Güncellenecek kayýt ile dosyadaki kayýt numaralarý karþýlaþtýrýlýyor.
                yedek=i;//Bulunan kaydýn konumu korunuyor
                printf("Aradiginiz Kayit:\n");
            printf("%s\t%s\n",dersler[i].dersId,dersler[i].dersAdi);
            break;
           }
           else if(i==sayac-1){
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);
           }
        }
    
    //Program buraya gelmiþse demekki kullnaýcý güncellemek istediði kaydý bulmuþtur.
        int sec;
        printf("Ders Id sini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ders Id sini Giriniz:");
            scanf("%s",&dersler[yedek].dersId);
        }

        printf("Ders Adini Degistirmek Istiyor musunuz?\n");
        printf("Evet icin 1 hayir icin 2 giriniz.\n");
        scanf("%d",&sec);
        if(sec==1){
            printf("Yeni Ders Adini Giriniz:");
            scanf("%s",&dersler[yedek].dersAdi);
        }

       
        FILE *fp;
        fp=fopen("ders.txt","w");//Dosya güncellemek için açýlmýþtýr
        for(i=0;i<sayac;i++){
        	//Güncel kayýt ayný konumda dosyaya yazýlýyor
            fprintf(fp,"%15s\t%15s\n",dersler[i].dersId,dersler[i].dersAdi);
        }
        fclose(fp);
}

//Ders Modulu Fonksiyonlari Bitti
//*************************************************************************

//*************************************************************************
//Not Modulu Fonksiyonlari Baslama
void not_ver_fonk(struct dersVer derslerim[20],int sayac1,struct notVer notlarim[6],int sayac2,struct ogrenci student[1000],int sayac){
	int no;
	int bul=0;
	tekrar:
	printf("\nLutfen islem yapacaginiz ogrencinin numarasini giriniz");
	scanf("%d",&no);
	for(i=0;i<sayac;i++){
	//Notlarý girilecek olan kayýt aranýyor
		if(atoi(student[i].ogrNo)==no){
		bul=1;//kayýt bulundu
		printf("aradiginiz kayit\nOgrenciNo\tisim\t\tsoyisim");
		printf("\n%s  \t\t%s  \t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim);
		break;
		}
	}
	if(bul==0){//kayýt bulunamazsa
		printf("aradiginiz kayit bulunmamaktadir\n");
		goto tekrar;
	}
	
	//Eðer bulunan kayýt notlar.txt de mevcut ise demekki daha önce bu kiþiye ait not girilmiþtir.
	//Bir kez daha not girilmesi engeleniyor
	for(i=0;i<sayac2;i++){
		if(atoi(notlarim[i].ogrno)==no){
			printf("Bu Ogrenciye Ait Not Girilmistir...");
			goto tekrar;
		}
	}
	//program buraya gelmiþse bu kiþi için yeni not giriþi demektir 
	//Ve öðrencinin notlarý sýrayla giriliyor.
	printf("lutfen ogrenci numarasini tekrar giriniz:");
	scanf("%s",&notlarim[sayac2].ogrno);
	printf("1.ders Notu girin");
	scanf("%s",&notlarim[sayac2].not1);
	printf("2.ders Notu girin");
	scanf("%s",&notlarim[sayac2].not2);
	printf("3.ders Notu girin");
	scanf("%s",&notlarim[sayac2].not3);
	printf("4.ders Notu girin");
	scanf("%s",&notlarim[sayac2].not4);
	printf("5.ders Notu girin");
	scanf("%s",&notlarim[sayac2].not5);
	FILE *fnot;
	//Girilen notlar öðrenci numarasýyla birlikte notlar.txt dosyasýna yazýlýyor.
        fnot = fopen("notlar.txt","a");
		fprintf(fnot,"%-10s %-10s %-10s %-10s %-10s %-10s\n",notlarim[sayac2].ogrno,notlarim[sayac2].not1,notlarim[sayac2].not2,notlarim[sayac2].not3,notlarim[sayac2].not4,notlarim[sayac2].not5);
        fclose(fnot);
	
	
}

//Transcrip Oluþturma Fonksiyonu
void transkript_fonk(struct dersVer derslerim[20],int sayac1,struct notVer notlarim[6],int sayac2,struct ogrenci student[1000],int sayac){
	int no,bul,yedek;
	tekrar:
		bul=0;
	printf("Ogrenci Numarasi Giriniz:");
	scanf("%d",&no);
	for(i=0;i<sayac;i++){
		if(atoi(student[i].ogrNo)==no){//Transkrip için kullanýcýný girdiði numara aranýyor
			bul=1;//kayýt bulundu
			yedek=i;//kullanýcýnýn konumu saklanýyor ve ekrana basýlýyor
			
			printf("*****************************************************************************\n");
			printf("%s \t%s \t%s \t%s \t%s \t\t%s","No","isim","soyisim","Bas.Yili","Bolum","Sinif");
			printf("\n%-5s \t%-5s \t%-5s \t%-5s \t\t%-5s \t%-5s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
			break;
		}
	}
	if(bul==0){//kayýt bulunamazsa
		printf("Boyle Bir Kayit Bulunamadi");
		goto tekrar;
	}
	//Program buraya gelmiþse kayýt bulunmuþ demektir
	//Kullanýcýnýn not ortalamasý hesaplanýyor
	//burada sonuc float olasý gerektiði için typecasting iþlemi yapýlýyor. 
		float a=(float)(atoi(notlarim[yedek].not1)
			+atoi(notlarim[yedek].not2)
			+atoi(notlarim[yedek].not3)
			+atoi(notlarim[yedek].not4)
			+atoi(notlarim[yedek].not5))
			/5;
	//Dersler notlarýyla beraber ekrana basýlýyor
		printf("\n%s   \t%s 	%s\n",derslerim[yedek].ders1,"=",notlarim[yedek].not1);
		printf("\n%s    \t%s 	%s\n",derslerim[yedek].ders2,"=",notlarim[yedek].not2);
		printf("\n%s   \t%s 	%s\n",derslerim[yedek].ders3,"=",notlarim[yedek].not3);
		printf("\n%s 	 \t%s 	%s\n",derslerim[yedek].ders4,"=",notlarim[yedek].not4);
		printf("\n%s 	 \t%s 	%s\n",derslerim[yedek].ders5,"=",notlarim[yedek].not5);
		printf("\nNot Ortalamasi : %f",a);
	    printf("\n******************************************************************************");
}
//Not modülü fonksiyonu bitti
//**********************************************************************************





















