#pragma once


enum class UiState {
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

class MainGameView {
public:
    UiState current_state = UiState::OFFICE;
    int current_cam = 0;

    void drawUi();

private:
    void drawOfficeUi();
    void drawCamerasUi();
    void drawMaskUi();
};