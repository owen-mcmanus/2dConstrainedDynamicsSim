#ifndef SPRING_FG
#define SPRING_FG

#include "force_generator.h"
#include "state.h"

class SpringFg : public ForceGenerator {
public:
	SpringFg(){};
	static void calculate(State* state, State* state1, double k);

};

#endif // !SPRING_FG
