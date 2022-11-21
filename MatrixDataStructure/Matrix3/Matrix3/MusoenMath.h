#pragma once
#include <math.h>
#include <iostream>

#define PI 3.14159265

class mat3 { //mat3 클래스 생성
public:
	float mat[3][3] = {}; //float형 3x3 행렬 생성 후 0으로 초기화

	mat3() {} //기본 생성자

	mat3(float a1, float b1, float c1, 
		float a2, float b2, float c2,
		float a3, float b3, float c3) { //main.cpp에서 사용할 float형 변수
		
		mat[0][0] = a1;
		mat[0][1] = b1;
		mat[0][2] = c1;
		mat[1][0] = a2;
		mat[1][1] = b2;
		mat[1][2] = c2;
		mat[2][0] = a3;
		mat[2][1] = b3;
		mat[2][2] = c3;
	} //행렬의 모든 자리에 float형 변수가 들어가도록 함

	mat3 Transpose() { //전치행렬을 만들어주는 함수
		mat3 tmat;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tmat.mat[i][j] = mat[j][i]; //전치
			}
		}
		return tmat; //tmat 값 반환
	}
};


class vec3 { //vec3 클래스 생성
public:
	float vec[3] = {}; //float형 3x1 행렬(벡터)
	float x, y, z;

	vec3() { //벡터 3x1 생성자
		x = vec[0] = 0;
		y = vec[1] = 0;
		z = vec[2] = 1; //값 초기화
	}
};

const vec3 operator*(const vec3 v, const mat3 m) { // 연산자 오버로딩
	vec3 result;
	mat3 mat = m; //class mat3 의 mat를 m으로 설정
	mat = mat.Transpose(); //함수를 이용하여 행렬을 전치

	float x = v.x; //x를 vec3의 x으로 설정
	float y = v.y; //y를 vec3의 y으로 설정
	float z = v.z; //z를 vec3의 z으로 설정

	       //벡터 값 x X 행렬[n][n]  벡터 값 y X 행렬[n][n]  벡터 값 z X 행렬[n][n]
	result.x = (x * mat.mat[0][0]) + (y * mat.mat[0][1]) + (z * mat.mat[0][2]); 
	result.y = (x * mat.mat[1][0]) + (y * mat.mat[1][1]) + (z * mat.mat[1][2]); 
	result.z = (x * mat.mat[2][0]) + (y * mat.mat[2][1]) + (z * mat.mat[2][2]); 

	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.vec[i] += m.mat[i][j] * v.vec[j];
		}
	}*/
	return result; //result 값 반환
}