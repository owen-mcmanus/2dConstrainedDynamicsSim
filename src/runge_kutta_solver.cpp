#include "../include/runge_kutta_solver.h"
#include "../include/state.h"

void RungeKuttaSolver::solve(State* system, double dt) {
	if (!system->is_fixed) {
		system->a = system->f * (1 / system->mass);

		FlatVector k1p = system->v;
		FlatVector k2p = system->v + system->a * (dt / 2);
		FlatVector k3p = system->v + system->a * (dt / 2);
		FlatVector k4p = system->v + system->a * dt;

		system->v = system->v + (system->a * dt );
		system->p = system->p + ((k1p + k2p * 2 + k3p * 2 + k4p) * (dt / 6));
	}
}