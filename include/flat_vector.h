#ifndef FLAT_VECTOR
#define FLAT_VECTOR
#include <math.h>

	class FlatVector {
	public:
		FlatVector(float _x, float _y) : x(_x), y(_y) {};
		//~FlatVector();
		FlatVector() {};

		float x;
		float y;

		FlatVector operator+(FlatVector const& obj);

		FlatVector operator-(FlatVector const& obj);

		float operator*(FlatVector const& obj);

		FlatVector operator*(float s);

		float length();

		FlatVector norm();
	};

#endif
