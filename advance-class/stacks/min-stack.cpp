#include <bits/stdc++.h>

using namespace std;
class MinStack
{
    stack<pair<int, int>> st;
    MinStack()
    {
        st = {};
    }

    void push(int x)
    {
        if (st.size() == 0)
        {
            st.push({x, x});
        }
        else
        {
            int mn = st.top().second;
            st.push({x, min(mn, x)});
        }
    }

    void pop()
    {
        if (st.size() == 0)
            return;
        st.pop();
    }

    int top()
    {
        if (st.size() == 0)
            return -1;
        return st.top().first;
    }

    int getMin()
    {
        if (st.size() == 0)
            return -1;
        return st.top().second;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    return 0;
}
