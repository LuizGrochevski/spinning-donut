#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int k;
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];

    printf("\x1b[2J");

    for (;;) {
        memset(b, 32, sizeof(b));
        memset(z, 0, sizeof(z));

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sinf(i);
                float d = cosf(j);
                float e = sinf(A);
                float f = sinf(j);
                float g = cosf(A);
                float h = d + 2.0f;
                float D = 1.0f / (c * h * e + f * g + 5.0f);
                float l = cosf(i);
                float m = cosf(B);
                float n = sinf(B);
                float t = c * h * g - f * e;

                int x = 40 + (int)(30 * D * (l * h * m - t * n));
                int y = 12 + (int)(15 * D * (l * h * n + t * m));
                int o = x + 80 * y;
                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));

                if (x > 0 && x < 80 && y > 0 && y < 22 && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        printf("\x1b[H");
        for (k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : '\n');
        }

        A += 0.04f;
        B += 0.02f;
    }

    return 0;
}
