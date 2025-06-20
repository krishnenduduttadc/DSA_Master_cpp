#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

void initList(LinkedList& list) {
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

void addLast(LinkedList& list, int val) {
    Node* newNode = new Node(val);
    if (list.size == 0) {
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
    list.size++;
}

int getSize(const LinkedList& list) {
    return list.size;
}

void display(const LinkedList& list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(LinkedList& list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    list.head = list.tail = nullptr;
    list.size = 0;
}

int main() {
    LinkedList list;
    initList(list);

    addLast(list, 10);
    addLast(list, 20);
    addLast(list, 30);
    display(list); // Should display: 10 20 30
    cout << getSize(list) << endl; // Should display: 3

    addLast(list, 40);
    addLast(list, 50);
    display(list); // Should display: 10 20 30 40 50
    cout << getSize(list) << endl; // Should display: 5

    deleteList(list);

    return 0;
}
