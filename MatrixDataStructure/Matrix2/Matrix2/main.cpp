#include <iostream>
#include <math.h>

using namespace std;

	//1. 단위 행렬(identity matrix)
	//단위 행렬로 초기화하는 함수 작성
class IM {
public:
	float Mat[3][3]; //2차원 3x3행렬

	IM() { //생성자
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; i++)
			{
				Mat[i][j] = 0;
			}
		}
	}

	void Reset() { //초기화 함수 작성
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Mat[i][j] = 0;
			}
		}
		//x, y, z 축을 1로 초기화
		Mat[0][0] = 1;
		Mat[1][1] = 1;
		Mat[2][2] = 1;
	}
};


	//2. 전치 행렬(transpose matrix)
	//전치 행렬을 만드는 함수 작성
class TM {
public: 
	float Mat[3][3];
	int t;

	void Transpose() { //전치 행렬 함수
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; i < 3; i++)
			{
				t = Mat[i][j];
				Mat[i][j] = Mat[j][i]; //행과 열의 인덱스를 바꾸어 저장
				Mat[j][i] = t;
			}
		}
	}
};

int main(void) {
	//3. 연산 함수
	//a)multiply matrix
	

	//b)multiply transpose matrix
	 
	 
	//c)multiply vector
	 
	 
	//d)multiply transpose vector
	 
	 
	//e)행렬/벡터 간 덧셈, 뺄셈
	 
	 
	//f)상수 곱셈, 상수 나눗셈


}