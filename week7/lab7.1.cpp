#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode* next;
};  // End of struct studentNode

class LinkedList {
protected:
    studentNode* start;

public:
    LinkedList();
    ~LinkedList();
    void InsertNode(const char* name, int age, char sex, float gpa);
    void DeleteNode();
    void GoNext();
    virtual void ShowNode();
};  // End of class LinkedList

class NewList : public LinkedList {
public:
    void GoFirst();
    void ShowNode() override;  // Override to print header
};  // End of class NewList

LinkedList::LinkedList() : start(nullptr) {}  // Initialize start to nullptr

LinkedList::~LinkedList() {
    studentNode* current = start;
    while (current != nullptr) {
        studentNode* next = current->next;
        delete current;
        current = next;
    }
    start = nullptr;
}

void LinkedList::InsertNode(const char* name, int age, char sex, float gpa) {
    studentNode* newNode = new studentNode;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);  // Avoid potential buffer overflow
    newNode->name[sizeof(newNode->name) - 1] = '\0';  // Ensure null termination
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    // Insert at the beginning
    newNode->next = start;
    start = newNode;
}

void LinkedList::DeleteNode() {
    if (start == nullptr) {
        printf("No node to delete.\n");
        return;
    }

    studentNode* temp = start;
    start = start->next;
    delete temp;
}

void LinkedList::GoNext() {
    if (start != nullptr) {
        start = start->next;
    }
}

void LinkedList::ShowNode() {
    if (start != nullptr) {
        printf("%s %d %c %.2f\n", start->name, start->age, start->sex, start->gpa);
    } else {
        printf("No node to display.\n");
    }
}

void NewList::GoFirst() {
    start = this->start;  // Access inherited `start` using `this` pointer
}

void NewList::ShowNode() override {  // Override behavior for NewList
    printf("\nNew List:\n");
    LinkedList::ShowNode();  // Call base class implementation
}

int main() {
    LinkedList listA;
    NewList listB;

    listA.InsertNode("one", 1, 'A', 1.1);
    listA.InsertNode("two", 2, 'B', 2.2);
    listA.InsertNode("three", 3, 'C', 3.3);
    listA.ShowNode();

    listB.InsertNode("four", 4, 'D', 4.4);
    listB.InsertNode("five", 5, 'E', 5.5);
    listB.InsertNode("six", 6, 'F', 6.6);
    listB.GoFirst();
    listB.DeleteNode();
    listB.ShowNode();

    return 0;
}
