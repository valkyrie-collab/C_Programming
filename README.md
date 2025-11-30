# CharacterInputOut.c has some explaination about getchar() putchar() first time written in this file; putchar 
# is a single argument function;

# CountBlanksTabsNewlines.c has major explanaiton about the getchar and putchar() functions and why putchar() 
# prints frist even when it is in the printf();

# CountNextLine.c has some info about EOF;

# EscapeCharacters.c has detail information about each and very escape character in the C programming

# LinuxWCcode.c this is the code for wc command in the terminal of unix/Linux system and how this works

# ReplacingSpecialCharactersWithTheirEscapeCharacter.c this code here replaces tabs and backspace with \t and \b *though I can't able to create backspace but tabs are working fine;

Q.why for getchar in the same line we have to pres ctrl+d two time but when in the fresh newline using enter only one time
Ans. Explanation:
      Unix terminals use line-buffered input by default.
      ##This means that input is not sent character-by-character to your program; it's buffered until you press Enter (newline).
      ##When you press Ctrl+D on an empty (fresh) line, it immediately signals EOF to the program because the input buffer is empty and Ctrl+D tells the terminal "send EOF now".
      ##However, if there is already some typed text on the current line (input buffer is not empty), pressing Ctrl+D just tells the terminal "send the current buffered input now" without EOF — the program reads that 
          input but doesn’t see EOF yet.
      ##You must press Ctrl+D a second time on the new empty line to signal EOF and end input.

# In C programming there is not "INDEX OUT OF BOUND ERROR" it should be done personally/ buy the programmer

Q. Why one should use int main() {return 0;} and not void main () {return ;}?
# Ans: This is because the C standard (and also the C++ standard) requires the return type of the main function to be int. This allows your program to return a value to the operating system, where returning 0 typically means successful execution and any non-zero value indicates an error.​

    Why not void main?
#        void main() is not standard compliant. While it might work on some compilers, it may not be portable and can cause undefined behavior, especially on systems where the OS expects an integer status code from the program.

#        The C standard does not guarantee what will happen if you use void main(), but it does guarantee behavior for the int main() signature.

#        Using int main() ensures maximum portability, correctness, and proper communication of the program's exit status.

Q. Why do we need to copy instead of just printing temp_arr?
# Ans: In your program, you read multiple lines into the same buffer temp_arr. Each new line overwrites the old 
#        contents.

#    If you want to remember the longest line (or any specific line), you must copy it into another buffer (longest_arr) before temp_arr gets overwritten.

#    Just printing temp_arr at the end will show only the last input line, because all previous lines were overwritten.

#    Copying stores the desired line separately, preserving it for later use.

Q. Why is null terminator ('\0') important?
# Ans: In C, strings are represented as arrays of characters terminated by a null character '\0'.

#       The null terminator marks where the string ends.

#       Functions like printf("%s", ...) rely on '\0' to know when to stop printing.

#       Without '\0', the string is considered unterminated, so printing continues to read adjacent memory until it finds a zero byte or crashes, often showing garbage characters (�).

Q. Why does copying work fine even if we "skip" the null terminator in the copy loop?
# Ans: In your copying loop:

    <!-- c
    int i = 0;
    while ((longest_arr[i] = temp_arr[i]) != '\0') {
        i++;
    } -->
#   This loop copies the null terminator '\0' as well; it stops only after copying it.

#   So longest_arr also ends with a valid null terminator.

#   This makes longest_arr a properly null-terminated string suitable for printing.

Q. Why does printing temp_arr without a null terminator cause garbage output?
#  Ans: In your original code, when the input line is not null-terminated properly, or a previous line        overwrites the array partially, temp_arr may not have a '\0' at the end.

#   Printing such an array with %s in printf causes the function to read beyond the valid text until it randomly encounters '\0' in memory.

#   This shows unintended characters or corruption symbols (�) on console.

Q. what is segmentation fault(Core Dumped)
# Ans: It is an error occur when we want to access the unaccessable part of the memory like going out of range in array ex: array of size 10 but accessing the 10the index

Q. What will happen is we do not end the Character array with '\0' while printing with %s in C
# Ans: In C, strings are arrays of characters terminated by a null character '\0'. This null marks the end of the string for printing or other string operations. If the null terminator is missing or misplaced, functions like printf("%s") continue reading memory after the intended string until they randomly hit a '\0'. This causes garbage, or unexpected characters, to print after the string.

# When using math library which is sperated from the C stander library must use -lm when creating executable file <filename.c -o filename -lm>

# To get desire number of bits one must create mask of number of bits required "mask = ~(~0 << bits);"

# To find move bits for the give number is "(num >> (position + 1 - bits)) & mask" to get the desire bits
