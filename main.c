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
 Descriptions : Programme principale permettant de faire le carré magique de façon algorithmique
 Entrées : Rien
 Sorties : Un carré magique dans un tableau
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
 Descriptions : procedure pour avancer les coordonnées actuel vers la gauche
 Entrées : tableau, coordonnées actuel
 Sorties : coordonnées actuel modifiée
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
 Descriptions : test les coordonnée actuel pour vérifier si la case est occupée ou non
 Entrées : tableau, coordonnées actuel
 Sorties : si oui (1) ou non (0) la case est occupée
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
 Descriptions : procedure pour avancer les coordonnées actuel vers la droite
 Entrées : tableau, coordonnées actuel
 Sorties : coordonnées actuel modifiée
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
 Descriptions : Initialise le tableau et les coordonnée actuel
 Entrées : tableau et coordonnée actuel (non initialisées)
 Sorties : tableau et coordonnée actuel (initialisées)
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
 Descriptions : procedure permettant aux coordonnée actuel d'avancer. Comprend différentes fct & pcd de test et de déplacement.
 Entrées : tableau et coordonnée actuel
 Sorties : coordonnée actuel modifiée
-----------------------------------*/

void pcd_avancer(int tab[TAILLE][TAILLE], coord *coord_a){
    pcd_av_g(tab, &(*coord_a));
    if ((fct_corriger(tab, &(*coord_a)))==1){
        pcd_av_d(tab, &(*coord_a));
    }
}



/*-----------------------------------
 Descriptions : fonction qui test si la case actuel est remplie ou non
 Entrées : tableau, coordonnées actuel
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
 Descriptions : procedure permettant de placcer la valeur du compteur de remplissage à la case actuel
 Entrées : tableau, coordonnées actuel, compteur de remplissage
 Sorties : tableau (modifié)
-----------------------------------*/

void pcd_placer(int tab[TAILLE][TAILLE], coord *coord_a, int *cpt_remp){
    tab[(*coord_a).nx][(*coord_a).ny]=*cpt_remp;
}



/*-----------------------------------
 Descriptions : Procedure d'affichage du tableau completé
 Entrées : tableau
 Sorties : tableau affiché
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
