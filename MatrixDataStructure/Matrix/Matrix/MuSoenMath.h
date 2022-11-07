#pragma once
#include <math.h>
#include <iostream>

#define PI 3.14159265

class mat3 { //mat3 클래스 생성
public :
	float mat[3][3]; //float형 3x3 행렬

public:
	mat3() { //생성자
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				mat[i][j] = 0; //멤버 변수 초기화
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

	//mat3 operator*(mat3& m) { //연산자 오버로딩
	//	for (int i = 0; i < 3; ++i) {
	//		for (int j = 0; j < 3; ++j) {
	//			mat[i][j] *= m.mat[i][j];
	//		}
	//	}
	//}
};

class vec3 { //vec3 클래스 생성
public:
	float vec[3]; //float형 3x1 좌표(벡터)

public:
	vec3() { //생성자 
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 1; //동차좌표
	}
	
	vec3 operator*(mat3 m) { //연산자 오버로딩
		vec3 v;
		// Vector와 Matrix 행렬 곱하기
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				v.vec[i] += m.mat[i][j] * v.vec[j];
			}
		}

		v.vec[2] = 1;

		return v; //저장된 값 반환
	}

};
