#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TPfinal.h"

etudiant *Creat()
    {
        etudiant *e =NULL ;
        ///alloué pour struct etudiant
        e = (etudiant *) malloc(sizeof(*e));
        ///alloué pour struct notes
        e->modules = (notes *) malloc(sizeof(notes));
        ///alloué pour struct module
            e->modules->ANG = (module *) malloc(sizeof(module));
            e->modules->LM = (module *) malloc(sizeof(module));
            e->modules->SI = (module *) malloc(sizeof(module));
            e->modules->AO = (module *) malloc(sizeof(module));
            e->modules->POO = (module *) malloc(sizeof(module));
            e->modules->ASDD = (module *) malloc(sizeof(module));
            e->modules->TL = (module *) malloc(sizeof(module));
        e->next = NULL ;
                ///retourné un pointeur vers l'etudiant crée
    return e ;
    }

etudiant *Ajouter_elem(listeEtud *liste)
    {
        etudiant *position = NULL ;
        position = liste->first ;
            if (position == NULL)
            {
                position = Creat();
                liste->first = position ;
            }
            else
            {
                while (position->next != NULL )  position = position->next ; /// pour aboutir au dernier etudiant
                position->next = Creat() ;          /// créer un nouveau
                position = position->next ;
            }
                liste->taille ++   ;         ///incrementer la taille de la liste
                position->modules->coeffTotale = InitEtud(position);  /// initialiser l'etudiant
        return position ;
    }

int InitEtud ( etudiant *etud )
{
    int i ;
        ///initaliser les infos de l'etudiant
        etud->num[0] = '\n' ;
        etud->nom[0] = '\n' ;
        etud->prenom[0] = '\n' ;
        etud->num[1] = '\0' ;
        etud->nom[1] = '\0' ;
        etud->prenom[1] = '\0' ;
        etud->credit =  0 ;
        etud->groupe = 0 ;
        etud->moyenne = -1 ;
        /// initaliser coefficients
        etud->modules->ANG->coeff = 1 ;
        etud->modules->TL->coeff = 2;
        etud->modules->ASDD->coeff = 3 ;
        etud->modules->AO->coeff = 2 ;
        etud->modules->SI->coeff = 3 ;
        etud->modules->POO->coeff = 3 ;
        etud->modules->LM->coeff = 2 ;
        etud->modules->ANG->coeff = 1 ;
        ///initaliser credit
        etud->modules->TL->credit = 4 ;
        etud->modules->ASDD->credit = 6 ;
        etud->modules->AO->credit = 5 ;
        etud->modules->SI->credit = 4 ;
        etud->modules->POO->credit = 5 ;
        etud->modules->LM->credit = 4 ;
        etud->modules->ANG->credit = 2 ;
        ///initaliser note
         etud->modules->TL->note = 0 ;
        etud->modules->ASDD->note = 0 ;
        etud->modules->AO->note = 0 ;
        etud->modules->SI->note = 0 ;
        etud->modules->POO->note = 0 ;
        etud->modules->LM->note = 0 ;
        etud->modules->ANG->note = 0 ;
        ///return coeff somme
    i =  etud->modules->ANG->coeff + etud->modules->TL->coeff + etud->modules->ASDD->coeff + etud->modules->AO->coeff +
         etud->modules->SI->coeff +  etud->modules->POO->coeff + etud->modules->LM->coeff ;
    return i ;
}

void Remplir (etudiant *etud,int num)
{
    /// les informations de l'etudiant
    printf("entrer le nom de l'etudiant n %d : ",num);
        fgets(etud->nom , 25 , stdin);
        fgets(etud->nom , 25 , stdin);
    printf("entrer son prenom : ");
        fgets(etud->prenom , 25 , stdin);
    printf("entrer son numero d'inscription : ");
        fgets(etud->num , 25 , stdin);
    printf("entrer son Groupe : ");
        scanf("%d",&(etud->groupe));
        RempNotes(etud,num);
       // MoyGen(etud);
       //  Credit(etud);
}

void RempNotes (etudiant *etud , int num )
{
    /// remplir les notes .. ps : boucle de controle de note pour chaque module
    do{
                printf("entrer la note du module TL de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->TL->note));
    }while((etud->modules->TL->note) > 20 || (etud->modules->TL->note) < 0);
    do{
                printf("entrer la note du module ASDD de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->ASDD->note));
    }while((etud->modules->ASDD->note) > 20 || (etud->modules->ASDD->note) < 0);
    do{
                printf("entrer la note du module POO de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->POO->note));
    }while((etud->modules->POO->note) > 20 || (etud->modules->POO->note) < 0);
    do{
                printf("entrer la note du module AO de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->AO->note));
    }while((etud->modules->AO->note) > 20 || (etud->modules->AO->note) < 0);
    do{
                printf("entrer la note du module LM de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->LM->note));
    }while((etud->modules->LM->note) > 20 || (etud->modules->LM->note) < 0);
    do{
                printf("entrer la note du module SI de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->SI->note));
     }while((etud->modules->SI->note) > 20 || (etud->modules->SI->note) < 0);
    do{
                printf("entrer la note du module ANG de l'etudiant %d: ",num);
                scanf("%lf",&(etud->modules->ANG->note));
     }while((etud->modules->ANG->note) > 20 || (etud->modules->ANG->note) < 0);
}

int MoyGen (etudiant *etud)
{
    double moy = 0 ;
       moy += (etud->modules->ANG->note) * (etud->modules->ANG->coeff);
       moy += (etud->modules->TL->note) * (etud->modules->TL->coeff);
       moy += (etud->modules->ASDD->note) * (etud->modules->ASDD->coeff);
       moy += (etud->modules->AO->note) * (etud->modules->AO->coeff);
       moy += (etud->modules->SI->note) * (etud->modules->SI->coeff);
       moy += (etud->modules->POO->note) * (etud->modules->POO->coeff);
       moy += (etud->modules->LM->note) * (etud->modules->LM->coeff);
       moy /= etud->modules->coeffTotale ;
       etud->moyenne = moy ;    /// affecte la moyenne au champ de l'etudiant

        if ( moy >= 10 ) return 1 ; else return 0 ;     ///admis 1 ou ajourné 0
}

int Credit (etudiant *etud)
{
    int i ;
        if ( etud->moyenne >= 10 )
        {
            etud->credit = 30 ;
            return 30 ;
        }
    /// sinon on doit calculer les credits des modules , ps : par defaut il sont initailiser a MAX ta3hum
        if ( (etud->modules->TL->note) < 10 )  etud->modules->TL->credit = 0 ;
        if ( (etud->modules->AO->note) < 10 )  etud->modules->AO->credit = 0 ;
        if ( (etud->modules->SI->note) < 10 )  etud->modules->SI->credit = 0 ;
        if ( (etud->modules->LM->note) < 10 )  etud->modules->LM->credit = 0 ;
        if ( (etud->modules->ASDD->note) < 10 ) etud->modules->ASDD->credit = 0 ;
        if ( (etud->modules->POO->note) < 10 )  etud->modules->POO->credit = 0 ;
        if ( (etud->modules->ANG->note) < 10 )  etud->modules->ANG->credit = 0 ;

     i = etud->modules->TL->credit + etud->modules->AO->credit + etud->modules->SI->credit + etud->modules->LM->credit +
         etud->modules->ASDD->credit + etud->modules->POO->credit + etud->modules->ANG->credit ;
    ///return le credit obtenu vers le champ de credit
    etud->credit = i ;
     return i ;
}

etudiant *MajorDePromo (listeEtud *l1)
{
    etudiant *position = NULL  , *major = NULL ;
    double max = 0 ;
    int i ;
       if (l1->first == NULL) return major ;
    position = l1->first ;
       for (i = 0 ; i < l1->taille ; i++) /// on peut faire while ( position != NULL ) {}
        {
            if ( position->moyenne > max )
            {
                max = position->moyenne ;
                major = position ;
            }
            position = position->next ;
        }
    return major ;
}


etudiant *RechEtud ( listeEtud *l1)
{
    char Num[25] ;
    etudiant *position = l1->first ;
        if (l1->first == NULL) return NULL ;
    printf("Entrer la numero d'inscription de l'etudiant : ");
    fgets(Num,25,stdin);
    fgets(Num,25,stdin);
        while ( strcmp(Num,position->num) != 0 && position->next != NULL )  position = position->next ;
        if ( strcmp(Num,position->num) == 0 ) return position ;
        else return NULL ;
}

void Display (etudiant *etud)
{
    ///afficher les infos finales
    printf("Numero d'inscription : %s",etud->num);
    printf("Nom : %s",etud->nom);
    printf("Prenom : %s",etud->prenom);
    printf("Groupe : %d\n",etud->groupe);
    printf("Moyenne : %lf\n",etud->moyenne);
    printf("Credit : %d \n/************/\n",etud->credit);
}

void DisplayNotes ( etudiant *etud )
{
    ///afficher les notes
    printf("la note du module TL est : %lf\n",etud->modules->TL->note);
    printf("la note du module ASDD est : %lf\n",etud->modules->ASDD->note);
    printf("la note du module POO est : %lf\n", etud->modules->POO->note);
    printf("la note du module AO est : %lf\n", etud->modules->AO->note);
    printf("la note du module SI est : %lf\n",etud->modules->SI->note);
    printf("la note du module LM est : %lf\n",etud->modules->LM->note);
    printf("la note du module ANG est : %lf\n",etud->modules->ANG->note);
}

void DeleteList (listeEtud *l1)
{
    etudiant *position = l1->first , *to_delete ;
                while ( position->next != NULL)
                {
                    position = position->next;
                    to_delete = position;
                    free(to_delete);
                }
                l1->first = NULL ;
                l1->taille = 0 ;
}

int Menu (listeEtud *l1)
{
    int choix,nbr = 0 ;
    system("pause");
    system("cls");          ///clear screen

        printf("Bienvenue a l'application de gestion de la promo Informatique 2016-2017 \nCreated By W@il\n");
        printf("1-initaliser et Remplir toute la promo \n2-Inserer des nouveaux etudiants \n");
        printf("3-Afficher toute la promo \n4-Afficher le nombre totale des etudiants \n5-Afficher un etudiant \n");
        printf("6-Afficher le major de promo \n7-Reinitaliser toute la promo\n8-ecraser tous \n");
        printf("9-initaliser toute la promo \n0-exit\n");
        printf("entrer votre choix : ");
            scanf("%d",&choix);
    switch (choix)
    {
          case 0 : ;        ///exit
              break ;

          case 9 :          ///initaliser toute la promo
            {
                 int cmp ;
                etudiant *position = NULL ;
                position = l1->first ;

                if (position) DeleteList(l1);
                    printf("entrer le nombre totale de la promo : ");
                        scanf("%d",&nbr);

                for ( cmp = 0 ; cmp < nbr ; cmp++)
                {
                    Ajouter_elem(l1);
                }
                position = l1->first ;
                }break ;
          case 1 :          /// remplir toute la promo
            {
                int cmp ;
                etudiant *position = NULL ;
                position = l1->first ;
                if (position == NULL)   /// càd la liste est vide
                {
                    printf("entrer le nombre totale de la promo : ");
                        scanf("%d",&nbr);
                for ( cmp = 0 ; cmp < nbr ; cmp++)
                {
                    Ajouter_elem(l1);
                }
                position = l1->first ;
                }
               for ( cmp = 0 ;cmp < nbr ; cmp++ )
               {
                   InitEtud(position);
                   Remplir(position,cmp+1);
                   MoyGen(position);
                   Credit(position);
                   position = position->next;
               }
            }
            break;

          case 2 :          ///insert N student ps : read(N)
            {
               etudiant *b = NULL ;
               int nbrEtud , cmp ; ///cmp = compteur
               printf("entrer le nombre d'etudiants que vous voulez inserer : ");
               scanf("%d",&nbrEtud);
               for  (cmp = 0 ; cmp < nbrEtud ; cmp++ )
               {
                   b = Ajouter_elem(l1);
                   Remplir(b,l1->taille);
                   MoyGen(b);
                   Credit(b);
               }
            }
            break;

          case 3 :       /// display all students
            {
                etudiant *position  = l1->first ;
                if ( position == NULL) printf("la liste est vide\n");
                else
                {
                    while(position != NULL )
                    {
                        Display(position);
                        position = position->next ;
                    }
                }
            }
            break ;

          case 4 :          /// afficher le nombre totale
             printf("le nombre d'etudiants : %d\n",l1->taille);
            break;

          case 5 :          /// afficher un etudiant
            {
                int con ;
                etudiant *a_afficher = NULL ;
                a_afficher = RechEtud(l1);
                if ( a_afficher == NULL)
                {
                    printf("cet etudiant n'existe pas !\nvoulez vous le créer ( 0 = Oui , 1 = Non ): ");
                    scanf("%d",&con);
                    if (!con)
                    {
                       a_afficher = Ajouter_elem(l1);
                        Remplir(a_afficher,l1->taille);
                        MoyGen(a_afficher);
                        Credit(a_afficher);
                        system("cls");
                        Display(a_afficher);
                    }
                }
                else Display(a_afficher);
            }
            break;

          case 6 :          ///display le majeur
            {
                if ( MajorDePromo(l1) != NULL) Display(MajorDePromo(l1));
                else printf("vous n'avez pas encore rempli la liste des etudiants \n");
            }
            break;

          case 7 :          ///reinitaliser
            {
                etudiant *position = l1->first ;
                    while ( position != NULL)
                    {
                        InitEtud(position);
                        position = position->next;
                    }
                    printf("Reset Successfully \n");
            }
            break ;

          case 8 :          ///Delete all promo
            {
                DeleteList(l1);
                printf("Deleted Successfully \n");
            }break;

            default : printf("ton choix n'existe pas\n");
    }
    return choix ;
}
