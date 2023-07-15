#ifndef GRAVITY_FG
#define GRAVITY_FG

#include "force_generator.h"
#include "../include/single_rigidbody.h"

class GravityFg :public ForceGenerator {
public:
	GravityFg(){};
	static void calculate(SingleRigidbody* rb);

};

#endif // !GRAVITY_FG
