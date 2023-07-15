#ifndef SINGLE_RIGIDBODY
#define SINGLE_RIGIDBODY
#include <math.h>
#include "state.h"
#include "euler_solver.h"
#include "rigidbody.h"

class SingleRigidbody:Rigidbody {
public:
	SingleRigidbody(bool fixed);
	State state;
	void addGravityForce();
	void stepSimulationEuler();
};

#endif