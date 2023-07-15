#ifndef DOUBLE_RIGIDBODY
#define DOUBLE_RIGIDBODY

#include <math.h>
#include <string>
#include "state.h"
#include "euler_solver.h"
#include "runge_kutta_solver.h"
#include "rigidbody.h"


class DoubleRigidbody : Rigidbody {
public:
	DoubleRigidbody(std::string _name, bool fixed, bool fixed1);
	State state;
	State state1;
	void addGravityForce();
	void addSpringForce(double k);
	void stepSimulationEuler(double dt);
	void stepSimulationRK4(double dt);
	void reset();

	std::string name = "";
};

#endif