#ifndef GFLOAT

#define GFLOAT
#define BUFF_SIZE 100

extern int buff_arr[BUFF_SIZE];
extern int buff_top;

int getchs();
void ungetchs(int c);
int check_buffer(int c);
int get_float(double *pn);

#endif