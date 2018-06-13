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