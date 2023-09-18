#include <iostream>
#include <vector>
using namespace std;

/*
Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and supports two methods:

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
2. getValue(int row, int col)

Returns the current value of the coordinate (row,col) from the rectangle.
*/

class SubrectangleQueries
{
    vector<vector<int>> rec;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        rec = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                rec[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return rec[row][col];
    }
};

int main()
{
    vector<vector<int>> original = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    SubrectangleQueries s(original);

   cout<<s.getValue(0,2)<<endl;
   s.updateSubrectangle(0,0,2,2,55);
   cout<<s.getValue(0,0)<<endl;

    return 0;
}