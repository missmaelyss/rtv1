/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:40:53 by marnaud           #+#    #+#             */
/*   Updated: 2017/05/30 14:40:55 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define screenWidth 640
#define screenHeight 480
#define viewplaneWidth 0.64
#define viewplaneHeight 0.48
#define viewplaneDist 1
#define f 1
#define xRes 640
#define yRes 480
#define xIndent  viewplaneWidth / (float)xRes
#define yIndent  viewplaneHeight / (float)yRes

int		main(void)
{
    t_vct3d camPos;
    t_vct3d vecDir;
    t_vct3d upVec;
    t_vct3d rightVec;
    t_vct3d viewPlaneUpLeft;
    SDL_Rect	position;
    t_vct3d pixel;
    double delta;
    double a;
    double b;
    double c;
    t_figure sphere;
    t_figure lumiere;
    double solution;
    t_vct3d point_solution;
    t_vct3d vecteurNormal;
    t_vct3d vecteurLumierePoint;
    double  angleLumiere;
    double   norme;
    
    SDL_Window  *fenetre;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *ecran;
    SDL_Surface *pix;
    SDL_Event evenements;
    int terminer;
    
    terminer = 0;
    SDL_Init(SDL_INIT_VIDEO);
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    pix = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
    ecran = SDL_CreateRGBSurface(0, screenWidth, screenHeight, 32, 0, 0, 0, 0);

    camPos.x = 0.2;
    camPos.y = 0;
    camPos.z = 0;
    vecDir.x = -0.1;
    vecDir.y = 1;
    vecDir.z = 0;
    upVec.x = 0;
    upVec.y = 0;
    upVec.z = 1;
    rightVec.x = 1;
    rightVec.y = 0;
    rightVec.z = 0;
    sphere.origin.x = 0;
    sphere.origin.y = 500;
    sphere.origin.z = 0;
    sphere.rayon = 50;
    lumiere.origin.x = 50;
    lumiere.origin.y = 400;
    lumiere.origin.z = 30;

    viewPlaneUpLeft.x = camPos.x + ((vecDir.x*viewplaneDist)+(upVec.x*(viewplaneHeight/2.0*f))) - (rightVec.x*(viewplaneWidth/2.0*f));
    viewPlaneUpLeft.y = camPos.y + ((vecDir.y*viewplaneDist)+(upVec.y*(viewplaneHeight/2.0*f))) - (rightVec.y*(viewplaneWidth/2.0*f));
    viewPlaneUpLeft.z = camPos.z + ((vecDir.z*viewplaneDist)+(upVec.z*(viewplaneHeight/2.0*f))) - (rightVec.z*(viewplaneWidth/2.0*f));
    
    position.y = 0;
    while (position.y < screenHeight)
    {
        position.x = 0;
        while (position.x < screenWidth)
        {
            pixel.x = viewPlaneUpLeft.x + rightVec.x*xIndent*position.x - upVec.x*yIndent*position.y;
            pixel.y = viewPlaneUpLeft.y + rightVec.y*xIndent*position.x - upVec.y*yIndent*position.y;
            pixel.z = viewPlaneUpLeft.z + rightVec.z*xIndent*position.x - upVec.z*yIndent*position.y;
            a = pow(pixel.x, 2) + pow(pixel.y, 2) + pow(pixel.z, 2);
            b = 2 * (pixel.x*(camPos.x - sphere.origin.x) + pixel.y*(camPos.y - sphere.origin.y) + pixel.z*(camPos.z - sphere.origin.z));
            c = (pow(camPos.x - sphere.origin.x, 2) + pow(camPos.y - sphere.origin.y, 2) + pow(camPos.z - sphere.origin.z, 2)) - pow(sphere.rayon, 2);
            delta = pow(b, 2) - (4*a*c);
            if (delta >= 0)
            {
                solution = (-b + sqrt(delta))/(2*a) > (-b - sqrt(delta))/(2*a) ? (-b - sqrt(delta))/(2*a) : (-b + sqrt(delta))/(2*a);
                point_solution.x = camPos.x + pixel.x * solution;
                point_solution.y = camPos.y + pixel.y * solution;
                point_solution.z = camPos.z + pixel.z * solution;
                vecteurNormal.x = point_solution.x - sphere.origin.x;
                vecteurNormal.y = point_solution.y - sphere.origin.y;
                vecteurNormal.z = point_solution.z - sphere.origin.z;
                norme = sqrt(pow(vecteurNormal.x,2) + pow(vecteurNormal.y,2) + pow(vecteurNormal.z,2));
                vecteurNormal.x /= norme;
                vecteurNormal.y /= norme;
                vecteurNormal.z /= norme;
                vecteurLumierePoint.x = lumiere.origin.x - point_solution.x;
                vecteurLumierePoint.y = lumiere.origin.y - point_solution.y;
                vecteurLumierePoint.z = lumiere.origin.z - point_solution.z;
                norme = sqrt(pow(vecteurLumierePoint.x,2) + pow(vecteurLumierePoint.y,2) + pow(vecteurLumierePoint.z,2));
                vecteurLumierePoint.x /= norme;
                vecteurLumierePoint.y /= norme;
                vecteurLumierePoint.z /= norme;
                angleLumiere = vecteurNormal.x*vecteurLumierePoint.x + vecteurNormal.y*vecteurLumierePoint.y + vecteurNormal.z*vecteurLumierePoint.z;
                if (angleLumiere < 0)
                    angleLumiere  = 0;
                SDL_FillRect(pix, NULL, SDL_MapRGB(ecran->format, 146 * angleLumiere, 20*angleLumiere ,  76 * angleLumiere ));
                SDL_BlitSurface(pix, NULL, ecran, &position);
            }
            (position.x)++;
        }
        (position.y)++;
    }
     texture = SDL_CreateTextureFromSurface(renderer, ecran);
     SDL_RenderCopy(renderer, texture, NULL, NULL);
     SDL_RenderPresent(renderer);
     
     while(!terminer)
     {
         SDL_WaitEvent(&evenements);
         
         if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
             terminer = 1;
     }
    
     SDL_DestroyTexture(texture);
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(fenetre);
     SDL_Quit();
     
     return 0;
}
