#include<iostream>
int g_count = 0;
using namespace std;

int MinWeightTriangulation(int i, int j);//自顶向下，使用备忘录数组的动态规划算法 
int MinWeightTriangulation_2(int n);//自底向上的动态规划算法 
int GetWeight(int i, int k, int j);//计算三角形的周长 
void PrintTriangulation(int i, int j); //输出组成最优解的各个三角形的周长 

const int N = 6;
int w[N][N] = { {0,2,2,3,1,4},
			   {2,0,1,5,2,3},
			   {2,1,0,2,1,4},
			   {3,5,2,0,6,2},
			   {1,2,1,6,0,1},
			   {4,3,4,2,1,0} };//图的邻接矩阵 
int m[N][N];    //m[i][j]表示多边形{Vi-1VkVj}的最优权值
int s[N][N];    //s[i][j]记录Vi-1到Vj最优三角剖分的中间点K

int main(int argc, char** argv)
{
	//自顶向下
	cout << MinWeightTriangulation(1, N - 1) << endl;
	//自底向上
	cout << MinWeightTriangulation_2(N - 1) << endl;

	PrintTriangulation(1, N - 1); //输出组成最优解的各个三角形的周长 

	system("pause");
	return 0;
}


int MinWeightTriangulation(int i, int j)//自顶向下，使用备忘录数组的动态规划算法  
{
	if (m[i][j] != 0) {
		return m[i][j];
	}
		
	if (i == j) {
		return 0;
	}
	
	//先处理k=i的情形，注意我们取顶点vi-1为起点		
	m[i][j] = MinWeightTriangulation(i + 1, j) + GetWeight(i - 1, i, j); //MinWeightTriangulation(i, i)==0，就不写了 
	s[i][j] = i;
	//再处理i<k<j的情形
	for (int k = i + 1; k < j; k++)
	{
		int t = MinWeightTriangulation(i, k) + MinWeightTriangulation(k + 1, j) + GetWeight(i - 1, k, j);
		if (t < m[i][j])
		{
			m[i][j] = t;
			s[i][j] = k;
		}
	}
	return m[i][j];
}

int MinWeightTriangulation_2(int n)//自底向上的动态规划算法 
{
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;

	for (int r = 2; r <= n; r++)//r为当前计算的链长（子问题规模）    
	{
		for (int i = 1; i <= n - r + 1; i++) //n-r+1为最后一个r链的前边界 
		{
			int j = i + r - 1; //计算前边界为i，链长为r的链的后边界j，注意我们取顶点vi-1为起点    
			//先处理k=i的情形
			m[i][j] = m[i][i] + m[i + 1][j] + GetWeight(i - 1, i, j);
			s[i][j] = i;
			//再处理i<k<j的情形
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + GetWeight(i - 1, k, j);
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}

	return m[1][n];
}

int GetWeight(int i, int k, int j)//计算三角形的周长 
{
	return w[i][k] + w[k][j] + w[j][i];
}

void PrintTriangulation(int i, int j) //输出组成最优解的各个三角形的周长 
{
	if (i == j) {
		return;
	}

	PrintTriangulation(i, s[i][j]);
	cout << "V" << i - 1 << "-V" << s[i][j] << "-V" << j << " = " << GetWeight(i - 1, s[i][j], j) << endl;
	PrintTriangulation(s[i][j] + 1, j);
}
