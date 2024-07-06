#include <iostream>
#include <stack>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* ptr;

    Node(int d) {
        data = d;
        ptr = nullptr;
    }
};

// Function to check if a linked list is palindrome
bool isPalindrome(Node* head) {
    Node* slow = head;
    bool ispalin = true;
    stack<int> stack;

    // Push elements onto stack
    while (slow != nullptr) {
        stack.push(slow->data);
        slow = slow->ptr;
    }

    // Check palindrome by popping elements from stack
    while (head != nullptr) {
        int i = stack.top();
        stack.pop();
        if (head->data == i) {
            ispalin = true;
        } else {
            ispalin = false;
            break;
        }
        head = head->ptr;
    }
    return ispalin;
}

int main() {
    // Create nodes and form a linked list: 1->2->3->4->3->2->1
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(3);
    Node* six = new Node(2);
    Node* seven = new Node(1);
    one->ptr = two;
    two->ptr = three;
    three->ptr = four;
    four->ptr = five;
    five->ptr = six;
    six->ptr = seven;

    // Check if the linked list is palindrome
    bool condition = isPalindrome(one);
    cout << "isPalidrome: " << boolalpha << condition << endl;

    // Clean up allocated memory
    delete one;
    delete two;
    delete three;
    delete four;
    delete five;
    delete six;
    delete seven;

    return 0;
}
