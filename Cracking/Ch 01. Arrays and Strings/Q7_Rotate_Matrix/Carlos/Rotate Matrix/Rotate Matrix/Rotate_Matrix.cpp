#include <iostream>
using namespace std;

bool rotateMatrix(int **matrix, int n)
{
	/*if (sizeof(matrix) == 0 || sizeof(matrix) != sizeof(matrix[0]))
	{
		return false;
	}*/

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

	return true;
}

void dispMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int n;

	cout << "Size of matrix:" << endl;
	cin >> n;

	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	int cont = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = cont;
			cont++;
		}
	}

	cout << endl << "Original Matrix:" << endl;
	dispMatrix(matrix, n);

	rotateMatrix(matrix, n);

	cout << endl << "90 degrees clockwise Matrix:" << endl;
	dispMatrix(matrix, n);

	system("pause");
}