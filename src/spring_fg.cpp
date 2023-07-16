#include "../include/spring_fg.h" 
#include "../include/flat_vector.h"
#include <iostream>

void SpringFg::calculate(SingleRigidbody* rb, SingleRigidbody* rb1, double k_s, double k_d,double rest_len) {
	double length = (rb->state.p - rb1->state.p).length();
	double spring_v = ((rb->state.p.x-rb1->state.p.x) / length) * (rb->state.p.x - rb1->state.p.x)* (rb->state.v.x - rb1->state.v.x) + ((rb->state.p.y - rb1->state.p.y) / length) * (rb->state.p.y - rb1->state.p.y) * (rb->state.v.y - rb1->state.v.y);
	double f_mag = k_s*(length-rest_len)-(k_d*spring_v);
	//double f_mag = k_s * length * (1 - rest_len) - (k_d * spring_v);
	FlatVector force = (rb->state.p - rb1->state.p).norm()*f_mag;
	//FlatVector force = (rb->state.p - rb1->state.p)*k;

	rb->state.f = rb->state.f - force;
	rb1->state.f = rb1->state.f + force;
}