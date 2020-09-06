/*************************************************************************
	> File Name: 20_有效的括号.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 19时05分38秒
 ************************************************************************/
bool isValid(char *s) {
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;
    while (s[0]) {
        switch(s[0]) {
            case '(':
            case '[':
            case '{':stack[++top] = s[0]; break;
            case ')':flag = (top != -1 && stack[top--] == '(');break;
            case ']':flag = (top != -1 && stack[top--] == '[');break;
            case '}':flag = (top != -1 && stack[top--] == '{');break;
        }
        s++;
        if (!flag) break;
    }
    free(stack);
    return (flag && top == -1) 
}
