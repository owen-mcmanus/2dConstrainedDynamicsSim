#ifndef RIGIDBODY
#define RIGIDBODY
#include <math.h>
#include "state.h"
#include "euler_solver.h"

class Rigidbody {
public:
	Rigidbody() {  };
	virtual void addGravityForce() {};
	virtual void stepSimulationEuler() {};
};

#endif