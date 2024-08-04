/* f1.c */
int a;
static int b;
extern int c;
void y(int);
void d(int);
void x(int x, int y) {
    a += x;
    b += y;
    d(c);
}
int main() {
    y(a);
}