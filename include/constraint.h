#ifndef CONSTRAINT
#define CONSTRAINT
#include "../include/martrix.h"

class Constraint {
public:
	Constraint() {
		j = Matrix();
		jdot = Matrix();
	};
	Matrix j;
	Matrix jdot;
};

#endif // !SPRING_FG
