#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Linux/macOS 用，Windows 下改成 Sleep()

// 彩色代码数组
const char *colors[] = {
    "\033[31m", "\033[32m", "\033[33m", "\033[34m",
    "\033[35m", "\033[36m", "\033[91m", "\033[92m",
    "\033[93m", "\033[94m", "\033[95m", "\033[96m"
};

// 清屏并移动光标到左上角
void clear() {
    printf("\033[2J\033[H");
}

int main() {
    float x, y;
    int frame = 0;
    srand(time(0));

    while (1) {
        clear(); // 每一帧清屏
        for (y = 1.5f; y > -1.5f; y -= 0.1f) {
            for (x = -1.5f; x < 1.5f; x += 0.05f) {
                float a = x * x + y * y - 1;
                if (a * a * a - x * x * y * y * y <= 0.0f) {
                    int colorIndex = rand() % (sizeof(colors) / sizeof(colors[0]));
                    printf("%s*\033[0m", colors[colorIndex]);
                } else {
                    // 中心打印文字
                    if (y > -0.1f && y < 0.1f && x > -0.5f && x < 0.5f) {
                        const char *msg = "I ❤️ You";
                        int pos = (int)((x + 0.5f) / 1.0f * strlen(msg));
                        if (pos >= 0 && pos < strlen(msg))
                            printf("\033[97m%c\033[0m", msg[pos]);
                        else
                            printf(" ");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }

        usleep(100000); // 每帧等待 100ms (Linux/macOS)
        frame++;
    }

    return 0;
}

