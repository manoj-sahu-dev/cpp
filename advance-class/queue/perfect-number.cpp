#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Given an integer A, you have to find the Ath Perfect Number.
 * A Perfect Number has the following properties:
 * It comprises only 1 and 2.
 * The number of digits in a Perfect number is even.
 * It is a palindrome number.
 * For example, 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.
 *
 * @param A integer
 * @return string
 */
string solve(int A)
{
    string res;
    queue<string> series;
    int count = 0;
    series.push("1");
    series.push("2");

    while (count < A)
    {
        string num = series.front();
        series.push(num + "1");
        series.push(num + "2");
        series.pop();
        cout << num << endl;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            num += num[i];
        }
        res = num;
        cout << num << endl;
        count += 1;
    }

    return res;
}

int main()
{
    system("clear");
    cout << "enter term: ";
    int n = 0;
    cin >> n;
    string result = solve(n);
    cout << n << "th term of perrfect number : " << result << endl;
    return 0;
}
