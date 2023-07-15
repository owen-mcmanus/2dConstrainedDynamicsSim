#include "../include/single_rigidbody.h"
#include "../include/gravity_fg.h" 
#include <iostream>

SingleRigidbody::SingleRigidbody(bool fixed) {
	state = State(fixed);
}

void SingleRigidbody::addGravityForce() {
	GravityFg::calculate(&state);
}

void SingleRigidbody::stepSimulationEuler() {
	EulerSolver::solve(&state);
	std::cout << state.p.x << " " << state.p.y << std::endl;
}