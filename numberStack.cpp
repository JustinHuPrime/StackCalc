// Copyright 2018 Justin Hu
//
// This file is part of StackCalc.
//
// StackCalc is free software: you can redistribute it and / or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// StackCalc is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// StackCalc.  If not, see <https://www.gnu.org/licenses/>.

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