#include <stdio.h>

#define TOTAL_CHARS 128  // ASCII字符集的大小

int main() {
    int c;
    int freq[TOTAL_CHARS] = {0};  // 用于存储每个字符的频率
    int i, j;

    // 读取输入的字符并统计频率
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < TOTAL_CHARS) {
            freq[c]++;
        }
    }

    // 打印字符频度的直方图
    printf("\nCharacter Frequency Histogram:\n");
    for (i = 0; i < TOTAL_CHARS; i++) {
        if (freq[i] > 0) {
            if (i == '\n') {
                printf("\\n  : ");
            } else if (i == '\t') {
                printf("\\t  : ");
            } else if (i == ' ') {
                printf("' '  : ");
            } else {
                printf("%c   : ", i);
            }
            for (j = 0; j < freq[i]; j++) {
                printf("#");
            }
            printf(" (%d)\n", freq[i]);  // 打印频率值
        }
    }

    return 0;
}

