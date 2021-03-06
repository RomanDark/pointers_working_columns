// ConsoleApplication15.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>


using namespace std;

void _printA(int **a, int m, int n) {

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void delKN(int **a, int m, int &n, int k) {
	
	cin >> k;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = k; j < n; j++)
		{
			a[i][j] = a[i][j + 1];
			
		}
		
	}
	n--;

	//_printA(a, m, n);
}

void delLastN(int **a, int m, int &n) {
	n--;
	
	//_printA(a, m, n);
}

void delFirstN(int **a, int m, int &n) {

	n--;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = a[i][j + 1];
		}
	}
	
	//_printA(a, m, n);
}

void addP(int **a, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 9 + 1;
		}
	}
	_printA(a, m, n);

}

void _del(int **&a, int m) {

	for (int i = 0; i < m; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

void addKN(int **&a, int m, int &n, int k) {

	cin >> k;

	int **b;

	b = new int*[m];
	n++;

	for (int i = 0; i < m; i++)
	{
		b[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < k) b[i][j] = a[i][j]; else b[i][j + 1] = a[i][j];
		}
	}
	_del(a, m);

	a = b;
}

void check(int **a, int m, int n) {
	

	//дополнительный массив для записи всех сумм
	int *p;
	p = new int[m+n+2];


	int sum1 = 0; // сумма строк
	int sum2 = 0; // сумма столбцов
	int sum3 = 0; // сумма главной диагонали
	int sum4 = 0; // сумма побочной диагонали


	//сумма елементов строк и столбцов
	for (int i = 0; i < m; i++)
	{
		sum1 = 0;
		sum2 = 0;

		for (int j = 0; j < n; j++)
		{
			sum1 += a[i][j];
			sum2 += a[j][i];
		}

		//запись елементов в дополнительный массив
		p[i] = sum1;
		p[i + m] = sum2;
	}
	//сумма елементов диагоналей
	for (int i = 0; i < m; i++)
	{
		for (int j = 0, j1 = m - 1; j < n; j++, j1--)
		{
			if (i == j) sum3 += a[i][j];
			if (i + j1 == m - 1) sum4 += a[i][j1];
		}
		//запись елементов в дополнительнйы массив
		p[m + n] = sum3; 
		p[m + n + 1] = sum4;
	}


	//сравнение елементов друг с другом
	int z = 0;

	for (int i = 0; i <= m+n; i++)
	{
		if (p[i] == p[i + 1]) z = 1;  //если все равны то возврощаем 1
		else {
			z = 0; 
			break; //инчае выходим из цикла z = 0
		}
	}

	if (z == 0) cout << "ne yavlyaetsya magi4eskim!" << endl; else cout << "Magi4eskii!" << endl; 

	//вывод массива
	for (int i = 0; i < m+n+2; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	//удаление массива
	delete[] p;
}

int main()
{
	srand(time(NULL));
	
	int **a;
	int m = 3, n = 3;

	//создание динамического массива
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}*/

	addP(a, m, n);
	check(a, m, n); //вызов функции проверки

	_del(a, m);

	/*int **a;
	int m = 5, n = 5;

	cin >> m >> n;

	int k;

	a = new int*[m];
	
	for (int i = 0; i < m; i++)
	{
		a[i] = new int [n];
	}

	addP(a, m, n);
	

	//delKN(a, m, n, k = 0);

	//delLastN(a, m, n);
	//delFirstN(a, m, n);
	//addKN(a, m, n, k = 0);

	_printA(a, m, n);
	_del(a, m);
	*/

	system("pause");
    return 0;
}