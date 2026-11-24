#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "bullet.h"
#include "GameConfig.h"
#include "raymath.h"

typedef struct Player
{
    Vector2 position;
    Vector2 size;
    Vector2 shootingOffset;
    float speed;
    float velocity;
    bool canShoot;
    Bullet bullets[MAX_BULLETS];
    int health;
    float invulnTimer;
} Player;

void initPlayer(Player *player);
void UpdatePlayer(Player *player, float delta);
void DrawPlayer(Player *player);
void shootBullet(Player *player);

#endif