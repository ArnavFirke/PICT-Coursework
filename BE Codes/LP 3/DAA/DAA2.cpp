#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void printCodes(Node *root, string code)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->data << ": " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(string text)
{

    unordered_map<char, int> freq;
    for (char c : text)
    {
        freq[c]++;
    }

    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    for (auto pair : freq)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node *root = minHeap.top();
    printCodes(root, "");
}

int main()
{
    cout << "Example 1\n";
    string text = "bcaaa";
    huffman(text);
    cout << "Example 2\n";
    text = "aabccc";
    huffman(text);
    cout << "Example 3\n";
    text = "hello";
    huffman(text);
    cout << "Example 4\n";
    text = "daa";
    huffman(text);

    return 0;
}
