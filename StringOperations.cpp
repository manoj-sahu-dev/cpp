#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<char> to_lower(vector<char> &A);
vector<char> to_upper(vector<char> &A);
int isAlphaNumeric(vector<char> &A);
int isAlphaBets(vector<char> &A);
string reverseString(string A, int start, int end);
string reverseSentence(string A);
int isPalindrome(string A, int start, int end);
int findLongestPalindrome(string A, int fid, int sid);
string longestPalindrome(string A);
int findOccurrences(string A, string B);
string playingWithString(string A);
string longestCommonPrefix(vector<string> &A);
bool isVowel(char c);
int findAmazingSubstring(string A);
int changeChar(string A);

void Print(vector<char> &A);
int main()
{
    /*vector<char> A{'S', 'c', 'a', 'l', 'e', 'r', 'A', 'c', 'a', 'd', 'e', 'm', 'y'};
    Print(A);
    int result = isAlphaBets(A);
    cout << "result = " << result << endl;*/

    /*string A = "scaler";
    cout << "A = " << A << endl;
    A = reverseString(A, 0, A.length() - 1);
    cout << "after reverse A = " << A << endl; */

    /*string A = "aabaa";
    int result = isPalindrome(A, 0, A.size() - 1);
    cout << "result = " << result << endl;*/

    /*string A = "crulgzfkif gg ombt vemmoxrgf qoddptokkz op xdq hv ";
    A = reverseSentence(A);
    cout << A << endl; */

    /*string A = "bobob";
    string B = "bob";
    cout << "A = " << A << endl;
    int result = findOccurrences(A, B); */

    /*string A = "AbcaZeoB";
    string result = playingWithString(A);
    cout << "result = " << result << endl;*/

    /*vector<string> A{"abab", "ab", "abcd"};
    string result = longestCommonPrefix(A);
    cout << "result = " << result << endl;*/
    // string A = "AzZGBauYuTknYjjWEEbLvqMQwnoSgXKBdHKEVpeoxYNNtBfrxQrPauttMzjKFayKwMeuChjzCocgAHfAmPCatOqarzLuabyTnxoheeocVshfERNssVPfRyPmwvOVGbzNAuvryYNWwIeyZLMlLbkcFFJRHjEIgIwOThRJJFpLbunVrbhAYsMtdsKslLAGElwrZjvZweIytMpPEYVmktQeNleNROcTjrNxXeHvOMMTMfqZHTUjetojHFzZwOekfAILYISANxeJFRNgeZDKoOTddXqxduPIjGXsRSSkgIqKMeSqlQwAKtdrkvHLgmKleNAPEztGMPmZzUuCImLAhzUnXmsVzFvJUTeIKleuRnMPNAPWJYAZLXgzTBPmkXVShbBSlIAJSeFgvRFvcoqfVFgHUefxUxuYFCfUxbxlOslUhYRFXKmMmqDIQhhfXyGqUwGMSYeLLpEsKAhvFUzavDCOUgtmmNMnsvfmCdPWuWIjuUfZCBTrWnaDopbqXcjzSqRMpQWIBNnMcOQZjDkjPkxsuwENYQyjgSHFJrgSLnwbEInBfdeIfBbVuZZbBrblJgKHOmLZACLQkSRxxQJeUMPIQutraxFtrRcSeqAejOTSqaFGglQOoWPkcNOnLIgfclWNtjGQRVMlqCPUnUlOLbHfkzUyNAmTsswWtZjIGUBrLmRmstHgVcRUgWdQTCEPRzjPVTMJRJocYHftwoRzOSyQexjmceRHdqFdgNuGmGTUdXQaNwKmvOUzZPzGCBVcbVLgMoQrESbpVGteVVntOwEWxXsZnSAoIfBSsWVhDFBuDTkcrnsPdmmSHymouxHlcgtjgKUAPznxsIRUjDFsrjadJjEtPaWTVBHpatqYeSgrpWJDOGfgIGQPcTIXVsCVyCfKMpcXWGkvwuRuTmvCbNMLeUkZrEpYZdlKAgFELfwCCbZCYBcXhfUrsIHfdwhYyxHKAMYMERwlyRtxObDoxBhjXmynYkmkYZrkzlCuvrhW";
    string A = "abcabbccd";
    int result = changeChar(A);
    cout << "A = " << A << ", change char = " << result << endl;
    return 0;
}

int solve(vector<string> &A, string B)
{
    unordered_map<char, int> myMap;
    for (int i = 0; i < 26; i++)
    {
        myMap[B[i]] = i;
    }
    vector<string> vec;

    for (string it : A)
    {
        string s;
        for (int i = 0; i < it.size(); i++)
        {
            s += myMap[it[i]];
        }
        vec.push_back(s);
    }

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
        {
            return 0;
        }
    }

    return 1;
}

int changeChar(string A)
{
    int n = A.size(), match = 1;

    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        int start = 0, end = i, pal = 1;
        while (start < end)
        {
            if (A[start] != A[end])
            {
                pal = 0;
                break;
            }
            start++;
            end--;
        }

        if (pal)
        {
            match = i + 1;
        }
    }

    return n - match;
}
bool isVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }
    return false;
}

int findAmazingSubstring(string A)
{
    int fp = 0, sp = 0, count = 0, n = A.length();

    for (fp = 0; fp < n; fp++)
    {
        bool isVowelChar = isVowel(A[fp]);
        // cout << A[fp] << ", isVowel = " << isVowelChar << endl;
        if (isVowelChar)
        {
            count += (n - fp);
            // cout << A[fp] << ", isVowel =====>>> " << isVowelChar << endl;
            // cout << (n - sp) + 1 << ", count = " << count << endl;
            // for (sp = fp; sp < n; sp++)
            // {
            //     count += 1;
            // }
        }
    }

    return count % 10003;
}
string longestCommonPrefix(vector<string> &A)
{
    int i = 0, minLen = INT_MAX, len = A.size();
    string mcp;
    for (int i = 0; i < len; i++)
    {
        int size = A[i].length();
        minLen = min(minLen, size);
    }
    int idx = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[i].length() == minLen)
        {
            idx = i;
            // cout << "idx " << idx << endl;
            break;
        }
    }

    while (i < minLen)
    {
        char d = A[idx][i];
        int nomatch = 0;
        // cout << "character = " << d << endl;
        for (int j = 0; j < len; j++)
        {
            // cout << "A[" << j << "][" << i << "] = " << A[j][i] << endl;
            if (d != A[j][i])
            {
                nomatch = 1;
                break;
            }
        }
        if (nomatch == 0)
        {
            mcp += d;
        }
        else
        {
            break;
        }
        // cout << "nomatch = " << nomatch << ", mcp = " << mcp << endl;
        i += 1;
    }
    return mcp;
}
string playingWithString(string A)
{
    A += A;
    int n = A.length(), i = 0;

    while (i < n)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            A[i] = '#';
        }
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
    return A;
}

int findOccurrences(string A, string B)
{
    int n = A.length(), i = 0, bn = B.length(), count = 0, li = 0;
    while (i < (n - bn) + 1)
    {
        li = 0;
        while (B[li] == A[i + li] && li < bn)
        {
            li += 1;
        }
        if (li == bn)
        {
            count += 1;
        }
        i++;
    }

    return count;
}
int findLongestPalindrome(string A, int fid, int sid)
{
    while (fid >= 0 && sid < A.length())
    {
        if (A[fid] != A[sid])
        {
            break;
        }
        fid -= 1;
        sid += 1;
    }
    cout << "fid = " << fid << " sid = " << sid << ", gap = " << (sid - fid - 1) << endl;
    return sid - fid - 1;
}
string longestPalindrome(string A)
{
    int n = A.length();
    int ans = 0, amax = 0, fid = 0, sid = 0, diff = 0, start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        fid = i, sid = i;
        while (fid >= 0 && sid < A.length())
        {
            if (A[fid] != A[sid])
            {
                break;
            }
            fid -= 1;
            sid += 1;
        }
        diff = sid - fid - 1;
        ans = max(ans, diff);

        if (ans > amax)
        {
            amax = ans;
            start = fid;
            end = sid;
            // cout << "start = " << start << " end = " << end << endl;
        }
        if (i < n - 1)
        {
            fid = i, sid = i + 1;
            while (fid >= 0 && sid < A.length())
            {
                if (A[fid] != A[sid])
                {
                    break;
                }
                fid -= 1;
                sid += 1;
            }
            diff = sid - fid - 1;
            ans = max(ans, diff);

            if (ans > amax)
            {
                amax = ans;
                start = fid;
                end = sid;
                // cout << "start = " << start << " end = " << end << endl;
            }
        }
    }
    cout << "start = " << start << " end = " << end << endl;
    cout << ans << endl;
    string B;
    for (int i = start + 1; i < end; i++)
        B += A[i];
    return B;
}
int isPalindrome(string A, int start, int end)
{
    // cout << A << endl;
    while (start <= end)
    {
        // cout << "start = " << start << ", end = " << end << ", " << A[start] << " " << A[end] << endl;
        if (A[start] != A[end])
            return 1;
        start += 1;
        end -= 1;
    }
    return 0;
}
string reverseSentence(string A)
{
    // cout << "origianal = " << A << endl;
    int s = 0, e = 0, n = A.length();

    A = reverseString(A, 0, n - 1);
    // cout << "reversed = " << A << endl;

    while (e < n)
    {
        e = s + 1;
        while (A[e] != ' ' && e < n)
        {
            e += 1;
        }
        A = reverseString(A, s, e - 1);
        s = e + 1;
        // cout << s << " " << e << " " << A << endl;
    }
    s = 0, n = A.length();
    cout << A << endl;
    string N;
    while (s < n)
    {
        if (A[s] == ' ')
        {
            e = 0;
            N += A[s];

            while (A[++s] == ' ')
            {
                // e += 1;
                // cout << s << endl;
            }
            // cout << A << endl;
        }
        N += A[s];
        s += 1;
    }

    return N;
}
string reverseString(string A, int start, int end)
{
    // cout << "start = " << start << " end = " << end << endl;
    while (start < end)
    {
        swap(A[start], A[end]);
        start += 1;
        end -= 1;
    }
    return A;
}

int isAlphaBets(vector<char> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))
        {
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

int isAlphaNumeric(vector<char> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '0' && A[i] <= '9'))
        {
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
vector<char> to_upper(vector<char> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] >= 'a' && A[i] <= 'z')
        {
            A[i] -= 32;
        }
    }

    return A;
}

vector<char> to_lower(vector<char> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A[i] += 32;
        }
    }

    return A;
}
void Print(vector<char> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}