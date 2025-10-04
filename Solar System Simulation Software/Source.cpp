#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include<raygui.h>
#include <cmath>
#include<iostream>
int main() {
    const int screenWidth = 1600;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Solar system");
             
    //Planet variables
    float Ex = 0, Mx = 0, Vx = 0, Ma_x = 0, Ju_x = 0, Sx = 0, Ux = 0, Nx = 0;
    //Gui Elements Bool
    bool drawWires = false;
    bool drawOrbits = false;
    float sliderValue;
    Color VENUS_COLOR = (Color){ 245, 222, 179, 255 }; // light yellow / wheat color
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
       BeginDrawing();
       ClearBackground(BLACK);

       //planet angular speed (radians per frame ~ scaled)
       Ex   += 0.0172f;   // Earth
       Mx   += 0.0714f;   // Mercury
       Vx   += 0.0279f;   // Venus
       Ma_x += 0.00915f;  // Mars
       Ju_x += 0.00145f;  // Jupiter
       Sx   += 0.000584f; // Saturn
       Ux   += 0.000205f; // Uranus
       Nx   += 0.000104f; // Neptune
           // orbit radii (scaled so they fit in 800x800)
    float config[8];
    config[0] = 80.0f+sliderValue;   // Mercury
    config[1] = 120.0f+sliderValue;  // Venus
    config[2] = 160.0f+sliderValue;  // Earth
    config[3] = 200.0f+sliderValue;  // Mars
    config[4] = 260.0f+sliderValue;  // Jupiter
    config[5] = 320.0f+sliderValue;  // Saturn
    config[6] = 380.0f+sliderValue;  // Uranus
    config[7] = 430.0f+sliderValue;  // Neptune
       // reset angles when > 2π
       if (Ex   >= 2*PI) Ex = 0.0f;
       if (Mx   >= 2*PI) Mx = 0.0f;
       if (Vx   >= 2*PI) Vx = 0.0f;
       if (Ma_x >= 2*PI) Ma_x = 0.0f;
       if (Ju_x >= 2*PI) Ju_x = 0.0f;
       if (Sx   >= 2*PI) Sx = 0.0f;
       if (Ux   >= 2*PI) Ux = 0.0f;
       if (Nx   >= 2*PI) Nx = 0.0f;

       // planet coordinates
       float M_X  = cos(Mx)   * config[0] + screenWidth/2;
       float M_Y  = sin(Mx)   * config[0] + screenHeight/2;

       float V_X  = cos(Vx)   * config[1] + screenWidth/2;
       float V_Y  = sin(Vx)   * config[1] + screenHeight/2;

       float E_X  = cos(Ex)   * config[2] + screenWidth/2;
       float E_Y  = sin(Ex)   * config[2] + screenHeight/2;

       float Ma_X = cos(Ma_x) * config[3] + screenWidth/2;
       float Ma_Y = sin(Ma_x) * config[3] + screenHeight/2;

       float Ju_X = cos(Ju_x) * config[4] + screenWidth/2;
       float Ju_Y = sin(Ju_x) * config[4] + screenHeight/2;

       float S_X  = cos(Sx)   * config[5] + screenWidth/2;
       float S_Y  = sin(Sx)   * config[5] + screenHeight/2;

       float U_X  = cos(Ux)   * config[6] + screenWidth/2;
       float U_Y  = sin(Ux)   * config[6] + screenHeight/2;

       float N_X  = cos(Nx)   * config[7] + screenWidth/2;
       float N_Y  = sin(Nx)   * config[7] + screenHeight/2;

       // draw Sun
       DrawCircle(screenWidth/2, screenHeight/2, 40+sliderValue/2, YELLOW);
        //GUI Feutures
         if (GuiButton(Rectangle{20, screenHeight-50, 100, 40}, "Wires")) {
            drawWires = !drawWires;
        }
          GuiSlider(
            (Rectangle){ 20, screenHeight - 100, 200, 25 },
            "Min", "Max",
            &sliderValue,
            0.0f, 100.0f
        );
        if (GuiButton(Rectangle{20, screenHeight-150, 100, 40}, "orbits")) {
            drawOrbits = !drawOrbits;
        }
        DrawText("offset",230,screenHeight-100,20,WHITE);
        //Distance of each planets from the sun
        float d_mercury =config[0];
        float d_venus =  config[1];
        float d_earth =  config[2];
        float d_mars =   config[3];
        float d_jupiter= config[4];
        float d_saturn = config[5];
        float d_uranus = config[6];
        float d_neptune =config[7];
        
   
        if(drawWires){
            DrawLine(screenWidth/2,screenHeight/2,M_X,M_Y,RED);
            DrawLine(screenWidth/2,screenHeight/2,V_X,V_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,E_X,E_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,Ma_X,Ma_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,Ju_X,Ju_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,S_X,S_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,U_X,U_Y,GREEN);
            DrawLine(screenWidth/2,screenHeight/2,N_X,N_Y,GREEN);
        }
        
        if(drawOrbits){
            DrawCircleLines(screenWidth/2,screenHeight/2,d_mercury,WHITE);
            DrawCircleLines(screenWidth/2,screenHeight/2,d_venus,WHITE);
             DrawCircleLines(screenWidth/2,screenHeight/2,d_earth,WHITE);
            DrawCircleLines(screenWidth/2,screenHeight/2,d_mars,WHITE);
             DrawCircleLines(screenWidth/2,screenHeight/2,d_jupiter,WHITE);
            DrawCircleLines(screenWidth/2,screenHeight/2,d_saturn,WHITE);
             DrawCircleLines(screenWidth/2,screenHeight/2,d_uranus,WHITE);
            DrawCircleLines(screenWidth/2,screenHeight/2,d_neptune,WHITE);
        }
        if(IsKeyDown(KEY_F11)){ToggleFullscreen();} 
// draw planets        
       DrawCircle(M_X, M_Y, 5+sliderValue/64, RED);          // Mercury
       DrawCircle(V_X, V_Y, 6+sliderValue/64, VENUS_COLOR);  // Venus
       DrawCircle(E_X, E_Y, 7+sliderValue/64, BLUE);         // Earth
       DrawCircle(Ma_X, Ma_Y, 6+sliderValue/64, ORANGE);     // Mars
       DrawCircle(Ju_X, Ju_Y, 10+sliderValue/64, BROWN);     // Jupiter
       DrawCircle(S_X, S_Y, 9+sliderValue/64, GRAY);         // Saturn
       DrawCircle(U_X, U_Y, 8+sliderValue/64, SKYBLUE);      // Uranus
       DrawCircle(N_X, N_Y, 8+sliderValue/64, DARKBLUE);     // Neptune

       EndDrawing();
    }

    CloseWindow();
    return 0;
}
