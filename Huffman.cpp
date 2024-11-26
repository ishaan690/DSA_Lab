#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// A Node in the Huffman Tree
struct Node {
    char ch;                // Character
    int freq;               // Frequency of the character
    Node *left, *right;     // Left and right children

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator to order nodes in the priority queue by frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build the Huffman Tree
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add to the priority queue
    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Merge nodes until only one node remains (the root)
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with the combined frequency
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();  // The root of the Huffman Tree
}

// Generate Huffman Codes by traversing the tree
void generateHuffmanCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, save the code for the character
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Free the allocated memory for the Huffman Tree
void freeHuffmanTree(Node* root) {
    if (!root) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}

int main() {
    // Example input
    string text = "huffman coding example";

    // Step 1: Count the frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Step 2: Build the Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Step 3: Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Step 4: Print the Huffman Codes
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Step 5: Encode the input text
    string encodedText;
    for (char ch : text) {
        encodedText += huffmanCodes[ch];
    }
    cout << "\nEncoded Text: " << encodedText << "\n";

    // Step 6: Decode the encoded text (optional)
    string decodedText;
    Node* current = root;
    for (char bit : encodedText) {
        current = (bit == '0') ? current->left : current->right;

        // If we reach a leaf node, append the character to the decoded text
        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root;
        }
    }
    cout << "\nDecoded Text: " << decodedText << "\n";

    // Free the memory used by the Huffman Tree
    freeHuffmanTree(root);

    return 0;
}
