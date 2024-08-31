#include <iostream>
#include <raylib.h>

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

class Food {
  Texture2D texture;
  Vector2 position;

  public:
    Food() 
    {
      Image image = LoadImage("food.png");
      texture = LoadTextureFromImage(image);
      UnloadImage(image);
      position = GenerateRandomPos();
    }

    ~Food()
    {
      UnloadTexture(texture);
    }

    void Draw()
    {
      DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
      float x = GetRandomValue(0, cellCount - 1);
      float y = GetRandomValue(0, cellCount - 1);
      return Vector2{x, y};
    };
};

int main()
{
  std::cout << "Starting the game..." << std::endl;
  InitWindow(cellSize*cellCount, cellSize*cellCount, "Retro Snake");
  SetTargetFPS(60);

  Food food = Food();

  while(WindowShouldClose() == false)
  {
    BeginDrawing();

    ClearBackground(green);
    food.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
