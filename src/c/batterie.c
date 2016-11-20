#include <pebble.h>
#include "batterie.h"


void batterie(GContext *ctx, int16_t x, int16_t y, GColor couleur, int charge)
{
	
	/*************************************************/
	/*         Dessin symbole de la batterie         */
	/*************************************************/
	uint8_t epaisseurTrait;
		
	/* Définir la couleur de la ligne */
	#ifdef PBL_COLOR
 	graphics_context_set_stroke_color(ctx, couleur);
	#else
	graphics_context_set_stroke_color(ctx, GColorWhite);
	#endif
	
	/* Défini la largeur des lignes */
	epaisseurTrait = 1;
	graphics_context_set_stroke_width(ctx, epaisseurTrait);
	
	/* Contour de la batterie */
	GRect rect_bounds = GRect(x, y, 23, 9);
	graphics_draw_rect(ctx, rect_bounds);
	// Fill a rectangle with rounded corners
	//int corner_radius = 1;
	//graphics_draw_round_rect(ctx, rect_bounds, corner_radius);
	
	/* Borne + */
	GPoint start = GPoint(x + 23, y + 2);
	GPoint end = GPoint(x + 23, y + 6);
	graphics_draw_line(ctx, start, end);
	start = GPoint(x + 24, y + 2);
	end = GPoint(x + 24, y + 6);
	graphics_draw_line(ctx, start, end);
	
	/* Barre de charge */
	/* Défini la largeur des lignes */
	epaisseurTrait = 1;
	graphics_context_set_stroke_width(ctx, epaisseurTrait);
	for (int i = 0 ; i < charge ; i += 10)
		{
			GPoint start = GPoint(x + 2 + (i / 5), y + 2);
			GPoint end = GPoint(x + 2 + (i / 5), y + 6);
			graphics_draw_line(ctx, start, end);
		}	
}