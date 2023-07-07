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

        Node* remove(int value) {
            if (this == nullptr) {
                return this;  // Empty tree or node not found
            }

            if (value < this->value) {
                if (left != nullptr){
                    left = left->remove(value);
                }
            } else if (value > this->value) {
                if (right != nullptr) {
                    right = right->remove(value);
                }
            }
            // Case 1: No child or one child
            if (left == nullptr) {
                Node* temp = right;
                delete this;
                return temp;
            } else if (right == nullptr) {
                Node* temp = left;
                delete this;
                return temp;
            }

            // Case 2: Two children
            // Find the minimum value node from the right subtree (successor)
            Node* successor = right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            // Copy the data of the successor to the current node
            value = successor->value;

            // Delete the successor node
            right = right->remove(successor->value);
        

            return this;
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
    
    node->remove(25);

    node->inorderTraversal();
    cout << endl;

    delete node;

    return 0;
}