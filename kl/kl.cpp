// kl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
class node
{
public:
    int roll_no;
    string name;
    float cgpa;
    node* next;
    node* back;
    node()
    {
        roll_no = 0;
        name = "";
        cgpa = 0.0;
        next = NULL;
        back = NULL;
    }
};
class linklist {
public:
    node* head;
    node* tail;
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insertion(int roll_no, string name, float cgpa)
    {
        node* temp = new node;
        temp->roll_no = roll_no;
        temp->name = name;
        temp->cgpa = cgpa;
        int flag = 0;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else if (temp->name < head->name)
        {
            temp->next = head;
            head->back = temp;
            head = temp;
        }
        else
        {
            node* s = head;

            while (s != tail)
                if (s->name < temp->name && temp->name < s->next->name)
                {
                    temp->next = s->next;
                    temp->back = s;
                    s->next->back = temp;
                    s->next = temp;
                    flag++;
                    break;
                }
                else
                    s = s->next;
        }
        if (flag == 0)
        {
            tail->next = temp;
            temp->back = tail;
            tail = tail->next;
        }

    }
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        cout << "Student Data:" << endl;
        while (current != NULL)
        {
            cout << "Roll No: " << current->roll_no << ", Name: " << current->name << ", CGPA: " << current->cgpa << endl;
            current = current->next;
        }
    }

};

int main()
{
    linklist l;
    int roll_no;
    string name;
    float cgpa;

    for (int i = 0; i <= 2; i++)
    {
        cout << "ENTER ROLL NO. , NAME , CGPA " << endl;
        cin >> roll_no;
        cin >> name;
        cin >> cgpa;
        l.insertion(roll_no, name, cgpa);
    }
    l.display();
    system("pause");
    return 0;
}