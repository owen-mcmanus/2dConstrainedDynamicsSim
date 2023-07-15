#ifndef SPRING_FG
#define SPRING_FG

#include "force_generator.h"
#include "single_rigidbody.h"

class SpringFg : public ForceGenerator {
public:
	SpringFg(){};
	static void calculate(SingleRigidbody* rb, SingleRigidbody* rb1, double k);

};

#endif // !SPRING_FG
