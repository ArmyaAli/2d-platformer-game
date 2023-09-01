#include "raylib.h"

typedef struct _Ball {
  Vector2 pos;
  Vector2 vel;
  Vector2 acc;
  float radius;
} Ball;

const int screenWidth  = 800;
const int screenHeight = 450;

int main(void) {

    InitWindow(screenWidth, screenHeight, "2D Platformer Game");
    SetTargetFPS(60);               

    Ball ball;
    init(&ball); 
    float acc = 0.0f;
    while (!WindowShouldClose()) {
        
        float dt = GetFrameTime();
        printf("dt: %f acc: %f\n", dt, acc);

        acc += dt;
        handleKeypress(&ball);

        if (ball.pos.y <=screenHeight-ball.radius) ball.pos.y += ball.acc.y;

        BeginDrawing();
        ClearBackground(RAYWHITE);  
        DrawText("hello", 10, 10, 20, DARKGRAY);
        DrawCircleV(ball.pos, ball.radius, MAROON);
        EndDrawing();
    }

    return 0;
}

void init(Ball* ball) { 
   ball->pos = (Vector2){ (float) screenWidth / 2, (float) screenHeight / 2 };  
   ball->vel = (Vector2){ 0.0f, 0.0f };  
   ball->acc = (Vector2){0.0f, 10.0f};
   ball->radius = 50;
}

void handleKeypress(Ball* ball) {
    float xMax = screenWidth - ball->radius;
    float xMin = 0 + ball->radius;
    float yMax = screenHeight - ball->radius; 
    float yMin = 0 + ball->radius;

    if (IsKeyDown(KEY_RIGHT) && ball->pos.x <= xMax) ball->pos.x += 2.0f; 
    if (IsKeyDown(KEY_LEFT) && ball->pos.x >= xMin)  ball->pos.x -= 2.0f;  
    if (IsKeyDown(KEY_UP) && ball->pos.y >= yMin)    ball->pos.y -= 20.0f; 
    if (IsKeyDown(KEY_DOWN) && ball->pos.y <= yMax)  ball->pos.y += 20.0f; 
    if (IsKeyDown(KEY_SPACE)) ball->pos.y -= 10.0f;
}
