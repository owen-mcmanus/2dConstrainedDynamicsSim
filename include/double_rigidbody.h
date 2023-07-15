#ifndef DOUBLE_RIGIDBODY
#define DOUBLE_RIGIDBODY
#include <math.h>
#include "state.h"
#include "euler_solver.h"
#include "runge_kutta_solver.h"
#include "rigidbody.h"

class DoubleRigidbody : Rigidbody {
public:
	DoubleRigidbody(bool fixed, bool fixed1);
	State state;
	State state1;
	void addGravityForce();
	void addSpringForce(float k);
	void stepSimulationEuler();
	void reset();
};

#endif