
#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "GameConfig.h"
#include "enemy.h"
#include "collision.h"
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");
    SetTargetFPS(GetMonitorRefreshRate(0));

    //init
    Player player = {0};
    initPlayer(&player);

    Enemy enemy = {0};
    initEnemy(&enemy);

    Enemy enemies[10] = {0};
    enemies[0]=enemy;

    Upgrade upgrades[10]= {0};
    Upgrade upgrade = {0};
    upgrades[0]=upgrade;

    Bullet enemyBullet= {0};
    Bullet enemyBullets[10]={0};
    enemyBullets[0]= enemyBullet;

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        //Update
        UpdatePlayer(&player, delta);
        for (int i = 0; i < MAX_BULLETS; i++)
        {
            if (player.bullets[i].isActive)
                UpdateBullet(&player.bullets[i], delta);

        }

        if(enemies[0].isActive)
        UpdateEnemy(&enemies[0], delta);

        HandleCollisions(&player, enemies,1,upgrades, 1, enemyBullets,1);

        //Drawing
        BeginDrawing();
            ClearBackground(BLACK);
            DrawPlayer(&player);
            for (int i = 0; i < MAX_BULLETS; i++)
            {
                if (player.bullets[i].isActive)
                    DrawBullet(&player.bullets[i]);
            }

            if(enemies[0].isActive)
            DrawEnemy(&enemies[0]);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}