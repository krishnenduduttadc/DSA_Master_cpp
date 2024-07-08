#include <iostream>

using namespace std;

// Define Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Intersect class to find the intersection point in Y-shaped Linked Lists
class Intersect {
public:
    // Function to find intersection point
    int intersectPoint(Node* head1, Node* head2) {
        Node* p1 = head1;
        Node* p2 = head2;
        int s1 = 0, s2 = 0;

        // Calculate lengths of both linked lists
        while (p1 != nullptr) {
            s1++;
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            s2++;
            p2 = p2->next;
        }

        // Reset pointers to the head of each linked list
        p1 = head1;
        p2 = head2;

        // Adjust pointer of longer list to same starting point as shorter list
        if (s1 > s2) {
            int diff = s1 - s2;
            while (diff > 0) {
                p1 = p1->next;
                diff--;
            }
        } else {
            int diff = s2 - s1;
            while (diff > 0) {
                p2 = p2->next;
                diff--;
            }
        }

        // Move both pointers until they meet at intersection point
        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        // If no intersection found, return -1
        if (p1 == nullptr) return -1;

        // Return data at intersection point
        return p1->data;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

// Main function to test the Intersect class
int main() {
    // Creating two linked lists with an intersection point
    Node* common = new Node(8);
    common->next = new Node(10);

    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    Node* head2 = new Node(4);
    head2->next = new Node(7);
    head2->next->next = common;

    Intersect intersect;
    int result = intersect.intersectPoint(head1, head2);

    cout << "The intersection point data is: " << result << endl;

    // Clean up memory
    delete common->next;
    delete common;
    delete head1->next->next->next;
    delete head1->next->next;
    delete head1;
    delete head2->next->next;
    delete head2->next;
    delete head2;

    return 0;
}
