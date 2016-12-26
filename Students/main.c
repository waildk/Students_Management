#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TPfinal.h"

int main()
{
    int s  ;
    listeEtud *promo = NULL ;
    promo = (listeEtud *) malloc(sizeof(*promo)); /// Allouer l'espace necessaire pour la liste des etudiants
    promo->first = NULL ;                  /// initaliser la liste à NULL
    promo->taille = 0 ;                    /// initaliser la taille de la liste
        do{
            s = Menu(promo);               /// repèter l'affichage du menu jusqu'a taper 0 ( exit )
        }while ( s != 0 );
return 0;
}
