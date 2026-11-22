#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "bullet.h"
#include "GameConfig.h"

typedef struct Player
{
    Vector2 position;
    Vector2 size;
    float speed;
    float velocity;
    bool canShoot;
    Bullet bullets[MAX_BULLETS];
} Player;

void initPlayer(Player *player);
void UpdatePlayer(Player *player, float delta);
void DrawPlayer(Player *player);
void shootBullet(Player *player);

#endif