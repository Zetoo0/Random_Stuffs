#include <iostream>
#include "m2x2.h"
#include "vec3.h"
#include "randomMathStuffs.h"

void MainStart() {
    vec3 v1(-2.0f, 4.0f, 4.0f);
    vec3 v2(-5.0f, 3.0f, 32.0f);
	m2x2 mat2(3.0f, 6.0f, 2.0f, 8.0f);
    m2x2 matrix(v1, v2);
    std::cout << mat2.Transpose() << std::endl;
    std::cout << mat2.m00() << std::endl;
    std::cout << mat2.m01() << std::endl;
    std::cout << mat2.m10() << std::endl;
    std::cout << mat2.m11() << std::endl;
    std::cout <<"Determinante\n" << mat2.Determinant() << std::endl;
    std::cout <<"2 matrix add\n"<< mat2 + matrix << std::endl;
}

int main()
{
    MainStart();
}

