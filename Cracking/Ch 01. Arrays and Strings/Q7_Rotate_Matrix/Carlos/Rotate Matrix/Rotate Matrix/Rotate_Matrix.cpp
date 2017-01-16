#include <iostream>

using namespace std;

bool rotateMatrix(int matrix[4][4])
{
	/*if (sizeof(matrix) == 0 || sizeof(matrix) != sizeof(matrix[0]))
	{
		return false;
	}*/

	int n = sizeof(matrix);
	for (int layer = 0; layer < n/2; layer++)
	{
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; i++)
		{
			int offset = i - first;

			//Guarda el valor de top
			int top = matrix[first][i];

			//left -> top
			matrix[first][i] = matrix[last - offset][first];

			//bottom -> left
			matrix[last - offset][first] = matrix[last][last - offset];

			//right -> bottom
			matrix[last][last - offset] = matrix[i][last];

			//top -> right
			matrix[i][last] = top;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	return true;
}

int main()
{
	int matrix[4][4];

	int cont = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = cont;
			cont++;
		}
	}

	rotateMatrix(matrix);

	system("pause");
}