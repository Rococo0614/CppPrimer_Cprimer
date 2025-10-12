#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string() {
    int capacity = 0, length = 0;
    char *str = NULL;
    int ch;

    while ((ch = getchar()) != ' ' && ch != '\n' && ch != EOF) {
        if (length + 1 >= capacity) {
            capacity = (capacity == 0) ? 16 : capacity * 2;
            char *temp = realloc(str, capacity);
            if (!temp) { free(str); return NULL; }
            str = temp;
        }
        str[length++] = (char)ch;
    }

    if (str) {
        str[length] = '\0';
    } else {
        str = calloc(1, 1);
    }
    return str;
}

int get_state(char *str) {
    if (strcmp(str, "Scissors") == 0) return 0;
    if (strcmp(str, "Paper") == 0) return 1;
    if (strcmp(str, "Rock") == 0) return 2;
    return -1;
}

int which_to_win(char *str1, char *str2) {
    int state1 = get_state(str1);
    int state2 = get_state(str2);

    if (state1 == -1 || state2 == -1) {
        free(str1); free(str2);
        return -1;
    }

    if (state1 == state2) {
        printf("Tie\n");
    } else if ((state2 - state1 + 3) % 3 == 2) {
        printf("Player2\n");
    } else {
        printf("Player1\n");
    }

    free(str1); free(str2);
    return 0;
}

int main() {
    int num;
    if (scanf("%d", &num) != 1) return -1;
    while (getchar() != '\n');  // 清空缓冲区

    for (int i = 0; i < num; i++) {
        char *str1 = get_string();
        char *str2 = get_string();
        if (which_to_win(str1, str2) == -1) return -1;
    }
    return 0;
}