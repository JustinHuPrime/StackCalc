#include "numberStack.h"
using namespace CustomADT;

NumberStack::NumberStack (): head {nullptr}, length {0}
{}

NumberStack::~NumberStack ()
{
    Node* temp = head -> next;
    
    while (head != nullptr)
    {
        temp = head -> next;
        delete head;
        head = temp;
    }
}

void NumberStack::push (double value)
{
    Node* node = new Node;

    node -> next = head;
    node -> data = value;

    head = node;

    length++;
}

double NumberStack::pop ()
{
    if (isEmpty ())
    {
        throw "NumberStack::pop: stack is empty - cannot pop.";
    }

    Node* victim = head;
    head = victim -> next;

    double victimData = victim -> data;

    delete victim;
    
    length--;

    return victimData;
}

double NumberStack::peek () const
{
    return head -> data;
}

int NumberStack::getLength () const
{
    return length;
}

bool NumberStack::isEmpty () const
{
    return length == 0;
}

double& NumberStack::operator[] (int index) const
{
    if (index >= length)
    {
        throw "NumberStack::operator[]: requested index is past the end of the stack.";
    }

    Node* curr = head;

    for (; index > 0; index--)
    {
        curr = curr -> next;
    }

    return curr -> data;
}