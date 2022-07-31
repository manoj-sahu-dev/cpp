#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TrieNode
{
public:
    map<char, TrieNode *> children;
    int count = 0;
    bool isLeaf;
};

/**
 * @brief Given a list of N words, find the shortest unique prefix to represent each word in the list.
 * NOTE: Assume that no word is the prefix of another. In other words, the representation is always possible
 *
 * @param A
 * @return vector<string>
 */
vector<string> prefix(vector<string> &A);
/**
 * @brief Given an array of words A (dictionary) and another array B (which contain some words).
 * You have to return the binary array (of length |B|) as the answer where 1 denotes that the word is present in the dictionary and 0 denotes it is not present.
 * Formally, for each word in B, you need to return 1 if it is present in Dictionary and 0 if not.
 * Such problems can be seen in real life when we work on any online editor (like Google Documnet), if the word is not valid it is underlined by a red line.
 * NOTE: Try to do this in O(n) time complexity.
 *
 * @param A
 * @param B
 * @return vector<int>
 */
vector<int> spelling_checker(vector<string> &A, vector<string> &B);

/**
 * @brief We want to make a custom contacts finder applications as part of our college project.
 * The application must perform two types of operations:
 * Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name.
 * This must store B[i] as a new contact in the application.
 * Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial name to search the application for.
 * It must count the number of contacts starting with B[i].
 *
 * You have been given sequential add and find operations. You need to perform each operation in order.
 * And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .
 *
 * @param A
 * @param B
 * @return vector<int>
 */
vector<int> contact_finder(vector<int> &A, vector<string> &B);

/**
 * @brief Given two arrays of strings A of size N and B of size M.
 * Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using exactly one modification in B[i], Else C[i] = '0'.
 * NOTE: modification is defined as converting a character into another character.
 *
 * @param A
 * @param B
 * @return string
 */
string modified_search(vector<string> &A, vector<string> &B);
bool is_present_with_one_modification(TrieNode *A, string word);
void insertWords(TrieNode *root, vector<string> &A);
void insertWord(TrieNode *A, string word);
bool isPresent(TrieNode *A, string word);
int get_prefix_length(TrieNode *A, string word);
string get_prefix_string(TrieNode *A, string word);

void print(vector<int> &A)
{
    cout << "content of vector: ";
    for (int x : A)
        cout << x << " ";
    cout << endl;
}
void print(vector<string> &A)
{
    cout << "content of vector: ";
    for (string x : A)
        cout << x << " ";
    cout << endl;
}
int main(int argc, char **argv)
{
    system("clear");

    /*vector<string> words{"apple", "ball", "cat"};
    vector<string> pre = prefix(words);
    for (string word : pre)
    {
        cout << word << endl;
    }*/

    /*vector<string> A{"hat", "cat", "rat"};
    vector<string> B{"cat", "ball"};
    print(A);
    print(B);
    vector<int> ans = spelling_checker(A, B);
    print(ans);*/

    /*vector<int> A{0, 0, 1, 1};
    vector<string> B{"hack", "hacker", "hac", "hak"};
    print(A);
    print(B);
    vector<int> ans = contact_finder(A, B);
    print(ans);*/

    vector<string> A{"data", "circle", "cricket"};
    vector<string> B{"date", "circel", "crikket", "data", "circl"};
    print(A);
    print(B);
    string result = modified_search(A, B);
    cout << "result: " << result << endl;
    return 0;
}
void insertWord(TrieNode *A, string word)
{
    TrieNode *current = A;
    for (char ch : word)
    {
        if (current->children[ch] == NULL)
        {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
        current->count++;
        // cout << "increasing count for " << ch << ", count: " << current->count << endl;
    }
    current->isLeaf = true;
}

void insertWords(TrieNode *root, vector<string> &A)
{

    int wordsCount = A.size();
    for (int i = 0; i < wordsCount; i++)
    {
        insertWord(root, A[i]);
    }
}
string get_prefix_string(TrieNode *A, string word)
{
    TrieNode *current = A;
    string prefix_str;
    for (char ch : word)
    {
        if (current->children[ch] == NULL)
        {
            return NULL;
        }
        prefix_str.push_back(ch);
        current = current->children[ch];
        if (current->count == 1)
        {
            return prefix_str;
        }
    }
    return prefix_str;
}

vector<string> prefix(vector<string> &A)
{
    vector<string> prefixes;
    TrieNode *root = new TrieNode();
    insertWords(root, A);
    int wordsCount = A.size();
    for (int i = 0; i < wordsCount; i++)
    {
        string s = get_prefix_string(root, A[i]);
        prefixes.push_back(s);
    }
    return prefixes;
}

bool isPresent(TrieNode *A, string word)
{
    TrieNode *current = A;
    for (char ch : word)
    {
        if (current->children[ch] == NULL)
        {
            return false;
        }
        current = current->children[ch];
    }
    return current->isLeaf;
}

int get_prefix_length(TrieNode *A, string word)
{
    TrieNode *current = A;
    for (char ch : word)
    {
        if (current->children[ch] == NULL)
        {
            return 0;
        }
        current = current->children[ch];
    }
    return current->count;
}
vector<int> spelling_checker(vector<string> &A, vector<string> &B)
{
    vector<int> ans;
    TrieNode *dictionary = new TrieNode();
    insertWords(dictionary, A);
    for (string word : B)
    {
        bool present = isPresent(dictionary, word);
        ans.push_back(present ? 1 : 0);
    }
    return ans;
}
vector<int> contact_finder(vector<int> &A, vector<string> &B)
{
    int n = A.size(), i = 0;
    vector<int> ans;
    TrieNode *dictionary = new TrieNode();
    for (i = 0; i < n; i++)
    {
        switch (A[i])
        {
        case 0: // add into disctionary
            insertWord(dictionary, B[i]);
            break;
        case 1:
            int count = get_prefix_length(dictionary, B[i]);
            ans.push_back(count);
            break;
        }
    }
    return ans;
}
bool is_present_with_one_modification(TrieNode *A, string word)
{
    TrieNode *current = A;
    bool one_modified = false;
    for (char ch : word)
    {
        if (current->children[ch] == NULL)
        {
            if (one_modified)
            {
                return false;
            }
            else
            {
                one_modified = true;
            }
        }
        current = current->children[ch];
    }
    return current->isLeaf;
}
string modified_search(vector<string> &A, vector<string> &B)
{
    string result;
    TrieNode *dictionary = new TrieNode();
    insertWords(dictionary, A);

    for (string word : B)
    {
        bool is_present = is_present_with_one_modification(dictionary, word);
        result += is_present ? "1" : "0";
    }
    return result;
}
