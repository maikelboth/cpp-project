//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENTITY_H
#define GBA_SPRITE_ENGINE_PROJECT_ENTITY_H


class Entity {
private:

public:
    Entity() = default;

    virtual void moveTo(int x, int y) = 0;
    virtual void setVelocity(int dx, int dy) = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENTITY_H
