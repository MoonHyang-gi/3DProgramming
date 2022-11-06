#pragma once
//#include <math.h>
#include <iostream>

//#define PI 3.14

//vec3(float 3*1) -> 2차원좌표 + 동차좌표
//mat3(float 3*3) -> 2차원 행렬

//double rad(int numb) {
//	return numb * (PI / 180);
//};

class mat3 {
public :
	float mat[3][3];

public:
	mat3() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				mat[i][j] = 0;
			}
		}
	}

	/*mat3 operator*(vec3 v) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				mat[i][j] *= v.vec[j];
			}
		}
	}*/

	/*mat3 operator*(mat3& m) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				mat[i][j] *= m.mat[i][j];
			}
		}
	}*/
};

class vec3 {
public:
	float vec[3];

public:
	vec3() {
		for (int i = 0; i < 3; i++) {
			vec[i] = 0;
		}
	}

	vec3 operator*(mat3& m) {
		vec3 v;
		
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				m.mat[i][j] *= v.vec[i];
			}
		}

		return v;
	}

};

//mat3::mat3(float Translate, float Rotate, float Scale)
//{
//	double num = rad(30);
//	Translate =
//		(1, 0, 3,
//		0, 1, 5,
//		0, 0, 1);
//
//	Rotate =
//		(cos(num), -sin(num), 0,
//		sin(num), cos(num), 0,
//		0, 0, 1	);
//
//	Scale =
//		(2, 0, 0,
//		0, 2, 0,
//		0, 0, 1
//			);
//}