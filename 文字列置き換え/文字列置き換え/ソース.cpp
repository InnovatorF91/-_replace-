/*������u������*/
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

        // �u�����镶�����T��
        p = strstr(p, before);
        if (p == NULL) {
            // ������Ȃ���΁A����ȏ�u��������̂͂Ȃ��̂ŏI������
            break;
        }

        // �u���ΏۂɂȂ�Ȃ��ʒu���v�Z
        const char* p2 = p + before_len;

        // �u���ΏۂɂȂ�Ȃ��ʒu(p2) �ȍ~�̕�������A
        // �u���̉e�����󂯂Ȃ��ʒu�Ɉړ�
        memmove(p + after_len, p2, strlen(p2) + 1);

        // �u������
        memcpy(p, after, after_len);

        // �T���J�n�ʒu�����炷
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