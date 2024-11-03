/*Develop a program to implement Huffman Encoding using a greedy 
strategy.*/

#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

Node* createNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}


void sorthuffnodes(Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}
Node* huffman(int n, char characters[], int frequencies[]) {
    Node* nodes[100];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }
    while (n > 1) {
       
        sorthuffnodes(nodes, n);
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = createNode('#', left->freq + right->freq, left, right);
       
        for (int i = 2; i < n; i++) {
            nodes[i-2] = nodes[i];
        }

        nodes[n-2] = parent;
        n--;
    }

    return nodes[0];
}
void printhuffcode(Node* root, char code[], int top) {

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << ": ";
        for (int i = 0; i < top; i++) {
            cout << code[i];
        }
        cout << endl;
        return;
    }

    if (root->left != nullptr) {
        code[top] = '0';
        printhuffcode(root->left, code, top + 1);
    }

    if (root->right != nullptr) {
        code[top] = '1';
        printhuffcode(root->right, code, top + 1);
    }
}





int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char characters[100];
    int frequencies[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> characters[i];
        cout << "Enter frequency of " << characters[i] << ": ";
        cin >> frequencies[i];
    }

    Node* root = huffman(n, characters, frequencies);

    char code[100];
    cout << "---------------Huffman code---------------------:\n";
    printhuffcode(root, code, 0);

    return 0;
}