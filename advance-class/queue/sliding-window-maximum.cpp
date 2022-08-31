#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * @brief Given an array of integers A. There is a sliding window of size B, moving from the very left of the array to the very right.
 * You can only see the B numbers in the window. Each time the sliding window moves rightwards by one position.
 * You have to find the maximum for each window.
 *
 * Return an array C, where C[i] is the maximum value in the array from A[i] to A[i+B-1].
 *
 * Refer to the given example for clarity.
 *
 * NOTE: If B > length of the array, return 1 element with the max of the array
 *
 * @param A array of integers
 * @param B sliding window size
 * @return vector<int>
 */
vector<int> slidingMaximum(const vector<int> &A, int B);
vector<int> slidingMaximumBF(const vector<int> &A, int B);
void print(vector<int> &A, string msg = "")
{
    cout << msg << " vector ";
    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int B = 2;
    print(A, "input");
    vector<int> result = slidingMaximumBF(A, B);
    print(result, "brut force result");
    result = slidingMaximum(A, B);
    print(result, "optimized result");
    return 0;
}

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    deque<int> running_stream;
    vector<int> result;
    int n = A.size(), i = 0, num = 0;
    for (i = 0; i < B; i++)
    {
        num = A[i];

        while (!running_stream.empty() && num >= A[running_stream.back()])
        {
            running_stream.pop_back();
        }
        running_stream.push_back(i);
    }

    for (; i < n; i++)
    {
        num = A[i];
        result.push_back(A[running_stream.front()]);
        while (!running_stream.empty() && running_stream.front() <= i - B)
        {
            running_stream.pop_front();
        }

        while (!running_stream.empty() && num >= A[running_stream.back()])
        {
            running_stream.pop_back();
        }
        running_stream.push_back(i);
    }
    result.push_back(A[running_stream.front()]);
    return result;
}

vector<int> slidingMaximumBF(const vector<int> &A, int B)
{
    int n = A.size(), right = n - B;
    vector<int> result;
    for (int i = 0; i <= right; i++)
    {
        int max_sliding = INT_MIN;
        for (int j = i; j < (i + B); j++)
        {
            max_sliding = max(max_sliding, A[j]);
        }
        result.push_back(max_sliding);
    }
    return result;
}