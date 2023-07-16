#include "../include/runge_kutta_solver.h"
#include "../include/state.h"
#include <iostream>
#include "../include/single_rigidbody.h"

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

void RungeKuttaSolver::solve(double dt, void (*applyForces)()){
	const double len = SingleRigidbody::rb_list.size();
	std::vector <FlatVector> vi;
	std::vector <FlatVector> pi;

	std::vector <State> accumulator;
	for (int n = 0; n < len; n++) {
		vi.push_back(FlatVector(SingleRigidbody::rb_list[n]->state.v.x, SingleRigidbody::rb_list[n]->state.v.y));
		pi.push_back(FlatVector(SingleRigidbody::rb_list[n]->state.p.x, SingleRigidbody::rb_list[n]->state.p.y));

		accumulator.push_back(State(true));
		accumulator[n].v = FlatVector(SingleRigidbody::rb_list[n]->state.v.x, SingleRigidbody::rb_list[n]->state.v.y);
		accumulator[n].p = FlatVector(SingleRigidbody::rb_list[n]->state.p.x, SingleRigidbody::rb_list[n]->state.p.y);
	}

	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < len; n++) {
			SingleRigidbody::rb_list[n]->state.f.x = 0;
			SingleRigidbody::rb_list[n]->state.f.y = 0;
		}
		if (i == 0) {
			applyForces();
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.a = SingleRigidbody::rb_list[n]->state.f * (1 / SingleRigidbody::rb_list[n]->state.mass);
				accumulator[n].v = accumulator[n].v + (SingleRigidbody::rb_list[n]->state.a * (dt / 6));
				accumulator[n].p = accumulator[n].p + (SingleRigidbody::rb_list[n]->state.v * (dt / 6));
			}
		}
		if (i == 1 || i == 2) {
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.v = vi[n] + (SingleRigidbody::rb_list[n]->state.a * (dt / 2));;
				SingleRigidbody::rb_list[n]->state.p = pi[n] + (SingleRigidbody::rb_list[n]->state.v * (dt / 2));
			}
			applyForces();
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.a = SingleRigidbody::rb_list[n]->state.f * (1 / SingleRigidbody::rb_list[n]->state.mass);
				accumulator[n].v = accumulator[n].v + (SingleRigidbody::rb_list[n]->state.a * (2 * dt / 6));
				accumulator[n].p = accumulator[n].p + (SingleRigidbody::rb_list[n]->state.v * (2 * dt / 6));
			}
		}
		if (i == 3) {
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.v = vi[n] + (SingleRigidbody::rb_list[n]->state.a * dt);;
				SingleRigidbody::rb_list[n]->state.p = pi[n] + (SingleRigidbody::rb_list[n]->state.v * dt);
			}
			applyForces();
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.a = SingleRigidbody::rb_list[n]->state.f * (1 / SingleRigidbody::rb_list[n]->state.mass);
				accumulator[n].v = accumulator[n].v + (SingleRigidbody::rb_list[n]->state.a * (dt / 6));
				accumulator[n].p = accumulator[n].p + (SingleRigidbody::rb_list[n]->state.v * (dt / 6));
			}
			for (int n = 0; n < len; n++) {
				SingleRigidbody::rb_list[n]->state.v = accumulator[n].v;
				SingleRigidbody::rb_list[n]->state.p = accumulator[n].p;
			}
		}
	}
}