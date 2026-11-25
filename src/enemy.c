#include "enemy.h"

void initEnemy(Enemy *enemy)
{
    enemy->position = (Vector2){960, 0};
    enemy->size = (Vector2){50, 50};
    enemy->speed = 30.f;
    enemy->shootingOffset =(Vector2){Vector2Scale(enemy->size, 0.3f).x,0};
    // for (int i = 0; i < MAX_BULLETS; i++)
    //     enemy->bullets[i] = createBullet(Vector2Add(enemy->position, enemy->shootingOffset));
    enemy->isActive=true;
}

// void shootBullet(Enemy *enemy)
// {
//     for (int i = 0; i < MAX_BULLETS; i++)
//     {
//         if (!enemy->bullets[i].isActive)
//         {
//             enemy->bullets[i].position = Vector2Add(enemy->position, enemy->shootingOffset);
//             enemy->bullets[i].isActive = true;
//             return;
//         }
//     }
// }

void UpdateEnemy(Enemy *enemy, float delta)
{
    enemy->position.y += enemy->speed * delta;
}

void DrawEnemy(Enemy *enemy)
{
    DrawRectangleV(enemy->position, enemy->size, RED);
}