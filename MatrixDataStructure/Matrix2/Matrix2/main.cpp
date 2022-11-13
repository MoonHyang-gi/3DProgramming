#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

	//1. ���� ���(identity matrix)
	//���� ��ķ� �ʱ�ȭ�ϴ� �Լ� �ۼ�
class IM {
public:
	float Mat3[3][3]; //3x3���

	IM() { //������
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; i++)
			{
				Mat3[i][j] = 0;
			}
		}
	}

	void Reset() { //�ʱ�ȭ �Լ� �ۼ�
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Mat3[i][j] = 0; //�ʱ�ȭ
			}
		}
		//x, y, z ���� 1�� �ʱ�ȭ
		Mat3[0][0] = 1;
		Mat3[1][1] = 1;
		Mat3[2][2] = 1;
	}
};


	//2. ��ġ ���(transpose matrix)
	//��ġ ����� ����� �Լ� �ۼ�
class TM {
public: 
	float Mat[3][3];
	float t;

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


	//3. ���� �Լ�
	//a)multiply matrix
	vector<vector<int>> solution(vector<vector<int>> arr1,
		vector<vector<int>> arr2) {
		vector<vector<int>> answer;

		for (int i = 0; i < arr1.size(); i++) 
		{
			vector<int> v;
			for (int j = 0; j < arr2[0].size(); j++) 
			{
				int sum = 0;
				for (int k = 0; k < arr1[0].size(); k++) 
				{
					sum += arr1[i][k] * arr2[k][j];
				}
				v.push_back(sum);
			}
			answer.push_back(v);
		}

		return answer;
	}

	//b)multiply transpose matrix
	vector< vector<int> > solution(vector< vector<int> >& J,
		vector< vector<int> >& R, int n, int m) {
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				for (int k = 0; k < n; k++) 
				{
					R[i][k] += J[i][j] * J[k][j];
				}
			}
		}
		return R;
	}
	 
	//c)multiply vector
	
	 
	//d)multiply transpose vector
	 
	 
	//e)���/���� �� ����, ����
	 
	 
	//f)��� ����, ��� ������


int main(void) {
	//a
	vector<vector<int>> arr1 = { {1,0,0},{0,1,0},{0,0,1} };
	vector<vector<int>> arr2 = { {1,0,0},{0,1,0},{0,0,1} };
	vector<vector<int>> ans = solution(arr1, arr2);

	for (size_t i = 0; i < ans.size(); i++)
	{
		for (size_t j = 0; j < ans[0].size(); j++)
		{
			cout << ans[i][j] << ' ';
		}putchar('\n');
	}

	return 0;
}