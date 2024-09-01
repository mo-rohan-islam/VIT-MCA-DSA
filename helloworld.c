#include <stdio.h>

// Function declaration (prototype)
void print(const char *message);

int main () {
    print("Hello World!");
    return 1;
}

void print(const char *message) {
    printf("%s\n\n", message);
}