#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert a digit at end of linked list
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Add two numbers represented as linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0); // dummy node
    Node* temp = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
    // First number = 243 (stored as 3 -> 4 -> 2)
    Node* num1 = nullptr;
    insertAtEnd(num1, 3);
    insertAtEnd(num1, 4);
    insertAtEnd(num1, 2);

    // Second number = 564 (stored as 4 -> 6 -> 5)
    Node* num2 = nullptr;
    insertAtEnd(num2, 4);
    insertAtEnd(num2, 6);
    insertAtEnd(num2, 5);

    cout << "First Number : ";
    printList(num1);
    cout << "Second Number: ";
    printList(num2);

    Node* result = addTwoNumbers(num1, num2);

    cout << "Result       : ";
    printList(result);

    return 0;
}
