#include "../include/double_rigidbody.h"
#include "../include/gravity_fg.h" 
#include <iostream>
#include "../include/spring_fg.h"

DoubleRigidbody::DoubleRigidbody(bool fixed, bool fixed1) {
	state = State(fixed);
	state1 = State(fixed1);
}

void DoubleRigidbody::addGravityForce() {
	GravityFg::calculate(&state);
	GravityFg::calculate(&state1);
}

void DoubleRigidbody::addSpringForce(float k) {
	SpringFg::calculate(&state, &state1, k);
}

void DoubleRigidbody::stepSimulationEuler() {
	//RungeKuttaSolver::solve(&state);
	//RungeKuttaSolver::solve(&state1);
	EulerSolver::solve(&state);
	EulerSolver::solve(&state1);
	std::cout <<"1: " << state.p.x << " " << state.p.y << std::endl;
	std::cout <<"2: " << state1.p.x << " " << state1.p.y << std::endl;
}

void DoubleRigidbody::reset() {
	state.f = state.f * 0;
	state1.f = state1.f * 0;
}