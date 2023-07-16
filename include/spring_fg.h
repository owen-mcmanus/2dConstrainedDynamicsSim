#ifndef SPRING_FG
#define SPRING_FG

#include "force_generator.h"
#include "single_rigidbody.h"

class SpringFg : public ForceGenerator {
public:
	SpringFg(){};
	static void calculate(SingleRigidbody* rb, SingleRigidbody* rb1, double k_s, double k_d, double rest_len);

};

#endif // !SPRING_FG
