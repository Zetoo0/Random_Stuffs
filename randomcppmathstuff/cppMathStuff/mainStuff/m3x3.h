
#include <iostream>
#include "vec3.h"

//refactor the operators to work well with other matrices(now just with 2x2)

class m3x3
{
public:
	//number matrix
	m3x3(vec3 v1, vec3 v2, vec3 v3) : matrix{ {v1.x(), v1.y(), v1.z()}, {v2.x(), v2.y(), v2.z()}, {v3.x(), v3.y(), v3.z()} } {}
	m3x3(float v11, float v12, float v13,float v21, float v22, float v23, float v31, float v32, float v33) : matrix{ {v11,v12, v13}, {v21, v22, v23}, {v31, v32, v33} } {}

	float m00() const { return matrix[0][0]; }
	float m01() const { return matrix[0][1]; }
	float m02() const { return matrix[0][2]; }
	float m10() const { return matrix[1][0]; }
	float m11() const { return matrix[1][1]; }
	float m12() const { return matrix[1][2]; }
	float m20() const { return matrix[2][0]; }
	float m21() const { return matrix[2][1]; }
	float m22() const { return matrix[2][2]; }

	m3x3 operator-() const { return m3x3(-matrix[0][0], -matrix[0][1], -matrix[0][2],-matrix[1][0], -matrix[1][1], -matrix[1][2], -matrix[2][0], -matrix[2][1], -matrix[2][2]); }
	//m2x2 operator[][](int i, int j) const { return matrix[i][j]; }

	m3x3 operator+=(const m3x3& m2)
	{
		matrix[0][0] += m2.matrix[0][0];
		matrix[0][1] += m2.matrix[0][1];
		matrix[0][2] += m2.matrix[0][2];
		matrix[1][0] += m2.matrix[1][0];
		matrix[1][1] += m2.matrix[1][1];
		matrix[1][2] += m2.matrix[1][2];
		matrix[2][0] += m2.matrix[2][0];
		matrix[2][1] += m2.matrix[2][1];
		matrix[2][2] += m2.matrix[2][2];
		return *this;
	}

	m3x3 operator*=(const float num)
	{
		matrix[0][0] *= num;
		matrix[0][1] *= num;
		matrix[0][2] *= num;
		matrix[1][0] *= num;
		matrix[1][1] *= num;
		matrix[1][2] *= num;
		matrix[2][0] *= num;
		matrix[2][1] *= num;
		matrix[2][2] *= num;
		return *this;
	}

	inline m3x3 Transpose()
	{
		std::swap(matrix[0][1], matrix[1][0]);
		std::swap(matrix[0][2], matrix[2][0]);
		std::swap(matrix[1][2], matrix[2][1]);
		/*matrix[0][1] = matrix[1][0];
		matrix[0][2] = matrix[2][0];
		matrix[1][0] = matrix[0][1];
		matrix[1][2] = matrix[2][1];
		matrix[2][0] = matrix[0][2];
		matrix[2][1] = matrix[1][2];*/
		return *this;
	}

	inline float Determinante()
	{

		return ((matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) - (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));
	}

public:
	float matrix[3][3];
};


inline std::ostream& operator<<(std::ostream& out, const m3x3 mat3)
{
	return out << mat3.matrix[0][0] << ' ' << mat3.matrix[0][1] << ' ' << mat3.matrix[0][2] << '\n' << mat3.matrix[1][0] << ' ' << mat3.matrix[1][1] << ' ' << mat3.matrix[1][2] << '\n' << mat3.matrix[2][0] << ' ' << mat3.matrix[2][1] << ' ' << mat3.matrix[2][2];
}



inline m3x3 operator+(const m3x3& m1, const m3x3& m2) {
	return m3x3(m1.matrix[0][0] + m2.matrix[0][0], m1.matrix[0][1] + m2.matrix[0][1], m1.matrix[0][2] + m2.matrix[0][2], m1.matrix[1][0] + m2.matrix[1][0], m1.matrix[1][1] + m2.matrix[1][1], m1.matrix[1][2] + m2.matrix[1][2], m1.matrix[2][0] + m2.matrix[2][0], m1.matrix[2][1] + m2.matrix[2][1], m1.matrix[2][2] + m2.matrix[2][2]);
}

inline m3x3 operator-(const m3x3& m1, const m3x3& m2) {
	return m3x3(m1.matrix[0][0] - m2.matrix[0][0], m1.matrix[0][1] - m2.matrix[0][1], m1.matrix[0][2] - m2.matrix[0][2], m1.matrix[1][0] - m2.matrix[1][0], m1.matrix[1][1] - m2.matrix[1][1], m1.matrix[1][2] - m2.matrix[1][2], m1.matrix[2][0] - m2.matrix[2][0], m1.matrix[2][1] - m2.matrix[2][1], m1.matrix[2][2] - m2.matrix[2][2]);
}

inline m3x3 operator*(const m3x3& m1, const m3x3& m2) {
	return m3x3((m1.matrix[0][0] * m2.matrix[0][0]) + (m1.matrix[0][1] * m2.matrix[1][0]) + (m1.matrix[0][2] * m2.matrix[2][0]),
				(m1.matrix[0][0] * m2.matrix[0][1]) + (m1.matrix[0][1] * m2.matrix[1][1]) + (m1.matrix[0][2] * m2.matrix[2][1]),
				(m1.matrix[0][0] * m2.matrix[0][2]) + (m1.matrix[0][1] * m2.matrix[1][2]) + (m1.matrix[0][2] * m2.matrix[2][2]),
				(m1.matrix[1][0] * m2.matrix[0][0]) + (m1.matrix[1][1] * m2.matrix[1][0]) + (m1.matrix[1][2] * m2.matrix[2][0]),
				(m1.matrix[1][0] * m2.matrix[0][1]) + (m1.matrix[1][1] * m2.matrix[1][1]) + (m1.matrix[1][2] * m2.matrix[2][1]),
				(m1.matrix[1][0] * m2.matrix[0][2]) + (m1.matrix[1][1] * m2.matrix[1][2]) + (m1.matrix[1][2] * m2.matrix[2][2]),
				(m1.matrix[2][0] * m2.matrix[0][0]) + (m1.matrix[2][1] * m2.matrix[1][0]) + (m1.matrix[2][2] * m2.matrix[2][0]),
				(m1.matrix[2][0] * m2.matrix[0][1]) + (m1.matrix[2][1] * m2.matrix[1][1]) + (m1.matrix[2][2] * m2.matrix[2][1]),
				(m1.matrix[2][0] * m2.matrix[0][2]) + (m1.matrix[2][1] * m2.matrix[1][2]) + (m1.matrix[2][2] * m2.matrix[2][2]));
}

inline m3x3 operator*(const m3x3& m, float num) {
	return m3x3(m.matrix[0][0] * num, m.matrix[0][1] * num, m.matrix[0][2] * num, m.matrix[1][0] * num, m.matrix[1][1] * num, m.matrix[1][2] * num, m.matrix[2][0] * num, m.matrix[2][1] * num, m.matrix[2][2] * num);
}
