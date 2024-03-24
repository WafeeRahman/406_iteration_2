#define CENTER 400
#define MOVEMENT_DIST 200
#define BOUNDS_X_POS CENTER + MOVEMENT_DIST
#define BOUNDS_X_NEG CENTER - MOVEMENT_DIST

#include <raylib.h>
#include "aalloc.h"

#ifndef PLAYER_INCLUDE_H
#define PLAYER_INCLUDE_H

typedef struct Player
{
  Texture2D sprite;
  Vector2 position;
  int health; //NEW -- HEALTH
} Player;

#endif

Player *create_player(Arena *arena, Vector2 position);
void update_player(Player *player, float delta_time);
void draw_player(Player *player);
void hit_player(Player *player);