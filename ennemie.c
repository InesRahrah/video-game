#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "ennemie.h"



void initialiser_imageBACK(image * IMAGE)
{
IMAGE->ur1="ground.jpg";
IMAGE->img=IMG_Load(IMAGE->ur1);
if (IMAGE->img==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
IMAGE->pos_img_ecran.x=0;
IMAGE->pos_img_ecran.y=0;
IMAGE->pos_img_affiche.x=0;
IMAGE->pos_img_affiche.y=0;
IMAGE->pos_img_affiche.h=511;//511
IMAGE->pos_img_affiche.w=800;//800

}


void affiche_image(SDL_Surface *screen,image IMAGE)
{

SDL_BlitSurface(IMAGE.img , &IMAGE.pos_img_affiche ,screen , &IMAGE.pos_img_ecran);
}






void initialiserEnnemie(ennemie*e)
{
e->frame=0;

e->mat[0][0]=IMG_Load("ph 1.png");
e->mat[0][1]=IMG_Load("ph 2.png");
e->mat[0][2]=IMG_Load("ph 3.png");
e->mat[0][3]=IMG_Load("ph 4.png");



e->mat[1][0]=IMG_Load("ph1.png");
e->mat[1][1]=IMG_Load("ph2.png");
e->mat[1][2]=IMG_Load("ph3.png");
e->mat[1][3]=IMG_Load("ph4.png");

e->image_actuelle=e->mat[0][0];


e->etat=0;
e->pos.x=420;
e->pos.y=270;//260

e->direction=0;
}

void afficherEnnemi(ennemie e,SDL_Surface *screen)
{
SDL_BlitSurface(e.image_actuelle,NULL,screen,&e.pos);
}




void annimerEnnemi(ennemie*e)
{



if (e->frame==3)
e->frame=0;
else
(e->frame)++;

switch (e->direction)
{
case 1:
e->image_actuelle=e->mat[1][e->frame];
break;
case 0:
e->image_actuelle=e->mat[0][e->frame];
break;
}

}




void move(ennemie*e)
{

int posMAX=350;//250
int posMIN=300;//200
int speed=4;
if(e->direction==0){
    if(e->pos.x>posMIN){ 
      e->pos.x-=speed;}
 else{
     e->direction=1;
}
}else{
   if(e->pos.x<posMAX){
     e->pos.x+=speed;
}else{
    e->direction=0;
}}}

      





int collision(personne p, ennemie e) {
   
    if (((p.posScreen.x + p.posScreen.w) < e.pos.x) || ((p.posScreen.x) > (e.pos.x + e.pos.w)) || ((p.posScreen.y + p.posScreen.h) < e.pos.y) || ((p.posScreen.y) > (e.pos.y + e.pos.h)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}


void moveIA(ennemie *e ,personne *p)
{

/*int d=abs(e->pos.y-p->posScreen.y);//414
int s1=100;//380
int s2=150;//50

switch(e->etat){
   case 0://waiting
    if (d<=0)
       {e->etat=0;
         printf("wait\n");}
 else if(s2<d && d<=s1)
          {printf("start\n");
e->etat=1;}//waiting->following
          //printf("start\n");}
     break;
   case 1://following
       if(0<d && d<=s2)
           { e->etat=2;//following->attacking
             printf("attack\n");}
 else if (s2<d && d<=s1) 
         e->etat=1;
 else if (d<=0)
         e->etat=0;
      printf("commence\n");
      break;
   case 2://attacking
    if(0<d && d<=s2)
          e->etat=2;
else if(d<=0)
           e->etat=0;//attacking->following
    printf("retour\n");
       break;
}
}  */ 

  int d = abs(e->pos.x - p->posScreen.x);
    int s1 = 100;//70 // distance à partir de laquelle l'ennemi commence à suivre
    int s2 = 110;//80 // distance à partir de laquelle l'ennemi attaque

    switch (e->etat) {
        case 0: // en mouvement aléatoire
            if (d <= s1) {
                e->etat = 1; // commence à suivre le joueur
                printf("L'ennemi commence à suivre le joueur.\n");
            }
            break;
        case 1: // en train de suivre le joueur
            if (d <= s2) {
                e->etat = 2; // commence à attaquer le joueur
                printf("L'ennemi attaque le joueur.\n");
            }
            else if (d > s1) {
                e->etat = 0; // retourne en mouvement aléatoire
                printf("L'ennemi retourne en mouvement aléatoire.\n");
            }
            break;
        case 2: // en train d'attaquer le joueur
            if (d > s2) {
                e->etat = 1; // arrête l'attaque et suit le joueur
                printf("L'ennemi arrête l'attaque et suit le joueur.\n");
            }
            break;
        default:
            printf("Erreur : état inconnu pour l'ennemi.\n");
            break;
    }
}







void liberer_image(image IMAGE)
{
SDL_FreeSurface(IMAGE.img);

}

void liberer_ennemie(ennemie e)
{
SDL_FreeSurface(e.image_actuelle);

}




//***********************************







void iniPerso(personne *p)
{
p->frame=0;

p->mat[0][0]=IMG_Load("img 11.png");
p->mat[0][1]=IMG_Load("img 22.png");
p->mat[0][2]=IMG_Load("img 33.png");
p->mat[0][3]=IMG_Load("img 44.png");



p->mat[1][0]=IMG_Load("img 1.png");
p->mat[1][1]=IMG_Load("img 2.png");
p->mat[1][2]=IMG_Load("img 3.png");
p->mat[1][3]=IMG_Load("img 4.png");

p->image_actuelle=p->mat[0][0];

p->posScreen.x==6;
p->posScreen.y=270;//270

p->vitesse=1;
p->acceleration=0;
p->up=0;
p->direction=0;
p->score=200;
p->nbvie=3;
p->vie_actuelle=p->tab[3];


p->tab[0]=IMG_Load("vie0.png");
p->tab[1]=IMG_Load("vie1.png");
p->tab[2]=IMG_Load("vie2.png");
p->tab[3]=IMG_Load("vie3.png");

p->postxt.x=SCREEN_W-80;
p->postxt.y=0;

p->player=1;
p->posplayer.x=540;
p->posplayer.y=0;
}

void afficherPerso(personne p, SDL_Surface * screen)
{
SDL_BlitSurface(p.image_actuelle,NULL,screen,&p.posScreen);
}




void animerPerso(personne *p)
{

if (p->frame==3)
p->frame=0;
else
(p->frame)++;

switch (p->direction)
{
case 1:
p->image_actuelle=p->mat[1][p->frame];
break;
case 0:
p->image_actuelle=p->mat[0][p->frame];
break;
}




}



void movePerso(personne *p, Uint32 dt)
{


double dx=0.05*p->acceleration * dt *dt +0.04*p->vitesse *dt;//0.04*
//int speed=4;
if (p->direction==0)
(p->posScreen.x)+=dx;//dx;
else if  (p->direction==1)
(p->posScreen.x)-=dx;//dx;


p->vitesse=1+ p->acceleration *dt ;

if (p->vitesse <0)
p->vitesse=0;


/*p->dx=0.5*p->acceleration * dt *dt + p->vitesse *dt;

 
if (p->direction==0 && p->posScreen.x<1090)
{(p->posScreen.x)+=p->dx;
//printf("%d--",p->posScreen.x);
}
else if  (p->direction==1 && p->posScreen.x>=-125)
{(p->posScreen.x)-=p->dx;}
//printf("aa---%d---",p->posScreen.x);}

//else if  (p->direction==1 && p->posScreen.x>=1055)
//{(p->posScreen.x)-=p->dx+15;
//}


p->vitesse=1+ p->acceleration *dt ;

if (p->vitesse <0)
p->vitesse=0;*/
}



void sautPerso(personne *p, Uint32 dt  )
{
int height=140;
//double dx=0.5*p->acceleration * dt *dt + p->vitesse *dt;

if (height<0)
	height=0;

if(p->up==1 && p->posScreen.y>height)
	{(p->posScreen.y)-=150;


 	if (p->direction==0 && p->posScreen.x<1055)
	{(p->posScreen.x)+=130;}
	//printf("----%d------",p->posScreen.x);}
	else if  (p->direction==1 && p->posScreen.x>=-125)
	(p->posScreen.x)-=130;}
        

//if (p->posScreen.y<=height)
 	//p->up=0;
if(p->up==0 && p->posScreen.y<250 )
	{(p->posScreen.y)+=150;
if (p->direction==0 && p->posScreen.x<1055)
{(p->posScreen.x)+=130;}
//printf("%d--",p->posScreen.x);}
else if  (p->direction==1 && p->posScreen.x>=-125)
(p->posScreen.x)-=130;}



}









void initialiser_texte(texte *txte)
{
TTF_Init();

txte-> police=TTF_OpenFont("smile.ttf",45);
txte->color_txt.r=0;
txte->color_txt.g=0;
txte->color_txt.b=0;

}



void vie(personne *p)
{
switch (p->nbvie)
{
case 0:
	p->vie_actuelle=p->tab[0];
break;
case 1:
	p->vie_actuelle=p->tab[1];
break;
case 2:
	p->vie_actuelle=p->tab[2];
break;
case 3:
	p->vie_actuelle=p->tab[3];
break;
}


}


void afficherScoreVie(personne p,texte txte,SDL_Surface *screen)
{
char chscore[20];
char chplayer[20];

SDL_BlitSurface(p.vie_actuelle,NULL,screen,&p.posvie);

sprintf(chscore,"%d",p.score);
txte.txt=TTF_RenderText_Blended(txte.police,chscore,txte.color_txt);
SDL_BlitSurface(txte.txt , NULL, screen , &p.postxt);

sprintf(chplayer,"player %d:",p.player);
txte.txt=TTF_RenderText_Blended(txte.police,chplayer,txte.color_txt);
SDL_BlitSurface(txte.txt , NULL, screen , &p.posplayer);


}








void liberer_personne(personne p)
{
SDL_FreeSurface(p.image_actuelle);

}



