#include <gtk/gtk.h>
typedef struct 
{
int jour;
int  mois;
int  annee;
}DATE;
typedef struct etudiant{

char nom[20];
char prenom[20];
char cin[20];
DATE dt_naiss;
char chambre[20];
char email[40];
char paiement[20];
int niveau [20];
char sexe[20];

}
etudiant;

int verifier(char log[],char Pw[]);
int rech (int NumRech);
void ajouter();
int rechercher();
void supprimer();
void modifier();
void afficher(GtkWidget *liste);
void afficher_rec(GtkWidget *liste,char cinr[]);
int niveau(int calcul[],char txt[]);





