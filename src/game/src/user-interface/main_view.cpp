#include "main_view.h"

#include <string>
#include <raylib.h>
#include <raygui.h>


void MainGameView::drawUi() {
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

    // cameras and mask buttons
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle officeBtnBoundingBox = {
        officeBtnOffset,
        SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
        officeBtnSize.x,
        officeBtnSize.y
    };
    
    if (GuiButton(officeBtnBoundingBox, "CAM BUTTON")){
        current_state = UiState::CAMERAS;
    }
    GuiButton(
        (Rectangle){
            SCREEN_SIZE.x-officeBtnOffset-officeBtnSize.x,
            SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
            officeBtnSize.x,
            officeBtnSize.y
        }, 
        "MASK BUTTON");
}
void MainGameView::drawCamerasUi() {

}
void MainGameView::drawMaskUi() {

}