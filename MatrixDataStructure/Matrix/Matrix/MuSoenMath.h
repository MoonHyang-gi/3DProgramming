#pragma once
#include <math.h>
#include <iostream>

#define PI 3.14159265

class mat3 { //mat3 Ŭ���� ����
public :
	float mat[3][3]; //float�� 3x3 ���

public:
	mat3() { //������
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				mat[i][j] = 0; //��� ���� �ʱ�ȭ
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

	//mat3 operator*(mat3& m) { //������ �����ε�
	//	for (int i = 0; i < 3; ++i) {
	//		for (int j = 0; j < 3; ++j) {
	//			mat[i][j] *= m.mat[i][j];
	//		}
	//	}
	//}
};

class vec3 { //vec3 Ŭ���� ����
public:
	float vec[3]; //float�� 3x1 ��ǥ(����)

public:
	vec3() { //������ 
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 1; //������ǥ
	}
	
	vec3 operator*(mat3 m) { //������ �����ε�
		vec3 v;
		// Vector�� Matrix ��� ���ϱ�
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				v.vec[i] += m.mat[i][j] * v.vec[j];
			}
		}

		v.vec[2] = 1;

		return v; //����� �� ��ȯ
	}

};
