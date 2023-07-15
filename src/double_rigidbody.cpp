#include "../include/double_rigidbody.h"
#include "../include/gravity_fg.h" 
#include <iostream>
#include "../include/spring_fg.h"

DoubleRigidbody::DoubleRigidbody(std::string _name, bool fixed, bool fixed1) {
	state = State(fixed);
	state1 = State(fixed1);
	name = _name;
}

void DoubleRigidbody::addGravityForce() {
	GravityFg::calculate(&state);
	GravityFg::calculate(&state1);
}

void DoubleRigidbody::addSpringForce(double k) {
	SpringFg::calculate(&state, &state1, k);
}

void DoubleRigidbody::stepSimulationEuler(double dt) {
	EulerSolver::solve(&state, dt);
	EulerSolver::solve(&state1, dt);
}

void DoubleRigidbody::stepSimulationRK4(double dt) {
	RungeKuttaSolver::solve(&state, dt);
	RungeKuttaSolver::solve(&state1, dt);
}

void DoubleRigidbody::reset() {
	state.f = state.f * 0;
	state1.f = state1.f * 0;
}