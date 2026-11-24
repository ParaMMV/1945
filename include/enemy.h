#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "bullet.h"
#include "GameConfig.h"
#include "raymath.h"

typedef struct Enemy
{
    Vector2 position;
    Vector2 size;
    float speed;
    int health;
    bool isActive;
    Vector2 shootingOffset;
    //add enemy bullet pool
} Enemy;

void initEnemy(Enemy *enemy);
void UpdateEnemy(Enemy *enemy, float delta);
void DrawEnemy(Enemy *enemy);
// void shootBullet(Enemy *enemy);
#endif