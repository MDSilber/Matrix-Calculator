#include "Matrix.h"
#include <iostream>
using std::cout;
using std::cin;

template<typename T>
Matrix<T>::Matrix(const unsigned int rows, const unsigned int columns, bool ask)
{
	mNumRows = rows;
	mNumCols = columns;
	askValues = ask;

	if(rows>0 && columns>0)
	{
		mData = new T* [mNumRows];
		for(int i = 0; i<mNumRows;i++)
		{
			mData[i] = new T[mNumCols];
		}

		if(ask)
		{
			cout << "\nPlease enter the elements with spaces between them, one row at a time, then hit enter.\n";
			for(int i = 0; i<mNumRows;i++)
			{
				for(int j = 0; j<mNumCols; j++)
				{
					std::cin >> mData[i][j];
				}
			}
		}

		else
		{
			for(int i = 0; i<mNumRows;i++)
			{
				for(int j = 0; j<mNumCols; j++)
				{
					mData[i][j] = 0;
				}
			}
		}
	}
}

template <typename T> Matrix<T>::Matrix(const Matrix<T>& rhs)
{
	mNumRows = rhs.mNumRows;
	mNumCols = rhs.mNumCols;

	if(mNumRows>0 && mNumCols>0){

		mData = new T* [mNumRows];

		for(int i = 0; i<mNumRows;i++)
		{
			mData[i] = new T[mNumCols];
		}

		for(int i = 0; i<mNumRows;i++)
		{
			for(int j = 0; j<mNumCols; j++)
			{
				mData[i][j] = rhs.mData[i][j];
			}
		}

	}
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& rhs)
{
	mNumRows = rhs.mNumRows;
	mNumCols = rhs.mNumCols;

	mData = new T* [mNumRows];
	for(int i = 0; i<mNumRows;i++)
	{
		mData[i] = new T[mNumCols];
	}


	for(int i = 0; i<mNumRows;i++)
	{
		for(int j = 0; j<mNumCols; j++)
		{
			mData[i][j] = rhs.mData[i][j];
		}
	}

	return *this;
}

template <typename T> Matrix<T>::~Matrix()
{
	for(int i = 0; i<mNumRows; i++)
	{
		delete []mData[i];
	}
	delete []mData;
}

template <typename T> void Matrix<T>::setSize(const unsigned int newRows, const unsigned int newCols)
{
	if(mNumRows == newRows && mNumCols == newCols)
	{
		return;
	}

	if(mNumRows == 0 && mNumCols == 0)
	{
		//recreate array
		mData = new T* [newRows];
		for(int i = 0; i<newRows;i++)
		{
			mData[i] = new T[newCols];
		}

		//Initialize to zero
		for(int i = 0; i<newRows; i++)
		{
			for(int j = 0; j<newCols; j++)
			{
				mData[i][j] = 0;
			}
		}
	}

	if(mNumRows > 0 && mNumCols > 0)
	{
		//Deallocate memory completely, then reallocate as necessary

		if(newRows == 0 || newCols == 0)
		{
			return;
		}

		//Delete
		for(int i = 0; i<mNumRows; i++)
		{
			delete []mData[i];
		}
		delete []mData;

		//Make again
		mData = new T* [newRows];
		for(int i = 0; i<newRows;i++)
		{
			mData[i] = new T[newCols];
		}

		//Initialize to zero
		for(int i = 0; i<newRows; i++)
		{
			for(int j = 0; j<newCols; j++)
			{
				mData[i][j] = 0;
			}
		}
	}
	/*4 cases:
	 * 1. Originally (0,0), need to allocate new memory
	 * 2. Originally allocated, need to delete to (0,0)
	 * 3. Originally (n,m), need to change to same dimensions (return nothing)
	 * 4. Originally (n,m), need to change to (i,j)
	 */
}

template <typename T> Matrix<T> Matrix<T>::transpose() const
{
	for(int i = 0; i<mNumRows; i++)
	{
		for(int j = 0; i<mNumCols; j++)
		{
			mData[i][j] = mData[j][i];
		}
	}

	return *this;
}

/*template <typename T> Matrix<T>& Matrix<T>::operator+=(const Matrix& a)
		{
	*this = *this + a;
	return *this;
		}

template <typename T> Matrix<T>& Matrix<T>::operator-=(const Matrix& a)
		{
	*this = *this + a;
	return *this;
		}
*/
template <typename T> void Matrix<T>::setValue(int row, int column)
{
	std::cout << "\nWhat row and column would you like to change?\n";
	std::cin >> row >> column;
	std::cout << "\nWhat would you like the value to be?\n";
	T input;
	std::cin >> input;
	mData[row][column] = input;
}

template <typename T> void Matrix<T>::getValue(int row, int column)
{
	std::cout << "\nWhat are the row and column of the value you would like to return?\n";
	std::cin >> row >> column;
	std::cout << "\nThe value you requested is: " << mData[row][column] << "\n";
}

template <typename T> void Matrix<T>::print()
{
	for(int i = 0; i<mNumRows; i++)
	{
		for(int j = 0; j<mNumCols; j++)
		{
			std::cout << mData[i][j] << " ";
		}
		std::cout << "\n";
	}
}

template <typename T> T& Matrix<T>::operator()(const unsigned int row, const unsigned int column)
{
	return mData[row][column];
}

template <typename T> const T& Matrix<T>::operator()(const unsigned int row, const unsigned int column) const
{
	return mData[row][column];
}

template <typename T> Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
	if(a.mNumRows != b.numRows() || a.mNumCols != b.numCols())
	{
		std::cout << "\nThis is an illegal operation. You cannot add two matrices\n";
		std::cout << "with different dimensions.\n";
		exit(1);
	}

	Matrix<T> solution(a.mNumRows, a.mNumCols, false);

	for(int i = 0; i<a.mNumRows; i++)
	{
		for(int j = 0; j<a.mNumCols; j++)
		{
			solution(i,j) = a(i,j)+b(i,j);
		}
	}

	return solution;
}

template <typename T> Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b)
{
	if(a.mNumRows != b.numRows() || a.mNumCols != b.numCols())
	{
		std::cout << "\nThis is an illegal operation. You cannot subtract two matrices\n";
		std::cout << "with different dimensions.\n";
		exit(1);
	}

	Matrix<T> solution(a.mNumRows, a.mNumCols, false);

	for(int i = 0; i<a.mNumRows; i++)
	{
		for(int j = 0; j<a.mNumCols; j++)
		{
			solution(i,j) = a(i,j)-b(i,j);		
		}
	}

	return solution;
}

template <typename T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
{
	if(a.mNumCols != b.numRows())
	{
		std::cout << "\nThese two matrices cannot be multiplied. Please restart program.\n";
		exit(1);
	}

	Matrix<T> solution(a.mNumRows, b.numCols(), false);

	for(int i = 0; i< a.mNumRows; i++)
	{
		for(int j = 0; j<b.numCols(); j++)
		{
			solution(i,j) = 0;
			for(int k = 0; k<a.mNumCols;k++)
			{
				solution(i,j) = solution(i,j) + a(i,k)*b(k,j);
			}
		}
	}

	return solution;
}

template <typename T> std::ostream& operator<<(std::ostream& output, const Matrix<T>& a)
{
	for(int i = 0; i<a.mNumRows; i++)
	{
		for(int j = 0; j<a.mNumCols; j++)
		{
			output << a.mData[i][j] << " ";
		}
		output << "\n";
	}

	return output;
}

