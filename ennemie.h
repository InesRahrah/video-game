#ifndef ENNEMIE_H
#define ENNEMIE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 511
#define SCREEN_W 800
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include <math.h> 

typedef struct 
{
int frame;
int direction;
SDL_Rect pos;
SDL_Surface * mat[30][30];
SDL_Surface * image_actuelle;
int etat;

} ennemie;

typedef struct
{

SDL_Rect posScreen,posvie;
int frame;
SDL_Surface * mat[20][20];
SDL_Surface * tab[20];
SDL_Surface * vie_actuelle ;
SDL_Surface * image_actuelle ;
SDL_Surface * vie;
int direction;
double vitesse,acceleration;
int up;
int nbvie;
int score;
SDL_Rect postxt;
double dx;
int player;
SDL_Rect posplayer;

}personne;



typedef struct
{
SDL_Surface *txt;

SDL_Colour color_txt;
TTF_Font *police;
}texte;




typedef struct
{
char *ur1;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;




void initialiser_imageBACK(image * IMAGE);
void affiche_image(SDL_Surface * screen,image IMAGE);
void liberer_image(image IMAGE);

void initialiserEnnemie(ennemie*e);
void afficherEnnemi(ennemie e,SDL_Surface *screen);
void liberer_ennemie(ennemie e);
void annimerEnnemi(ennemie*e);
void move(ennemie*e);
int collision(personne p, ennemie e);
void moveIA(ennemie *e,personne*p);



void iniPerso(personne *p);
void initialiser_texte(texte *txte);
void afficherPerso(personne p, SDL_Surface * screen);
void movePerso(personne *p,Uint32 dt);
void animerPerso(personne *p);
void sautPerso(personne *p, Uint32 dt);
void vie(personne *p);
void afficherScoreVie(personne p,texte txte,SDL_Surface *screen);
void liberer_personne(personne p);


#endif



