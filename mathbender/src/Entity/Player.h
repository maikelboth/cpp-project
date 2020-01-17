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
    int maxFireAttackCooldown = 40;
    int maxWaterAttackCooldown = 100;
    int fireAttackCooldown = 0;
    int waterAttackCooldown = 0;

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
    bool isFireAttackOnCooldown() {return fireAttackCooldown > 0; };
    bool isWaterAttackOnCooldown() {return waterAttackCooldown > 0; };
    void reduceFireAttackCooldown(int ticks);
    void reduceWaterAttackCooldown(int ticks);
    void reduceHealth(int amount);
    void setHealth(int amount);
    int getHealth() { return health; };
    void setMaxHealth(int amount) { maxHealth = amount; };
    int getMaxHealth() { return maxHealth; };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
