#include <raylib.h>
#include "aalloc.h"
#include "player.h"

int main(int argc, char **argv)
{
  Arena arena = create_arena(sizeof(Player) * 2);  
  InitWindow(800, 600, "Test");
  SetTargetFPS(120);

  Player *player = create_player(&arena, (Vector2){.x=0, .y=0});

  while(!WindowShouldClose())
  {
    update_player(player, GetFrameTime());
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_player(player);
    EndDrawing();
  }

  aclear(&arena);
  destroy_arena(arena);
    
  return 0;
}