#include "timer.h"

#include <bn_string.h>

#include "fuzzyfont.h"

timer::timer(int start_frames) :
    _frames_left(start_frames),
    _num_sprs(),
    _text_gen(fuzzyfont) {
    _text_gen.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);
}

void timer::_draw_text() {
    _num_sprs.clear();
    _text_gen.generate({-100, 60}, bn::to_string<4>(_frames_left/60), _num_sprs);
}

int timer::frames_left() { return _frames_left; }

void timer::update() {
    if(_frames_left > 0) _frames_left--;
    _draw_text();
}