#include "../include/spring_fg.h" 
#include "../include/flat_vector.h"
#include <iostream>

void SpringFg::calculate(SingleRigidbody* rb, SingleRigidbody* rb1, double k) {
	//double f_mag = k*(state->p - state1->p).length();
	//FlatVector force = (state->p - state1->p).norm()*f_mag;
	FlatVector force = (rb->state.p - rb1->state.p)*k;

	rb->state.f = rb->state.f - force;
	rb1->state.f = rb1->state.f + force;
}