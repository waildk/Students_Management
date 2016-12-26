#ifndef Tpf
#define Tpf

typedef struct etudiant etudiant ;
typedef struct notes notes ;
typedef struct module module ;
typedef struct listeEtud listeEtud ;
///declarations des strectures

struct etudiant
{
    char num[25] ;
    int groupe ;
    int credit ;
    char nom[25] ;
    char prenom[25] ;
    double moyenne ;
    notes *modules ;
    etudiant *next ;
};
struct module
{
    double note ;
    int coeff ;                 /// modules->TL->note
    int credit;
};
struct notes
{
    module *TL ;
    module *ASDD ;
    module *AO ;
    module *SI ;
    module *POO ;
    module *LM ;
    module *ANG ;
    int coeffTotale ;       /// somme des coeffitions
};
struct listeEtud
{
    etudiant *first ;
    int taille ;               /// Taille de la liste
};


///Prototypes des fonctions
etudiant *Creat() ;         ///Constructeur ( Allocation )

etudiant *Ajouter_elem(listeEtud *liste);       ///Ajouter un Etudiant a la liste return(pointeur vers cet etudiant)

etudiant *MajorDePromo (listeEtud *l1);         ///return(pointeur vers le major de promo)

etudiant *RechEtud ( listeEtud *l1);            ///rechercher un etudiant par son Numero d'inscription

int InitEtud ( etudiant *etud ) ;               ///Initaliser les informations d'un etudiant return(somme de coeff)

int MoyGen (etudiant *etud) ;                   ///calculer la moyenne Générale return( 1 = Admis , 0 = Ajourné )

int Credit (etudiant *etud);                    ///calculer le credit d'un etudiant return(credit de l'etudiant )

int Menu (listeEtud *l1);                       /// return(choix de l'étudiant)

void Remplir (etudiant *etud,int num) ;         ///remplir les infos principales de l'etudiant ,num = numero séquentiel

void Display (etudiant *etud) ;                 /// afficher les infos de l'etudiants

void RempNotes (etudiant *etud , int num );     ///remplir les notes de l'etudiant

void DisplayNotes ( etudiant *etud );           ///afficher les notes de l'etudiant

void DeleteList (listeEtud *l1);                ///supprimer la liste entière
#endif // Tpf
