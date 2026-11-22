#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

typedef struct Bullet
{
    Vector2 position;
    Vector2 size;
    float speed;
    bool isActive;
} Bullet;

void   initBullet(Bullet *bullet, Vector2 spawnPos);
Bullet createBullet(Vector2 spawnPos);
void   UpdateBullet(Bullet *bullet, float delta);
void   DrawBullet(Bullet *bullet);

#endif