#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*declarations de la structure data*/
typedef struct
{
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
}DATE;
/*fin de la structure date*/
<<<<<<< HEAD



=======
>>>>>>> 0612e0c634f99ede88416e52fa574268b3edf95b
/*declaration de la structure clients*/
 typedef struct
{
    unsigned int id_client;
    char nom[50];
    char prenom[50];
    char profession[50];
    unsigned int numero_tel;
    DATE date;
}CLIENT, Mise_jour;
CLIENT C;
/*fin de la structure client*/


/*declaration de la structure compte*/
struct
{
   unsigned  int id_compte;
   unsigned  int id_client;
   unsigned  int solde;
   char derniere_operation[50];
}comptes,check;
/*fin de la structure compte*/





/* procedure  gestion clients*/
void GESTION_des_clients()
{
    int choix=0;
    printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU GESTION DES CLIENTS \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.AJOUTER UN CLIENT \n\t\t2.MODIFIER LES INFPORMATION D'UN CLIENTS \n\t\t3.SUPPRESION D'UN CLIENTS\n\t\t4.RECHERCHE D'UN CLIENTS\n\t\t5.AFFICHER LA LISTE DES CLIENTS\n\t\t6.QUITTEZ\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
    scanf("%d",&choix);
        switch(choix)
        {
            case 1:Ajout_client();
            break;
            case 2:Modification_client();
            break;
            case 3:supression_client();
            break;
            case 4:recherche_client();
            break;
            case 5:afficher_liste_clients();
            break;
            case 6:main();
            break;
            default:
                printf("Choix non disponible!!");
            break;

        }
}
/*fin de procedures gestion client*/

/*procedure d'ajout d'un client*/
void Ajout_client()
{
    int choix = 1;
    FILE *client = NULL;
    client = fopen("Client.txt","a+");
    do
    {
        printf("** AJOUT D'UN CLIENT ** \n\n");
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
        fprintf(client,"%u;%s;%s;%s;%u;%u/%u/%u\n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);

    }while(choix == 1);
    fclose(client);
}
/*FINDE PROCEDURE AJOUT CLIENTS*/

/*PROCEDURE MODIFCATION CLIENT*/
void Modification_client()
{

    Mise_jour Cli_modif;
    FILE *client = NULL;
    FILE *fich_modifier;
    client = fopen("client.txt","r+");
    fich_modifier = fopen("fich_modifier.txt","w+");
    printf("** MODIFICATION DES DONNEES DES CLIENTS **: \n\n");
    printf("Entrez l'id du client dont vous voulez faire des modifications: ");
    scanf("%d",&Cli_modif.id_client);
    while(fscanf(client,"%d",&C.id_client) == 1)
    {
        int test = 0;
        int choice = 0;
        fgetc(client);
        fscanf(client,"%[^;]s",C.nom);
        fgetc(client);
        fscanf(client,"%[^;]s",C.prenom);
        fgetc(client);
        fscanf(client,"%[^;]s",C.profession);
        fgetc(client);
        fscanf(client,"%d",&C.numero_tel);
        fgetc(client);
        fscanf(client,"%d",&C.date.jour);
        fgetc(client);
        fscanf(client,"%d",&C.date.mois);
        fgetc(client);
        fscanf(client,"%d",&C.date.annee);
        if(Cli_modif.id_client == C.id_client)
        {
           do
            {
                test = 1;
                printf("vous allez modifier les donnees de: %s \n",C.nom);
                printf("Ses anciennes informations etaient: \n");
                printf("ID_client: %u \n NOM: %s \n PRENOM: %s \n PROFESSION: %s \n NUM_TEL: %u \n DATE_D'AJOUT: %u/%u/%u \n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);
                printf("Veuillez choisir le champ que vous voulez modifier: \n1.Le nom \n2.Le prenom \n3.La Profession \n4.Le Numero_tel \n5.La Date \n");
                scanf("%d",&choice);
                switch(choice)
                    {
                        case 1:
                            printf("Entrez le nouveau nom: \n");
                            scanf("%s",Cli_modif.nom);
                        break;
                        case 2:
                            printf("Entrez le nouveau prenom: \n");
                            scanf("%s",Cli_modif.prenom);
                        break;
                        case 3:
                            printf("Entrez la nouvelle profession: \n");
                            scanf("%s",Cli_modif.profession);
                        break;
                        case 4:
                            printf("Entrez le nouveau numero_tel: \n");
                            scanf("%d",&Cli_modif.numero_tel);
                        break;
                        case 5:
                            printf("Entrez la nouvelle date: \n");
                            scanf("%d/%d/%d",&Cli_modif.date.jour,&Cli_modif.date.mois,&Cli_modif.date.annee);
                    }
                    printf("Voulez-vous rentrer au menu des modifications pour choisir un autre champ a modifier?(6/7)\n");
                    scanf("%d",&choice);
            }while(choice == 6);
            printf("Changement effectue!!");
        }
        fprintf(fich_modifier,"%u;%s;%s;%s;%u;%u/%u/%u\n",Cli_modif.id_client,Cli_modif.nom,Cli_modif.prenom,Cli_modif.profession, Cli_modif.numero_tel,Cli_modif.date.jour, Cli_modif.date.mois, Cli_modif.date.annee);
    }
        fclose(client);
        fclose(fich_modifier);
        remove("client.txt");
        rename("fich_modifier.txt","client.txt");

}
/*FIN DE PROCEDURE MODIFIER CLIENTS*/

/*PROCEDURE SUPPRIMER CLIENTS*/
void supression_client()
{
    char choix[] = "N";
    CLIENT c_sup;
    FILE *client = NULL;
    FILE *fich_sup = NULL;
    fopen("client.txt","r");
    fopen("fich_sup.txt","w");
    printf("** SUPRESSION DE CLIENT **\n");
    fflush(stdin);
    printf("Veuillez entrer l'id du client que vous voulez suprimer: \n");
    scanf("%d",&c_sup.id_client);
    while(fscanf(client,"%u;%s;%s;%s;%u;%u/%u/%u\n",&C.id_client,&C.nom,&C.prenom,&C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF)
    {
        if (C.id_client != c_sup.id_client)
        {
            fprintf(fich_sup,"%u;%s;%s;%s;%u;%u/%u/%u\n",&c_sup.id_client,&c_sup.nom,&c_sup.prenom,&c_sup.profession,&c_sup.numero_tel,&c_sup.date.jour, &c_sup.date.mois, &c_sup.date.annee);
        }
    }
    fclose(client);
    fclose(fich_sup);
    remove(client);
    rename("fich_supp.txt","client.txt");
}
/*FINDE PROCEDURE SUPPRIMER*/

/*PROCEDURE RECHERCHE CLIENTS*/
void recherche_client()
{
    CLIENT C_rech;
    FILE *client = NULL;
    client = fopen("client.txt","r+");
    printf("** RECHERCHE D'UN CLIENT** \n");
    printf("Enter l'id du client que vous chercher: ");
    scanf("%d",&C_rech.id_client);
    while(fscanf(client,"%u;\t%s;\t%s;\t%s;\t%u;\t%u/%u/%u\n",&C.id_client,&C.nom,&C.prenom,&C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF)
    {
        if (C.id_client == C_rech.id_client)
            printf("Le candidat que vous chercher a les informations suivantes: \n NOM: %s \n PRENOM: %s PROFESSION: %s NUM_TEL: %u DATE: %u/%u/%u \n", C.nom, C.prenom, C.profession, C.numero_tel, C.date.jour, C.date.mois, C.date.annee);
    }
    fclose(client);
}
/*FIN DE PROCEDURE RECHERHCHE CLIENTS*/

/*PROCEDURE AFFICHE LISTE DES CLIENTS */
void afficher_liste_clients()
{

    FILE *client = NULL;
    client = fopen("Client.txt","r");
    do{
        printf("ID CLIENTS | NOM | PRENOM | PROFESSION |NUMERO DE TEL /jj/mm/aaaa\n");
        printf("%u;%s;%s;%s;%u;%u/%u/%u\n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);
    }
    while(fscanf(client,"%u;%s;%s;%s;%u;%u/%u/%u\n",&C.id_client,&C.nom,&C.prenom,&C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF);
    fclose(client);
}
/*FIN DE PROCEDURE */




/*FIN DE PROCEDURE AFFICHE CLIENTS*/

/***

 supprimer recherche et affiche clients
*/



/*procedure gestion des compte*/
void GESTION_des_comptes()
{
    int choix=0;
     printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  GESTION DES COMPTES \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.NOUVEAU COMPTE \n\t\t2.CONSULTATION D'UN COMPTE \n\t\t3.FERMETURE D'UN COMPTE\n\t\t4.AFFICHER LA LISTE DES COMPTE\n\t\t5.MENU GENERAL \n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
     scanf("%d",&choix);
     switch(choix)
     {
            case 1:nouveau_compte();
            break;
            case 2://consultation_des_compte();
            break;
            case 3:fermeture_compte();
            break;
            case 4:affichage_compte();
            break;
            case 5:main();
            break;

     }

}
/*fin de la procedure gestion des comptes*/

/*procedure nouveau compte*/
void nouveau_compte()
{
    int choix;
    FILE *compte = NULL;
    compte = fopen("compte.txt","a+");
    do
    {
        printf("Entrer le numero d'identification du compte:  ");
        scanf("%d",&comptes.id_compte);
        fflush(stdin);
        printf("Entrer le numero d'identification du client:  ");
        scanf("%d",&comptes.id_client);
        fflush(stdin);
        printf("Entrer solde:  ");
        scanf("%d",&comptes.solde);
        fflush(stdin);
        printf("quelle est la derniere operation:  ");
        scanf("%s",comptes.derniere_operation);
        fflush(stdin);
        printf("Voulez-vous continuer d'ajouter un nouveau compte?(1/0): ");
        scanf("%d",&choix);
        fflush(stdin);
        fprintf(compte,"%d | %d %d | %s \n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);

    }while(choix == 1);
        fclose(compte);
}
/*fin de procedure nouveau compte*/

/*procedure fermeture de compte*/
void fermeture_compte()
{
    FILE *compte;
    compte=fopen("compte.txt","r");
    FILE *supp_compte;
    supp_compte=fopen("supp_compte.txt","w");
    printf("entrer le  numero d'identification du compte: ");
    scanf("%d",&check.id_compte);
     while(fscanf(compte,"%d | %s | %d | %s",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation) !=EOF);
     {
         if(check.id_compte!=comptes.id_compte)
         {
            fprintf(supp_compte,"%d | %s | %d | %s",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
         }
     }
     fclose(compte);
     fclose(supp_compte);
     remove("compte.txt");
     rename("supp_compte,txt","compte.txt");
}
/*fin de procedure fermeture de compte*/


/*procedure affichage des comptes*/
void affichage_compte()
    {


       FILE *compte = fopen("compte.txt","r");
       printf("id compte | id client| solde| derniere operation" );
     while (fscanf(compte,"%s | %s | %d | %s",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation)!=EOF);
       {

        printf("%s | %s | %d | %s",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
       }
        fclose(compte);
    }
/*fin de la procedure affichage des compte*/











int main()
{    system("cls");
     int choix;
    system("color 9");
    printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU PRINCIPAL\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.GESTION DES CLIENTS \n\t\t2.GESTION DES COMPTE\n\t\t3.OPERATION\n\t\t4.QUITTEZ\n\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
   scanf("%d",&choix);

    system("cls");
    switch(choix)
    {
        case 1:GESTION_des_clients();
        break;
        case 2:GESTION_des_comptes();
        break;
        case 3://OPERATION();
        break;
        case 4://QUITTEZ();
        break;
        default:
            printf("Choix non disponible!!");
        break;

    }
return 0;
}

