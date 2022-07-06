#ifndef VEC3_H
#define VEC3_H



#include <iostream>
#include <cmath>

class vec3 
{
public:
	vec3() : e{0, 0, 0} {}
	vec3(float x, float y, float z) : e{x, y, z} {}

	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	float operator[](int i) const { return e[i]; }
	//float& operator[](int i) const { return e[i]; }

	vec3 operator+=(const vec3& v1) {
		e[0] += v1.e[0];
		e[1] += v1.e[1];
		e[2] += v1.e[2];
		return *this;
	}

	vec3 operator*=(const float num) {
		e[0] *= num;
		e[1] *= num;
		e[2] *= num;
		return *this;
	}

	float Square() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	float Length() const {
		return std::sqrt(Square());
	}


	inline vec3 Normalize() {
		return vec3(e[0] / Length(), e[1] / Length(), e[2] / Length());
	}

	inline float Distance(const vec3& v) {
		vec3 fromD(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
		return std::sqrt(fromD.Square());
	}


public:
	float e[3];
};

inline vec3 operator+(const vec3& v, const vec3& w) {
	return vec3(v.e[0] + w.e[0], v.e[1] + w.e[1], v.e[2] + w.e[2]);
}

inline vec3 operator-(const vec3& v, const vec3& w) {
	return vec3(v.e[0] - w.e[0], v.e[1] - w.e[1], v.e[2] - w.e[2]);
}

inline vec3 operator*(const vec3& v, const vec3& w) {
	return vec3(v.e[0] * w.e[0], v.e[1] * w.e[1], v.e[2] * w.e[2]);
}

inline vec3 operator*(float num, const vec3& v) {
	return vec3(num * v.e[0], num * v.e[1], num * v.e[2]);
}

inline float DotProduct(const vec3& v, const vec3& w) {
	return v.e[0] * w.e[0] + v.e[1] * w.e[1] + v.e[2] * w.e[2];
}

inline vec3 CrossProduct(const vec3& v, const vec3& w) {
	return vec3(v.e[1] * w.e[2] - v.e[2] * w.e[1], v.e[2] * w.e[0] - v.e[0] * w.e[2], v.e[0] * w.e[1] - v.e[1] * w.e[0]);
}





#endif // !VEC3_H
