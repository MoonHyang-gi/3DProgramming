#pragma once
#include <math.h>
#include <iostream>

#define PI 3.14159265

class mat3 { //mat3 Ŭ���� ����
public:
	float mat[3][3] = {}; //float�� 3x3 ��� ���� �� 0���� �ʱ�ȭ

	mat3() {} //�⺻ ������

	mat3(float a1, float b1, float c1, 
		float a2, float b2, float c2,
		float a3, float b3, float c3) { //main.cpp���� ����� float�� ����
		
		mat[0][0] = a1;
		mat[0][1] = b1;
		mat[0][2] = c1;
		mat[1][0] = a2;
		mat[1][1] = b2;
		mat[1][2] = c2;
		mat[2][0] = a3;
		mat[2][1] = b3;
		mat[2][2] = c3;
	} //����� ��� �ڸ��� float�� ������ ������ ��

	mat3 Transpose() { //��ġ����� ������ִ� �Լ�
		mat3 tmat;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tmat.mat[i][j] = mat[j][i]; //��ġ
			}
		}
		return tmat; //tmat �� ��ȯ
	}
};


class vec3 { //vec3 Ŭ���� ����
public:
	float vec[3] = {}; //float�� 3x1 ���(����)
	float x, y, z;

	vec3() { //���� 3x1 ������
		x = vec[0] = 0;
		y = vec[1] = 0;
		z = vec[2] = 1; //�� �ʱ�ȭ
	}
};

const vec3 operator*(const vec3 v, const mat3 m) { // ������ �����ε�
	vec3 result;
	mat3 mat = m; //class mat3 �� mat�� m���� ����
	mat = mat.Transpose(); //�Լ��� �̿��Ͽ� ����� ��ġ

	float x = v.x; //x�� vec3�� x���� ����
	float y = v.y; //y�� vec3�� y���� ����
	float z = v.z; //z�� vec3�� z���� ����

	       //���� �� x X ���[n][n]  ���� �� y X ���[n][n]  ���� �� z X ���[n][n]
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
	return result; //result �� ��ȯ
}