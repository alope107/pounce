#pragma once

enum GAME_TYPE {
    TITLE_SCREEN,
    FISH_GAME,
    JUMP_GAME
};

class game {
    public:
        virtual GAME_TYPE update() = 0;
        virtual ~game() = default;
};