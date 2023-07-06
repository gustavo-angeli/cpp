#include <iostream>

using namespace std;

class Node {
    private:
        int value;
        Node* left;
        Node* right;
    public:
        Node(int value) : value(value), left(nullptr), right(nullptr) {}

        void insert(int value) {
            if (value < this->value) {
                if (left == nullptr) {
                    left = new Node(value);
                }
                left->insert(value);
            } else if (value > this->value) {
                if (right == nullptr) {
                    right = new Node(value);
                }
                right->insert(value);
            }
        }

        void remove(int value) {
            if (left != nullptr && left->value == value) {
                left = nullptr;
            } else if (right != nullptr && right->value == value) {
                right = nullptr;
            }
            if (value < this->value) {
                if (left != nullptr){
                    left->remove(value);
                }
            } else if (value > this->value) {
                if (right != nullptr) {
                    right->remove(value);
                }
            }
            
        }

        void inorderTraversal() {
            if (left != nullptr) {
            left->inorderTraversal();
            }
            cout << value << " ";
            if (right != nullptr) {
                right->inorderTraversal();
            }
        }
};

int main() {
    Node* node = new Node(20);
    
    node->insert(10);
    node->insert(30);
    node->insert(15);
    node->insert(25);

    node->inorderTraversal();
    cout << endl;
    
    node->remove(10);
    node->remove(30);
    node->remove(15);
    node->remove(25);

    node->inorderTraversal();
    cout << endl;

    delete node;

    return 0;
}