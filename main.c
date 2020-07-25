
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct
{
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
}DATE;


struct
{
    unsigned int id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    unsigned int numero_tel;
    DATE date;
}CLIENT, Mise_jour;



void Ajout_client()
{

    int choix = 1;
    FILE *fichier = NULL;
    fichier = fopen("Client.txt","a+");
    do
    {
        printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ** Ajout d'un client **\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf(" \n\n");
        printf("Entrez l'identifiant du client: \n");
        scanf("%d",&CLIENT.id_client);
        fflush(stdin);
        printf("Entrez le nom du client: \n");
        scanf("%s",CLIENT.nom);
        fflush(stdin);
        printf("Entrez le prenom du client: \n");
        scanf("%s",CLIENT.prenom);
        fflush(stdin);
        printf("Entrez sa profession: \n");
        scanf("%s",CLIENT.profession);
        fflush(stdin);
        printf("Entrez le numero_tel du client: \n");
        scanf("%d",&CLIENT.numero_tel);
        printf("Entrez la date d'ajout du client: \n");
        scanf("%d/%d/%d",&CLIENT.date.jour,&CLIENT.date.mois,&CLIENT.date.annee);//ici, on récupère la date du jour d'ajout du client
        printf("ID_client: %u \n NOM: %s \n PRENOM: %s \n PROFESSION: %s \n NUM_TEL: %u \n DATE_D'AJOUT: %u/%u/%u \n",CLIENT.id_client,CLIENT.nom,CLIENT.prenom,CLIENT.profession, CLIENT.numero_tel,CLIENT.date.jour, CLIENT.date.mois, CLIENT.date.annee);
        printf("Voulez-vous continuer d'ajouter les clients? (1/0) \n");
        scanf("%d",&choix);
        fprintf(fichier,"%u;%s;%s;%s;%u;%u/%u/%u\n",CLIENT.id_client,CLIENT.nom,CLIENT.prenom,CLIENT.profession, CLIENT.numero_tel,CLIENT.date.jour, CLIENT.date.mois, CLIENT.date.annee);

    }while(choix == 1);
    fclose(fichier);
}

void Modification_client()
{
    FILE *fichier = NULL;
    FILE *fich_modifier;
    fichier = fopen("client.txt","r");
    fich_modifier = fopen("fichier_modifier.txt","w");
    printf("**Modification des informations du client**: \n");
    printf("Entrez l'id du client dont vous voulez faire des modifications: ");
    scanf("%d",&Mise_jour.id_client);
    while(fscanf(fichier,"%u;%s;%s;%s;%u;%u/%u/%u\n",&CLIENT.id_client,&CLIENT.nom,&CLIENT.prenom,&CLIENT.profession,&CLIENT.numero_tel,&CLIENT.date.jour, &CLIENT.date.mois, &CLIENT.date.annee) != EOF)
    {
        int test = 0;
        int choice = 0;
        if(Mise_jour.id_client == CLIENT.id_client)
        {

           test = 1;
           printf("vous allez modifier les donnees de: %s",CLIENT.nom);
           printf("Voulez-vous modifier \n1.Le nom \n2.Le prenom \n3.La Profession \n4.Le Numero_tel \n5.La Date");
           switch(choice)
                {
                    case 1:
                        printf("Entrez le nouveau nom: \n");
                        scanf("%s",Mise_jour.nom);
                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);

                    break;
                    case 2:
                        printf("Entrez le nouveau prenom: \n");
                        scanf("%s",Mise_jour.prenom);
                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);
                    break;
                    case 3:
                        printf("Entrez la nouvelle profession: \n");
                        scanf("%s",Mise_jour.profession);
                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);
                    break;
                    case 4:
                        printf("Entrez le nouveau numero_tel: \n");
                        scanf("%d",&Mise_jour.numero_tel);
                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);
                    break;
                    case 5:
                        printf("Entrez la nouvelle date: \n");
                        scanf("%u/%u/%u",&Mise_jour.date.jour,&Mise_jour.date.mois,&Mise_jour.date.annee);
                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);
                }

                        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Mise_jour.id_client,Mise_jour.nom,Mise_jour.prenom,Mise_jour.profession, Mise_jour.numero_tel,Mise_jour.date.jour, Mise_jour.date.mois, Mise_jour.date.annee);
                printf("Changement effectue!!");
        }
        else
            printf("l'id entre n'existe pas dans le fichier!!!");
        fclose(fichier);
        fclose(fich_modifier);
        remove("fich_modifier.txt");
        rename("fich_modifier.txt","client.txt");

    }

}

void GESTION_des_clients()
{
    int choix=0;
     printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU GESTION DES COMPTE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.AJOUTER UN CLIENT \n\t\t2.MODIFIER LES INFPORMATION D'UN CLIENTS \n\t\t3.SUPPRESION D'UN CLIENTS\n\t\t4.RECHERCHE D'UN CLIENTS\n\t\t5.AFFICHER LA LISTE DES CLIENTS\n\t\t6.QUITTEZ\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
     scanf("%d",&choix);
     system("cls");
     switch(choix)
     {
        case 1:Ajout_client();
            break;
        case 2:Modification_client();
            break;
        case 3://suppresion_client();
            break;
        case 4://recherche_dun_client();
            break;
        case 5://afficher_les_client();
            break;
        case 6:main();
            break;
//         default;
    }


}

int main()
{
     int choix;
    system("color 9");
    printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU PRINCIPAL\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.GESTION DES CLIENTS \n\t\t2.GESTION DES COMPTE\n\t\t3.OPERATION\n\t\t4.QUITTEZ\n\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");

    scanf("%d",&choix);

    system("cls");
    switch(choix)
    {
        case 1: GESTION_des_clients();
        break;
        case 2://GESTION_des_comptes();
        break;
        case 3://OPERATION();
        break;
        case 4: //QUITTEZ();
        break;
//        default;
    }

}

