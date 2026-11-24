#ifndef UPGRADE_H
#define UPGRADE_H

#include "raylib.h"

typedef enum UpgradeType { UPGRADE_HEALTH, UPGRADE_FIRE_RATE } UpgradeType;

typedef struct Upgrade
{
    Vector2 position;
    Vector2 size;
    UpgradeType type;
    bool isActive;
} Upgrade;

#endif