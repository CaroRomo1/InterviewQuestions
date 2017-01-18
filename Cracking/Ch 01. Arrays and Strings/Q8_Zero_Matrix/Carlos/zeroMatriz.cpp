#include <iostream>

using namespace std;

void showMatrix(int mat[4][5])
{
	for (int i = 0; i < sizeof(mat[0][0]); i++)
	{
		for (int j = 0; j < sizeof(mat[0])/sizeof(mat[0][0]); j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void nullifyRows(int mat[4][5], int i)
{
	for (int j = 0; j < sizeof(mat[0]) / sizeof(mat[0][0]); j++)
	{
		mat[i][j] = 0;
	}
}

void nullifyCols(int mat[4][5], int j)
{
	for (int i = 0; i < sizeof(mat[0][0]); i++)
	{
		mat[i][j] = 0;
	}
}


void zeroMatrix(int mat[4][5])
{
	bool firstRowZero = false;
	bool firstColZero = false;

	int ren = sizeof(mat[0][0]);
	int col = sizeof(mat[0]) / sizeof(mat[0][0]);

	//Revisa si el primer renglon tiene un 0
	for (int j = 0; j < col; j++)
	{
		if (mat[0][j] == 0)
		{
			firstRowZero = true;
			break;
		}
	}

	//Revisa si la primer columna tiene un 0
	for (int i = 0; i < ren; i++)
	{
		if (mat[i][0] == 0)
		{
			firstColZero = true;
			break;
		}
	}

	//Encuentra los ceros en el resto de la matriz
	for (int i = 1; i < ren; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (mat[i][j] == 0)
			{
				mat[i][0] = 0;
				mat[0][j] = 0;
			}
		}
	}

	//Nullify rows based on zeros position
	for (int i = 1; i < ren; i++)
	{
		if (mat[i][0] == 0)
		{
			nullifyRows(mat, i);
		}
	}

	//Nullify columns based on zeros position
	for (int j = 1; j < col; j++)
	{
		if (mat[0][j] == 0)
		{
			nullifyCols(mat, j);
		}
	}

	//Nullify first row
	if (firstRowZero)
	{
		nullifyCols(mat, 0);
	}

	if (firstColZero)
	{
		nullifyCols(mat, 0);
	}

}

//Tamaño de renglon: sizeof(mat[0][0])
//Tamaño de columna: sizeof(mat[0])/sizeof(mat[0][0])

int main()
{
	int mat[4][5] = {
		{1,3,6,3,5} ,
		{0,2,3,5,5} ,
		{3,2,3,6,5} ,
		{1,1,1,1,0} };

	showMatrix(mat);

	zeroMatrix(mat);

	showMatrix(mat);

	system("pause");

}