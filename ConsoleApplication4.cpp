#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class PriorityQueue {  //создание класса приоритетной очереди
private:
    Node* head;
public:
    PriorityQueue() {
        head = NULL;
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node* current = head;
            Node* previous = NULL;
            while (current != NULL && current->data < data) {
                previous = current;
                current = current->next;
            }

            if (previous == NULL) {
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = current;
                previous->next = newNode;
            }
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl; //проверка очереди на пустоту
            exit(1);
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        return data;
    }
};

int main() {
    PriorityQueue queue;

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int data = rand() % 301 - 150; // генерирует рандомное число от -150 до 150
        queue.enqueue(data);
    }

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}