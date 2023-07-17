#ifndef CONSTRAINTS
#define CONSTRAINTS

#include "single_rigidbody.h"

class Constraints {
public:
	Constraints() {};
	static void calculateCircleConst(SingleRigidbody* rb);
	static void calculateRigidSpringConst(SingleRigidbody* rb, SingleRigidbody* rb1);
};

#endif // !SPRING_FG
