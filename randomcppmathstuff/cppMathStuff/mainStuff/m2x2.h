#include <iostream>
#include "vec3.h"
class m2x2
{
public:
	//number matrix
	m2x2(vec3 v1, vec3 v2) : matrix{ {v1.x(), v1.y()}, {v2.x(), v2.y()} } {}
	m2x2(float v11, float v12, float v21, float v22) : matrix{ {v11,v12}, {v21, v22} } {}

	float m00() const { return matrix[0][0]; }
	float m01() const { return matrix[0][1]; }
	float m10() const { return matrix[1][0]; }
	float m11() const { return matrix[1][1]; }

	m2x2 operator-() const { return m2x2(-matrix[0][0], -matrix[0][1], -matrix[1][0], -matrix[1][1]); }
	//m2x2 operator[][](int i, int j) const { return matrix[i][j]; }

	m2x2 operator+=(const m2x2& m2)
	{
		matrix[0][0] += m2.matrix[0][0];
		matrix[0][1] += m2.matrix[0][1];
		matrix[1][0] += m2.matrix[1][0];
		matrix[1][1] += m2.matrix[1][1];
		return *this;
	}

	m2x2 operator*=(const float num)
	{
		matrix[0][0] *= num;
		matrix[0][1] *= num;
		matrix[1][0] *= num;
		matrix[1][1] *= num;
		return *this;
	}

	inline m2x2 Transpose()
	{
		matrix[0][1] = matrix[1][0];
		matrix[1][0] = matrix[0][1];
		return *this;
	}

	inline float Determinant() 
	{
		//return (this->VecArr[0].x * this->VecArr[1].y) - ((this->VecArr[1].x) * (this->VecArr[0].y));
		return(matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
	}

public:
	float matrix[2][2];
};

inline std::ostream& operator<<(std::ostream& out, const m2x2 mat2)
{
	return out << mat2.matrix[0][0] << ' ' << mat2.matrix[0][1] << '\n' << mat2.matrix[1][0] << ' ' << mat2.matrix[1][1];
}

inline m2x2 operator+(m2x2 m1, m2x2 m2) {
	return m2x2(m1.matrix[0][0] + m2.matrix[0][0], m1.matrix[0][1] + m2.matrix[0][1], m1.matrix[1][0] + m2.matrix[1][0], m1.matrix[1][1] + m2.matrix[1][1]);
}

inline m2x2 operator-(m2x2 m1, m2x2 m2) {
	return m2x2(m1.matrix[0][0] - m2.matrix[0][0], m1.matrix[0][1] - m2.matrix[0][1], m1.matrix[1][0] - m2.matrix[1][0], m1.matrix[1][1] - m2.matrix[1][1]);
}

inline m2x2 operator*(m2x2 m1, m2x2 m2) {
	return m2x2((m1.matrix[0][0] * m2.matrix[0][0]) + (m1.matrix[0][1] * m2.matrix[1][0]), 
				(m1.matrix[0][0] * m2.matrix[0][1]) + (m1.matrix[0][1] * m2.matrix[1][1]),
				(m1.matrix[1][0] * m2.matrix[0][0]) + (m1.matrix[1][0] * m2.matrix[1][0]),
				(m1.matrix[1][0] * m2.matrix[0][1]) + (m1.matrix[1][1] * m2.matrix[1][1]));
}

inline m2x2 operator*(m2x2 m, float num) {
	return m2x2(m.matrix[0][0] * num, m.matrix[0][1] * num, m.matrix[1][0] * num, m.matrix[1][1] * num);
}

