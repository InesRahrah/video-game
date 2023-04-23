#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "ennemie.h"

int main()
{
SDL_Surface *screen;
image IMAGE;
SDL_Event event ;
TTF_Font *police;
TTF_Font * font;
font = TTF_OpenFont("smile.ttf", 28);

int x;
ennemie e;
personne p ;
texte txte;


if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO| SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n",SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(SCREEN_W , SCREEN_H ,32 , SDL_SWSURFACE |SDL_DOUBLEBUF);

initialiser_imageBACK(&IMAGE);
initialiserEnnemie(&e);
iniPerso(&p); 
initialiser_texte(&txte);
Uint32 t_prev=SDL_GetTicks();
Uint32 dt;

int continuer=1;


while (continuer==1)
{
affiche_image(screen,IMAGE);

afficherEnnemi(e,screen);
afficherPerso(p, screen);
vie(&p);
afficherScoreVie( p,txte,screen);
annimerEnnemi(&e);
move(&e);
//moveIA(&e,&p);



    


	SDL_PollEvent(&event);
	switch (event.type)
	{
        case SDL_QUIT:
            continuer=0;
            break;
           
         
//***************************


         case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
		
	    case SDLK_ESCAPE:
		continuer =0;
		break;
               case SDLK_a:
		(p.acceleration)+=0.005;

		break;
            
             

            case SDLK_LEFT:
		
		{p.direction=1;

             dt=SDL_GetTicks()-t_prev;
            SDL_Flip(screen);
    
          movePerso(&p, dt);
          animerPerso(&p);
          move(&e);
          moveIA(&e,&p);
if ((collision(p,e))&&((200<p.score<300) || (0<p.nbvie<3)))
                 
                    {(p.nbvie)--;
                    (p.score)--;}
               else
                 if((p.score<0) || (p.nbvie==0))
                    {vie(&p);
                    afficherScoreVie(p,txte,screen);
                    continuer=0;}
                
/*printf("contact existe.\n");
else
printf("pas de contact.\n");*/

 

               break;}

 
            
             case SDLK_RIGHT:

		{p.direction=0;
         dt=SDL_GetTicks()-t_prev;
         SDL_Flip(screen);
    
        movePerso(&p, dt);
        animerPerso(&p);
        move(&e);
        moveIA(&e,&p);
if ((collision(p,e))&&((200<p.score<300) || (0<p.nbvie<3)))
                 
                    {(p.nbvie)--;
                    (p.score)--;}
               else
                 if((p.score<0) || (p.nbvie==0))
                    {vie(&p);
                    afficherScoreVie(p,txte,screen);
                    continuer=0;}
               
/*printf("contact existe.\n");
else
printf("pas de contact.\n");*/


        break;}

           case SDLK_b:

		{p.up=1;

SDL_Flip(screen);
    
sautPerso(&p , dt);
animerPerso(&p);
move(&e);
if ((collision(p,e))&&((200<p.score<300) || (0<p.nbvie<3)))
                 
                    {(p.nbvie)--;
                    (p.score)--;}
               else
                 if((p.score<0) || (p.nbvie==0))
                    {vie(&p);
                    afficherScoreVie(p,txte,screen);
                    continuer=0;}
               
/*printf("contact existe.\n");
else
printf("pas de contact.\n");*/


break;}
case SDLK_n:

		{p.up=0;

SDL_Flip(screen);   
sautPerso(&p , dt );
animerPerso(&p);
move(&e);
if ((collision(p,e))&&((200<p.score<300) || (0<p.nbvie<3)))
                 
                    {(p.nbvie)--;
                    (p.score)--;}
               else
                 if((p.score<0) || (p.nbvie==0))
                    {vie(&p);
                    afficherScoreVie(p,txte,screen);
                    continuer=0;}
               
/*printf("contact existe.\n");
else
printf("pas de contact.\n");*/


break;}}}




t_prev=SDL_GetTicks();










SDL_Delay(60);     
SDL_Flip(screen);      



}



liberer_image(IMAGE);
liberer_ennemie(e);
liberer_personne(p);
}

