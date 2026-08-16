#include<iostream>
#include <unistd.h>
#include <string.h>

using namespace std;
int main()
{
    int fd[2];
    pipe(fd);
    char buffer[20];
    if(fork()==0)
    {   close(fd[1]);
        cout<<"Child process"<<endl;
        read(fd[0], buffer, sizeof(buffer));
        cout<<"Data received: "<<buffer<<endl;
        close(fd[0]);
    }
    else
    {
       close(fd[0]);
        char  msg[]="Hello from parent";
        write(fd[1], msg, sizeof(msg));
        cout<<"Parent process"<<endl;
        close(fd[1]);
    }
}