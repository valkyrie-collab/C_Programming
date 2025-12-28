#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Added for malloc

#define MAXLINE 5000
#define MAXLEN 1000

char *lineptr[MAXLINE];  // Global array of 5000 char pointers

// Simple allocator using malloc
char *alloc(int n) {
    return (char *)malloc(n);
}

// Reads one line into buffer, returns length
int getlines(char *p_arr, int limit) {
    int count, ch;
    
    // Read chars until EOF, newline, or buffer full
    for (count = 0; count < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; count++) {
        *p_arr++ = ch;  // Store char and advance pointer
    }
    
    if (ch == '\n') {  // FIXED: == instead of =
        *p_arr++ = ch;
        count++;
    }
    
    *p_arr = '\0';  // Null-terminate the string
    return count;
}

// Prints all lines
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);  // FIXED: Removed extra *
    }
}

// Reads all lines into memory
int read_lines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = getlines(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';  // Remove newline
            strcpy(p, line);       // Copy to heap
            lineptr[nlines++] = p; // Store pointer
        }
    }  // FIXED: Moved return outside loop
    
    return nlines;  // Return total lines read
}

// Swaps two pointer elements
void swap(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Quicksort for strings (renamed to avoid conflict)
void my_qsort(char *v[], int left, int right) {
    int i, last;
    
    if (left >= right) return;  // Base case: 0 or 1 element
    
    swap(v, left, (left + right) / 2);  // Move pivot to left
    last = left;
    
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {  // If v[i] < pivot
            swap(v, ++last, i);           // Move to left partition
        }
    }
    
    swap(v, left, last);  // Restore pivot
    
    my_qsort(v, left, last - 1);   // Sort left partition
    my_qsort(v, last + 1, right);  // Sort right partition
}

void free_memory(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        free(lineptr[i]);  // Free each allocated line
    }
}

int main() {
    int nlines;
    
    if ((nlines = read_lines(lineptr, MAXLINE)) > 0) {
        my_qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        free_memory(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/*
Let's trace the program with this input:

```
banana
apple
cherry
```

### Phase 1: Reading Input (`read_lines` and `getlines`)

**First iteration** (reading "banana\n"):
- `getlines` receives `line` buffer at address `0x7000`
- Reads 6 characters: `b`,`a`,`n`,`a`,`n`,`a`
- Sees newline, adds `\n`, then `\0`
- Returns length 7
- `read_lines` allocates 7 bytes at heap address `0x1000`
- Copies "banana" (without `\n`) to `0x1000`
- Stores pointer: `lineptr[0] = 0x1000`

**Second iteration** (reading "apple\n"):
- `getlines` reuses `line` buffer at `0x7000`
- Reads 5 characters, adds `\n`, then `\0`
- Returns length 6
- Allocates 6 bytes at `0x1007`
- Copies "apple" to `0x1007`
- Stores pointer: `lineptr[1] = 0x1007`

**Third iteration** (reading "cherry\n"):
- Allocates 7 bytes at `0x100D`
- Copies "cherry" to `0x100D`
- Stores pointer: `lineptr[2] = 0x100D`

**Memory layout after reading:**
```
Heap:
0x1000: "banana\0"
0x1007: "apple\0"
0x100D: "cherry\0"

Stack (lineptr array):
[0] = 0x1000  → "banana"
[1] = 0x1007  → "apple"
[2] = 0x100D  → "cherry"
```

### Phase 2: Sorting (`my_qsort`)

**Initial call**: `my_qsort(lineptr, 0, 2)`

**Partitioning step**:
- Pivot index = (0+2)/2 = 1 → "apple"
- `swap(v, 0, 1)` moves pivot to left: `lineptr` becomes `[0x1007, 0x1000, 0x100D]`
- `last = 0`
- Compare "banana" (0x1000) with pivot "apple": `strcmp` > 0 → no swap
- Compare "cherry" (0x100D) with pivot: `strcmp` > 0 → no swap
- Final swap restores pivot: `swap(v, 0, 0)` does nothing

**Recursive calls**:
- `my_qsort(v, 0, -1)` → returns immediately (base case)
- `my_qsort(v, 1, 2)` → sorts right partition

**Right partition sort**:
- Pivot index = (1+2)/2 = 1 → "banana"
- `swap(v, 1, 1)` does nothing
- Compare "cherry" with "banana": `strcmp` > 0 → no swap
- Partition complete

**Final `lineptr` state**:
```
[0] = 0x1007  → "apple"
[1] = 0x1000  → "banana"
[2] = 0x100D  → "cherry"
```

Notice the **strings never moved**—only their pointers shuffled positions in the array.

### Phase 3: Output (`writelines`)

Iterates through `lineptr` and prints:
```
printf("%s\n", 0x1007);  // prints "apple"
printf("%s\n", 0x1000);  // prints "banana"
printf("%s\n", 0x100D);  // prints "cherry"
```

**Final output**:
```
apple
banana
cherry
```

### Key Insights from This Example

- **Efficiency**: Sorting 3 strings required only 2 pointer swaps, not 18 character moves
- **Memory**: The heap holds three small, exact-sized allocations; the stack array holds just 3 addresses (24 bytes total)
- **Indirection**: `lineptr[i]` gives you a pointer to a pointer—dereferencing once gets the heap address, dereferencing again gets the character
- **Stability**: The newline stripping in `read_lines` makes `strcmp` compare only content, not formatting artifacts
*/
