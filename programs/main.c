#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main() {
    int word_length = 0;
    int word_lengths[MAX_WORD_LENGTH] = {0}; // 假设单词最大长度为20
    int c;

    // 读取输入并统计单词长度
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            word_length++;
        } else if (word_length > 0) {
            if (word_length <= MAX_WORD_LENGTH) {
                word_lengths[word_length - 1]++;
            }
            word_length = 0;
        }
    }

    // 如果输入以字母结束，确保最后一个单词也被统计
    if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
        word_lengths[word_length - 1]++;
    }

    // 打印水平直方图
    printf("Horizontal Histogram:\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > 0) {
            printf("%2d: ", i + 1);
            for (int j = 0; j < word_lengths[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}

