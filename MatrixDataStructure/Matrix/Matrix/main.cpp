#include "MusoenMath.h"

using namespace std;

int main(void) {
	vec3 v;
	//mat3 Mat;
	mat3 Translate, Rotate, Scale;
	
	//3, 5 이동
	Translate.mat[0][0] = 1;
	Translate.mat[1][1] = 1;
	Translate.mat[0][2] = 3;
	Translate.mat[1][2] = 5;
	Translate.mat[2][2] = 1;
	
	//반지름
	double radius = 30 * (PI / 180);
	//30도 회전
	Rotate.mat[0][0] = cos(radius);
	Rotate.mat[1][0] = -sin(radius);
	Rotate.mat[0][1] = sin(radius);
	Rotate.mat[1][1] = cos(radius);
	Rotate.mat[2][2] = 1;

	//2배 확대
	Scale.mat[0][0] = 2;
	Scale.mat[1][1] = 2;
	Scale.mat[2][2] = 1;

	vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대
	//cout << Rotate.mat[0][0] * p.vec[0] << endl;

	for (int i = 0; i < 3; ++i) {
			cout << p.vec[i] << endl; //결과값 출력
	}

	return 0;
}