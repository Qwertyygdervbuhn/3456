#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

    void clear() {
        while (head) {
            pop_front();
        }
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    List& operator=(const List& other) {
        if (this == &other) {
            return *this;
        }

        clear();

        Node* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }

        return *this;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_back() {
        if (!tail) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;
    }

    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List() {
        clear();
    }
};

int main() {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Original list: ";
    list.print();

    list.reverse();
    cout << "After reverse: ";
    list.print();

    list.pop_back();
    cout << "After removing last element: ";
    list.print();

    list.pop_front();
    cout << "After removing first element: ";
    list.print();

    List list2;
    list2 = list;
    cout << "Copy of list: ";
    list2.print();

}
