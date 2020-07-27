/*directuves de preprocesseur*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*debut de prototypes*/
void affichage_compte();
void afficher_liste_clients();
void Ajout_client();
void consultation();
void fermeture_compte();
void GESTION_des_clients();
void GESTION_des_comptes();
void GESTION_des_operation();
void Modification_client();
void nouveau_compte();
void QUITTEZ();
void recherche_client();
void retrait();
void supression_client();
void virement();
void fordelay(int j);
void decompte();
int main();
/*fin des prototypes*/

/*declarations de la structure date*/
typedef struct
{
     int jour;
     int mois;
     int annee;
}DATE;
/*fin de la structure date*/

/*declaration de la structure clients*/
 typedef struct
{
     int id_client;
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
     int id_compte;
     int id_client;
     int solde;
     char derniere_operation[10];
}comptes,check,recherche_compte;
/*fin de la structure compte*/





/* procedure  gestion clients*/
void GESTION_des_clients()
{
    int choix=0;
    printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU GESTION DES CLIENTS \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.AJOUTER UN CLIENT \n\t\t2.MODIFIER LES INFPORMATION D'UN CLIENTS \n\t\t3.SUPPRESION D'UN CLIENTS\n\t\t4.RECHERCHE D'UN CLIENTS\n\t\t5.AFFICHER LA LISTE DES CLIENTS\n\t\t6.MENU GENERAL\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
    scanf("%d",&choix);
        switch(choix)
        {
            case 1:decompte();
                Ajout_client();
            break;
            case 2:decompte();
                Modification_client();
            break;
            case 3:decompte();
                supression_client();
            break;
            case 4:decompte();
            recherche_client();
            break;
            case 5:decompte();
            afficher_liste_clients();
            break;
            case 6:decompte();
            main();
            break;
            default:
                printf("Choix non disponible!!");
            break;

        }
}
/*fin de procedures gestion client*/

/*procedure d'ajout d'un client*/


int valid(char *chaine ,int option)
{
    if(option == 1)
    {
        if(strlen(chaine) > 9)
            return 0;
        int items_in_array = 0;
        char caracteres_autorises[] = "0123456789";
        for(int j = 0; j<9 ;j++)
        {
            for(int k = 0; k<10 ;k++)
            {
                if(chaine[j] == caracteres_autorises[k])
                {
                    items_in_array++;
                    break;
                }
            }
        }
        if(items_in_array == 9)
            return 1;
        else
            return 0;
    }
    else if(option == 2)
    {
        for(int j = 0 ;j<strlen(chaine) ;j++)
        {
            if((chaine[j] < 65 || chaine[j] > 91) && (chaine[j] < 97 || chaine[j] > 123 || strlen(chaine) < 3 || strlen(chaine) > 49))
                return 0;
        }
        return 1;
    }
    else if(option == 3)
    {
        if((atoi(chaine) < 13 || atoi(chaine) > 35))
            return 0;
        else
            return 1;
    }
    else if(option == 4)
    {
        char caracteres_autorises[] = "0123456789.";
        for(int j = 0; j<strlen(chaine) ;j++)
        {
            if(!strrchr(caracteres_autorises ,chaine[j]) || (atof(chaine) < 0 || atof(chaine) > 20))
                return 0;
        }
        return 1;
    }
}


void lire(char *tab)
{
    fgets(tab ,200 ,stdin);
    int j = 0;
    while(tab[j] != '\n')
        j++;
    tab[j] = '\0';
}



void securite_id(unsigned int *id_client)
{
    char id_client_char[15] = "";
    do
    {
        lire(id_client_char);
        if(!valid(id_client_char ,1))
        {
            warning("\n\n\tNumero d'ID Invalide(ne doit contenir que 9 chiffres de 0 a 9) !\n\n");
            printf("\tEntrer le Numero d'ID > ");
        }
    }while(!valid(id_client_char ,1));
    *id_client = atoi(id_client_char);
}



void Ajout_client()
{
    int choix = 1;
    FILE *client = NULL;
    client = fopen("Client.txt","a+");
    do
    {

        system("cls");
        printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ** AJOUT D'UN CLIENT **\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        ENTRER:
        printf("Entrez l'identifiant du client: \n");
<<<<<<< HEAD
        scanf("%d",&check.id_client);
        fflush(stdin);
        if(check.id_client == C.id_client)
        {
            printf("UN CLIENTS A DEJA CET IDENTIFIANT\n ");
            printf("veuillez entrer un autre svp\n");
            printf("Entrez l'identifiant du client: \n");
            goto ENTRER;
        } else
        {
        C.id_client=check.id_client;
=======
        securite_id(&C.id_client);
        fflush(stdin);
>>>>>>> 750a0ec745ed4a636d9a7aed213361c1e47aface
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
        fprintf(client,"%u;%s;%s;%s;%u;%u/%u/%u\n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);
        printf("Voulez-vous continuer d'ajouter les clients? (1/0) \n");
        scanf("%d",&choix);
        }
        if (choix ==0)
            system("cls");
            GESTION_des_clients();

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
    client = fopen("client.txt","r");
    fich_modifier = fopen("fich_modifier.txt","w");
    printf("** MODIFICATION DES DONNEES DES CLIENTS **: \n\n");
    printf("Entrez l'id du client dont vous voulez faire des modifications: ");
    securite_id(&Cli_modif.id_client);
    while(fscanf(client,"%d",&C.id_client) == 1)
    {

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
        GESTION_des_clients();

}
/*FIN DE PROCEDURE MODIFIER CLIENTS*/

/*PROCEDURE SUPPRIMER CLIENTS*/
void supression_client()
{
    int choix = 1;
    CLIENT c_sup;
    FILE *client = NULL;
    FILE *fich_sup = NULL;
    fopen("client.txt","r");
    fopen("fich_sup.txt","w");
    printf("** SUPRESSION DE CLIENT **\n\n");
    printf("\n1.Par l'id du client \n2.Par le nom du client ");
    printf("choisir comment vous voulez que la suppression se passe: \n");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1:
            printf("Veuillez entrer l'id du client que vous voulez suprimer: \n");
<<<<<<< HEAD
            securite_id(&c_sup.id_client);
            while(fscanf(client,"%u",C.id_client) == 1)
=======
            scanf("%d",&c_sup.id_client);
            while(fscanf(client,"%d") == 1)
>>>>>>> 11449e868dbe9ab977602b624d4aa1ffbd382d85
        {
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
            if (C.id_client != c_sup.id_client)
            {
                fprintf(fich_sup,"%d;%s;%s;%s;%d;%d/%d/%d\n",c_sup.id_client,c_sup.nom,c_sup.prenom,c_sup.profession,c_sup.numero_tel,c_sup.date.jour, c_sup.date.mois, c_sup.date.annee);
            }
        }
        fclose(client);
        fclose(fich_sup);
        choice:
        printf("voulez-vous confirmer la suppression?(1/0): ");
            scanf("%d",&choix);
            if(choix == 1)
            {
                printf("\n\n");
                printf("suppression effectuer avec succes");
                remove("client.txt");
                rename("fich_supp.txt","client.txt");
                GESTION_des_clients();
            }
            else
                printf("Vous n'avez pas supprimer le client!!");
                GESTION_des_clients();
        break;
        case 2:
            printf("Veuillez entrer le nom du client que vous voulez supprimer: ");
            scanf("%s",c_sup.nom);
<<<<<<< HEAD
            while(fscanf(client,"%u",C.id_client) == 1)
=======
            while(fscanf(client,"%d") == 1)
>>>>>>> 11449e868dbe9ab977602b624d4aa1ffbd382d85
        {
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
            if(strcmp(C.nom, c_sup.nom) == 1)
            {
                fprintf(fich_sup,"%u;%s;%s;%s;%u;%u/%u/%u\n",c_sup.id_client,c_sup.nom,c_sup.prenom,c_sup.profession,c_sup.numero_tel,c_sup.date.jour,c_sup.date.mois,c_sup.date.annee);
            }
        }
            fclose(client);
            fclose(fich_sup);
            printf("voulez-vous confirmer la suppression?(1/0): ");
            scanf("%d",&choix);
            if(choix == 1)
            {
                remove("client.txt");
                rename("fich_supp.txt","client.txt");
                GESTION_des_clients();
            }
            else
                printf("Vous n'avez pas supprimer le client!!");
                 GESTION_des_clients();
        break;
        default:
                printf("Choix non disponible!!");
                goto choice;

    }

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
<<<<<<< HEAD
    securite_id(&C_rech.id_client);
    while(fscanf(client,"%u;\t%s;\t%s;\t%s;\t%u;\t%u/%u/%u\n",&C.id_client,&C.nom,&C.prenom,&C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF)
=======
    scanf("%d",&C_rech.id_client);
    while(fscanf(client,"%u;\t%s;\t%s;\t%s;\t%u;\t%u/%u/%u\n",&C.id_client,C.nom,C.prenom,C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF)
>>>>>>> 11449e868dbe9ab977602b624d4aa1ffbd382d85
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
        printf("%u;|%s;|%s;|%s;|%u;| %u/%u/%u \n\n",C.id_client,C.nom,C.prenom,C.profession, C.numero_tel,C.date.jour, C.date.mois, C.date.annee);
    }
    while(fscanf(client,"%u;%s;%s;%s;%u;%u/%u/%u\n",&C.id_client,C.nom,C.prenom,C.profession,&C.numero_tel,&C.date.jour, &C.date.mois, &C.date.annee) != EOF);
    fclose(client);
    GESTION_des_clients();
}
/*FIN DE PROCEDURE AFFICHE CLIENTS*/


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
            case 1:decompte();
            nouveau_compte();
            break;
            case 2:decompte();
            consultation();
            break;
            case 3:decompte();
            fermeture_compte();
            break;
            case 4:decompte();
            affichage_compte();
            break;
            case 5:decompte();
            main();
            break;

     }

}
/*fin de la procedure gestion des comptes*/

/*procedure nouveau compte*/

void nouveau_compte()
{
    FILE *compte = NULL;
    int choix = 0;
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
        fprintf(compte,"%d; | %d; | %d; | %s; |\n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
        printf("Voulez-vous continuer d'ajouter un nouveau compte?(1/0): ");
        scanf("%d",&choix);
        fflush(stdin);

    }while(choix == 1);
        if(choix==0){
            system("cls");
            GESTION_des_comptes();
            }
                fclose(compte);
}

/*fin de procedure nouveau compte*/

/*PROCEDURE CONSULTATION COMPTE(recherche)*/

 void consultation()
    {
        FILE *compte = NULL;
        compte = fopen("compte.txt","r");
        printf("entrer l'id du compte a afficher :");
        scanf("%d",&recherche_compte.id_compte);
     while (fscanf(compte,"%d; | %d; | %d; | %s; |\n",&comptes.id_compte,&comptes.id_client,&comptes.solde,comptes.derniere_operation)!=EOF);
        {
            if(recherche_compte.id_compte==comptes.id_compte)
            {
                printf("| %d; | %d; | %d; | %s; |\n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
            }


        }

        fclose(compte);
    }
/*fin de procedure*/


/*procedure fermeture de compte*/

void fermeture_compte()
{
    FILE *compte = NULL;
    compte = fopen("compte.txt","r");
    FILE *supp_compte=NULL;
    supp_compte = fopen("supp_compte.txt","w");
    printf("\t\t** SUPRESSION DE CLIENT **\n\n");
    printf("entrer le  numero d'identification du compte que vous voulez supprimer: ");
    scanf("%d",&check.id_compte);
     while (fscanf(compte,"%d; | %d; | %d; | %s; |\n",&comptes.id_compte,&comptes.id_client,&comptes.solde,comptes.derniere_operation)!=EOF);
     {
         if(comptes.id_compte  != check.id_compte )
         {
            fprintf(supp_compte,"%d; | %d; | %d; | %s; |\n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
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
        int test =0;
       FILE *compte = fopen("compte.txt","r");
       printf("id compte | id client| solde| derniere operation" );
     while (fscanf(compte,"%d | %d | %d | %s",&comptes.id_compte,&comptes.id_client,&comptes.solde,comptes.derniere_operation)!=EOF);
       {
        printf("%d | %d | %d | %s",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
        test ++;
       }
        fclose(compte);
        if (test==0)
        {
            system("cls");
            printf("\nAUCUN COMPTE\n");
        }

    }
/*fin de la procedure affichage des compte*/

/*  GESTION DES OPERATION*/

void GESTION_des_operation()
{


 int choix=0;
     printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  GESTION DES OPERATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.RETRAIT \n\t\t2.VIREMENT \n\t\t3.MENU GENERAL\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
     scanf("%d",&choix);
     switch(choix)
     {
            case 1:decompte();
            retrait();
            break;
            case 2:decompte();
            virement();
            break;
            case 3:decompte();
            main();
            break;
            default:
                printf("entrez un choix valide svp...");
                break;
     }
}

/*FIN DE FONCTION*/

/*procedure retrait*/
void retrait()
{
 FILE *compte = NULL;
    compte =fopen("compte.txt","a+");
    unsigned int idcompte_debit=0;
    printf("ENTRER L'ID DU COMPTE A DEBITER: ");
    scanf("%d",&idcompte_debit);
    unsigned int somme_debit=0;
    do{
        if(idcompte_debit == comptes.id_compte)
        {
            printf("ENTRER LE MONTANT A DEBITER:FCFA ");
            scanf("%d",&somme_debit);
            comptes.solde-=somme_debit;
            fprintf(compte,"%d | %d | %d | %s \n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
            printf("\n\nDEBIT EFFECTUER AVEC SUCCESS!!!!");

        }
    }
    while (fscanf(compte,"%d | %d | %d | %s",&comptes.id_compte,&comptes.id_client,&comptes.solde,comptes.derniere_operation)!=EOF);
        fclose(compte);

}
/*fin de procedure retrait*/

/*procedure virement*/

void virement()
{
    FILE *compte = NULL;
    compte =fopen("compte.txt","a+");
    unsigned int idcompte_credit=0;
    printf("ENTRER L'ID DU COMPTE A CREDITER: ");
    scanf("%d",&idcompte_credit);
    unsigned int somme_debit=0;
    do{
        if(idcompte_credit == comptes.id_compte)
        {
            printf("ENTRER LE MONTANT A VIRER:FCFA ");
            scanf("%d",&somme_debit);
            comptes.solde+=somme_debit;
            fprintf(compte,"%d | %d | %d | %s \n",comptes.id_compte,comptes.id_client,comptes.solde,comptes.derniere_operation);
            printf("\n\nVIREMENT EFFECTUER AVEC SUCCESS!!!!");

        }
    }
    while (fscanf(compte,"%d | %d | %d | %s",&comptes.id_compte,&comptes.id_client,&comptes.solde,comptes.derniere_operation)!=EOF);
        fclose(compte);

}
/*fin de procedure virement*/

/*quittez lz programme*/
void QUITTEZ()
{
    system("cls");
    printf("a bientot.............");


}

/*fin de fonction*/


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void decompte()
{

    printf("\nChargement");
                for(int i=0;i<=6;i++)
                    {
                        fordelay(100000000);
                        printf(".");
                    }
                    system("cls");
}
/*fonction principal main*/
int main()
{    system("cls");
     int choix,i;
    system("color 9");
    printf("\n\n\t\t\t            KALATA BANK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE MENU PRINCIPAL\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.GESTION DES CLIENTS \n\t\t2.GESTION DES COMPTE\n\t\t3.OPERATION\n\t\t4.QUITTEZ\n\n\n\t ENTREZ LE NUMERO CORRESPONDANT A VOTRE CHOIX: ");
   scanf("%d",&choix);

    system("cls");
    switch(choix)
    {
        case 1:decompte();
                GESTION_des_clients();
        break;
        case 2:decompte();
            GESTION_des_comptes();
        break;
        case 3:
            decompte();
            GESTION_des_operation();
        break;
        case 4:QUITTEZ();
        break;
        default:
            printf("Choix non disponible!!");
        break;

    }
return 0;
}
/*fin de main*/
