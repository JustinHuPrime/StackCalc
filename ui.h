#ifndef UI_H
#define UI_H

#include "numberStack.h"
#include <string>
using std::string;
using CustomADT::NumberStack;

void init ();
void uninit ();
void draw (const NumberStack&, const string&);
void drawPrompt (const string&);

#endif /* UI_H */