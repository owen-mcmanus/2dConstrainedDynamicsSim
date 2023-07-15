#include "../include/flat_vector.h"

//FlatVector::FlatVector(float _x, float _y) {
	//x = _x;
	//y = _y;
//};

FlatVector FlatVector::operator+(FlatVector const& obj) {
	return FlatVector(x + obj.x, y + obj.y);
}

FlatVector FlatVector::operator-(FlatVector const& obj) {
	return FlatVector(x - obj.x, y - obj.y);
}

float FlatVector::operator*(FlatVector const& obj) {
	return x * obj.x + y * obj.y;
}

FlatVector FlatVector::operator*(float s) {
	return FlatVector(x * s, y * s);
}

float FlatVector::length() {
	return sqrt(x * x + y * y);
}

FlatVector FlatVector::norm() {
	float length = this->length();
	if (length == 0) {
		return FlatVector(0,0);
	}
	return FlatVector(x / length, y / length);
}