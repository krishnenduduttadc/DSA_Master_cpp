#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Method to add a node at the end of the list
    void addLast(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Method to display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Method to merge two sorted linked lists
    static LinkedList* mergeTwoSortedLists(LinkedList* l1, LinkedList* l2) {
        LinkedList* mergedList = new LinkedList();

        Node* one = l1->head;
        Node* two = l2->head;
        while (one != nullptr && two != nullptr) {
            if (one->data < two->data) {
                mergedList->addLast(one->data);
                one = one->next;
            } else {
                mergedList->addLast(two->data);
                two = two->next;
            }
        }

        while (one != nullptr) {
            mergedList->addLast(one->data);
            one = one->next;
        }

        while (two != nullptr) {
            mergedList->addLast(two->data);
            two = two->next;
        }

        return mergedList;
    }

    // Method to find the middle node of the list for merge sort
    static Node* midNode(Node* head, Node* tail) {
        Node* slow = head;
        Node* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Method to perform merge sort on the linked list
    static LinkedList* mergeSort(Node* head, Node* tail) {
        if (head == tail) {
            LinkedList* singleNodeList = new LinkedList();
            singleNodeList->addLast(head->data);
            return singleNodeList;
        }

        Node* mid = midNode(head, tail);
        LinkedList* firstHalf = mergeSort(head, mid);
        LinkedList* secondHalf = mergeSort(mid->next, tail);

        return mergeTwoSortedLists(firstHalf, secondHalf);
    }
};

int main() {
    LinkedList* list = new LinkedList();

    // Adding elements to the list
    list->addLast(10);
    list->addLast(2);
    list->addLast(19);
    list->addLast(22);
    list->addLast(3);
    list->addLast(7);

    // Performing merge sort
    LinkedList* sorted = LinkedList::mergeSort(list->head, list->tail);

    // Displaying the sorted list
    cout << "Sorted list:" << endl;
    sorted->display();

    return 0;
}
