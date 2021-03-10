#define GUI_GRID_WAbs		    ((safezoneW / safezoneH) min 1.2)
#define GUI_GRID_HAbs		    (GUI_GRID_WAbs / 1.2)
#define GUI_GRID_X			    safezoneX
#define GUI_GRID_Y			    (safezoneY + (safezoneH - GUI_GRID_HAbs))
#define GUI_GRID_W			    (GUI_GRID_WAbs / 40)
#define GUI_GRID_H			    (GUI_GRID_HAbs / 25)

#define GUI_GRID_CENTER_WAbs    GUI_GRID_WAbs
#define GUI_GRID_CENTER_HAbs    GUI_GRID_HAbs
#define GUI_GRID_CENTER_X	    (safezoneX + (safezoneW - GUI_GRID_CENTER_WAbs)/2)
#define GUI_GRID_CENTER_Y	    (safezoneY + (safezoneH - (GUI_GRID_CENTER_HAbs / 1.2))/2)
#define GUI_GRID_CENTER_W	    (GUI_GRID_CENTER_WAbs / 40)
#define GUI_GRID_CENTER_H	    (GUI_GRID_CENTER_HAbs / 25)

#define SET_GUI_GRID_CENTER_X(value) x = (value) * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X
#define SET_GUI_GRID_CENTER_Y(value) y = (value) * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y
#define SET_GUI_GRID_CENTER_W(value) w = (value) * GUI_GRID_CENTER_W
#define SET_GUI_GRID_CENTER_H(value) h = (value) * GUI_GRID_CENTER_H

#define PIXEL_GRID (1.5 * (pixelH * pixelGrid))
#define SIZE_M (1 + PIXEL_GRID)