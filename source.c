


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
		    scanf("%d",&secim);//Kullan�c�dan de�er bekleniyor
		    printf("\n\n");
		FILE *fp = fopen("ogrenci.txt","r");//dosya okunup fp de�i�kenine at�l�yor.
        int sayac=0;//Ogrenci.txt dosyas�ndaki sat�r say�s�n� tutan de�i�ken
        for(i=0;!feof(fp);i++){ //Dosyadan sat�r sat�r veri okunup student adl� structure dolduruluyor.
            fscanf(fp,"%s %s %s %s %s %s",&student[i].ogrNo,&student[i].isim,&student[i].soyisim,&student[i].basYili,&student[i].bolum,&student[i].sinif);
            sayac++;
        }//Ogrenci Ders ekleme dosyasi okunuyor eger yeni bir ogrenci eklenecekse dersleride eklenmelidir
        FILE *fn = fopen("alinan_dersler.txt","r");//dosya okunup fp de�i�kenine at�l�yor.
        int sayac1=0;//alinan_dersler.txt dosyas�ndaki sat�r say�s�n� tutan de�i�ken tutan de�i�ken
        for(i=0;!feof(fn);i++){//Dosyadan sat�r sat�r veri okunup derslerim adl� structure dolduruluyor
            fscanf(fn,"%s %s %s %s %s %s",&derslerim[i].ogr_no,&derslerim[i].ders1,&derslerim[i].ders2,&derslerim[i].ders3,&derslerim[i].ders4,&derslerim[i].ders5);
            sayac1++;
        }
        FILE *fnot = fopen("notlar.txt","r");//dosya okunup fp de�i�kenine at�l�yor.
        int sayac2=0;//dersler.txt
        for(i=0;!feof(fnot);i++){
            fscanf(fnot,"%s %s %s %s %s %s",&notlarim[i].ogrno,&notlarim[i].not1,&notlarim[i].not2,&notlarim[i].not3,&notlarim[i].not4,&notlarim[i].not5);
            sayac2++;//notlar.txt
        }
        fclose(fp); //okuma i�leminden sonra dosyalar kapat�l�yor
        fclose(fn);
        fclose(fnot);
        //Kullan�c�n�n yapt��� se�ime g�re program dalland�r�l�yor
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
	char cumle[40];//Bolum Ad�n� tutacak de�i�ken
	int sec,sinif,bul=0;
		printf("\t--------------------------\n");
		printf("\t1- Bolume Gore Listele\n");
		printf("\t2- Sinifa Gore Listele\n");
		printf("\t--------------------------\n");
        scanf("%d",&sec);
        //Kullan�c� se�imi
        switch(sec){
        	case 1:
        		printf("Bolum Adini Giriniz:");
        		gets(cumle);//Kullan��c�dan Bolum ad� girilmesi bekleniyor
        		gets(cumle);
        		printf("%-16s %-16s %-16s %-16s %-16s %-16s\n","Ogrenci No","Isim","Soyisim","Baslama yili","Bolum","Sinif");
        		for(i=0;i<sayac-1;i++){//structure i�inde dola��l�yor
        		//strcmp() metodu iki string de�eri kar��la�t�r�r e�itlerse 0 d�ner
        			if(strcmp(student[i].bolum ,cumle)==0){//Kullan�c�n� girdi�i bolum ogrenci dosyas�nda varsa ko�ul sa�lan�yor							
        				bul=1;//kay�t bulundu
        				//ekrana yazd�r�l�yor
        				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
   		    		}
				}
				if(bul==0){//bul=0 ise kay�t bulunamam�st�r
					printf("Bolumde Ogrenci Bulunmamaktadir\n");
				}
				break;//case 1: ait olan 
				
			case 2:
				printf("Sinif Numarasini Giriniz");
				scanf("%d",&sinif);//s�n�f numaras� al�n�yor
				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n","Ogrenci No","Isim","Soyisim","Baslama yili","Bolum","Sinif");
        		for(i=0;i<sayac-1;i++){
        			//atoi() metodu char olarak tutulan say�lar� integer olarak d�n��t�r�r
        			if(atoi(student[i].sinif)==sinif){
        				bul=1;//Kay�t bulundu
        				//ekarana yazd�r�l�yor
        				printf("%-16s %-16s %-16s %-16s %-16s %-16s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
   		    		}
   		    	}
   		    	if(bul==0){//kay�t Bulunamad�
   		    		printf("Bu Sinifta Ogrenci Bulunmamaktadir\n");
				}
				break;//case 2: ye ait plan
		}
}


//Ogrnci kayit arama Fonksiyonu
void ogrenci_kayitAra(struct ogrenci student[1000],int sayac){
		char ad[20];//��renci ad�n� tutan dizi de�i�keni
        int no,sec,bul=0;//��renci numaras�n� tutan  no kullan�c�se�imi i�in sec ve kay�t bulundu�una dair bul de�i�kenleri
        printf("\t--------------------------\n");
		printf("\t1- Ogrenci Numarasina Gore Ara\n");
		printf("\t2- Ogrenci Adina Gore Ara\n");
		printf("\t--------------------------\n");
        scanf("%d",&sec);//Kullan�c�dan de�er bekleniyor.
        //Kullan�c� se�imi
        switch(sec){
        	case 1://Kullan�c� 1'i se�erse
        		printf("\tAramak Istediginiz Kaydin Ogrenci Numarasinini Giriniz:");
        		scanf("%d",&no);
		        for(i=0;i<sayac;i++){
		        	//atoi() fonksiyonu char olarak tan�mlanan bir tam say� de�i�kenini integer'a d�n��t�r�r.
		           if(atoi(student[i].ogrNo)==no){//Ko�ul sa�lan�rsa kay�t bulunmu� demektir.
		                printf("Aradiginiz Kayit:\n");
		                //Kay�t ekrana bas�l�yor.
		            	printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
		            	break;//D�ng�k�r�l�yor
		           }
		           else if(i==sayac-1)//Kay�t bulunmad�ysa
		                printf("\tAradiginiz Kayit Bulunmamaktadir.");
		        }
		        break;//case 1: e ait olan break
		     case 2:
		     	//Kullan�c� 2'yi se�erse ��renci ad�na g�re arama yap�l�yor.
		     		printf("\tAramak Istediginiz Ogrencinin Adini Giriniz:");
//gets() fonksiyonu girilen karakter dizisini birle�tirerek i�leme tabi tutar
        			gets(ad);//Kullan�c�dan isim al�n�yor.
        			gets(ad);
		        	for(i=0;i<sayac;i++){//structure i�inde geziliyor.
		        	//strcmp() fonksiyonu iki string de�i�keni kar��la�t�r�r e�er stringler e�i�tse 0 d�ne.
		          		 if(strcmp(student[i].isim,ad)==0){//kullan�c�n�n girdi�i isim ile structure daki isimler kar��la�t�r�l�yor
		          		 	 bul=1;//Kay�t bulundu
		               		 printf("Aradiginiz Kayit:\n");
		               		 //kay�t ekrana bas�l�yor
		            		 printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
		           		}
		        	}
		        	if(bul==0)//Kay�t bulunamazsa
		               printf("\tAradiginiz Kayit Bulunmamaktadir.");       		
		}     
}	
	
//Ogrenci kayit ekleme Fonksiyonu
void ogrenci_kayitEkle(struct ogrenci student[1000],int sayac, int sayac1,struct dersVer derslerim[20]){
	//ogrenci_fonk fonksiyonunda dosyadan veri okunurken sayac dosyadaki sat�r say�s�n� tutmu�tu �imdi bu sat�r numaras�n� kullanman�n vakti.
        printf("Ogrenci  Numarasini Giriniz:");
        scanf("%s",&student[sayac].ogrNo);//��renci no 
        printf("Ismini Giriniz:");
        scanf("%s",&student[sayac].isim);//isim
        printf("Soyismini Giriniz:");
        scanf("%s",&student[sayac].soyisim);//soyisim
        printf("Baslangic yilini Giriniz:");
        scanf("%s",&student[sayac].basYili);//ba�alam y�l�
        printf("Bolumunu Giriniz:");
        scanf("%s",&student[sayac].bolum);//b�l�m
        printf("Ogrenci Sinifini Giriniz");
        scanf("%s",&student[sayac].sinif);//s�n�f 
        
        //Ogrenci Ders Ekleme Islemleri
       	printf("ogrenci numarasini tekrar giriniz");
       	scanf("%s",&derslerim[sayac1].ogr_no);//��renci no
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
fp = fopen("ogrenci.txt","a");//Dosya a��l�yor
//Eklenen kay�t dosyaya yaz�l�yor.
fprintf(fp,"%-10s %-10s %-10s %-10s %-10s %-10s\n",student[sayac].ogrNo,student[sayac].isim,student[sayac].soyisim,student[sayac].basYili,student[sayac].bolum,student[sayac].sinif);
fclose(fp);//dosya kapat�l�yor
FILE *fn;
fn = fopen("alinan_dersler.txt","a");//al�nan dersler dosyas� a��l�yor
//Al�nan dersler dosyaya yaz�l�yor
fprintf(fn,"%-10s %-10s %-10s %-10s %-10s %-10s\n",derslerim[sayac1].ogr_no,derslerim[sayac1].ders1,derslerim[sayac1].ders2,derslerim[sayac1].ders3,derslerim[sayac1].ders4,derslerim[sayac1].ders5);
fclose(fn);
        

}


//Ogrenci kayit guncelleme Fonksiyonu
void ogrenci_kayitGuncellestir(struct ogrenci student[1000],int sayac){
        int no,yedek;//Kulllan�c�n girdi�i de�eri tutan de�i�ken no g�ncellenecek kayd�n konumunu tutan de��ken yedek
        printf("\tGuncellestirmek Istediginiz Kaydin Ogrenci Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
        	//structure i�inde geziliyor
           if(atoi(student[i].ogrNo)==no){//Kullan�c�n�n girdi�i numara ile structure daki de�erler kar��la�t�r�l�yor
                yedek=i;//g�ncellenecek kayd�n konumu daha sonra dosyaya yazmak i�in yedek adl� de�i�kene akatr�l�yor.
                printf("Aradiginiz Kayit:\n");
                //Kay�t ekrana bas�l�yor
            printf("\t%s\t%s\t%s\t%s\t%s\t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
            break;//D�ng� k�r�l�yor
           }
           else if(i==sayac-1){//Kay�t bulunamazsa
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);//Program sonland�r�l�yor.
           }
        }
        
        //Program buraya gelmi�se demekki g�ncelleme yapacak kayd� bulmu�tur.
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
        	//Kay�t dosyaya ayn� konumda yaz�l�yor
            fprintf(fp,"%15s\t%15s\t%15s\t%15s\t%15s\t%15s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
        }
        fclose(fp);
}
//Ogrenci Modulu Fonksiyonlar� Bitti
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
		    printf("\t2- ��retim Elemani Ara\n");
		    printf("\t3- Ogretim Elemani Ekle\n");
		    printf("\t4- Ogretim Elemani Guncellestir\n");
		    printf("\t5- Programdan Cikis.\n");
		    printf("\t--------------------------\n");
		    printf("\tSeciminiz:");
		    scanf("%d",&sec);
		    printf("\n\n");
		    FILE *fo = fopen("��retmen.txt","r");//��retmen dosyas� okunmak i�in a��l�yor
		    for(i=0;!feof(fo);i++){
		    	//okunan de�erler teacher structure'na at�l�yor
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


//Ogretmen kay�tlar�n� Listeleme
void ogretmen_listele(struct ogretmen teacher[1000],int sayac){
	char cumle[20];//B�l�m ad�n� tutan dizi de�i�keni
	int bul=0;
	printf("Bolum Adini Giriniz:");
	gets(cumle);//Bolum ad� kullan�c�dan al�n�yor
	gets(cumle);
	printf("%-16s %-16s %-16s %-16s\n","Sicil No","Isim","Soyisim","Bolumu");
        for(i=0;i<sayac-1;i++){
        	if(strcmp(teacher[i].bolum_og,cumle)==0){//Bolum ad� bulunarak ekrana bas�l�yor
        		bul=1;//Kay�t bulundu
        		printf("%-16s %-16s %-16s %-16s\n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
			} 
        }
        if(bul==0){//Kay�t bulunmazsa
        	printf("Bu Bolumde Egitim G�revlisi Bulunmamaktadir");
		}
}


//ogretmen Kayitlarini Arama

void ogretmen_ara(struct ogretmen teacher[1000],int sayac){
	 int no,bul=0;
        printf("\tAramak Istediginiz Ogretmenin Sicil  Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
           if(atoi(teacher[i].sicilNo)==no){//Kullan�c�n�n girdi�i de�er ile kay�tlar aras�ndaki numaralar kar��la�t�r�l�yor
           		bul=1;
                printf("Aradiginiz Kayit:\n");
                //Bulunan kay�t ekrana bas�l�yor.
             printf("\t%s\t%s\t%s\t%s \n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
            break;//D�ng� k�r�l�yor
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
        fp = fopen("��retmen.txt","a");
        fprintf(fp,"%-15s %-15s %-15s %-15s\n",teacher[sayac].sicilNo,teacher[sayac].isim,teacher[sayac].soyisim,teacher[sayac].bolum_og);
        fclose(fp);

}

//Ogretmen Kayit Guncelleme
void ogretmen_kayitGuncelle(struct ogretmen teacher[1000],int sayac){
	  int no,yedek;
        printf("\tGuncellestirmek Istediginiz Kaydin sicil Numarasinini Giriniz:");
        scanf("%d",&no);
        for(i=0;i<sayac;i++){
           if(atoi(teacher[i].sicilNo)==no){//G�ncelle�tirilmek istenen kay�t aran�yor
                yedek=i;//bulunan kayhd�n konumu korunuyor.
                printf("Aradiginiz Kayit:\n");
                //kay�t ekrana bas�l�yor.
            printf("%s\t%s\t%s\t%s\n",teacher[i].sicilNo,teacher[i].isim,teacher[i].soyisim,teacher[i].bolum_og);
            break;//d�ng� k�r�l�yor
           }
           else if(i==sayac-1){//kay�t bulunamazsa 
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);//program sonland�r�l�yor
           }
        }

	//E�er program buraya gelmi�se kullan�c� g�nclleyecek kayd� bulmu� demektir.
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
        fp=fopen("��retmen.txt","w");//Dosya a��l�yor
        for(i=0;i<sayac-1;i++){
        	//G�ncellenen kay�t dosyaya yaz�l�yor
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
			FILE *fd = fopen("ders.txt","r");//dosya okunup fp de�i�kenine at�l�yor.
        	int sayac=0;
        	for(i=0;!feof(fd);i++){
        		//Desr.txt dosyas�ndaki veriler okunarak derrler adl� structure'a at�l�yor
            fscanf(fd,"%s %s ",&dersler[i].dersId,&dersler[i].dersAdi);
            sayac++;
        }
        fclose(fd);//dosya kapat�l�yor
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
	char ara[20];//ders ad�n� tutan dizi de�i�keni
	     printf("\tAramak Istediginiz Dersin Adini Giriniz:");
        gets(ara);//kullan�c�dan ders ad� al�n�yor
        gets(ara);
        for(i=0;i<sayac;i++){
            if(strcmp(dersler[i].dersAdi,ara)==0){//kulln�c�n�n girdi�i ders ad� ile dosyadaki ders adlar� kar��la�t�r�l�yor.
            		bul=1;//kay�t bulundu
                printf("Aradiginiz Ders:\n");
             printf("\t%s\t%s \n",dersler[i].dersId,dersler[i].dersAdi);
            break;//d�ng� k�r�l�yor
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
           if(atoi(dersler[i].dersId)==no){//G�ncellenecek kay�t ile dosyadaki kay�t numaralar� kar��la�t�r�l�yor.
                yedek=i;//Bulunan kayd�n konumu korunuyor
                printf("Aradiginiz Kayit:\n");
            printf("%s\t%s\n",dersler[i].dersId,dersler[i].dersAdi);
            break;
           }
           else if(i==sayac-1){
                printf("\tAradiginiz Kayit Bulunmamaktadir.");
                exit(1);
           }
        }
    
    //Program buraya gelmi�se demekki kullna�c� g�ncellemek istedi�i kayd� bulmu�tur.
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
        fp=fopen("ders.txt","w");//Dosya g�ncellemek i�in a��lm��t�r
        for(i=0;i<sayac;i++){
        	//G�ncel kay�t ayn� konumda dosyaya yaz�l�yor
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
	//Notlar� girilecek olan kay�t aran�yor
		if(atoi(student[i].ogrNo)==no){
		bul=1;//kay�t bulundu
		printf("aradiginiz kayit\nOgrenciNo\tisim\t\tsoyisim");
		printf("\n%s  \t\t%s  \t%s\n",student[i].ogrNo,student[i].isim,student[i].soyisim);
		break;
		}
	}
	if(bul==0){//kay�t bulunamazsa
		printf("aradiginiz kayit bulunmamaktadir\n");
		goto tekrar;
	}
	
	//E�er bulunan kay�t notlar.txt de mevcut ise demekki daha �nce bu ki�iye ait not girilmi�tir.
	//Bir kez daha not girilmesi engeleniyor
	for(i=0;i<sayac2;i++){
		if(atoi(notlarim[i].ogrno)==no){
			printf("Bu Ogrenciye Ait Not Girilmistir...");
			goto tekrar;
		}
	}
	//program buraya gelmi�se bu ki�i i�in yeni not giri�i demektir 
	//Ve ��rencinin notlar� s�rayla giriliyor.
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
	//Girilen notlar ��renci numaras�yla birlikte notlar.txt dosyas�na yaz�l�yor.
        fnot = fopen("notlar.txt","a");
		fprintf(fnot,"%-10s %-10s %-10s %-10s %-10s %-10s\n",notlarim[sayac2].ogrno,notlarim[sayac2].not1,notlarim[sayac2].not2,notlarim[sayac2].not3,notlarim[sayac2].not4,notlarim[sayac2].not5);
        fclose(fnot);
	
	
}

//Transcrip Olu�turma Fonksiyonu
void transkript_fonk(struct dersVer derslerim[20],int sayac1,struct notVer notlarim[6],int sayac2,struct ogrenci student[1000],int sayac){
	int no,bul,yedek;
	tekrar:
		bul=0;
	printf("Ogrenci Numarasi Giriniz:");
	scanf("%d",&no);
	for(i=0;i<sayac;i++){
		if(atoi(student[i].ogrNo)==no){//Transkrip i�in kullan�c�n� girdi�i numara aran�yor
			bul=1;//kay�t bulundu
			yedek=i;//kullan�c�n�n konumu saklan�yor ve ekrana bas�l�yor
			
			printf("*****************************************************************************\n");
			printf("%s \t%s \t%s \t%s \t%s \t\t%s","No","isim","soyisim","Bas.Yili","Bolum","Sinif");
			printf("\n%-5s \t%-5s \t%-5s \t%-5s \t\t%-5s \t%-5s\n",student[i].ogrNo,student[i].isim,student[i].soyisim,student[i].basYili,student[i].bolum,student[i].sinif);
			break;
		}
	}
	if(bul==0){//kay�t bulunamazsa
		printf("Boyle Bir Kayit Bulunamadi");
		goto tekrar;
	}
	//Program buraya gelmi�se kay�t bulunmu� demektir
	//Kullan�c�n�n not ortalamas� hesaplan�yor
	//burada sonuc float olas� gerekti�i i�in typecasting i�lemi yap�l�yor. 
		float a=(float)(atoi(notlarim[yedek].not1)
			+atoi(notlarim[yedek].not2)
			+atoi(notlarim[yedek].not3)
			+atoi(notlarim[yedek].not4)
			+atoi(notlarim[yedek].not5))
			/5;
	//Dersler notlar�yla beraber ekrana bas�l�yor
		printf("\n%s   \t%s 	%s\n",derslerim[yedek].ders1,"=",notlarim[yedek].not1);
		printf("\n%s    \t%s 	%s\n",derslerim[yedek].ders2,"=",notlarim[yedek].not2);
		printf("\n%s   \t%s 	%s\n",derslerim[yedek].ders3,"=",notlarim[yedek].not3);
		printf("\n%s 	 \t%s 	%s\n",derslerim[yedek].ders4,"=",notlarim[yedek].not4);
		printf("\n%s 	 \t%s 	%s\n",derslerim[yedek].ders5,"=",notlarim[yedek].not5);
		printf("\nNot Ortalamasi : %f",a);
	    printf("\n******************************************************************************");
}
//Not mod�l� fonksiyonu bitti
//**********************************************************************************





















