#include "../include/constraints.h"

void Constraints::calculateCircleConst(SingleRigidbody* rb) {
	double lambda = (-1 * (rb->state.f * rb->state.p) - (rb->state.mass * (rb->state.v * rb->state.v))) / (rb->state.p * rb->state.p);
	rb->state.f = rb->state.f + (rb->state.p * lambda);
}

void Constraints::calculateRigidSpringConst(SingleRigidbody* rb, SingleRigidbody* rb1) {
	FlatVector dist = FlatVector(rb->state.p.x - rb1->state.p.x, rb->state.p.y - rb1->state.p.y);
	FlatVector rel_v = FlatVector(rb->state.v.x - rb1->state.v.x, rb->state.v.y - rb1->state.v.y);
	double n = (rb->state.mass)*(-1*(rel_v*rel_v)+((rb1->state.f*dist)/rb1->state.mass)-((rb->state.f * dist)/rb->state.mass))*(rb1->state.mass);
	double d = rb1->state.mass * (dist * dist) + rb->state.mass * (dist * dist);
	double lamba = (n/d);
}