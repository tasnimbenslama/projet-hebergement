#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
 ECIN,
 ENOM,
 EPRENOM,
 ECHAMBRE,
 EDT_NAISS,
 ESEXE,
 EEMAIL,
 ENIVEAU,
 EPAIEMENT,
 COLUMNS,
};

/*void ajouter()
{
struct etudiant ET;
   FILE *f;
   f=fopen("etudiant.txt","a+");
   if(f!=NULL)
    {
     printf(f,"%s %s %s %s %d %d %d %s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre,ET.dt_naiss.jour,ET.dt_naiss.mois,ET.dt_naiss.annee,ET.sexe,ET.email,ET.paiement,ET.niveau);
        fclose(f);
    }

}*/
void supprimer(char cin[])
{

struct etudiant ET;

FILE *f,*g;
f=fopen("etudiant.txt","r");
g=fopen("users.txt","a");
if(f!=NULL || g!=NULL ){
	do
{
	fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s ",ET.cin,ET.nom,ET.prenom,ET.chambre,&(ET.dt_naiss.jour),&(ET.dt_naiss.mois),&(ET.dt_naiss.annee),ET.sexe,ET.email,ET.paiement,ET.niveau);

if(strcmp(ET.cin,cin)!=0)
{
fprintf(g,"%s %s %s %s %d %d %d %s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre,ET.dt_naiss.jour,ET.dt_naiss.mois,ET.dt_naiss.annee,ET.sexe,ET.email,ET.paiement,ET.niveau);

        }
}while(!feof(f));

fclose(g);
fclose(f);
remove("etudiant.txt");
rename("users.txt","etudiant.txt");
}
}
int verifier(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s",ch1,ch2)!=EOF);
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}

///////////////////////////////////////////////////////////
void afficher(GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
char chambre[20];
DATE dt_naiss;
char email[40];
char sexe[20];
char paiement[20];
char niveau[20];

store=NULL;


FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{	renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",ECHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("date naissance",renderer,"text",EDT_NAISS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("paiement",renderer,"text",EPAIEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	
column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

							   	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f==NULL)
{
return;
}
else{
	f=fopen("etudiant.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s \n",cin,nom,prenom,chambre,&(dt_naiss.jour),&(dt_naiss.mois),&(dt_naiss.annee),sexe,email,paiement,niveau)!=EOF)
{char mot[200];
sprintf(mot,"%d/%d/%d",dt_naiss.jour,dt_naiss.mois,dt_naiss.annee);
	gtk_list_store_append(store, &iter);
									gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM,prenom,ECHAMBRE,chambre,EDT_NAISS,mot,ESEXE,sexe,EEMAIL,email,EPAIEMENT,paiement,ENIVEAU,niveau);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}
}
/////////////////////////////////////////////////////////////
void modifier( etudiant ET)
{


FILE *f,*g;
etudiant E;
f=fopen("etudiant.txt","r");
g=fopen("users.txt","a");
if(f!=NULL ||g!=NULL)
do{
fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s\n",E.cin,E.nom,E.prenom,E.chambre,&(E.dt_naiss.jour),&(E.dt_naiss.mois),&(E.dt_naiss.annee),E.sexe,E.email,E.paiement,E.niveau);
if 
(strcmp(ET.cin,E.cin)!=0)
{
fprintf(g,"%s %s %s %s %d %d %d %s %s %s %s\n",E.cin,E.nom,E.prenom,E.chambre,E.dt_naiss.jour,E.dt_naiss.mois,E.dt_naiss.annee,E.sexe,E.email,E.paiement,E.niveau);
}else 
fprintf(g,"%s %s %s %s %d %d %d %s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre,ET.dt_naiss.jour,ET.dt_naiss.mois,ET.dt_naiss.annee,ET.sexe,ET.email,ET.paiement,ET.niveau);
}while(!feof(f));
fclose(g);
fclose(f);
remove("etudiant.txt");
rename("users.txt","etudiant.txt");
}
////////////////////////////////////////////////////////

int rechercher(char cin[])
{
struct etudiant ET;
int b=0;
FILE*f;
f=fopen("etudiant.txt","r");
do{
fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s\n ",ET.cin,ET.nom,ET.prenom,ET.chambre,&(ET.dt_naiss.jour),&(ET.dt_naiss.mois),&(ET.dt_naiss.annee),ET.sexe,ET.email,ET.paiement,ET.niveau);
if(strcmp(ET.cin,cin)==0)
{b=1;}
}while(!feof(f));

fclose(f);
return(b);
}
///////////////////////////////////////////////////////////////
void afficher_rec(GtkWidget *liste,char cinr[])
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
char chambre[20];
DATE dt_naiss;
char email[40];
char sexe[20];
char paiement[20];
char niveau [20];

store=NULL;


FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{	renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",ECHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("date naissance",renderer,"text",EDT_NAISS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EEMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("paiement",renderer,"text",EPAIEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);							   	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f==NULL)
{
return;
}
else{
	f=fopen("etudiant.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s \n",cin,nom,prenom,chambre,&(dt_naiss.jour),&(dt_naiss.mois),&(dt_naiss.annee),sexe,email,paiement,niveau)!=EOF)
if(strcmp(cin,cinr)==0)
 
{char mot[200];
sprintf(mot,"%d/%d/%d",dt_naiss.jour,dt_naiss.mois,dt_naiss.annee);
	gtk_list_store_append(store, &iter);
									gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM,prenom,ECHAMBRE,chambre,EDT_NAISS,mot,ESEXE,sexe,EEMAIL,email,EPAIEMENT,paiement,ENIVEAU,niveau);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}
}
//////////////////////////////////////////////////
int niveau(int calcul[],char txt[])
{
 	FILE *f=NULL;
	DATE date;
	etudiant ET;
    	int s1=0,s2=0,s3=0,s4=0,s5=0,s=0;
    	f=fopen("etudiant.txt","r");
  if(f!=NULL)
  {
        
          
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s\n",ET.cin,ET.nom,ET.prenom,ET.chambre,&(ET.dt_naiss.jour),&(ET.dt_naiss.mois),&(ET.dt_naiss.annee),ET.sexe,ET.email,ET.paiement,ET.niveau)!=EOF)
			
         	{ 		if((calcul[0]==1)
&&(strcmp(ET.niveau,"1")==0))

                                 {
                                  s1++;

                                 }

  				if((calcul[1]==1)&&(strcmp(ET.niveau,"2")==0))
                                {
                                 s2++;

                                }

 				if((calcul[2]==1)&&(strcmp(ET.niveau,"3")==0))
                                {
              			 s3++;

            			}

 				if((calcul[3]==1)&&(strcmp(ET.niveau,"4")==0))
            			{
              			s4++;

            			}

 				if((calcul[4]==1)&&(strcmp(ET.niveau,"5")==0))
            			{
              			s5++;

            			}
       
       
    		}
s=s1+s2+s3+s4+s5;
 }
    fclose(f);
return s;
}

