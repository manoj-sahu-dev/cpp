#include <iostream>
#include <set>

using namespace std;

void print(set<char> mset)
{
    for (auto c : mset)
    {
        cout << c;
    }
}
/**
 * @brief Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 * Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.
 *
 * Note:
 * If there is no such window in A that covers all characters in B, return the empty string.
 * If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )
 *
 * @param A
 * @return int
 */
int getLongestSubstringLength(const string &A);

int main(int argc, char **argv)
{
    system("clear");
    string A = "h0jM9EvNVGhSlbgDxLnI34wvFk6V12QK6ncxcspvy7aZfuZYmXgtuCFK7ih4QSzYePvRFOyGSu9jyNd1Usv692TJrgDTxjRJ8dm8suQslHpMksOnW3NhYXkDpdaKqTd4jKw6Oa3ZG1wdsghE";

    int count = getLongestSubstringLength(A);

    cout << "longest string can be : " << count << endl;

    return 0;
}

int getLongestSubstringLength(const string &A)
{
    int count = 0, i = 0, j = 0, n = A.length();
    set<char> mset;
    while (j < n)
    {
        char jchar = A[j];
        if (mset.find(jchar) == mset.end())
        {
            mset.insert(jchar);
            int m = mset.size();
            count = max(count, m);
            j += 1;
        }

        else
        {
            char ichar = A[i];
            mset.erase(ichar);
            i++;
        }
    }
    return count;
}