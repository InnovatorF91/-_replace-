/*文字列置き換え*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NUMBER 101

char* replace(char* s, const char* before, const char* after)
{
    assert(s != NULL);
    assert(before != NULL);
    assert(after != NULL);

    const size_t before_len = strlen(before);
    if (before_len == 0) {
        return s;
    }

    const size_t after_len = strlen(after);
    char* p = s;

    for (;;) {

        // 置換する文字列を探す
        p = strstr(p, before);
        if (p == NULL) {
            // 見つからなければ、これ以上置換するものはないので終了する
            break;
        }

        // 置換対象にならない位置を計算
        const char* p2 = p + before_len;

        // 置換対象にならない位置(p2) 以降の文字列を、
        // 置換の影響を受けない位置に移動
        memmove(p + after_len, p2, strlen(p2) + 1);

        // 置換する
        memcpy(p, after, after_len);

        // 探索開始位置をずらす
        p += after_len;
    }

    return s;
}

int main(void) {
    char s[NUMBER];
    do {
        scanf("%s", s);
    } while (s[0] == '\0');
    replace(s, "at", "@");
    printf("%s", s);
    return 0;
}