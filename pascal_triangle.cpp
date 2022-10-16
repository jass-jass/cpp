#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    vector<vector<int>> triangle {{1}};
    int rows;
    cin >> rows;
    for(int i = 1; i < rows; i++)
    {
        triangle.push_back(vector<int> (1, 1));
        for(int j = 1; j<i; j++)
        {
            triangle[i].push_back(triangle[i-1][j-1]+triangle[i-1][j]);
        }
        triangle[i].push_back(1);
    }
    for(int i = 0; i < triangle.size(); i++)
    {
        for(int j = 0; j<=i; j++)
            printf("%d ", triangle[i][j]);
        printf("\n");
    }
    return 0;
}
