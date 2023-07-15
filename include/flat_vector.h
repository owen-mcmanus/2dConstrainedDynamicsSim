#ifndef FLAT_VECTOR
#define FLAT_VECTOR
#include <math.h>

	class FlatVector {
	public:
		FlatVector(double _x, double _y) : x(_x), y(_y) {};
		//~FlatVector();
		FlatVector() {};

		double x;
		double y;

		FlatVector operator+(FlatVector const& obj);

		FlatVector operator-(FlatVector const& obj);

		double operator*(FlatVector const& obj);

		FlatVector operator*(double s);

		double length();

		FlatVector norm();
	};

#endif
