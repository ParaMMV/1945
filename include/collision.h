#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "enemy.h"
#include "upgrade.h"

// Enemy enemies[], int enemyCount

void HandleCollisions(Player *player,Enemy enemies[], int enemyCount, Upgrade upgrades[], int upgradeCount, Bullet enemyBullets[], int enemyBulletCount);

#endif