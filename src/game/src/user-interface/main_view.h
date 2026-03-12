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

    void drawUi();

private:
    void drawOfficeUi();
    void drawCamerasUi();
    void drawMaskUi();
};