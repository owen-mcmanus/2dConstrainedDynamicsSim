#include "../include/gravity_fg.h" 
#include "../include/state.h"
#include <iostream>

void GravityFg::calculate(State *state) {
	state->f.y = state->f.y - state-> mass * 9.81f;
}