#include "player.h"

Player *create_player(Arena *arena, Vector2 position)
{
  Player *new_player = {0};
  new_player = aalloc(arena, sizeof(Player));
  new_player->sprite = LoadTexture("assets/player.png");
  new_player->position.x = CENTER;
  new_player->position.y = 400;
  return new_player;
}

void update_player(Player *player, float delta_time)
{
  if(IsKeyPressed(KEY_RIGHT))
  {
    if(player->position.x < BOUNDS_X_POS)
    {
      player->position.x += MOVEMENT_DIST;
    }
  }

  if(IsKeyPressed(KEY_LEFT))
  {
    if(player->position.x > BOUNDS_X_NEG)
    {
      player->position.x -= MOVEMENT_DIST;
    }
  }
}

void draw_player(Player *player)
{
  DrawTexture(
    player->sprite,
    player->position.x,
    player->position.y,
    WHITE
  );
}