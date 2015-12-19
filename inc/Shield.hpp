#ifndef SHIELD_H
#define SHIELD_H

#include <SFML/Graphics.hpp>
#include "Textures.hpp"
#include "PlayerLaser.hpp"
#include "InvaderFormation.hpp"

/* The shields protection the player from incoming fire. */

class Shield
{
private:
    static constexpr unsigned Y_POS = 520;

    // Individual shields have unique texture because they are destructable.
    sf::Texture texture;
    sf::Sprite sprite;

    // Image made from texture for pixel collision
    sf::Image img;

public:
    Shield(Textures &textures, const int xpos);
    sf::Sprite& getSprite(){ return this->sprite; }

    // Handles for collisions with lasers
    void handleCollide(PlayerLaser &player_laser, Lasers &invader_lasers);

    // Add splash damage to shield
    void damageShield(int x, int y, const int dmg);

};

#endif
