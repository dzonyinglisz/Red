#include "main_view.h"

#include <string>
#include <raylib.h>
#include <raygui.h>
#include <thread>
#include <iostream>

void MainGameView::loadTextures()
{
    Image officeViewImg = LoadImage("assets/officeview.png");
    if (officeViewImg.width < 10)
    {

        TraceLog(LOG_FATAL, "Texture didn't load TwT");
        throw;
    }
    officeView = LoadTextureFromImage(officeViewImg);
    if (officeView.width < 10)
    {
        TraceLog(LOG_FATAL, "Texture didn't load TwT");
        throw;
    }
    UnloadImage(officeViewImg);
    TraceLog(LOG_DEBUG, "Load OK!");
}

void MainGameView::drawUi()
{
    int tempNightMinutes = 186; // 3am

    std::string hourText = std::to_string(tempNightMinutes / 60);
    if (tempNightMinutes < 60)
        hourText += "PM";
    else
        hourText += "AM";

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

void MainGameView::drawOfficeUi()
{
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth() / GetWindowScaleDPI().x),
        static_cast<float>(GetScreenHeight() / GetWindowScaleDPI().y)};

    // cameras and mask buttons
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        officeBtnOffset,
        SCREEN_SIZE.y - officeBtnSize.y - (officeBtnOffset * 0.5f),
        officeBtnSize.x,
        officeBtnSize.y};
    const Rectangle maskBtnBoundBox = {
        SCREEN_SIZE.x - officeBtnOffset - officeBtnSize.x,
        SCREEN_SIZE.y - officeBtnSize.y - (officeBtnOffset * 0.5f),
        officeBtnSize.x,
        officeBtnSize.y};

    if (GuiButton(cameraBtnBoundBox, "CAM BUTTON"))
    {
        current_state = UiState::CAMERAS;
    }
    if (GuiButton(maskBtnBoundBox, "MASK BUTTON"))
    {
        current_state = UiState::MASK;
    }
    DrawTexture(officeView, 100, 100, WHITE);
}
void MainGameView::drawCamerasUi()
{
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth() / GetWindowScaleDPI().x),
        static_cast<float>(GetScreenHeight() / GetWindowScaleDPI().y)};

    const Rectangle cameraMapGui = {
        SCREEN_SIZE.x - (SCREEN_SIZE.x / 3) - 4,
        SCREEN_SIZE.y - (SCREEN_SIZE.x / 3) - 4,
        SCREEN_SIZE.x / 3, SCREEN_SIZE.x / 3};
    DrawRectangleRec(cameraMapGui, WHITE);
    const Vector2 buttonsOrigin = {cameraMapGui.x, cameraMapGui.y};
    const Vector2 camButtonSize = {100.0f, 30.0f};
    const Rectangle camButtons[14] = {
        (Rectangle){buttonsOrigin.x, buttonsOrigin.y, camButtonSize.x, camButtonSize.y},
        (Rectangle){buttonsOrigin.x + 105.0f, buttonsOrigin.y, camButtonSize.x, camButtonSize.y},
        (Rectangle){buttonsOrigin.x, buttonsOrigin.y + 35.0f, camButtonSize.x, camButtonSize.y},
    };
    for (int i = 0; i < 14; i++)
    {
        std::string name = "CAM A" + std::to_string(i);
        if (GuiButton(camButtons[i], name.c_str()))
        {
            current_cam = i;
        }
    }

    // DEBUG
    DrawText(
        std::to_string(current_cam).c_str(),
        SCREEN_SIZE.x / 2, SCREEN_SIZE.y / 2,
        20, WHITE);

    // Back to office button
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        officeBtnOffset,
        SCREEN_SIZE.y - officeBtnSize.y - (officeBtnOffset * 0.5f),
        officeBtnSize.x,
        officeBtnSize.y};
    if (GuiButton(cameraBtnBoundBox, "OFFICE BUTTON"))
    {
        current_state = UiState::OFFICE;
    }
}

void MainGameView::drawMaskUi()
{
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth() / GetWindowScaleDPI().x),
        static_cast<float>(GetScreenHeight() / GetWindowScaleDPI().y)};

    // Back to office button
    const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
    const float officeBtnOffset = officeBtnSize.x * 0.1f;
    const Rectangle cameraBtnBoundBox = {
        SCREEN_SIZE.x - officeBtnOffset - officeBtnSize.x,
        SCREEN_SIZE.y - officeBtnSize.y - (officeBtnOffset * 0.5f),
        officeBtnSize.x,
        officeBtnSize.y};
    if (GuiButton(cameraBtnBoundBox, "OFFICE BUTTON"))
    {
        current_state = UiState::OFFICE;
    }
}