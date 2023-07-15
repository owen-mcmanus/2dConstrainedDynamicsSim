#ifndef SYSTEM_STATE
#define SYSTEM_STATE

#include "flat_vector.h"

	class State {
	public:
		State() {};
		State(bool fixed);
		//~SystemState();

		FlatVector p;
		FlatVector v;
		FlatVector a;

		float mass;
		bool is_fixed;

		FlatVector f;
		
	};

#endif
