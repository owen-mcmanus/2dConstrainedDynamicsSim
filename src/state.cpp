#include "../include/state.h"

#include <assert.h>
#include <cstring>
#include <cmath>

State::State(bool fixed) {
	a = FlatVector(0, 0);
	v = FlatVector(0, 0);
	p = FlatVector(0, 0);
	f = FlatVector(0, 0);
	mass = 1;
	is_fixed = fixed;
}

