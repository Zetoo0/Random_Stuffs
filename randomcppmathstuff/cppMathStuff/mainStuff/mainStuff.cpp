#include <iostream>
#include "m2x2.h"
#include "m3x3.h"
#include "vec3.h"
#include "randomMathStuffs.h"

void MainStart() {
     vec3 v1(1.0f, 1.0f, 4.0f);
     vec3 v2(1.0f, 1.0f, 2.0f);
     vec3 v3(34.0f, -4.0f, 1.0f);
     m2x2 mat2(1.0f, 1.0f, 1.0f, 1.0f);
     m2x2 matrix(v1, v2);
     m3x3 matrix3(v1, v2, v3);
    std::cout << mat2.Transpose() << std::endl;
    std::cout << mat2.m00() << std::endl;
    std::cout << mat2.m01() << std::endl;
    std::cout << mat2.m10() << std::endl;
    std::cout << mat2.m11() << std::endl;
    std::cout <<"Determinante\n" << mat2.Determinant() << std::endl;
    std::cout <<"2 matrix add\n"<< mat2 + matrix << std::endl;
   // std::cout <<"2 matrix multiply\n"<< mat2() * matrix << std::endl;
    //std::cout << "3x3 matrix determinant: " << matrix3.Determinante() << std::endl;
    std::cout<<"oc 3x3 matrix:\n " << matrix3 << std::endl;
    std::cout << "3x3 matrix transpose: \n" << matrix3.Transpose() << std::endl;
}

int main()
{
    MainStart();
}

