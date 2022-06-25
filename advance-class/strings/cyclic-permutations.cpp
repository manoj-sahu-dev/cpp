#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}
vector<int> getLps(string A);
vector<int> generateLPS(string A);

int main()
{
    system("clear");

    string A = "110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111";
    string B = "110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111110111111111011111111101111111";
    string newString = A + "$" + B;
    newString.append(B.begin(), B.end() - 1);
    vector<int> lps = getLps(newString);
    print(lps);

    int count = 0, n = A.length();
    for (auto x : lps)
    {
        if (x == n)
        {
            count += 1;
        }
    }
    cout << count << endl;

    lps = generateLPS(newString);
    print(lps);
    count = 0;
    for (auto x : lps)
    {
        if (x == n)
        {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}

vector<int> generateLPS(string A)
{
    vector<int> L(A.length(), 0);
    int i = 1, j = 0;
    while (i < A.length())
    {
        if (A[i] == A[j])
        {
            L[i++] = ++j;
        }
        else
        {
            if (j == 0)
            {
                L[i++] = 0;
            }
            else
            {
                j = L[j - 1];
            }
        }
    }
    return L;
}

vector<int> getLps(string A)
{
    int i = 0, n = A.length(), j = 1;
    vector<int> lps(n, 0);

    while (j < n)
    {
        if (A[i] == A[j])
        {
            i += 1;
            lps[j] = i;
            j += 1;
        }
        else
        {

            if (i == 0)
            {
                lps[j] = 0;
                j += 1;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }
    return lps;
}