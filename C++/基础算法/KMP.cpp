#include <bits/stdc++.h>
using namespace std;

int *fail(char *p) {
    int len = strlen(p);
    int *f = (int *) malloc(len * sizeof(int));
    f[0] = -1;
    int i, j;
    for(j = 1; j < len; j++) {
        for(i = f[j-1]; ; i = f[i]) {
            if(p[j] == p[i+1]) {
                f[j] = i + 1;
                break;
            }
            else if(i == -1) {
                f[j] = -1;
                break;
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%d ",f[i]);
    }
    printf("\n");
    return f;
}
int kmp(char *t, char *p) {
    int *f = fail(p);
    int i, j;
    for(i = 0, j = 0; i < strlen(t) && j < strlen(p); ) {
        if(t[i] == p[j]) {
            i++;
            j++;
        }
        else if(j == 0)
            i++;
        else
            j = f[j-1] + 1;
    }
    return j == strlen(p) ? i - strlen(p) : -1;
}

int main()
{
    char s[]="aaaababcdeabcainnabkanancsncadhla";
    char p[]="abcdeabc";
    printf("%d\n",kmp(s,p));
    fail2(p);

    return 0;
}
