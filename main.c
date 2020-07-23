#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
}DATE;


 typedef struct
{
    unsigned int id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    unsigned int numero_tel;
    DATE date;
}CLIENT;



void ajout_client()
{
    CLIENT C;
    int choix = 1;
    FILE *fichier = NULL;
    fichier = fopen("Client.txt","a+");
    do
    {
        printf("** Ajout d'un client ** \n");
        printf("Entrez l'identifiant du client: \n");
        scanf("%d",&C.id_client);
        fflush(stdin);
        printf("Entrez le nom du client: \n");
        scanf("%s",C.nom);
        fflush(stdin);
        printf("Entrez le prenom du client: \n");
        scanf("%s",C.prenom);
        fflush(stdin);
        printf("Entrez sa profession: \n");
        scanf("%s",C.profession);
        fflush(stdin);
        printf("Entrez le numero_tel du client: \n");
        scanf("%d",&C.numero_tel);
        printf("Entrez la date d'ajout du client: \n");
        scanf("%d/%d/%d",&C.date.jour,&C.date.mois,&C.date.annee);//ici, on récupère la date du jour d'ajout du client
        printf("ID_client: %u \n NOM: %s \n PRENOM: %s \n PROFESSION: %s \n NUM_TEL: %u \n DATE_D'AJOUT: %u/%u/%u \n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);
        printf("Voulez-vous continuer d'ajouter les clients? (1/0) \n");
        scanf("%d",&choix);
        fprintf(fichier,"%u;%s;%s;%s;%u;%u/%u/%u\n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);

    }while(choix == 1);
    fclose(fichier);
}

void modification_client()
{
    int MAX = 1;
    CLIENT C[MAX];
    printf("**Modification des informations du client**: \n");
}




int main()
{
    ajout_client();
}
