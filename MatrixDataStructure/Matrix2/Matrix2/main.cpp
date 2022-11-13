#include <iostream>
#include <math.h>

using namespace std;

	//1. ���� ���(identity matrix)
	//���� ��ķ� �ʱ�ȭ�ϴ� �Լ� �ۼ�
class IM {
public:
	float Mat[3][3]; //2���� 3x3���

	IM() { //������
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; i++)
			{
				Mat[i][j] = 0;
			}
		}
	}

	void Reset() { //�ʱ�ȭ �Լ� �ۼ�
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Mat[i][j] = 0;
			}
		}
		//x, y, z ���� 1�� �ʱ�ȭ
		Mat[0][0] = 1;
		Mat[1][1] = 1;
		Mat[2][2] = 1;
	}
};


	//2. ��ġ ���(transpose matrix)
	//��ġ ����� ����� �Լ� �ۼ�
class TM {
public: 
	float Mat[3][3];
	int t;

	void Transpose() { //��ġ ��� �Լ�
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; i < 3; i++)
			{
				t = Mat[i][j];
				Mat[i][j] = Mat[j][i]; //��� ���� �ε����� �ٲپ� ����
				Mat[j][i] = t;
			}
		}
	}
};

int main(void) {
	//3. ���� �Լ�
	//a)multiply matrix
	

	//b)multiply transpose matrix
	 
	 
	//c)multiply vector
	 
	 
	//d)multiply transpose vector
	 
	 
	//e)���/���� �� ����, ����
	 
	 
	//f)��� ����, ��� ������


}