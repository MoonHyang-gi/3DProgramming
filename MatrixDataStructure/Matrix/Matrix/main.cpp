#include "MusoenMath.h"

using namespace std;

int main() {
	vec3 v;

	mat3 Translate, Rotate, Scale;

	Translate.mat[0][0] = 1;
	Translate.mat[1][1] = 1;
	Translate.mat[2][2] = 1;

	Rotate.mat[0][0] = cos(30);
	Rotate.mat[0][1] = -sin(30);
	Rotate.mat[1][0] = sin(30);
	Rotate.mat[1][1] = cos(30);
	Rotate.mat[2][2] = 1;

	Scale.mat[0][0] = 1;
	Scale.mat[1][1] = 1;
	Scale.mat[2][2] = 1;

	vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대

	for (int i = 0; i < 3; ++i) {
			cout << p.vec[i] << endl;
	}

	return 0;
}