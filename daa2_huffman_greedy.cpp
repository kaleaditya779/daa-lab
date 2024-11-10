#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct HeapNode {
    char data;
    int freq;
    HeapNode *left, *right;

    HeapNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct my_custom_comparator {
    bool operator()(HeapNode *l, HeapNode *r) {
        return l->freq > r->freq; // Min-Heap based on frequency
    }
};

// Function to print Huffman codes by traversing the Huffman Tree
void writeCodes(HeapNode *root, string str) {
    if (!root) return;

    // If this is a leaf node, print the character and its code
    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }

    writeCodes(root->left, str + "0");
    writeCodes(root->right, str + "1");
}

// Function to build Huffman Tree and generate codes
void huffman_coder(char data[], int freq[], int size) {
    priority_queue<HeapNode*, vector<HeapNode*>, my_custom_comparator> minH;

    // Create a leaf node for each character and add it to the priority queue
    for (int i = 0; i < size; i++) {
        minH.push(new HeapNode(data[i], freq[i]));
    }

    // Iterate until the heap contains only one node
    while (minH.size() > 1) {
        // Extract the two nodes with the lowest frequency
        HeapNode *left = minH.top();
        minH.pop();
        HeapNode *right = minH.top();
        minH.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        HeapNode *sum = new HeapNode('$', left->freq + right->freq);

        sum->left = left;
        sum->right = right;

        // Add the new node to the priority queue
        minH.push(sum);
    }

    // Print Huffman codes using the built Huffman tree
    writeCodes(minH.top(), "");
}

int main() {
    int freq[] = {1, 2, 3, 4, 5, 17};
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int size = sizeof(freq) / sizeof(freq[0]);
    
    huffman_coder(data, freq, size);

    return 0;
}
