#include "ui.h"
#include "numberStack.h"
#include <list>
#include <string>
#include <ncurses.h>
using std::string;
using std::stod;
using CustomADT::NumberStack;

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

        if (isdigit (key))
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
            hasDot = !(buffer[buffer.length () - 1] == '.');
            
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
        else if (key == '\n' || key == '\r' || key == KEY_ENTER)
        {
            s.push (stod (buffer));
            buffer = "";
            hasDot = false;

            draw (s, buffer);
            drawPrompt (buffer);
        }
        else if (key == DROP && s.getLength () >= 1)
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
            first = s.pop ();
            s.push (first / second);
            draw (s, buffer);
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