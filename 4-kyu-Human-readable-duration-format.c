#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *formatDuration(int n) {
    char *str = malloc(100);

    if (n == 0)return "now";

    int y = n / 31536000;
    n -= y * 31536000;
    int d = n / 86400;
    n -= d * 86400;
    int h = n / 3600;
    n -= h * 3600;
    int m = n / 60;
    n -= m * 60;
    int s = n;

    int time_array[5] = {y, d, h, m, s};
    char word_array[5][7] = {"year", "day", "hour", "minute", "second"};

    int i = 0;
    for (int j = 0; j < 5; ++j) {
        if (time_array[j] > 0) {
            i += 1;
        }
    }

    for (int j = 0; j < 5; ++j) {
        if (time_array[j] != 0) {
            char num[100] = {0};
            sprintf(num, "%d %s%s", time_array[j], word_array[j], time_array[j] == 1 ? "" : "s");
            strcat(str, num);

            if (i == 2) strcat(str, " and ");
            if (i-- > 2) strcat(str, ", ");
        }
    }
    return str;
}

int main() {
    printf("%s", formatDuration(1));

    return 0;
}