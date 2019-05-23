#include "stdafx.h"
#include <iostream>
using namespace std;

template<class A>
class CMatrix {
private:
	int Row;
	int Col;
	A **Data;
public:

	CMatrix(int newRow = 1, int newCol = 1)
	{
		Data = new A *[newRow];
		if (Data == nullptr)
		{
			exit(0);
		}
		for (int i = 0; i < newRow; i++)
		{
			Data[i] = new A[newCol];
			if (Data[i] == nullptr)
			{
				for (int j = 0; j < i; j++)
					delete Data[j];
				delete Data;
				exit(0);
			}
		}
		Row = newRow;
		Col = newCol;
	}

	CMatrix(const CMatrix &m) 
	{
		cout << "Copy Construct";
		
		Data = new A*[m.Row];
		for (int i = 0; i < m.Row; i++)
			Data[i] = new A[m.Col];
		Col = m.Col;
		Row = m.Row;
		for (int i = 0; i < Row; i++)
			for (int j = 0; j < Col; j++)
				Data[i][j] = m.Data[i][j];

	}
	~CMatrix()
	{
		cout << "Destroy"<<Data;
		for (int i = 0; i < Row; i++)
			delete[] Data[i];
		delete[] Data;
		Row = 0;
		Col = 0;
	}
	////////////////////////////////////////
	int getRow()
	{
		return Row;
	}
	int getCol() {
		return Col;
	}
	A **getData() 
	{
		return Data;
	}
	void setRow(int newRow)
	{
		Row = newRow;
	}
	void setCol(int newCol)
	{
		Col = newCol;
	}
	int setData(int newRow, int newCol, A **value)
	{
		for (int i = 0; i < Row; i++)
			delete Data[i];
		delete Data;
		Data = value;
		Row = newRow;
		Col = newCol;
		return 1;
	}
	A getElement(int indexRow, int indexCol)
	{
		return Data[indexRow, indexCol];
	}
	////////////////////////////////////////
	template<typename A>
	friend CMatrix<A> operator+(CMatrix<A>& a, CMatrix<A>& b)
	{
		if (!((a.Row == b.Row) && (a.Col == b.Col)))
			cout << "Error";
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] + b.Data[i][j];
		return res;
	}
	template<typename A>
	friend CMatrix<A> operator+(CMatrix<A>& a, A b)
	{
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] + b;
		return res;
	}
	template<typename A>
	friend CMatrix<A> operator+(A b, CMatrix<A>& a)//return a+b
	{
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] + b;
		return res;
	}
	////////////////////////////////
	template<typename A>
	friend CMatrix<A> operator-(CMatrix<A>& a, CMatrix<A>& b)
	{
		if (!((a.Row == b.Row) && (a.Col == b.Col)))
			cout << "Error";
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] - b.Data[i][j];
		return res;
	}
	template<typename A>
	friend CMatrix<A> operator-(CMatrix<A>& a, A b)
	{
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] - b;
		return res;
	}
	template<typename A>
	friend CMatrix<A> operator-(A b, CMatrix<A>& a)//return-1*a+b
	{
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = -1*(a.Data[i][j] + b);
		return res;
	}
	///////////////////////////////////////
	template<typename A>
	friend CMatrix<A> operator*(CMatrix<A>& a, CMatrix<A> &b)
	{
		if (!((a.Row == b.Row) && (a.Col == b.Col)))
			cout << "Error";
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] * b.Data[i][j];
		return res;
	}

	template<typename A>
	friend CMatrix<A> operator*(CMatrix<A>& a, A b)
	{
		
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] * b;
		return res;
	}
	template<typename A>
	friend CMatrix<A> operator*(A b, CMatrix<A>& a)//return a*b
	{
		
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] * b;
		return res;
	}
	//////////////////////////
	template<typename A>
	friend CMatrix<A> operator/(CMatrix<A>& a, A b)//return a*1/b
	{
		CMatrix res(a.Row, a.Col);
		for (int i = 0; i < a.Row; i++)
			for (int j = 0; j < a.Col; j++)
				res.Data[i][j] = a.Data[i][j] *(1/b);
		return res;
	}

	void operator=(const CMatrix& m)
	{

		Data = new A*[m.Row];
		for (int i = 0; i < m.Row; i++)
			Data[i] = new A[m.Col];
		Col = m.Col;
		Row = m.Row;
		for (int i = 0; i < Row; i++)
			for (int j = 0; j < Col; j++)
				Data[i][j] = m.Data[i][j];
	}
	bool operator==(CMatrix& a)
	{
		if (Row != a.Row)
		{
			return false;
		}
		if (Col != a.Col)
		{
			return false;
		}

		for (int i = 0; i < Row; i++)
			for (int j = 0; j < Col; j++)
				if (Data[i][j] != a.Data[i][j])
					return false;

		return true;
	}

	////////////////////////////////////
	template<typename A>
	friend ostream & operator<<(ostream& stream, CMatrix<A>& M)
	{
		stream << "\nMatrix[" << M.Row << "][" << M.Col << "] at " << M.Data << "=";
		for (int i = 0; i < M.Row; i++)
		{
			stream << '\n';
			for (int j = 0; j < M.Col; j++)
				stream << M.Data[i][j] << '\t';
		}
		return stream;
	}
	template<typename A>
	friend istream & operator>>(istream& stream, CMatrix<A>& M)
	{
		for (int i = 0; i < M.Row; i++)
			for (int j = 0; j < M.Col; j++)
				stream >> M.Data[i][j];
		return stream;
	}



};

int main()
{
	CMatrix<int> a(2,2);
	CMatrix<int> b(2,2);
	cin >> a >> b;
	CMatrix<int> proiz =a * b;
	CMatrix<int> sum = a + b;
	CMatrix<int> minus = a - b;

	cout << a << b << proiz << sum << minus;
	system("pause");
}
