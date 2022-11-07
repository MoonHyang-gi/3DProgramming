#include "MusoenMath.h"

using namespace std;

int main(void) {
	vec3 v;
	//mat3 Mat;
	mat3 Translate, Rotate, Scale;
	
	//3, 5 �̵�
	Translate.mat[0][0] = 1;
	Translate.mat[1][1] = 1;
	Translate.mat[0][2] = 3;
	Translate.mat[1][2] = 5;
	Translate.mat[2][2] = 1;
	
	//������
	double radius = 30 * (PI / 180);
	//30�� ȸ��
	Rotate.mat[0][0] = cos(radius);
	Rotate.mat[1][0] = -sin(radius);
	Rotate.mat[0][1] = sin(radius);
	Rotate.mat[1][1] = cos(radius);
	Rotate.mat[2][2] = 1;

	//2�� Ȯ��
	Scale.mat[0][0] = 2;
	Scale.mat[1][1] = 2;
	Scale.mat[2][2] = 1;

	vec3 p = v * Translate * Rotate * Scale;   // 3,5 �̵� | 30�� ȸ�� | 2�� Ȯ��
	//cout << Rotate.mat[0][0] * p.vec[0] << endl;

	for (int i = 0; i < 3; ++i) {
			cout << p.vec[i] << endl; //����� ���
	}

	return 0;
}