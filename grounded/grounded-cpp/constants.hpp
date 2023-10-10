/*
 * Grounded. Pequeño juego de plataformas.
 *
 *
 * Copyright (C) Alejandro Santos, 2014, ale@ralo.com.ar.
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace grounded {

#define TILE_SIZE 32
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

enum speeds {
    SPEED_PLAYER = 8,
    SPEED_ZOMBIE = 2,
    SPEED_FIREB  = 12,
};

enum ids {
    ID_BACKGROUND = 0,
    ID_WALL,
    ID_ITEM,
    ID_PLAYER,
    ID_EXIT,
    ID_ELEVATOR,
    ID_ZOMBIE,
    ID_FIREBALL,
};

}

#endif
