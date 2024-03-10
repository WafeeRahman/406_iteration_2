#include <stdio.h>
#include <raylib.h>
#include "aalloc.h"

int main(int argc, char **argv)
{
  Arena arena = create_arena(sizeof(int));
  int *a = aalloc(&arena, sizeof(int));
  *a = 4;
  printf("A is %d", *a);
  aclear(&arena);
  int *b = aalloc(&arena, sizeof(int));
  *b = 5;
  printf("B is %d", *b);
  
  InitWindow(800, 600, "Test");
  SetTargetFPS(120);

  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Success", 400, 300, 40, BLACK);
    EndDrawing();
  }

  aclear(&arena);
  destroy_arena(arena);
    
  return 0;
}