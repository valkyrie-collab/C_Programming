#CharacterInputOut.c has some explaination about getchar() putchar() first time written in this file; putchar is a single argument function;
#CountBlanksTabsNewlines.c has major explanaiton about the getchar and putchar() functions and why putchar() prints frist even when it is in the printf();
#CountNextLine.c has some info about EOF;
#EscapeCharacters.c has detail information about each and very escape character in the C programming
#LinuxWCcode.c this is the code for wc command in the terminal of unix/Linux system and how this works
#ReplacingSpecialCharactersWithTheirEscapeCharacter.c this code here replaces tabs and backspace with \t and \b *though I can't able to create backspace but tabs are working fine;

Q.why for getchar in the same line we have to pres ctrl+d two time but when in the fresh newline using enter only one time
Ans. Explanation:
      Unix terminals use line-buffered input by default.
      ##This means that input is not sent character-by-character to your program; it's buffered until you press Enter (newline).
      ##When you press Ctrl+D on an empty (fresh) line, it immediately signals EOF to the program because the input buffer is empty and Ctrl+D tells the terminal "send EOF now".
      ##However, if there is already some typed text on the current line (input buffer is not empty), pressing Ctrl+D just tells the terminal "send the current buffered input now" without EOF — the program reads that 
          input but doesn’t see EOF yet.
      ##You must press Ctrl+D a second time on the new empty line to signal EOF and end input.
