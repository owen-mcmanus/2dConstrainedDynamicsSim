#ifndef SINGLE_RIGIDBODY
#define SINGLE_RIGIDBODY

#include <math.h>
#include <string>
#include "state.h"
#include "euler_solver.h"
#include <vector>
#include "constraint.h"

class SingleRigidbody {
public:
	SingleRigidbody() {};
	SingleRigidbody(std::string _name, bool fixed);
	State state;
	void addGravityForce();
	void stepSimulationEuler(double dt);
	void stepSimulationRK4(double dt, void (*applyForces)());
	void reset();

	std::string name = "";
	static std::vector<SingleRigidbody*> rb_list;
	std::vector<Constraint*> constraint_list;

};

#endif