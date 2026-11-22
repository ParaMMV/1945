#include "bullet.h"

void initBullet(Bullet *bullet, Vector2 spawnPos)
{
    bullet->position = spawnPos;
    bullet->size = (Vector2){20, 20};
    bullet->speed = 750.f;
}

Bullet createBullet(Vector2 spawnPos)
{
    Bullet bullet = {0};
    initBullet(&bullet, spawnPos);
    return bullet;
}

void UpdateBullet(Bullet *bullet, float delta)
{
    bullet->position.y -= bullet->speed * delta;

    if (bullet->position.y + bullet->size.y < 0)
    bullet->isActive = false;
}

void DrawBullet(Bullet *bullet)
{
    DrawRectangleV(bullet->position, bullet->size, YELLOW);
}