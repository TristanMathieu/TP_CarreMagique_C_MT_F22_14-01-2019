#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

/* Types */

typedef struct coord{
        int nx;
        int ny;
}coord;

/* Prototypage */

void pcd_av_g (int tab[TAILLE][TAILLE], coord *coord_a);
int fct_corriger (int tab[TAILLE][TAILLE], coord *coord_a);
void pcd_av_d (int tab[TAILLE][TAILLE], coord *coord_a);

void pcd_initialiser(int tab[TAILLE][TAILLE], coord *coord_a);
void pcd_avancer(int tab[TAILLE][TAILLE], coord *coord_a);
int fct_rech_vide(int tab[TAILLE][TAILLE], coord *coord_a);
void pcd_placer(int tab[TAILLE][TAILLE], coord *coord_a, int *cpt_remp);
void pcd_afficher(int tab[TAILLE][TAILLE]);



/*-----------------------------------
 Descriptions : Programme principale permettant de faire le carr� magique de fa�on algorithmique
 Entr�es : Rien
 Sorties : Un carr� magique dans un tableau
-----------------------------------*/

int main()
{
    int tab[TAILLE][TAILLE];
    int cpt_remp;
    coord coord_a;

    pcd_initialiser(tab, &coord_a);
    for(cpt_remp=2;cpt_remp<=(TAILLE*TAILLE);cpt_remp++){
        pcd_avancer(tab, &coord_a);
        if(fct_rech_vide(tab, &coord_a)==1){
            pcd_placer(tab, &coord_a, &cpt_remp);
        }
    }

    pcd_afficher(tab);

    return 0;
}



/* Fct/Pcd */

/*-----------------------------------
 Descriptions : procedure pour avancer les coordonn�es actuel vers la gauche
 Entr�es : tableau, coordonn�es actuel
 Sorties : coordonn�es actuel modifi�e
-----------------------------------*/

void pcd_av_g (int tab[TAILLE][TAILLE], coord *coord_a){
	(*coord_a).nx=(*coord_a).nx+1;
	if((*coord_a).nx==5){
        (*coord_a).nx=0;
	}
	(*coord_a).ny=(*coord_a).ny-1;
	if((*coord_a).ny==-1){
        (*coord_a).ny=4;
	}
}



/*-----------------------------------
 Descriptions : test les coordonn�e actuel pour v�rifier si la case est occup�e ou non
 Entr�es : tableau, coordonn�es actuel
 Sorties : si oui (1) ou non (0) la case est occup�e
-----------------------------------*/

int fct_corriger (int tab[TAILLE][TAILLE], coord *coord_a){
	int remplie;

	if (tab[(*coord_a).nx][(*coord_a).ny]>0){
        remplie=1;
    }else{
        remplie=0;
	}
	return remplie;
}



/*-----------------------------------
 Descriptions : procedure pour avancer les coordonn�es actuel vers la droite
 Entr�es : tableau, coordonn�es actuel
 Sorties : coordonn�es actuel modifi�e
-----------------------------------*/

void pcd_av_d (int tab[TAILLE][TAILLE], coord *coord_a){
	(*coord_a).nx=(*coord_a).nx-1;
	if((*coord_a).nx==-1){
        (*coord_a).nx=4;
	}
	(*coord_a).ny=(*coord_a).ny-1;
	if((*coord_a).ny==-1){
        (*coord_a).ny=4;
	}
}



/*-----------------------------------
 Descriptions : Initialise le tableau et les coordonn�e actuel
 Entr�es : tableau et coordonn�e actuel (non initialis�es)
 Sorties : tableau et coordonn�e actuel (initialis�es)
-----------------------------------*/

void pcd_initialiser(int tab[TAILLE][TAILLE], coord *coord_a){

    int cptny=0;
    int cptnx=0;
    (*coord_a).nx=2;
    (*coord_a).ny=1;
    for(cptny=0;cptny<(TAILLE);cptny++){
        for(cptnx=0;cptnx<(TAILLE);cptnx++){
            tab[cptnx][cptny]=0;
        }
    }
    tab[(*coord_a).nx][(*coord_a).ny]=1;
}



/*-----------------------------------
 Descriptions : procedure permettant aux coordonn�e actuel d'avancer. Comprend diff�rentes fct & pcd de test et de d�placement.
 Entr�es : tableau et coordonn�e actuel
 Sorties : coordonn�e actuel modifi�e
-----------------------------------*/

void pcd_avancer(int tab[TAILLE][TAILLE], coord *coord_a){
    pcd_av_g(tab, &(*coord_a));
    if ((fct_corriger(tab, &(*coord_a)))==1){
        pcd_av_d(tab, &(*coord_a));
    }
}



/*-----------------------------------
 Descriptions : fonction qui test si la case actuel est remplie ou non
 Entr�es : tableau, coordonn�es actuel
 Sorties : si la case est vide (1) ou non (0)
-----------------------------------*/

int fct_rech_vide(int tab[TAILLE][TAILLE], coord *coord_a){
    int vide;
    if (tab[(*coord_a).nx][(*coord_a).ny]==0){
        vide=1;
    }else{
        vide=0;
    }
    return vide;
}



/*-----------------------------------
 Descriptions : procedure permettant de placcer la valeur du compteur de remplissage � la case actuel
 Entr�es : tableau, coordonn�es actuel, compteur de remplissage
 Sorties : tableau (modifi�)
-----------------------------------*/

void pcd_placer(int tab[TAILLE][TAILLE], coord *coord_a, int *cpt_remp){
    tab[(*coord_a).nx][(*coord_a).ny]=*cpt_remp;
}



/*-----------------------------------
 Descriptions : Procedure d'affichage du tableau complet�
 Entr�es : tableau
 Sorties : tableau affich�
-----------------------------------*/

void pcd_afficher(int tab[TAILLE][TAILLE]){
    int cptnx=0;
    int cptny=0;

    for(cptny=0;cptny<(TAILLE);cptny++){
        for(cptnx=0;cptnx<(TAILLE);cptnx++){
            printf(" %d\t|",tab[cptnx][cptny]);
        }
        printf("\n- - - - - - - - - - - - - - - - - - - - -\n");
    }
}
