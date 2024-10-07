#include<iostream>
using namespace std;
struct entry{
    int number;
    entry* next;
};

char displayMenu();
int getValue();
void displayList(entry*);
bool checkDuplicates(entry*, int);
void addNode(entry* &head);
void deleteNode(entry* &head);
void search(entry*);

int main(){
    entry* head = nullptr;
    char choice = displayMenu();
    while(choice != 'E'){
        switch(choice){
            case 'A': addNode(head);
            break;
            case 'B': deleteNode(head);
            break;
            case 'C': search(head);
            break;
            case 'D': displayList(head);
            break;
            case 'E': break;
            default: cout << "Invalid choice, try again...." << endl;
            break;
        }
        choice = displayMenu();
    }
    cout << "Good bye!!" << endl;
    return 0;
}
char displayMenu(){
    char choice;
    cout << "Please pick an option: " << endl;
    cout << "\tA. Add a number\t \tB. Delete a number\t \tC. Search for a number\t \tD. Display the whole list\t \tE. Exit\n";
    cin >> choice;
    choice = toupper(choice);
    return choice;
}
bool checkDuplicates(entry*head, int value){
    entry* cur = head;
    bool dupe = false;
    while(cur != NULL){
        if(cur->number == value){
            dupe = true;
            return dupe;
        }
        cur = cur->next;
    }
    return dupe;
}
void addNode(entry* &head){
    int value;
    entry * curr;
    entry * prev;
    entry * newNode;
    cout << "Enter the value you'd like to add: ";
    cin >> value;
    if(checkDuplicates(head, value)){
        cout << "Duplicate number not added to the list..." << endl;
    }else{
        newNode = new entry;
        newNode->number = value;
        newNode->next = nullptr;
        if(head == nullptr){
            head = newNode;
        }else{
            prev = NULL;
            curr = head;
            while(curr != NULL && curr->number < value){
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL){
                newNode->next = head;
                head = newNode;
            }else{
                newNode->next = curr;
                prev->next = newNode;
            }
        }
    }
}
void deleteNode(entry* &head){
    int value;
    entry * curr;
    entry * prev;
    if(head == nullptr){
        cout << "List is empty, nothing to be deleted..." << endl;
    }else{
        cout << "Enter the value you want to delete: " << endl;
        cin >> value;
        curr = head;
        prev = NULL;
        while(curr != NULL && curr->number != value){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            cout << "The number is not on the list..." << endl;
        }else if(prev == NULL){
            head = head->next;
            delete curr;
        }else{
            prev->next = curr->next;
            delete curr;
        }
    }

}
void displayList(entry * head){
    entry * cur = head;
    if(head == nullptr){
        cout << "Empty list\n";
        return;
    }
    while(cur != NULL){
        cout << cur->number << " " << endl;
        cur = cur->next;
    }
    //cout << endl << endl;
}
void search(entry* head){
    int value;
    entry * cur;
    cout << "Enter the value you'd like to search: ";
    cin >> value;
    cur = head;
    while(cur != nullptr && cur->number != value){
        cur = cur->next;
    }
    if(cur != NULL){
        cout << "The number is in the list!" << endl;
    }else{
        cout << "The number is not on the list :(" << endl;
    }
}