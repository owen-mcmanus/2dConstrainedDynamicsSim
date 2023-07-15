#include "../include/spring_fg.h" 
#include "../include/state.h"
#include "../include/flat_vector.h"
#include <iostream>

void SpringFg::calculate(State* state, State* state1, double k) {
	//double f_mag = k*(state->p - state1->p).length();
	//FlatVector force = (state->p - state1->p).norm()*f_mag;
	FlatVector force = (state->p - state1->p)*k;

	state->f = state->f - force;
	state1->f = state1->f + force;
}