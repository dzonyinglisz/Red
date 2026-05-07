#pragma once
#include <raylib.h>
#include <raygui.h>
#include "game/src/mechanics/time.h"

enum class UiState
{
    CLEAR,

    // MENU STATES
    MAIN_MENU,
    GAME_OVER,
    WIN_SCREEN,

    // GAMEPLAY STATES
    OFFICE,
    CAMERAS,
    MASK,
};

class MainGameView
{
public:
    UiState current_state = UiState::OFFICE;
    TimeKeeper *timeKeeper;
    int current_cam = 0;
    void loadTextures();
    Texture officeView;
    Texture maskView;
    void drawUi();

private:
    void drawOfficeUi();
    void drawCamerasUi();
    void drawMaskUi();
};