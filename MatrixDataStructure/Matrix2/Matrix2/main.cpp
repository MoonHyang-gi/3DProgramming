#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

	//1. ���� ���(identity matrix)
	//���� ��ķ� �ʱ�ȭ�ϴ� �Լ� �ۼ�
class Mat {
public:
	float mat3[3][3]; //3x3���
	float mat4[4][4]; //4x4���

	Mat() { //������
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; i++)
			{
				mat3[i][j] = 0; //��� ���� �ʱ�ȭ
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mat4[i][j] = 0; //��� ���� �ʱ�ȭ
			}
		}
	}

	void Reset() { //�ʱ�ȭ �Լ� �ۼ�
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mat3[i][j] = 0; //3x3 ����� ��� ���� 0���� �ʱ�ȭ
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mat4[i][j] = 0; //4x4 ����� ��� ���� 0���� �ʱ�ȭ
			}
		}

		//x, y, z, w �� 1�� �ʱ�ȭ
		mat3[0][0] = 1;
		mat3[1][1] = 1;
		mat3[2][2] = 1;

		mat4[0][0] = 1;
		mat4[1][1] = 1;
		mat4[2][2] = 1;
		mat4[3][3] = 1;
	}
};


	//2. ��ġ ���(transpose matrix)
	//��ġ ����� ����� �Լ� �ۼ�
class TMat {
public: 
	float mat3[3][3];
	float mat4[4][4];

	void Transpose() { //��ġ ��� �Լ�
		for (int i = 0; i < 3; i++) //3x3 ��ġ ���
		{
			for (int j = 0; i < 3; i++)
			{
				mat3[i][j] = mat3[j][i]; //��� ���� �ε����� �ٲپ� ����
			}
		}

		for (int i = 0; i < 4; i++) //4x4 ��ġ ���
		{
			for (int j = 0; i < 4; i++)
			{
				mat4[i][j] = mat4[j][i]; //��� ���� �ε����� �ٲپ� ����
			}
		}
	}
};

//���� �� Ŭ���� ����
class Vec3 //3x1
{
public:
	float vec3[3];

	Vec3() { //���� 3x1 ������
		for (int i = 0; i < 3; i++)
		{
			vec3[i] = 0; //�ʱ�ȭ
		}
		vec3[2] = 1;
	}
};

class Vec1x3 //1x3
{
public:
	float vec1x3[1][3];

	Vec1x3() { //���� 1x3 ������
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; i < 3; i++)
			{
				vec1x3[i][j] = 0; //�ʱ�ȭ
			}
		}
		vec1x3[0][2] = 1;
	}
};

class Vec4 //4x1
{
public:
	float vec4[4];

	Vec4() { //���� 4x1 ������
		for (int i = 0; i < 4; i++)
		{
			vec4[i] = 0; //�ʱ�ȭ
		}
		vec4[3] = 1;
	}
};

class Vec1x4 //1x4
{
public:
	float vec1x4[1][4];

	Vec1x4() { //���� 1x4 ������
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; i < 4; j++)
			{
				vec1x4[i][j] = 0; //�ʱ�ȭ
			}
		}
		vec1x4[1][3] = 1;
	}
};

	//3. ���� �Լ�
	//a)multiply matrix
	/*vector<vector<int>> solution(vector<vector<int>> arr1,
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
	}*/
const Mat operator*(Mat m, Mat r) //3x3��� X 3x3���
{
	Mat result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				result.mat3[i][j] += m.mat3[i][k] * r.mat3[k][j];
			}
		}
	}
	return result;
}

const Mat operator*(const Mat& m, const Mat& r) //4x4��� X 4x4���
{
	Mat result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				result.mat4[i][j] += m.mat4[i][k] * r.mat4[k][j];
			}
		}
	}
	return result;
}


	//b)multiply transpose matrix
	/*vector< vector<int> > solution(vector< vector<int> >& J,
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
	}*/
const TMat operator*(const TMat& m, const TMat& r) //3x3��ġ��� X 3x3��ġ���
{
	TMat result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				result.mat3[i][j] += m.mat3[i][k] * r.mat3[k][j];
			}
		}
	}
	return result;
}

const TMat operator*(TMat m, TMat r) //4x4��ġ��� X 4x4��ġ���
{
	TMat result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				result.mat4[i][j] += m.mat4[i][k] * r.mat4[k][j];
			}
		}
	}
	return result;
}


	//c)multiply vector
const Vec3 operator*(Mat m, Vec3 v) //3x3��� X vec3
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.vec3[i] += m.mat3[i][j] * v.vec3[j];
		}
	}
	return result;
}

const Vec1x3 operator*(Mat m, Vec1x3 v) //3x3��� X vec1x3
{
	Vec1x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				result.vec1x3[i][j] += m.mat3[i][j] * v.vec1x3[i][j];
			}
		}
	}
	return result;
}

const Vec4 operator*(Mat m, Vec4 v) //4x4��� X vec4
{
	Vec4 result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.vec4[i] += m.mat3[i][j] * v.vec4[i];
		}
	}
	return result;
}

const Vec1x4 operator*(Mat m, Vec1x4 v) //4x4��� X vec1x4
{
	Vec1x4 result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				result.vec1x4[k][j] += m.mat4[i][j] * v.vec1x4[k][j];
			}
		}
	}
	return result;
}


	//d)multiply transpose vector
const Vec3 operator*(TMat m, Vec3 v) //3x3��ġ��� X vec3
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.vec3[i] += m.mat3[i][j] * v.vec3[i];
		}
	}
	return result;
}

const Vec1x3 operator*(TMat m, Vec1x3 v) //3x3��ġ��� X vec1x3
{
	Vec1x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				result.vec1x3[k][j] += m.mat3[i][j] * v.vec1x3[k][j];
			}
		}
	}
	return result;
}

const Vec4 operator*(TMat m, Vec4 v) //4x4��ġ��� X vec4
{
	Vec4 result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{ 
			result.vec4[i] += m.mat3[i][j] * v.vec4[i];
		}
	}
	return result;
}

const Vec1x4 operator*(TMat m, Vec1x4 v) //4x4��ġ��� X vec1x4
{
	Vec1x4 result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				result.vec1x4[k][j] += m.mat3[i][j] * v.vec1x4[k][j];
			}
		}
	}
	return result;
}

	 
	//e)���/���� �� ����, ����
const Mat operator+(Mat m, Mat r) //3x3��� + 3x3���
{
	Mat result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.mat3[i][j] = m.mat3[i][j] + r.mat3[i][j];
		}
	}
	return result;
}

const Mat operator-(Mat m, Mat r) //3x3��� - 3x3���
{
	Mat result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.mat3[i][j] = m.mat3[i][j] - r.mat3[i][j];
		}
	}
	return result;
}

const Mat operator+(const Mat& m, const Mat& r) //4x4��� + 4x4���
{
	Mat result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.mat4[i][j] = m.mat4[i][j] + r.mat4[i][j];
		}
	}
	return result;
}

const Mat operator-(const Mat& m, const Mat& r) //4x4��� - 4x4���
{
	Mat result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.mat4[i][j] = m.mat4[i][j] - r.mat4[i][j];
		}
	}
	return result;
}


const Vec3 operator+(Vec3 v, Vec3 r) //vec3 + vec3
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.vec3[i] = v.vec3[i] + r.vec3[i];
	}
	return result;
}

const Vec3 operator-(Vec3 v, Vec3 r) //vec3 - vec3
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.vec3[i] = v.vec3[i] - r.vec3[i];
	}
	return result;
}

const Vec4 operator+(Vec4 v, Vec4 r) //vec4 + vec4
{
	Vec4 result;
	for (int i = 0; i < 4; i++)
	{
		result.vec4[i] = v.vec4[i] + r.vec4[i];
	}
	return result;
}

const Vec4 operator-(Vec4 v, Vec4 r) //vec4 - vec4
{
	Vec4 result;
	for (int i = 0; i < 4; i++)
	{
		result.vec4[i] = v.vec4[i] - r.vec4[i];
	}
	return result;
}

	 
	//f)��� ����, ��� ������
const Mat operator*(Mat m, int r) //3x3��� X ���
{
	Mat result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.mat3[i][j] = m.mat3[i][j] * r;
		}
	}
	return result;
}

const Mat operator*(Mat m, int r) //4x4��� X ���
{
	Mat result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.mat4[i][j] = m.mat4[i][j] * r;
		}
	}
	return result;
}

const Vec3 operator*(Vec3 v, int r) //vec3 X ���
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.vec3[i] = v.vec3[i] * r;
	}
	return result;
}

const Vec3 operator/(Vec3 v, int r) //vec3 / ���
{
	Vec3 result;
	for (int i = 0; i < 3; i++)
	{
		result.vec3[i] = v.vec3[i] / r;
	}
	return result;
}

const Vec1x3 operator*(Vec1x3 v, int r) //vec1x3 X ���
{
	Vec1x3 result;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.vec1x3[i][j] = v.vec1x3[i][j] * r;
		}
	}
	return result;
}

const Vec1x3 operator/(Vec1x3 v, int r) //vec1x3 / ���
{
	Vec1x3 result;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.vec1x3[i][j] = v.vec1x3[i][j] / r;
		}
	}
	return result;
}

const Vec4 operator*(Vec4 v, int r) //vec4 X ���
{
	Vec4 result;
	for (int i = 0; i < 4; i++)
	{
		result.vec4[i] = v.vec4[i] * r;
	}
	return result;
}

const Vec4 operator/(Vec4 v, int r) //vec4 / ���
{
	Vec4 result;
	for (int i = 0; i < 3; i++)
	{
		result.vec4[i] = v.vec4[i] / r;
	}
	return result;
}

const Vec1x4 operator*(Vec1x4 v, int r) //vec1x4 X ���
{
	Vec1x4 result;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.vec1x4[i][j] = v.vec1x4[i][j] * r;
		}
	}
	return result;
}

const Vec1x4 operator/(Vec1x4 v, int r) //vec1x4 / ���
{
	Vec1x4 result;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.vec1x4[i][j] = v.vec1x4[i][j] / r;
		}
	}
	return result;
}


int main(void) {
	//a
	//vector<vector<int>> arr1 = { {1,2,3},{4,5,6},{7,8,9} }; //ù��° �迭�� �� ����
	//vector<vector<int>> arr2 = { {9,8,7},{6,5,4},{3,2,1} }; //�ι�° �迭�� �� ����
	//vector<vector<int>> ans = solution(arr1, arr2);

	//cout << "��İ���\n" << endl;
	//for (size_t i = 0; i < ans.size(); i++)
	//{
	//	for (size_t j = 0; j < ans[0].size(); j++)
	//	{
	//		cout << ans[i][j] << ' ';
	//	}putchar('\n');
	//}


	return 0;
}