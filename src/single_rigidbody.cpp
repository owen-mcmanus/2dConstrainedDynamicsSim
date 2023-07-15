#include "../include/single_rigidbody.h"
#include "../include/gravity_fg.h" 
#include <iostream>

SingleRigidbody::SingleRigidbody(std::string _name, bool fixed) {
	state = State(fixed);
	name = _name;
}

void SingleRigidbody::addGravityForce() {
	GravityFg::calculate(&state);
}

void SingleRigidbody::stepSimulationEuler(double dt) {
	EulerSolver::solve(&state, dt);
}

void SingleRigidbody::stepSimulationRK4(double dt) {
	EulerSolver::solve(&state, dt);
}