#include <pebble.h>
#include "src/c/cible_localisation.h"

void cible_localisation(GContext *ctx, int16_t x, int16_t y, int32_t angleStartInt, GColor couleur)
{
	
	/*************************************************/
	/*          Dessin symbole localisation          */
	/*************************************************/
	uint8_t epaisseurTrait;
	uint16_t epaisseurArc;
	int32_t angle_startExt;
	int32_t angle_endExt;
	int32_t angle_endInt;
	int32_t angle_startInt;
		
	/* Définir la couleur de la ligne */
 	graphics_context_set_stroke_color(ctx, couleur);	
	
	/* Définir la couleur de remplissage */
 	graphics_context_set_fill_color(ctx, couleur);
	
	/* Défini la largeur des lignes */
	epaisseurTrait = 1;
	graphics_context_set_stroke_width(ctx, epaisseurTrait);

	/* Croix */
	GPoint startVerH = GPoint(x + 11, y);
	GPoint endVerH = GPoint(x + 11, y + 2);
	GPoint startVerB = GPoint(x + 11, y + 20);
	GPoint endVerB = GPoint(x + 11, y + 22);
	GPoint startHorG = GPoint(x, y + 11);
	GPoint endHorG = GPoint(x + 2, y + 11);
	GPoint startHorD = GPoint(x + 20, y + 11);
	GPoint endHorD = GPoint(x + 22, y + 11);
	graphics_context_set_stroke_width(ctx, 2);
	graphics_draw_line(ctx, startVerH, endVerH);
	graphics_draw_line(ctx, startVerB, endVerB);
	graphics_draw_line(ctx, startHorG, endHorG);
	graphics_draw_line(ctx, startHorD, endHorD);
	
	/* Arc intérieur */
	GRect arcInt = GRect(x + 8, y + 8, 7, 7);
	angle_startInt = DEG_TO_TRIGANGLE(angleStartInt);
	angle_endInt = DEG_TO_TRIGANGLE(360);
	epaisseurArc = 6; 
	graphics_fill_radial(ctx, arcInt , GOvalScaleModeFitCircle, epaisseurArc, angle_startInt, angle_endInt);
	
	/* Cercle exterieur (arc 360 deg) */
	GRect arcExt = GRect(x + 3, y + 3, 17, 17);
	angle_startExt = DEG_TO_TRIGANGLE(0);
	angle_endExt = DEG_TO_TRIGANGLE(360);
	epaisseurArc = 3; 
	graphics_fill_radial(ctx, arcExt , GOvalScaleModeFitCircle, epaisseurArc, angle_startExt, angle_endExt);
	
}