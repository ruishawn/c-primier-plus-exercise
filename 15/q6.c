/*
Design a bit-field structure that holds the following information: 
Font ID: A number in the range 0–255 
Font Size: A number in the range 0–127 
Alignment: A number in the range 0–2 represented the choices Left, Center, and Right 
Bold: Off (0) or on (1) 
Italic: Off (0) or on (1) 
Underline: Off (0) or on (1) 
 Use this structure in a program that displays the font parameters and uses a looped menu 
to let the user change parameters. For example, a sample run might look like this: 
 ID SIZE ALIGNMENT B I U
 1 12 left off off off
 f)change font s)change size a)change alignment
 b)toggle bold i)toggle italic u)toggle underline
 q)quit
s
 Enter font size (0-127): 36
 ID SIZE ALIGNMENT B I U
 1 36 left off off off
 f)change font s)change size a)change alignment
 b)toggle bold i)toggle italic u)toggle underline
 q)quit
a
 Select alignment:
 l)left c)center r)right
r
 ID SIZE ALIGNMENT B I U
 1 36 right off off off

  f)change font s)change size a)change alignment
 b)toggle bold i)toggle italic u)toggle underline
 q)quit
i
 ID SIZE ALIGNMENT B I U
 1 36 right off on off
 f)change font s)change size a)change alignment
 b)toggle bold i)toggle italic u)toggle underline
 q)quit
q
 Bye! 
The program should use the & operator and suitable masks to ensure that the ID and size 
entries are converted to the specified range.

*/