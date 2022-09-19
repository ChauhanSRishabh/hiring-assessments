#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head;

void insertBeginning(int data)
{
    node* temp = new(node);
    temp->data = data;
    temp->next= NULL;

    temp->next = head;
    head = temp;
}

void insertEnd(int data)
{
    node* temp = new(node);
    temp->data = data;
    temp->next= NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    node* traverse = head;
    while(traverse->next != NULL)
        traverse = traverse->next;

    traverse->next = temp;
}

void insertNthPosition(int data, int pos)
{
    node* temp = new(node);
    temp->data = data;
    temp->next= NULL;
    if(pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    node* traverse = head;
    for (int i = 0; i < pos-2; i++)
        traverse = traverse->next;
    
    temp->next = traverse->next;
    traverse->next = temp;
}

void display()
{
    node* temp = head;
    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteBeginning()
{
    node* temp = head;
    head = temp->next;
    delete temp;
}

void deleteEnd()
{
    node* temp;
    node* traverse = head;
    while (traverse->next->next != NULL)
        traverse = traverse->next;
    
    temp = traverse->next;
    traverse->next = NULL;
    delete(temp);
}

void deletePosition(int pos)
{
    node* temp = head;
    if(pos==1)
    {
        head = temp->next;
        delete(temp);
        return;
    }
    
    for (int i = 0; i < pos-2; i++)
    {
        temp = temp->next;
    }

    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}

void displayRecursion(node* p)
{
    node * temp = p;
    if(p == NULL)
        return;

    cout << temp->data << " ";
    displayRecursion(temp->next);
}

void iterativeReverse()
{
    node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = NULL;
    // BEGINNING
    insertBeginning(2);
    insertBeginning(1);
    insertBeginning(0);
    display();

    head = NULL;

    // END
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    display();

    // POSITION
    insertNthPosition(5,3);
    display();
    insertNthPosition(1,1);
    display();
    insertNthPosition(6,2);
    display();
    insertNthPosition(7,2);
    display();

    deleteBeginning();
    display();

    deleteEnd();
    display();

    deletePosition(1);
    display();
    deletePosition(2);
    display();

    displayRecursion(head);

    iterativeReverse();
    cout << endl;
    display();

    return 0;
}
