#include <iostream>
#include <vector>

using namespace std;
int books(vector<int> &A, int B);
bool is_possible(vector<int> &A, int B, int mid);
int main()
{
    system("clear");
    vector<int> A{31, 14, 19, 75};
    int B = 12;
    int result = books(A, B);
    cout << "result = " << result << endl;
    return 0;
}
/**
 * @brief Given an array of integers A of size N and an integer B.
 * The College library has N books. The ith book has A[i] number of pages.
 * You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.
 *
 * A book will be allocated to exactly one student.
 * Each student has to be allocated at least one book.
 * Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
 * Calculate and return that minimum possible number.
 *
 * NOTE: Return -1 if a valid assignment is not possible.
 *
 * @param A
 * @param B
 * @return int
 */
int books(vector<int> &A, int B)
{
    if (A.size() < B)
        return -1;
    int start = 0, end = 0, mid = 0, ans = -1;
    for (int i = 0; i < A.size(); i++)
    {
        start = max(start, A[i]);
        end += A[i];
    }
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        cout << "start = " << start << " end = " << end << ", mid = " << mid << endl;
        if (is_possible(A, B, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

bool is_possible(vector<int> &A, int B, int mid)
{
    cout << "B = " << B << ", mid = " << mid << endl;
    int student_count = 1, page_sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cout << "i = " << i << ", A[i] = " << A[i] << ", student_count = " << student_count << endl;
        if (page_sum + A[i] <= mid)
        {
            page_sum += A[i];
        }
        else
        {
            student_count += 1;
            if (student_count > B || A[i] > mid)
                return false;
            page_sum = A[i];
        }
    }
    return true;
}