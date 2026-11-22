
#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "raylib.h"
#include "player.h"
#include "GameConfig.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");
    SetTargetFPS(GetMonitorRefreshRate(0));

    Player player = {0};
    initPlayer(&player);

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        UpdatePlayer(&player, delta);
        for (int i = 0; i < MAX_BULLETS; i++)
            if (player.bullets[i].isActive)
                UpdateBullet(&player.bullets[i], delta);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawPlayer(&player);
            for (int i = 0; i < MAX_BULLETS; i++)
                if (player.bullets[i].isActive)
                    DrawBullet(&player.bullets[i]);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}