#include "ui.h"
#include "numberStack.h"
#include <string>
#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
using std::to_string;
using CustomADT::NumberStack;

void init ()
{
    setlocale (LC_ALL, "");
    initscr ();
    cbreak ();
    nonl();
    noecho ();
    intrflush(stdscr, false);
    keypad(stdscr, true);
    atexit (uninit);
}

void uninit ()
{
    endwin ();
}

void draw (const NumberStack& s, const string& buffer)
{
    int maxY = getmaxy (stdscr);
    string number;

    for (int i = 0; i < maxY - 1; i++)
    {
        move (i, 0);
        clrtoeol ();
    }

    for (int j = 0, i = maxY - 2; i > 0 && j < s.getLength (); i--, j++)
    {
        move (i, 0);
        number = to_string(s[j]);
        
        if (number.find ('.') != string::npos)
        {
            while (number [number.length () - 1] == '0')
            {
                number.erase (number.length () - 1);
            }
        }

        if (number [number.length () - 1] == '.')
        {
            number.erase (number.length () - 1);
        }

        printw (number.c_str ());
    }

    if (s.getLength () >= getmaxy (stdscr) - 2)
    {
        move (0, 0);
        clrtoeol ();
        printw ("...");
    }

    move (maxY - 1, 2 + buffer.length ());

    refresh ();
}

void drawPrompt (const string& s)
{
    int maxY = getmaxy (stdscr);

    move (maxY - 1, 0);
    clrtoeol ();
    printw (("> " + s).c_str ());
    move (maxY - 1, 2 + s.length ());

    refresh ();
}