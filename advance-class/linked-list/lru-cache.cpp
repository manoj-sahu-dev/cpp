#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

/**
 * @brief Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 *
 */
class LRUCache
{
private:
    class Node
    {
    public:
        int key, value;
        Node(int key, int value) : key(key), value(value) {}
    };
    list<Node> nodes;
    unordered_map<int, list<Node>::iterator> map;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity > 0 ? capacity : 1;
        map = {};
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            auto it = map[key];
            int value = it->value;
            nodes.push_front(*it);
            nodes.erase(it);
            map[key] = nodes.begin();
            cout << map[key]->value << " ";
            return value;
        }
        cout << -1 << " ";
        return -1;
    }

    void set(int key, int value)
    {
        if (map.find(key) != map.end()) // found, replace existing value
        {
            auto it = map[key];
            it->value = value;
        }
        else
        {
            if (nodes.size() == capacity) // removes least recently used node
            {
                Node last = nodes.back();
                map.erase(last.key);
                nodes.pop_back();
            }
            // cout << key << " : " << value << endl;
            Node node(key, value); // now we have some space, inser new node
            nodes.push_front(node);
            map[key] = nodes.begin();
        }
    }
};
void print(unordered_map < int, list<Node> map)
{
}
int main(int argc, char **argv)
{
    system("clear");
    bool debug = argc > 1;
    // string input = "59 7 S 2 1 S 1 10 S 8 13 G 12 S 2 8 G 11 G 7 S 14 7 S 12 9 S 7 10 G 11 S 9 3 S 14 15 G 15 G 9 S 4 13 G 3 S 13 7 G 2 S 5 9 G 6 G 13 S 4 5 S 3 2 S 4 12 G 13 G 7 S 9 7 G 3 G 6 G 2 S 8 4 S 8 9 S 1 4 S 2 9 S 8 8 G 13 G 3 G 13 G 6 S 3 8 G 14 G 4 S 5 6 S 10 15 G 12 S 13 5 S 10 9 S 3 12 S 14 15 G 4 S 10 5 G 5 G 15 S 7 6 G 1 S 5 12 S 1 6 S 11 8";
    string input = "32 4 S 5 13 S 9 6 S 4 1 G 4 S 6 1 S 8 11 G 13 G 1 S 12 12 G 10 S 15 13 S 2 13 S 7 5 S 10 3 G 6 G 10 S 15 14 S 5 12 G 5 G 7 G 15 G 5 G 6 G 10 S 7 13 G 14 S 8 9 G 4 S 6 11 G 9 S 6 12 G 3";
    stringstream ss(input);
    string word;
    // map<int, pair<char, pair<int, int>>> imap;
    cout << input << endl;
    vector<string> ops;
    while (ss >> word)
    {
        ops.push_back(word);
    }
    int operations = stoi(ops[0]);
    int capacity = stoi(ops[1]);
    LRUCache *lru_cache = new LRUCache(capacity);
    int opNum = 0;
    for (int i = 2; i < ops.size(); i++)
    {
        if (ops[i] == "S")
        {
            int key = stoi(ops[++i]);
            int value = stoi(ops[++i]);
            if (debug)
                cout << "\nS :: " << key << " " << value << endl;
            // imap.insert({opNum, {'S', {key, value}}});
            lru_cache->set(key, value);
        }
        else if (ops[i] == "G")
        {
            int key = stoi(ops[++i]);
            if (debug)
                cout << "\nG :: " << key << endl;
            lru_cache->get(key);
            // imap.insert({opNum, {'G', {key, key}}});
        }
        opNum += 1;
    }
    cout << endl;
    cout << "total operation " << opNum << endl;
    return 0;
    // 1 -1 -1 -1 -1 3 12 5 14 12 -1 3 -1 -1 -1 -1
}