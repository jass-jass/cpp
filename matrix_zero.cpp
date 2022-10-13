#include <iostream>
#include <string>

using namespace std;

typedef struct SIZE
{
    int row, column;
} SIZE;

SIZE input(int matrix[100][100])
{
    SIZE size;
    string str;
    cin >> str;
    for(int i=0; i<(str.length()-1); i++)
    {
        if(str[i+2] == '\0')
        {
            break;
        }
        if(str[i]==']')
        {
            size.row++;
            size.column =0;
            continue;
        }
        if(str[i]>47 && str[i]<58)
        {
            matrix[size.row][size.column] = str[i] - 48;
            size.column++;
        }
    }
    size.row ++;
    return size;
}

//void output(SIZE size, int zero_matrix[size.row][size.column])
void output(SIZE size, int zero_matrix[100][100])
{
    cout << "[";
    for(int i=0; i<size.row; i++)
    {
        cout << "[";
        for(int j=0; j<size.column; j++)
        {
            cout << zero_matrix[i][j] <<",";
        }
        cout << "\b]";
    }
    cout << "]";
}

void copy(SIZE size, int zero_matrix[100][100], int matrix[100][100])
{
    for(int i=0; i<size.row; i++)
    {
        for(int j=0; j<size.column; j++)
        {
            zero_matrix[i][j] = matrix[i][j];
        }
    }
}

//void set_zero(SIZE size, int zero_matrix[size.row][size.column], int matrix[100][100])
void set_zero(SIZE size, int zero_matrix[100][100], int matrix[100][100])
{
    copy(size, zero_matrix, matrix);
    for(int i=0; i<size.row; i++)
    {
        for(int j=0; j<size.column; j++)
        {
            if(!matrix[i][j])
            {
                for(int k=0; k<size.column; k++)
                {
                    zero_matrix[i][k] = 0;
                }
                for(int k=0; k<size.row; k++)
                {
                    zero_matrix[k][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int matrix [100][100];
    SIZE size = input(matrix);
    int zero_matrix[100][100];
    set_zero(size, zero_matrix, matrix);
    output(size, zero_matrix);
    return 0;
}
