#ifndef GRAVITY_FG
#define GRAVITY_FG

#include "force_generator.h"
#include "state.h"

class GravityFg :public ForceGenerator {
public:
	GravityFg(){};
	static void calculate(State* state);

};

#endif // !GRAVITY_FG
