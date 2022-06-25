#include <iostream>
#include <vector>

using namespace std;
enum Direction
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

void print(vector<int> &A)
{
    cout << "\ncontent of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

void print(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    cout << "\ncontent of vector: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int> > generateSpiralMatrix(int A);
int main()
{
    system("clear");
    int n = 0;
    cout << "enter a number to generate a matrix ";
    cin >> n;
    vector<vector<int> > matrix = generateSpiralMatrix(n);
    print(matrix);
    return 0;
}
vector<vector<int> > generateSpiralMatrix(int A)
{
    vector<vector<int> > matrix(A, vector<int>(A, 0));
    int maxNumber = A * A, currentNumber = 0, row = 0, column = 0;
    Direction direction = RIGHT;
    while (currentNumber < maxNumber)
    {
        matrix[row][column] = ++currentNumber;
        if (direction == RIGHT)
        {
            column += 1;
            if (column == A || matrix[row][column] != 0)
            {
                direction = DOWN;
                row += 1;
                column -= 1;
            }
        }
        else if (direction == DOWN)
        {
            row += 1;
            if (row == A || matrix[row][column] != 0)
            {
                direction = LEFT;
                row -= 1;
                column -= 1;
            }
        }
        else if (direction == LEFT)
        {
            column -= 1;
            if (column < 0 || matrix[row][column] != 0)
            {
                direction = UP;
                column += 1;
                row -= 1;
            }
        }
        else if (direction == UP)
        {
            row -= 1;
            if (row < 0 || matrix[row][column] != 0)
            {
                direction = RIGHT;
                row += 1;
                column += 1;
            }
        }
    }
    return matrix;
}