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

void drawError ()
{
    int maxY = getmaxy (stdscr);

    move (maxY - 1, 2);
    printw ("Error: divide by zero attempted.");
    move (maxY - 1, 2);

    refresh ();
}