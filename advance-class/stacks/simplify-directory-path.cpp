#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Given a string A representing an absolute path for a file (Unix-style).
 * Return the string A after simplifying the absolute path.
 *
 * Note:
 * In Unix-style file system:
 * A period '.' refers to the current directory.
 * A double period '..' refers to the directory up a level.
 * Any multiple consecutive slashes '//' are treated as a single slash '/'.
 * In Simplified Absolute path:
 *
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path doesn't end with trailing slashes '/'.
 * The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
 * Path will not have whitespace characters.
 * @param A
 * @return string
 */
string simplifyPath(string A);

int main(int argc, char **argv)
{
    system("clear");
    string A = "/a/./b/../../c/";
    string simple = simplifyPath(A);
    cout << "simplify Path : " << simple << endl;
    return 0;
}

string simplifyPath(string A)
{
    string ch = "";
    int len = A.length();
    stack<string> st;
    for (int i = 0; i < len; i++)
    {
        ch.clear();
        while (A[i] == '/')
        {
            i++;
        }
        while (i < len && A[i] != '/')
        {
            ch.push_back(A[i]);
            i += 1;
        }
        if (ch.compare("..") == 0)
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (ch.compare(".") == 0)
        {
            continue;
        }
        else if (ch.length() != 0)
        {
            st.push(ch);
        }
    }
    stack<string> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    string result = "/";
    while (!temp.empty())
    {
        string t = temp.top();
        if (temp.size() != 1)
        {
            result.append(t + "/");
        }
        else
        {
            result.append(t);
        }
        temp.pop();
    }
    return result;
}