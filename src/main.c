#include <raylib.h>

int main(int argc, char **argv)
{
  InitWindow(800, 600, "Test");
  SetTargetFPS(120);

  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Success", 400, 300, 40, BLACK);
    EndDrawing();
  }
    
  return 0;
}