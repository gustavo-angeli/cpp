#include <iostream>

using namespace std;

class Stack {
    private:
        int top = -1;
        string values[5];
    public:
        void push(string value) {
            cout << "Pushing value: " << value << " in stack" << endl;
            top++;
            values[top] = value;
            
        };

        bool isEmpty() {
            return top == -1;
        };

        string pop() {
            if (isEmpty()) {
                return "Empty stack";
            }
            string poppedValue = values[top];
            values[top] = "";
            top--;
            return "Popped value is: " + poppedValue;
        };

        string peek() {
            return "Top item of stack: " + values[top];
        };

        int size() {
            if (isEmpty()) {
                return 0;
            }
            return top;
        }

};

int main()
{
    Stack* stack = new Stack();

    cout << stack->pop() << endl;

    stack->push("value 1");
    cout << stack->peek() << endl << endl;
    stack->push("value 2");
    cout << stack->peek() << endl << endl;

    cout << stack->pop() << endl << endl;
    cout << stack->peek() << endl << endl;

    stack->push("value 3");
    cout << stack->peek() << endl;

    return 0;
}
