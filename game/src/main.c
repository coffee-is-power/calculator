#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 400;
static const int screenHeight = 600;

void ProcessResult() {
    
}

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    InitWindow(screenWidth, screenHeight, "Calculadora");
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
    char buffer[2000] = {0};
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if(GuiTextBox((Rectangle) {0, 0, GetScreenWidth(), GetScreenHeight()*0.2}, buffer, sizeof(buffer), true)) {
            ProcessResult(buffer, sizeof(buffer));
        }
        EndDrawing();
    }
#endif

    // De-Initialization
    CloseWindow();          // Close window and OpenGL context

    return 0;
}
