#include "player.h"

void initPlayer(Player *player)
{
    player->position = (Vector2){400, 280};
    player->size = (Vector2){50, 50};
    player->speed = 300.f;
    player->velocity = 0;
    player->canShoot = true;

    for (int i = 0; i < MAX_BULLETS; i++)
        player->bullets[i] = createBullet(player->position);
}

void shootBullet(Player *player)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (!player->bullets[i].isActive)
        {
            player->bullets[i].position = player->position;
            player->bullets[i].isActive = true;
            return;
        }
    }
}

void UpdatePlayer(Player *player, float delta)
{
    if (IsKeyDown(KEY_LEFT))  player->position.x -= player->speed * delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += player->speed * delta;
    if (IsKeyDown(KEY_UP))    player->position.y -= player->speed * delta;
    if (IsKeyDown(KEY_DOWN))  player->position.y += player->speed * delta;

    if (IsKeyPressed(KEY_SPACE) && player->canShoot)
        shootBullet(player);
}

void DrawPlayer(Player *player)
{
    DrawRectangleV(player->position, player->size, WHITE);
}