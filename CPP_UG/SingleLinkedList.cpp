#include <iostream>
using namespace std;
class SingleLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(NULL) {}
    };

    //Pointer to global pointer
    Node* head;
public:
    SingleLinkedList() : head(NULL) {
        //initialize the head as nullptr
    }

    Node* getNode(int index)
    {
        Node* curr = head;
        for(int i=0; i<index && curr; i++)
        {
            curr = curr->next;
        }
        return curr;
    }

    int get(int index) {
        Node* curr = head;
        for(int i=0; i<index && curr; i++) 
        {
            curr = curr->next;
        }
        return curr == NULL ? -1 : curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    void addAtTail(int val) {
        if(head == NULL)
        {
            addAtHead(val);
            return;
        }
        //Iterate to the tail
        Node* curr = head;

        while(curr && curr->next != NULL) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);
        curr->next = newNode;
        return;
    }

    void addAtIndex(int index, int val) {
        if(index == 0)
        {
            addAtHead(val);
            return;
        }

        Node* prev = getNode(index-1);

        if(prev == NULL)
            return;

        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        Node* node = getNode(index);

        if(node == NULL) {
            return;
        }

        if(index == 0) {
            head = node->next;
        } else {
            Node *prev = getNode(index-1);
            prev->next = node->next;
        }
    }

    void display() {
        Node* curr = head;
        while(curr != nullptr) {
            cout << curr->val << " " << endl;
            curr = curr->next;
        }
        return;
    }
};
int main() {
    SingleLinkedList* obj = new SingleLinkedList();
    obj->addAtHead(5);
    obj->addAtHead(8);
    obj->addAtHead(4);
    obj->addAtHead(2);
    cout << "Get value of Node " << obj->get(3) << endl;
    obj->addAtIndex(2, 9);
    obj->deleteAtIndex(3);
    obj->addAtTail(10);
    obj->display();
    return 0;
}