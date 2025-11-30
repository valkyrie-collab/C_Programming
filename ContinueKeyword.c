#include <stdio.h>
/*Continue just skips the other codes below it*/
void check_continue() {

    for (int i = 0; i < 10; i++) {
        
        if (i % 2 == 0) {
            continue;
        }

        printf("%d\n", i);
    }

}

int main() {
    check_continue();
    return 0;
}