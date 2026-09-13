#pragma once

#include "game_state.h"

enum GAME_TYPE {
    TITLE_SCREEN,
    FISH_GAME,
    END_SCREEN,
    JUMP_GAME
};

class game {
    public:
        virtual GAME_TYPE update() = 0;
        virtual ~game() = default;
};