//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYER_H


#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <vector>
#include "Attack.h"

class Player {

private:
    std::unique_ptr<Sprite> playerSprite;
    std::unique_ptr<Sprite> fireballSprite;
    std::unique_ptr<Sprite> waterSprite;
    SpriteBuilder<Sprite> builder;

    int maxHealth = 20;
    int health = maxHealth;
    int maxAttackCooldown = 40;
    int attackCooldown = 0;

public:
    Player();
    enum AttackType {WATER, FIRE};

    Sprite* getSprite();
    std::vector<Sprite*> getTemplateSprites();
    void load();
    void move(int x, int y);
    void moveTo(int x, int y);
    void setVelocity(int dx, int dy);
    std::unique_ptr<Attack> attack(AttackType type);

    bool isDead() { return health <= 0; };
    bool isAttackOnCooldown() { return attackCooldown > 0; };
    void reduceAttackCooldown(int ticks);
    int getAttackCooldown() { return attackCooldown; };
    int getMaxAttackCooldown() { return maxAttackCooldown; };
    void reduceHealth(int amount);
    void setHealth(int amount);
    int getHealth() { return health; };
    void setMaxHealth(int amount) { maxHealth = amount; };
    int getMaxHealth() { return maxHealth; };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
