#ifndef NUMBERSTACK_H
#define NUMBERSTACK_H

namespace CustomADT
{
    class NumberStack
    {
        public:
            NumberStack ();
            ~NumberStack ();

            void push (double);
            double pop ();
            double peek () const;
            int getLength () const;
            bool isEmpty () const;

            double& operator[] (int) const;

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