

#include "header.h"
int i,j;
int main()
{	
    struct ogrenci student[1000];//�rnek oluturuldu
    struct ogretmen teacher[1000];//�rnek oluturuldu
    struct ders dersler[10];//�rnek oluturuldu
    struct dersVer derslerim[20];//�rnek oluturuldu
    struct notVer  notlarim[6];//�rnek oluturuldu
    int sec;
    		printf("\t\nOgrenci Otomasyonu\n");
		    printf("\t--------------------------\n");
		    printf("\t1- Ogrenci Islemleri\n");
		    printf("\t2- Ogretim Elemani Islemleri\n");
		    printf("\t3- Ders Islemleri\n");
		    printf("\t4- Programdan Cikis.\n");
		    printf("\t--------------------------\n");
		    printf("\tSeciminiz:");
    scanf("%d",&sec);
    switch(sec){
    	case 1:
    		ogrenci_fonk(student,derslerim,notlarim);
    		break;
    	case 2:
			ogretmen_fonk(teacher);
			break;
		case 3:
			ders_fonk(dersler);
			break;
		case 4:
			exit(1);							
	}
	return 0;
}



