#include "../include/euler_solver.h"
#include "../include/state.h"

void EulerSolver::solve(State* system, double dt) {
	if (!system->is_fixed) {
		system->a = system->f * (1 / system->mass);

		//system->p.x += system->v.x * dt;
		//system->p.y += system->v.y * dt;
		system->p = system->p + system->v * dt;

		//system->v.x += system->a.x * dt;
		//system->v.y += system->a.y * dt;
		system->v = system->v + system->a * dt;
	}
}