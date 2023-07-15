#ifndef RUNGE_KUTTA_SOLVER
#define RUNGE_KUTTA_SOLVER

#include "state.h"

class RungeKuttaSolver {
public:
	RungeKuttaSolver() {};
	//~SystemState();

	static void solve(State* system);

};

#endif