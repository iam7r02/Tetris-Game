#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;

}

int main () {
    InitWindow(500,620,"raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while(WindowShouldClose() == false){

        UpdateMusicStream(game.music);
        game.HandleInput();
        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {323, 450}, 28, 2, WHITE);
            SetAudioStreamVolume(game.music.stream, 0);
        }
        else if (game.score >= 6000){
            DrawTextEx(font, "STAGE 6", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.15)){
            game.MoveBlockDown();
        }
        }
        
        else if (game.score >= 5000){
            DrawTextEx(font, "STAGE 5", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
            
        }
        else if (game.score >= 4000){
            DrawTextEx(font, "STAGE 4", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.25)){
            game.MoveBlockDown();
        }
        }

        else if (game.score >= 1500){
            DrawTextEx(font, "STAGE 3", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.3)){
            game.MoveBlockDown();
        }
        }

        else if (game.score >= 500){
            DrawTextEx(font, "STAGE 2", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.4)){
            game.MoveBlockDown();
        }
        }
        
        else{
            DrawTextEx(font, "STAGE 1", {345, 450}, 28, 2, WHITE);
            if(EventTriggered(0.5)){
            game.MoveBlockDown();
        }
        }

        



/*
        if(EventTriggered(0.4)){
            game.MoveBlockDown();
        }
*/
        



        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {353, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {363, 175}, 38, 2, WHITE);
        
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);


        DrawTextEx(font, scoreText, {300 +(170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();

    }

    CloseWindow();   
}