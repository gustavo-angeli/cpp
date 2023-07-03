#include <iostream>

using namespace std;

struct Node {
        string value;
        Node* previous;
};

class Stack {
    private:
        Node* top;
    public:

        void push(string value) {
            cout << "Pushing value: " << value << " in stack" << endl;

            Node* node = new Node();
            node->value = value;

            if (!isEmpty()) {
                node->previous = top;
            }
            top = node;
        };
        string pop() {
            if (isEmpty()) {
                return "The stack is empty";
            }

            cout << "Showing and removing the top value in stack: ";
            string poppedValue = top->value;
            this->top = top->previous;
            return poppedValue;
        };
        Node* peek() {
            cout << "Showing the top value in stack: ";
            return top;
        };
        bool isEmpty() {
            return top == nullptr;
        };
        int size() {
            if (isEmpty()) {
                return 0;
            }
            int stackSize = 1;
            while (top->previous != nullptr) {
                stackSize++;
                top = top->previous;
            }
            return stackSize;
        };
};

int main(){
    Stack* stack = new Stack();
    cout << stack->pop() << endl;

    stack->push("node 1");
    stack->push("node 2");

    cout << stack->pop() << endl;

    cout << stack->peek()->value <<endl;

    stack->push("node 3");
    cout << stack->peek()->value << endl;

    cout << stack->peek()->previous->value << endl;

    cout << "Stack size: " << stack->size() << endl;

    return 0;
}