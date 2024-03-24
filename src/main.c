#include <raylib.h>
#include "aalloc.h"
#include "player.h"

// Function to display main menu
void displayMainMenu();

int main(int argc, char **argv)
{
  // Initialize window and arena
  InitWindow(800, 600, "Hogwarts Hobo");
  SetTargetFPS(120);

  // Main loop flag
  bool inMainMenu = true;

  // Main menu loop
  while (inMainMenu)
  {
    // Display main menu
    displayMainMenu();

    // Check for button click events
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      // Get mouse position
      Vector2 mousePoint = GetMousePosition();

      // Check if "Play" button is clicked
      if (CheckCollisionPointRec(mousePoint, (Rectangle){100, 200, 200, 50}))
      {
        // Enter arena
        inMainMenu = false;

        // Arena code
        Arena arena = create_arena(sizeof(Player) * 2);
        Player *player = create_player(&arena, (Vector2){.x = 0, .y = 0});

        // Health bar variables
        DrawText("HP:", 550, 10, 20, BLACK);
        Rectangle healthBar = {600, 10, 200, 20};

        Color healthColor = GREEN;

        // Arena loop
        while (!WindowShouldClose())
        {
          update_player(player, GetFrameTime());

          // Update health bar
          healthBar.width = (float)player->health * 2; // Scale the width of the bar according to health
          if (player->health < 30)
            healthColor = RED; // Change color if health is low
          else
            healthColor = GREEN;

          BeginDrawing();
          ClearBackground(RAYWHITE);

          // Draw health bar
          DrawText("HP:", 550, 10, 20, BLACK);
          DrawRectangleRec(healthBar, healthColor);
          DrawRectangleLinesEx(healthBar, 2, BLACK); // Draw border for health bar

          // Draw player
          draw_player(player);

          EndDrawing();
        }

        // Clean up
        aclear(&arena);
        destroy_arena(arena);
      }
      // Check if "Instructions" button is clicked
      else if (CheckCollisionPointRec(mousePoint, (Rectangle){100, 300, 200, 50}))
      {
        // Display instructions screen
        // (Currently left blank)
      }
    }
  }

  CloseWindow();
  return 0;
}

// Function to display main menu
void displayMainMenu()
{
  BeginDrawing();
  ClearBackground(RAYWHITE);

  // Draw title
  DrawText("Hogwarts Hobo", 100, 100, 40, BLACK);

  // Draw "Play" button
  DrawRectangle(100, 200, 200, 50, BLUE);
  DrawText("Play", 155, 210, 30, WHITE);

  // Draw "Instructions" button
  DrawRectangle(100, 300, 200, 50, GREEN);
  DrawText("Instructions", 125, 310, 20, WHITE);

  EndDrawing();
}
