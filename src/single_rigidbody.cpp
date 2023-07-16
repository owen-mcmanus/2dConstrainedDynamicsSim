#include "../include/single_rigidbody.h"
#include "../include/gravity_fg.h" 
#include <iostream>
#include "../include/runge_kutta_solver.h"

std::vector<SingleRigidbody*> SingleRigidbody::rb_list;

SingleRigidbody::SingleRigidbody(std::string _name, bool fixed) {
	state = State(fixed);
	name = _name;
	if (!fixed) {
		//rb_list.push_back(this);
	}
}

void SingleRigidbody::addGravityForce() {
	//GravityFg::calculate(&state);
}

void SingleRigidbody::stepSimulationEuler(double dt) {
	EulerSolver::solve(&state, dt);
}

void SingleRigidbody::stepSimulationRK4(double dt, void (*applyForces)()) {
	//RungeKuttaSolver::solve(&state, dt, applyForces);
}

void SingleRigidbody::reset() {
	state.f = state.f * 0;
}