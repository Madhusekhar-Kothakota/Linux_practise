#include<stdio.h>
int main() {
    thread t1(display1);
    thread t2(display2);
    t1.join();
    t2.join();
}
void display1()
{
    printf("Displaying from thread 1\n");
}
void display2()
{
    printf("Displaying from thread 2\n");
}