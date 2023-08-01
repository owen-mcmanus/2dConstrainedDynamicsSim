#ifndef CONSTRAINTS
#define CONSTRAINTS

#include "single_rigidbody.h"
#include "martrix.h"
#include "gaussian_elimination.h"

class Constraints {
public:
	Constraints() {};
	static void calculateCircleConst(SingleRigidbody* rb);
	static void calculateRigidSpringConst(SingleRigidbody* rb, SingleRigidbody* rb1);
	static void createMatrices();
	static void Constraints::calculate();

	static void addCircleConstraint(SingleRigidbody* rb);

	//static Matrix w;
};

#endif // !SPRING_FG
