#include "ui.h"
#include "numberStack.h"
#include <string>
#include <ncurses.h>
#include <cmath>
using std::string;
using std::stod;
using CustomADT::NumberStack;
using std::pow;

char QUIT = 'q';
int DROP = KEY_DC;

int main ()
{
    int key = 0;
    double first, second;
    NumberStack s;
    string buffer = "";
    bool hasDot = false;

    init ();
    draw (s, buffer);
    drawPrompt (buffer);

    while (key != QUIT)
    {
        key = getch ();

        if (isdigit (key)) // number input
        {
            buffer += key;
            drawPrompt (buffer);
        }
        else if (key == '.' && !hasDot)
        {
            buffer += key;
            hasDot = true;
            drawPrompt (buffer);
        }
        else if (key == KEY_BACKSPACE)
        {
            hasDot = hasDot && !(buffer[buffer.length () - 1] == '.');
            
            if (buffer.length () > 1)
            {
                buffer.erase (buffer.length () - 1);
            }
            else
            {
                buffer = "";
            }

            drawPrompt (buffer);
        }
        else if ((key == '\n' || key == '\r' || key == KEY_ENTER) && buffer != "")
        {
            s.push (stod (buffer));
            buffer = "";
            hasDot = false;

            draw (s, buffer);
            drawPrompt (buffer);
        }
        else if (key == DROP && s.getLength () >= 1) // comands
        {
            s.pop ();
            draw (s, buffer);
        }
        else if (key == '+' && s.getLength () >= 2)
        {
            second = s.pop ();
            first = s.pop ();
            s.push (first + second);
            draw (s, buffer);
        }
        else if (key == '-' && s.getLength () >= 2)
        {
            second = s.pop ();
            first = s.pop ();
            s.push (first - second);
            draw (s, buffer);
        }
        else if (key == '*' && s.getLength () >= 2)
        {
            second = s.pop ();
            first = s.pop ();
            s.push (first * second);
            draw (s, buffer);
        }
        else if (key == '/' && s.getLength () >= 2)
        {
            second = s.pop ();
            if (second == 0)
            {
                s.push (second);
                drawError ();
            }
            else
            {
                first = s.pop ();
                s.push (first / second);
                draw (s, buffer);
            }
        }
        else if (key == 'p' && s.getLength() >= 2) {
            second = s.pop();
            first = s.pop();
            s.push(pow (first, second));
            draw(s, buffer);
        }
        else if (key == KEY_UP && s.getLength () >= 2)
        {
            second = s.pop ();
            first = s.pop ();

            s.push (second);
            s.push (first);

            draw (s, buffer);
        }
    }

    return 0;
}
