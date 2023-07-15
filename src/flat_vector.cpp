#include "../include/flat_vector.h"

//FlatVector::FlatVector(double _x, double _y) {
	//x = _x;
	//y = _y;
//};

FlatVector FlatVector::operator+(FlatVector const& obj) {
	return FlatVector(x + obj.x, y + obj.y);
}

FlatVector FlatVector::operator-(FlatVector const& obj) {
	return FlatVector(x - obj.x, y - obj.y);
}

double FlatVector::operator*(FlatVector const& obj) {
	return x * obj.x + y * obj.y;
}

FlatVector FlatVector::operator*(double s) {
	return FlatVector(x * s, y * s);
}

double FlatVector::length() {
	return sqrt(x * x + y * y);
}

FlatVector FlatVector::norm() {
	double length = this->length();
	if (length == 0) {
		return FlatVector(0,0);
	}
	return FlatVector(x / length, y / length);
}