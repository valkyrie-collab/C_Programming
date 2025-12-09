#ifndef CAL
#define CAL
#define NUMBER '1'
#define MAX_LEN 100
#define MAX_STK_SIZE 50

extern double stack[MAX_STK_SIZE];
extern int top;
extern char buffer_arr[MAX_STK_SIZE];
extern int buf_top;

void push(double val);//
double pop();//
int gettop(char s[]);//
int getlines();//
void ungetchar(char c);//

#endif