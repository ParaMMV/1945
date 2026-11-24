
#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "GameConfig.h"
#include "enemy.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");
    SetTargetFPS(GetMonitorRefreshRate(0));

    //init
    Player player = {0};
    initPlayer(&player);

    Enemy enemy = {0};
    initEnemy(&enemy);

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

        UpdateEnemy(&enemy, delta);

        //Drawing
        BeginDrawing();
            ClearBackground(BLACK);
            DrawPlayer(&player);
            for (int i = 0; i < MAX_BULLETS; i++)
            {
                if (player.bullets[i].isActive)
                    DrawBullet(&player.bullets[i]);
            }
            DrawEnemy(&enemy);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}