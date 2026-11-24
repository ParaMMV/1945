#include "collision.h"

static Rectangle PlayerRect(const Player *p)   { return (Rectangle){ p->position.x, p->position.y, p->size.x, p->size.y }; }
static Rectangle EnemyRect(const Enemy *e)     { return (Rectangle){ e->position.x, e->position.y, e->size.x, e->size.y }; }
static Rectangle BulletRect(const Bullet *b)   { return (Rectangle){ b->position.x, b->position.y, b->size.x, b->size.y }; }
static Rectangle UpgradeRect(const Upgrade *u) { return (Rectangle){ u->position.x, u->position.y, u->size.x, u->size.y }; }

static void DamagePlayer(Player *player, int amount)
{
    if (player->invulnTimer > 0.f) return;   // still immune
    player->health -= amount;
    player->invulnTimer = 1.0f;              // 1 second of immunity
}

// 

void HandleCollisions(Player *player,Enemy enemies[], int enemyCount, Upgrade upgrades[], int upgradeCount, Bullet enemyBullets[], int enemyBulletCount)
{
    Rectangle playerRect = PlayerRect(player);

    // Player bullets vs enemies, and player bullets vs enemy bullets
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        Bullet *pb = &player->bullets[i];
        if (!pb->isActive) continue;
        Rectangle pbRect = BulletRect(pb);

        for (int e = 0; e < enemyCount; e++)
        {
            if (!enemies[e].isActive) continue;
            if (CheckCollisionRecs(pbRect, EnemyRect(&enemies[e])))
            {
                pb->isActive = false;      
                enemies[e].isActive = false;
                break;   // this bullet is spent
            }
        }
        if (!pb->isActive) continue;

        for (int b = 0; b < enemyBulletCount; b++)
        {
            if (!enemyBullets[b].isActive) continue;
            if (CheckCollisionRecs(pbRect, BulletRect(&enemyBullets[b])))
            {
                pb->isActive = false;
                enemyBullets[b].isActive = false;
                break;
            }
        }
    }

    // Enemy bullets vs player
    for (int b = 0; b < enemyBulletCount; b++)
    {
        Bullet *eb = &enemyBullets[b];
        if (!eb->isActive) continue;
        Rectangle ebRect = BulletRect(eb);

        if (CheckCollisionRecs(ebRect, playerRect))
        {
            eb->isActive = false;
            DamagePlayer(player, 1);
        }
    }

    // Enemies vs player
    for (int e = 0; e < enemyCount; e++)
    {
        if (!enemies[e].isActive) continue;
        if (CheckCollisionRecs(EnemyRect(&enemies[e]), playerRect))
            DamagePlayer(player, 1);   // optionally also kill the enemy
    }

    // Upgrades vs player
    for (int u = 0; u < upgradeCount; u++)
    {
        if (!upgrades[u].isActive) continue;
        if (CheckCollisionRecs(UpgradeRect(&upgrades[u]), playerRect))
        {
            upgrades[u].isActive = false;
            switch (upgrades[u].type)
            {
                case UPGRADE_HEALTH:    player->health++; break;
                case UPGRADE_FIRE_RATE: /* apply your effect */ break;
            }
        }
    }
}