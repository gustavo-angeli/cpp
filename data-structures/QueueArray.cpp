#include <iostream>
#include <iterator>

using namespace std;

class Queue {
    private:
        int values[5];
    public:
            int last = -1;

        string enqueue(int value) {
            if (last < 4) {
            last++;
            values[last] = value;
            return "value add";
            }
            return "queue is full";
        };
        int dequeue() {
            int value = values[0];
            if (isEmpty()) {
                return 0;
            }
            for (int i = 0; i < size() - 1; i++) {
                int next = i + 1;
                values[i] = values[next];
            }
            last
            return value;
        };
        int front() {
            if (isEmpty()) {
                return 0;
            }
            return values[0];
        };
        bool isEmpty() {
            return last == -1;
        };
        int size() {
            if (isEmpty()) {
                return 0;
            }
            return last + 1;
        };
        void clear() {
            for (int i = 0; i < size() - 1; i++) {
                values[i] = 0;
            }
            last = -1;
        };
};

int main()
{
    Queue* queue = new Queue();

    cout << "Value removed of queue: " << queue->dequeue() << endl;

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    queue->enqueue(6);

    cout << "First value of queue: " << queue->front() << endl;

    cout << "Value removed of queue: " << queue->dequeue() << endl;
    cout << "Value removed of queue: " << queue->dequeue() << endl;
    cout << "Value removed of queue: " << queue->dequeue() << endl;
    cout << "Value removed of queue: " << queue->dequeue() << endl;
    queue->enqueue(2);
    cout << "Value removed of queue: " << queue->dequeue() << endl;

    cout << "First value of queue: " << queue->front() << endl;

    queue->clear();

    cout << queue->size() << endl;

    return 0;
}
