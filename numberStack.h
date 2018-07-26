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

#ifndef NUMBERSTACK_H
#define NUMBERSTACK_H

namespace CustomADT
{
    class NumberStack
    {
        public:
            NumberStack ();
            ~NumberStack ();

            void push (double); //adds value to stack
            double pop (); //removes value from stack and returns that value
            double peek () const; //returns value from top of stack
            int getLength () const;
            bool isEmpty () const; 

            double& operator[] (int) const; //gets the n'th element - O(n).

        private:
            struct Node
            {
                double data;
                Node* next;
            };

            Node* head;
            int length;
    };
}

#endif /* NUMBERSTACK_H */