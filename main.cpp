#include <iostream>
using namespace std;
#define BOUND 3
struct node {
    int data;
    node* next;
};

struct stack
{
    int capacity;
    node* head;
    node* top;
};
node* getnode(int key)
{
    node* k;
    k=new node;
    k->data =key;
    k->next = NULL;
    return k;
}
void init(stack& s)
{
    s.capacity = BOUND;
    s.head = NULL;
    s.top=s.head;
};
bool isfull(stack s)
{
    node* temp = s.head;
    int count=0;
    while (temp != NULL)
    {
        count++;
        temp=temp->next;
    };
    if (count >= s.capacity)
        return true;
    else
        return false;
};
bool isEmpty(stack s)
{
    node* temp = s.head;
    int count=0;
    while (temp != NULL)
    {
        count++;
        temp=temp->next;
    };
    if (count == 0)
        return true;
    else
        return false;
};

void push(stack& s, int val)
{
    try
    {
        if (isfull(s)!=true)
        {
            node *temp = s.head;
            node *k = getnode(val);
            if (s.head == NULL) {
                k->next = s.head;
                s.head = k;
            } else {
                while (temp->next != NULL) temp = temp->next;
                temp->next = k;
            }
            cout <<"value "<<val<<" added." << endl;
        }
        else throw(val);
    }
    catch (int k)
    {
        cout <<"value "<<val <<": <!Stack is full. Cannot add more elements>"<<endl;

    }

};
void pop(stack& s)
{
    node** popnode=&s.head;
    node* temp =s.head;
    while((*popnode)->next != NULL)
    {
        popnode = &((*popnode)->next);
        temp=*popnode;
    };
    *popnode = temp->next;
    delete temp;
}
int peek();
void display(stack s)
{
    for (node* i=s.head;i;i=i->next)
        cout<<i->data<<" ";
    cout<<endl;
};

int main() {
    stack s;
    int val;
    init(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    display(s);
    pop(s);
    display(s);
    return 0;
}
