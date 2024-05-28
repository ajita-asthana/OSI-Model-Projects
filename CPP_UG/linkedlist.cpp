#include <iostream>

class LinkedList {

    struct Node 
    {
        int data; // Data of the node
        Node *next; //pointer to the next node
        Node(int data) : data(data), next(nullptr) {} // Constructor
    };

    Node *head; // Pointer to the head of the list

    public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insert(int data) 
    {
        Node *newNode = new Node(data);
        newNode->next = head; //point the new node to the head
        head = newNode; //make the new node as the head
    }

    // Display the list
    void display() 
    {
        Node *temp = head;
        while(temp != nullptr) { //traverse the list
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~LinkedList() {
        Node *temp = head;
        while(temp != nullptr) {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.display();
    std::cout << std::endl;
    return 0;
}