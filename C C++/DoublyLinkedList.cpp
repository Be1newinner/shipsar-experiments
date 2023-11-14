#include <iostream>

using namespace std;

// Define the structure for a doubly linked list node
struct List {
    int data;
    List* prev;
    List* next;
};

// Initialize an empty linked list
List* initializeList() {
    return nullptr;
}

// Insert a new node with data at the end of the list
List* insert(List* head, int data) {
    List* newNode = new List;
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        newNode->prev = nullptr;
        return newNode;
    }

    List* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Delete the node with a specific data value
List* deleteNode(List* head, int data) {
    List* current = head;

    while (current != nullptr) {
        if (current->data == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            delete current;
            break;
        }
        current = current->next;
    }
    return head;
}

// Display the contents of the linked list
void displayList(List* head) {
    List* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    List* myList = initializeList();

    myList = insert(myList, 10);
    myList = insert(myList, 20);
    myList = insert(myList, 5);
    myList = insert(myList, 30);

    cout << "Linked List: ";
    displayList(myList);

    myList = deleteNode(myList, 20);

    cout << "Linked List after deleting 20: ";
    displayList(myList);

    return 0;
}

