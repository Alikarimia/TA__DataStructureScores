// run code to vscode & cpp.sh website 
#include <iostream>
#include <stdlib.h>

using namespace std;

int listSize = 0;
class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node() {
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertFirst(int value) {
        cout << "The element \"" << value << "\" added !" << endl;
        listSize++;

        Node* temp = new Node(); // new node
        // put the node in after
        if (head != nullptr)
            head->prev = temp;
        temp->value = value;
        temp->next = head;

        head = temp;
        //sum = head->value;

        //cout << sum;
    }

    void insertLast(int value) {
        cout << "The element \"" << value << "\" added !" << endl;
        listSize++;

        Node* temp = new Node(); // new node
        temp->value = value;


        if (head == nullptr)
            head = temp;

        else {
            Node* lastNode = head;

            while (lastNode->next != nullptr)
                lastNode = lastNode->next;

            temp->prev = lastNode;
            lastNode->next = temp;
        }
    }

    void insertWithPosition(int value, int position) {
        Node* temp = new Node(); // new node
        temp->value = value;

        if (position == 0) {
            cout << "The element \"" << value << "\" added !" << endl;
            listSize++;
            head->prev = temp;
            temp->next = head;
            head = temp;

        }
        else {
            if (position < listSize) {
                cout << "The element \"" << value << "\" added !" << endl;
                listSize++;
                Node* lastNode = head;
                while (position > 1) {
                    lastNode = lastNode->next;
                    --position;
                }
                lastNode->next->prev = temp;
                temp->next = lastNode->next;

                lastNode->next = temp;
                temp->prev = lastNode;
            }
            else {
                cout << "Not enough memory";
            }
        }
    }

    void deleteAtBeginning() {
        if (head == nullptr)
            cout << "List is empty !" << endl;
        else {
            cout << "The element " << head->value << " deleted !" << endl;
            listSize--;

            Node* temp = head;
            head = head->next;
            head->prev = nullptr;

            delete temp;
        }
    }
    void sumCalculator() {
        Node* lastNode = head;
        int sum = 0;
        while (lastNode != nullptr) {
            sum += lastNode->value;
            lastNode = lastNode->next;

        }
        cout << "sum is :" << sum << endl;
    }

    void deleteAtEnd() {
        if (head == nullptr)
            cout << "List is empty !" << endl;

        else if (head->next == nullptr) {
            cout << "The element " << head->value << " deleted !" << endl;
            listSize--;

            delete head;
            head = nullptr;

        }
        else {
            Node* temp = head;

            while (temp->next->next != nullptr)
                temp = temp->next;

            cout << "The element " << temp->next->value << " deleted !" << endl;
            listSize--;

            // delete last node
            delete (temp->next);

            temp->next = nullptr;
        }
    }

    void deleteAtGivenPosition(int position) {
        if (head == nullptr)
            cout << "List is empty !" << endl;

        else {
            Node* temp, * lastNode;

            if (position == 0) {
                cout << "The element " << head->value << " deleted !" << endl;
                listSize--;

                lastNode = head;
                head = head->next;
                head->prev = nullptr;
                delete lastNode;

            }
            else {
                temp = lastNode = head;

                while (position > 0) {
                    --position;
                    temp = lastNode;
                    lastNode = lastNode->next;
                }

                cout << "The element " << lastNode->value << " deleted !" << endl;
                listSize--;

                temp->next = lastNode->next;
                lastNode->next->prev = temp;

                // free pth node
                free(lastNode);
            }
        }
    }

    void search(int searchNumber) {
        Node* current = head;

        //  find the searchNumber in list
        while (current != nullptr && current->value != searchNumber)
            current = current->next;

        if (current == nullptr)
            cout << "\"" << searchNumber << "\" is not found in linked list !" << endl;

        else
            cout << "\"" << searchNumber << "\" found in list (position > \"" << current << "\")" << endl;
    }

    void print() {
        if (head == nullptr)
            cout << "List is empty !" << endl;

        else {
            Node* temp = head;
            cout << "Linked list: ";

            while (temp != nullptr) {
                if (temp->prev != nullptr) {
                    cout << temp->value << " (pre:" << temp->prev->value << ") -> ";
                }
                else
                    cout << temp->value << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
            cout << "\t \t <-";

        }
    }
    void showSize() {
        cout << "Size of linked list is : " << listSize << endl;
    }

    void getValue(int position) {
        Node* temp = new Node();
        temp = head;

        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }


        cout << temp->value;
    }

    // int size(){
    //     Node *temp = new Node();
    //     temp = head;
    //     int c = 0;
    //     for( ; temp != nullptr ; temp = temp -> next) c++;
    //     return c;
    // }

};

int main() {
    int choice, value, position;
    LinkedList douLinkList;

    do {
        cout << endl << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at selected index" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete from selected index" << endl;
        cout << "7. Display" << endl;
        cout << "8. Search" << endl;
        cout << "9. Show size of linked list" << endl;
        cout << "10. sum of linkedlist" << endl;
        cout << "11. return value of linkedlist" << endl;
        cout << "0. Exit" << endl << endl;
        cout << "------------------\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element : ";
            cin >> value;
            douLinkList.insertFirst(value);
            system("clear");
            break;

        case 2:
            cout << "Enter element : ";
            cin >> value;
            douLinkList.insertLast(value);
            system("clear");
            break;

        case 3:
            cout << "Enter position : ";
            cin >> position;

            cout << "Enter element : ";
            cin >> value;
            douLinkList.insertWithPosition(value, position);
            system("clear");
            break;

        case 4:
            douLinkList.deleteAtBeginning();
            system("clear");
            break;

        case 5:
            douLinkList.deleteAtEnd();

            system("clear");
            break;

        case 6:
            cout << "Enter position : ";
            cin >> position;
            douLinkList.deleteAtGivenPosition(position);

            system("clear");
            break;

        case 7:
            douLinkList.print();

            system("clear");
            break;

        case 8:
            cout << "Enter element : ";
            cin >> value;
            douLinkList.search(value);

            system("clear");
            break;

        case 9:
            douLinkList.showSize();

            system("clear");
            break;
        case 10:
            douLinkList.sumCalculator();

            system("clear");
            break;

        case 11:
            cout << "enter indet ";
            int index;
            cin >> index;
            douLinkList.getValue(index);

            system("clear");
            break;
        case 0:
            cout << "good byeeeeeee :)))";

            system("clear");
            break;

        default:
            cout << "Wrong command !" << endl;

            system("clear");
            break;

        }

    } while (choice != 0);
}