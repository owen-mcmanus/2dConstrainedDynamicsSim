#ifndef EULER_SOLVER
#define EULER_SOLVER

#include "state.h"

	class EulerSolver {
	public:
		EulerSolver() {};
		//~SystemState();

		static void solve(State* system, double dt);

	};

#endif
