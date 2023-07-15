#include "../include/runge_kutta_solver.h"
#include "../include/state.h"
#include <iostream>

void RungeKuttaSolver::halfSolve(State* system, double dt) {
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

void RungeKuttaSolver::solve(State* system, double dt, void (*applyForces)()){
	if (!system->is_fixed) {
		FlatVector vi = FlatVector(system->v.x, system->v.y);
		FlatVector pi = FlatVector(system->p.x, system->p.y);

		State accumulator = State(true);
		accumulator.v = FlatVector(system->v.x, system->v.y);
		accumulator.p = FlatVector(system->p.x, system->p.y);

		for (int i = 0; i < 4; i++) {
			system->f.x = 0;
			system->f.y = 0;
			if (i == 0) {
				applyForces();
				system->a = system->f * (1 / system->mass);
				accumulator.v = accumulator.v + (system->a * (dt / 6));
				accumulator.p = accumulator.p + (system->v * (dt / 6));
			}
			if (i == 1 || i == 2) {
				system->v = vi + (system->a * (dt / 2));
				system->p = pi + (system->v * (dt / 2));
				applyForces();
				system->a = system->f * (1 / system->mass);
				accumulator.v = accumulator.v + (system->a * (2 * dt / 6));
				accumulator.p = accumulator.p + (system->v * (2 * dt / 6));
			}
			if (i == 3) {
				system->v = vi + (system->a * dt);
				system->p = pi + (system->v * dt);
				applyForces();
				system->a = system->f * (1 / system->mass);
				accumulator.v = accumulator.v + (system->a * (dt / 6));
				accumulator.p = accumulator.p + (system->v * (dt / 6));
				system->v = accumulator.v;
				system->p = accumulator.p;
			}
		}
	}
}