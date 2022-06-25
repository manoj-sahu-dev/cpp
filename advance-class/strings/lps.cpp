#include <iostream>
#include <vector>
using namespace std;

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

vector<int> generateLPS(string &A)
{
    int n = A.length();
    vector<int> lps(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x = lsp[i - 1];
        while (A[x] != A[i])
        {
            if (x == 0)
            {
                x = -1;
                break;
            }
            x = lps[x - 1];
        }
        lps[i] = x + 1;
    }
    return lps;
}
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}