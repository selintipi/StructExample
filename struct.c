#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct STD {
	int id;
	char ad[20];
	int yas;
	int ort;
} ogrenci;

void liste_yaz(ogrenci* std, int n){
		int i;
		printf("ID\tAD\tYAS\tORT\n");
		for(i=0; i<n; i++){
		printf("%d\t%s\t%d\t%d\n",std[i].id,std[i].ad,std[i].yas,std[i].ort);
	}
}
void nota_gore_sirala(ogrenci* std, int n){
	int i,j;
	ogrenci tmp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1; j++){
		if(std[j].ort<std[j+1].ort)
		tmp = std[j];
		std[j] = std[j+1];
		std[j+1] = tmp;
		}
	}
}
void ada_gore_sirala(ogrenci* std, int n){
	int i,j;
	ogrenci tmp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1; j++){
		if(strcmp(std[j].ad,std[j+1].ad)==1)
		tmp = std[j];
		std[j] = std[j+1];
		std[j+1] = tmp;
		}
	}
}
int main()
{
	int n, i;
	ogrenci* std;
	printf("ogrenci sayisini giriniz :");
	scanf("%d",&n);
	std = (ogrenci*) malloc(n*sizeof(ogrenci));
		for(i=0; i<n; i++){
		printf("%d. ogrenci id\n",i);
		scanf("%d", &std[i].id);
		printf("%d. ogrenci adi\n",i);
		scanf("%s", std[i].ad);
		printf("%d. ogrenci yasi\n",i);
		scanf("%d", &std[i].yas);
		printf("%d. ogrenci ortalamasi\n",i);
		scanf("%d", &std[i].ort);
	}
		liste_yaz(std,n);
		nota_gore_sirala(std,n);
		liste_yaz(std,n);
		ada_gore_sirala(std,n);
		liste_yaz(std,n);
		
		free(std);
		return 0;
}
