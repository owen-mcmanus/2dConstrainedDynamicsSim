#include "../include/gravity_fg.h" 
#include <iostream>


void GravityFg::calculate(SingleRigidbody *rb) {
	rb->state.f.y =rb->state.f.y - rb->state.mass * 9.81f;
}