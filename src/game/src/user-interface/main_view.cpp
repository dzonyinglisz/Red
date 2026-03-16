#include "main_view.h"

#include <string>
#include <raylib.h>
#include <raygui.h>


void MainGameView::drawUi() {
    int tempNightMinutes = 186; // 3am
        
    std::string hourText = std::to_string(tempNightMinutes / 60);
    if (tempNightMinutes < 60) hourText += "PM"; else hourText += "AM";
    
    
    // Drawing: hour
    int defaultTextSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
        GuiLabel(
            (Rectangle){0, 0, 100, 32},
            hourText.c_str());
    GuiSetStyle(DEFAULT, TEXT_SIZE, defaultTextSize);


    if (current_state == UiState::OFFICE)
        drawOfficeUi();
    else if (current_state == UiState::CAMERAS)
        drawCamerasUi();
    else if (current_state == UiState::MASK)
        drawMaskUi();
}


void MainGameView::drawOfficeUi() {
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };

    // cameras and mask buttons
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        officeBtnOffset,
        SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
        officeBtnSize.x,
        officeBtnSize.y
    };
    const Rectangle maskBtnBoundBox = {
        SCREEN_SIZE.x-officeBtnOffset-officeBtnSize.x,
        SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
        officeBtnSize.x,
        officeBtnSize.y
    };

    if (GuiButton(cameraBtnBoundBox, "CAM BUTTON")){
        current_state = UiState::CAMERAS;
    }
    if (GuiButton(maskBtnBoundBox, "MASK BUTTON")) {
        current_state = UiState::MASK;
    }
}
void MainGameView::drawCamerasUi() {
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };


    const Rectangle cameraMapGui = {
        SCREEN_SIZE.x - (SCREEN_SIZE.x/3) - 4,
        SCREEN_SIZE.y - (SCREEN_SIZE.x/3) - 4,
        SCREEN_SIZE.x/3, SCREEN_SIZE.x/3
    };
    DrawRectangleRec(cameraMapGui, WHITE);


    // Back to office button
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        officeBtnOffset,
        SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
        officeBtnSize.x,
        officeBtnSize.y
    };
    if (GuiButton(cameraBtnBoundBox, "OFFICE BUTTON")){
        current_state = UiState::OFFICE;
    }
}

void MainGameView::drawMaskUi() {
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };

    // Back to office button
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        SCREEN_SIZE.x-officeBtnOffset-officeBtnSize.x,
        SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
        officeBtnSize.x,
        officeBtnSize.y
    };
    if (GuiButton(cameraBtnBoundBox, "OFFICE BUTTON")){
        current_state = UiState::OFFICE;
    }
}