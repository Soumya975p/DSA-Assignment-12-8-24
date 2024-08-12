#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* next;
    
    Node(char value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* t;

public:
    LinkedList() : t(nullptr) {}

    
    int getLength() {
        int length = 0;
        Node* current = t;
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        return length;
    }

    
    void addAtBeg(char x) {
        Node* newNode = new Node(x);
        newNode->next = t;
        t = newNode;
    }

   
    void append(char x) {
        Node* newNode = new Node(x);
        if (t == nullptr) {
            t = newNode;
        } else {
            Node* current = t;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void addAtPOS(char x, int pos) {
        if (pos < 0 || pos > getLength()) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (pos == 0) {
            addAtBeg(x);
        } else {
            Node* newNode = new Node(x);
            Node* current = t;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }


    void display() {
        Node* current = t;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
    void displayMORE() {
        Node* current = t;
        while (current != nullptr) {
            cout << "Address: " << current << ", Value: " << current->data;
            if (current->next != nullptr) {
                cout << ", Next Address: " << current->next;
            } else {
                cout << ", Next Address: nullptr";
            }
            cout << endl;
            current = current->next;
        }
    }

    
    void removeFirst() {
        if (t == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = t;
        t = t->next;
        delete temp;
    }

    
    void removeLast() {
        if (t == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (t->next == nullptr) {
            delete t;
            t = nullptr;
            return;
        }
        Node* current = t;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    
    void removePOS(int pos) {
        if (pos < 0 || pos >= getLength()) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (pos == 0) {
            removeFirst();
        } else {
            Node* current = t;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    
    ~LinkedList() {
        while (t != nullptr) {
            removeFirst();
        }
    }
};


int main() {
    LinkedList list;

   
    list.addAtBeg('w');
    list.append('X');
    list.append('Y');
    list.addAtPOS('Z', 2);
    cout << "List after adding elements: ";
    list.display();

    cout << "Length of list: " << list.getLength() << endl;

    cout << "Display more (address, value, next address):" << endl;
    list.displayMORE();

    list.removeFirst();
    cout << "List after removing first element: ";
    list.display();

    list.removeLast();
    cout << "List after removing last element: ";
    list.display();

    list.removePOS(1);
    cout << "List after removing element at position 1: ";
    list.display();

    return 0;
}