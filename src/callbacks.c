#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


int x;
calcul[5]={0,0,0,0,0};
char so[50];


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login,*pw, *windowAuth;     
char login1[20];
char passw[20];

login = lookup_widget (button, "entry1_nom");
pw = lookup_widget (button, "entry2_Mot");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));

f=fopen("utilisateur.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s \n",login1,passw);
fclose(f);
}
else
printf("\n NOT FOUND");
windowAuth=create_authen();
gtk_widget_show(windowAuth);

}
void
on_button2_authen_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *username,*password, *windowEspacefoyer,*Authentification,*windowerror;     
char user[20];
char pasw[20];
int trouve;
Authentification=lookup_widget(button,"authen");
username= lookup_widget (button, "entry4_login");
password= lookup_widget (button, "entry5_Pw");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));

trouve=verifier(user,pasw);

if(trouve==1)
{

gtk_widget_destroy(Authentification);
windowEspacefoyer=create_espace_foyer();
gtk_widget_show(windowEspacefoyer);
}
else 
{
windowerror=create_error();
gtk_widget_show(windowerror);
}
}
void
on_button5_ajouter_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*cin,*chambre,*email,*windowAjouter; 
FILE *f;
GtkWidget *jour,*mois,*annee;
GtkWidget *combobox,*combobox2;  
GtkWidget *togglebutton1,*togglebutton2;
GtkWidget *error1;  
struct etudiant ET;
DATE dt_naiss;
nom=lookup_widget (objet, "entry6_Nom");
prenom=lookup_widget(objet, "entry7_Pr");
cin=lookup_widget(objet, "entry8_cin");
chambre= lookup_widget (objet, "entry9_ch");
email= lookup_widget (objet, "entry1_email");

error1= lookup_widget (objet, "error");

strcpy(ET.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(ET.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(ET.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(ET.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
strcpy(ET.email,gtk_entry_get_text(GTK_ENTRY(email)));

combobox=lookup_widget(objet,"combobox1");
combobox2=lookup_widget(objet,"combobox3");
strcpy(ET.paiement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
strcpy(ET.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

jour=lookup_widget(objet,"spinbutton1");
mois=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");

ET.dt_naiss.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
ET.dt_naiss.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
ET.dt_naiss.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));




togglebutton1=lookup_widget(objet,"radiobutton1");
togglebutton2=lookup_widget(objet,"radiobutton2");
if (x==1)
{
strcpy(ET.sexe,"homme");
}
else if(x==2){
strcpy(ET.sexe,"femme");
}
if(rechercher(cin)==1)
{gtk_label_set_text(GTK_LABEL(error1),"cin deja inscrit");}
else{

f=fopen("etudiant.txt","a+");
if(f!=NULL)
{
  fprintf(f,"%s %s %s %s %d %d %d %s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre,ET.dt_naiss.jour,ET.dt_naiss.mois,ET.dt_naiss.annee,ET.sexe,ET.email,ET.paiement,ET.niveau);
  fclose(f);  
 }
}
}

void
on_button6_supp_clicked                (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *fenetre_supp,*suppression_succes,*error;

struct etudiant ET;
char cin[20];
error=lookup_widget (objet, "label_introuvable_supp");
fenetre_supp=lookup_widget(objet,"SUPPRIMER");
input =lookup_widget (objet, "entry12_CIN");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
if(rechercher(cin)==0)
{
gtk_label_set_text(GTK_LABEL(error),"cin introuvable");
}
else{
supprimer(cin);

fenetre_supp=lookup_widget(objet,"fenetre_supp");
gtk_widget_destroy(fenetre_supp);
suppression_succes=create_suppression_succes();
gtk_widget_show(suppression_succes);
}
}
void
on_button3_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
/*
GtkWidget  *windowajout,*principale,*Authentification;

windowajout=create_ajout ();
gtk_widget_show(windowajout);
Authentification=lookup_widget(button,"espace foyer");
gtk_widget_destroy(Authentification);*/
GtkWidget *principale, *Ajout;
principale=lookup_widget(button,"espace foyer");
gtk_widget_destroy(principale);
Ajout=lookup_widget(button,"ajout");
Ajout=create_ajout();
gtk_widget_show (Ajout);


}


void
on_button4_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowsupp;
windowsupp=create_SUPPRIMER();
gtk_widget_show(windowsupp);
}





void
on_button1_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *windowmodif;
windowmodif=create_modification();
gtk_widget_show(windowmodif);
}


void
on_button1_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout,*fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"window1");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* chambre;
DATE dt_naiss;
gchar* sexe;
gchar* email;
gchar* paiement;
gchar* niveau;
struct etudiant ET;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &chambre, 4, &dt_naiss, 5, &sexe, 6, &email, 7, &paiement, 8, &niveau,-1);
strcpy(ET.cin,cin);
strcpy(ET.nom,nom);
strcpy(ET.prenom,prenom);
strcpy(ET.chambre,chambre); 
ET.dt_naiss=dt_naiss;
strcpy(ET.sexe,sexe);
strcpy(ET.email,email);
strcpy(ET.paiement,paiement);
strcpy(ET.niveau,niveau);	
supprimer(cin);
afficher(treeview);
}
}
void
on_button1_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *Ajout,*principale;
 GtkWidget*treeview1;
/*principale=lookup_widget(objet,"espace foyer");
gtk_widget_destroy(principale);*/

Ajout=lookup_widget(objet,"ajout");
gtk_widget_destroy(Ajout);

principale = create_espace_foyer ();
/*gtk_widget_show (principale);*/


treeview1=lookup_widget(principale,"treeview4");

afficher(treeview1);

}

///////////////////////////////////////////////////
void
on_button1_affichersupp_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *supp,*principale;
 GtkWidget*treeview1;
/*principale=lookup_widget(objet,"espace foyer");
gtk_widget_destroy(principale);*/

supp=lookup_widget(objet,"SUPPRIMER");
gtk_widget_destroy(supp);

principale = create_espace_foyer ();
gtk_widget_show (principale);


treeview1=lookup_widget(principale,"treeview4");

afficher(treeview1);



}

/////////////////////////////////////////////////////////
void
on_button1_af_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*principale;
principale=lookup_widget(objet,"espace foyer");
treeview1=lookup_widget(objet,"treeview4");
principale = create_espace_foyer();
gtk_widget_show (principale);
gtk_widget_destroy(principale);
afficher(treeview1);
}
/////////////////////////////////////
void
on_button2_VAL_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*cin1,*chambre,*email,*windowAjouter; 
FILE *f;
GtkWidget *jour,*mois,*annee;
GtkWidget *combobox4,*combobox5;  
GtkWidget *togglebutton1,*togglebutton2;

GtkWidget *Modification;
GtkWidget *modif_succes;
GtkWidget *error;

 
etudiant ET;
etudiant E;
char cin[20];

Modification=lookup_widget(objet,"window3");
error=lookup_widget (objet, "label_introuvable_modif");
nom=lookup_widget(objet, "nom");
prenom=lookup_widget(objet, "prenom");
cin1=lookup_widget(objet, "entry1_C");
chambre= lookup_widget (objet, "chambre");
email= lookup_widget (objet, "entry2");

strcpy(ET.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(ET.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(ET.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));
strcpy(ET.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
strcpy(ET.email,gtk_entry_get_text(GTK_ENTRY(email)));

combobox4=lookup_widget(objet,"combobox4");
combobox5=lookup_widget(objet,"combobox5");
strcpy(ET.paiement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy(ET.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));

jour=lookup_widget(objet,"spinbutton4");
mois=lookup_widget(objet,"spinbutton5");
annee=lookup_widget(objet,"spinbutton6");

ET.dt_naiss.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
ET.dt_naiss.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
ET.dt_naiss.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));




togglebutton1=lookup_widget(objet,"radiobutton3");
togglebutton2=lookup_widget(objet,"radiobutton4");
if (x==1)
{
strcpy(ET.sexe,"homme");
}
else if(x==2){
strcpy(ET.sexe,"femme");
}/*
if(rechercher(cin)==0)
{
gtk_label_set_text(GTK_LABEL(error),"cin introuvable");
}
else{*/
modifier(ET);

Modification=lookup_widget(objet,"modification");
gtk_widget_destroy(Modification);
modif_succes=create_modification_succes();
gtk_widget_show(modif_succes);

}
/////////////////////////////////
void
on_button1_r_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *modif,*principale;
 GtkWidget*treeview1;
/*principale=lookup_widget(objet,"espace foyer");
gtk_widget_destroy(principale);*/

modif=lookup_widget(objet,"modification");
gtk_widget_destroy(modif);

principale = create_espace_foyer ();
gtk_widget_show (principale);


treeview1=lookup_widget(principale,"treeview4");

afficher(treeview1);

}

////////////////////////////////////////////////////////
void
on_button2_ret_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_mo,*fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"window1");
gtk_widget_destroy(fenetre_afficher);
fenetre_mo=create_modification();
gtk_widget_show(fenetre_mo);
}


void
on_button1_re_clicked                  (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_sup,*fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"window1");
gtk_widget_destroy(fenetre_afficher);
fenetre_sup=create_SUPPRIMER();
gtk_widget_show(fenetre_sup);
}


void
on_button1_rech_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowrech;
windowrech=create_recherche();
gtk_widget_show(windowrech);
}


void
on_button1_rech1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *input;
GtkWidget *error;
GtkWidget *recherche;
GtkWidget *affichage_rech;
GtkWidget *treeview3;
struct etudiant ET;
char cin[20];
input=lookup_widget(objet,"entry1_cin");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
if(rechercher(cin)==1){

recherche=lookup_widget(objet,"recherche");
gtk_widget_destroy(recherche);
affichage_rech=lookup_widget(objet,"recherche");
affichage_rech=create_recherche();
gtk_widget_show(affichage_rech);
treeview3=lookup_widget(affichage_rech,"treeview3");
afficher_rec(treeview3,cin);

}
}

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;
}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;}
else
{calcul[2]=0;}
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}

}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[4]=1;
}
else
{calcul[4]=0;}
}


void
on_button2_cal_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label49") ;
sum=niveau(calcul,"etudiant.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}                                        

void
on_button_calculement_clicked          (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Calcul;
principale=lookup_widget(objet,"espace foyer");
gtk_widget_destroy(principale);
Calcul=lookup_widget(objet,"option");
Calcul=create_option();
gtk_widget_show (Calcul);
}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* chambre;
DATE dt_naiss;
gchar* sexe;
gchar* email;
gchar* paiement;
gchar* niveau;
struct etudiant ET;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &chambre, 4, &dt_naiss, 5, &sexe, 6, &email, 7, &paiement, 8, &niveau,-1);
strcpy(ET.cin,cin);
strcpy(ET.nom,nom);
strcpy(ET.prenom,prenom);
strcpy(ET.chambre,chambre); 
ET.dt_naiss=dt_naiss;
strcpy(ET.sexe,sexe);
strcpy(ET.email,email);
strcpy(ET.paiement,paiement);
strcpy(ET.niveau,niveau);	
supprimer(cin);
afficher(treeview);
}
}


void
on_button1_dec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*authen;
 
/*principale=lookup_widget(button,"espace foyer");
gtk_widget_destroy(principale);*/

authen = create_authen();
gtk_widget_show (authen);
principale=lookup_widget(button,"espace foyer");
gtk_widget_destroy(principale);

}

