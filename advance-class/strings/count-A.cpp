#include <iostream>

using namespace std;

int countA(string &A)
{
    int count = 0;

    for (auto a : A)
    {
        cout << a << " ";
        if (a == 'a')
        {
            count++;
        }
    }
    cout << endl;

    return (count * (count + 1)) / 2;
}
int main(int argc, char **argv)
{
    system("clear");
    string A = "aab";
    cout << "enter: ";
    cin >> A;
    int result = countA(A);
    cout << "result: " << result << endl;
    return 0;
}