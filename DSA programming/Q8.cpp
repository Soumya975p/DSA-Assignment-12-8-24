#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char name[50];
    Node* next;

    Node(const char* n) {
        strcpy(name, n);
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* t;

public:
    LinkedList() {
        t = nullptr;
    }

    int getLength() {
        int count = 0;
        Node* current = t;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void addAtBeg(const char* n) {
        Node* new_node = new Node(n);
        new_node->next = t;
        t = new_node;
    }

    void append(const char* n) {
        Node* new_node = new Node(n);
        if (t == nullptr) {
            t = new_node;
            return;
        }
        Node* last = t;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }

    void display() {
        Node* current = t;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void displayALL() {
        Node* current = t;
        while (current != nullptr) {
            cout << "Address: " << current << ", Name: " << current->name 
                 << ", Next Address: " << current->next << endl;
            current = current->next;
        }
    }

    void removeFirst() {
        if (t != nullptr) {
            Node* temp = t;
            t = t->next;
            delete temp;
        }
    }

    void removeLast() {
        if (t == nullptr)
            return;

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
};

int main() {
    LinkedList friendsList;
    friendsList.addAtBeg("Avi");
    friendsList.append("Tushar");
    friendsList.append("Rudhav");
    cout<<"Displaying All The elements of the lis"<<endl;
    friendsList.display();  
    cout<<"Full Information of the list"<<endl;       
    friendsList.displayALL();  
    cout<<"After Removing the first element of the list"<<endl;   
    friendsList.removeFirst();
    friendsList.display();         
    friendsList.removeLast();
      cout<<"After Removing the last element of the list"<<endl; 
    friendsList.display();         

    return 0;
}