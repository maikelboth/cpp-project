//
// Created by Maikel on 4-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOSS_H
#define GBA_SPRITE_ENGINE_PROJECT_BOSS_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <vector>
#include "Entity.h"

class Boss : public Entity {
private:
    std::unique_ptr<Sprite> bossSprite;
    Direction spriteDirection;

    int maxHealth = 20;
    int health = maxHealth;
    int maxAttackCooldown = 20;
    int attackCooldown = 0;

public:
    Boss();

    Sprite * getSprite();
    void load();
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;

    bool isAttackOnCooldown() { return attackCooldown > 0; };
    void reduceAttackCooldown(int ticks);
    int getAttackCooldown() { return attackCooldown; };
    int getMaxAttackCooldown() { return maxAttackCooldown; };
    void setHealth(int amount);
    int getHealth() { return health; };
    void setMaxHealth(int amount) { maxHealth = amount; };
    int getMaxHealth() { return maxHealth; };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOSS_H