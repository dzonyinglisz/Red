#include "main_view.h"

#include <string>
#include <raylib.h>
#include <raygui.h>
#include <thread>
#include <iostream>

void MainGameView::loadTextures()
{
    Image maskViewImg = LoadImage("assets/maskview.png");
    Image officeViewImg = LoadImage("assets/officeview.png");
    maskView = LoadTextureFromImage(maskViewImg);
    officeView = LoadTextureFromImage(officeViewImg);
    UnloadImage(officeViewImg);
    UnloadImage(maskViewImg);

    // procedular
    noisePixels = (Color *)malloc(320 * 256 * sizeof(Color));
    Image whitenoise = GenImageWhiteNoise(320, 256, 3.0f);
    cameraNoise = LoadTextureFromImage(whitenoise);
}

void MainGameView::drawUi()
{
    if (current_state == UiState::OFFICE)
        DrawTextureEx(officeView, {0, 0}, 0.0f, 3.0f, WHITE);
    else if (current_state == UiState::MASK)
        DrawTextureEx(maskView, {0, 0}, 0.0f, 3.0f, WHITE);

    int timeRounded = timeKeeper->time;
    std::string hourText = std::to_string(timeRounded / 60);
    if (timeRounded < 60)
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
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())};

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
}
void MainGameView::drawCamerasUi()
{
    for (int i = 0; i < 320 * 256; ++i)
    {
        unsigned char v = rand() & 0xFF; // 0-255
        noisePixels[i].r = v;
        noisePixels[i].g = v;
        noisePixels[i].b = v;
        noisePixels[i].a = 255;
    }
    // push pixels to GPU
    UpdateTexture(cameraNoise, noisePixels);
    DrawTextureEx(cameraNoise, {0, 0}, 0.0f, 3.0f, WHITE);
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())};

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
    const char *camText = TextFormat("CAM %s", std::to_string(current_cam).c_str());
    DrawRectangle(SCREEN_SIZE.x / 2, SCREEN_SIZE.y / 2, MeasureText(camText, 20), 20, BLACK);
    DrawText(
        camText,
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
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())};

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