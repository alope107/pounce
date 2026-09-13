#pragma once

#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>

class timer {
    public:
        timer(int start_frames);
        int frames_left();
        void update();
    private:
        int _frames_left;
        bn::vector<bn::sprite_ptr, 4> _num_sprs;
        bn::sprite_text_generator _text_gen;
        void _draw_text();
};