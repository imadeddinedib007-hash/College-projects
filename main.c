#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char rue[30];
char ville[12];
int postalcode;
}adresse;
typedef struct{
int jour;
int mois;
int annee;
}date;
typedef struct{
char nom[12];
char prenom[20];
int numerocarte;
adresse b;
date a;
}membre;
typedef enum{disponible,emprunte,reserve}etat_livre;
typedef struct{
char titre[50];
char auteur[30];
int annee_de_sortie;
etat_livre etat;
}livre;

int main()
{
date a;
adresse b;
membre c[100];
etat_livre d;
livre e[100];
int i,j;
int k=0,n;
int m,s;
int disp=0,empr=0,reser=0;
printf("======WELCOME TO OUR LIBRARY======\n\n");
do {
printf("We currenly have %d MEMBERS and %d BOOKS.\n\n",m,s);
printf("choose an action :\n\n1_show current members.\n2_add new members.\n3_show all books.\n4_show only available books.\n5_show only taken books.\n6_add new books.\n");
scanf("%d",&n);
if(n==2){
    printf("welcome!\nplease enter how many members you want to add:\n");
    scanf("%d",&m);
    printf("now add the necessary informations for each member :\n\n ");
    for(i=0;i<m;i++){
            printf("add the informations of the member %d\n",i+1);
        printf("first name : ");
        scanf(" %[^\n]",c[i].prenom);
        printf("last name : ");
        scanf(" %[^\n]",c[i].nom);
        printf("ID card number : ");
        scanf("%d",&c[i].numerocarte);
        printf("address of residency :\n1_street : ");
        scanf(" %[^\n]",c[i].b.rue);
        printf("2_city : ");
        scanf(" %[^\n]",c[i].b.ville);
        printf("3_Postal code : ");
        scanf("%d",&c[i].b.postalcode);
        printf("Date of signing up :\n");
        do{
            printf("day : ");
            scanf("%d",&c[i].a.jour);
            if(c[i].a.jour<1 || c[i].a.jour>31)
                printf("enter a valid day\n");
        }while(c[i].a.jour<1 || c[i].a.jour>31);
        do{
            printf("month : ");
            scanf("%d",&c[i].a.mois);
            if(c[i].a.mois<1 || c[i].a.mois>12)
                printf("enter a valid month\n");
            }while(c[i].a.mois<1 || c[i].a.mois>12);
            printf("year : ");
            scanf("%d",&c[i].a.annee);
    }
}
else if(n==1){
    printf("Here is the list of all our members: \n\n");
    for(i=0;i<m;i++){
        printf("MEMBER %d\n",i+1);
        printf("first name : %s\n",c[i].prenom);
        printf("last name : %s\n",c[i].nom);
        printf("ID card number : %d\n",c[i].numerocarte);
        printf("adress :\n1_street :%s\n2_city :%s\n3_postal code :%d\n",c[i].b.rue,c[i].b.ville,c[i].b.postalcode);
        printf("member since :(%d/%d/%d)\n\n",c[i].a.jour,c[i].a.mois,c[i].a.annee);
    }
}
else if(n==6){
    printf("how many books do you want to add ?: ");
    scanf("%d",&s);
    for(i=0;i<s;i++){
        printf("enter the infomations of each book.\n\nBook number %d:\n",i+1);
        printf("Book name : ");
        scanf(" %[^\n]",e[i].titre);
        printf("Book author : ");
        scanf(" %[^\n]",e[i].titre);
        printf("release date : ");
        scanf("%d",&e[i].annee_de_sortie);
        printf("do you think this book is interesting ? if so what do you expect from now to next week ?\n0=still available.\t1=taken.\t2=reserved.\n");
        scanf("%d",&e[i].etat);
        if(e[i].etat==disponible)
            disp++;
        else if(e[i].etat==emprunte)
                empr++;
        else if(e[i].etat==reserve)
            reser++;
    }
}
else if(n==3){
        printf("Here is the list of all registered books :\n\n");
        for(i=0;i<s;i++){
            printf("BOOK NUMBER %d\n",i+1);
            printf("book name : %s\n",e[i].titre);
            printf("book author : %s\n",e[i].auteur);
            printf("realse date : %d\n",e[i].annee_de_sortie);
            printf("availability : %s\n\n",e[i].etat);
        }
}
else if(n==4){
    printf("there is currenly %d available books:\n",disp);
    for(i=0;i<disp;i++){
        printf("%d : %s",i+1,e[i].titre);
    }
}
else if(n==5){
    printf("there is currenly %d taken books:\n",empr);
    for(i=0;i<empr;i++){
        printf("%d : %s",i+1,e[i].titre);
    }
}
}while(k==0);

    return 0;
}
