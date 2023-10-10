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

#ifndef GAME_H
#define GAME_H

#include <boost/noncopyable.hpp>
#include <vector>
#include <map>
#include <SDL.h>

#include "gameobjects.hpp"


namespace grounded {

class gamemap : private boost::noncopyable {
public:
    typedef std::vector<char> VC;
    typedef std::vector<VC> VVC;

    gamemap();
    virtual ~gamemap();
    
    void next_map();
    
    void update();
    
    void on_timer();
    
    /// Get a map tile, (tile coordinates)
    char get(int x, int y) {
        return m_[y][x];
    }
    
    /// (pixel coordinates)
    bool out_of_bounds(int x, int y) {
        return (x < 0) || (y < 0)
            || ((x + TILE_SIZE) > WINDOW_WIDTH)
            || ((y + TILE_SIZE) > WINDOW_HEIGHT);
    }
 
    /// Get map width in tiles
    int width() const { return w_; }
    
    /// Get map height in tiles
    int height() const { return h_; }
    
    VG& items() { return items_; }
    
    VG& exits() { return exits_; }
    
    VG& elevators() { return elevators_; }
    
    VG& zombies() { return zombies_; }
    
    VG& specials() { return specials_; }
    
    VG& fireballs() { return fireballs_; }
    
    ent* getplayer() { return static_cast<ent*>( player_.get() ); }
    
    /// Returns true if there is a collision (pixel coordinates)
    bool has_zombie_collision(int x, int y);
    
    /// Returns true if there is a collision (pixel coordinates)
    bool has_exit_collision(int x, int y);

    /// Returns zombie index if there is a collision (pixel coordinates)
    gameobject* find_zombie_collision(int x, int y);
    
    /// Collect items (pixel coordinates)
    bool collect_items(int x, int y);

    bool has_collision(int x, int y, gameobject* except = 0);
    
    int find_min_collision_y(int ex, int ey, gameobject* except = 0);
    
private:
    void load_map(int n);
    void update(VG& v);
    int find_collision(int x, int y, VG& v, gameobject* except);
    
    int mapnum_;
    int w_, h_;
    VVC m_;
    
    VG items_;
    VG exits_;
    VG elevators_;
    VG zombies_;
    VG specials_;
    VG fireballs_;
    gameobject_ptr player_;
};

class game : private boost::noncopyable {
public:
    static game* instance() { return &s_game; }
    
private:
    static game s_game;

public:
    game();
    virtual ~game() {}
    
    gamemap* map() { return &map_; }
    bool run() const { return run_; }
    
    void poll_events();
    void update();
    void init();
    void on_timer();
    
private:
    bool run_;
    gamemap map_;
    std::map<Uint32, Uint8> teclas_;
};

};

#endif
