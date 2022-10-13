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
        if(str[i+2] == '\n')
        {
            break;
        }
        if(str[i]==']')
        {
            size.row++;
            continue;
        }
        if(str[i]>47 && str[i]<58)
        {
            matrix[size.row][size.column] = str[i] - 48;
            size.column++;
        }
    }
    return size;
}

void set_zero(SIZE size, int zero_matrix[size.row][size.column], int matrix[100][100])
{
    std::copy(matrix[0][0], matrix[0][0] + size.row*size.column, zero_matrix[0][0]);
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
    int zero_matrix[size.row][size.column];
    set_zero(size, zero_matrix, matrix);
    return 0;
}
