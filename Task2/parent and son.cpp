#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    pid_t pid = fork();

    if (pid > 0)
    {
        int f=0;
        cout<<"We have created a Child process"<<endl;
        cout<<"Child ID: "<<getpid()<<endl;
        cout<<"Something interesting"<<endl;
        execl("/bin/ps","ps",NULL);
        cout<<endl;
        exit(0);
    }
    else if (pid == 0)
        cout<<endl<<"The Child: "<<getpid()<<" The Parent: "<<getppid()<<endl<<endl;
    else 
        cout<<"error"<<endl;


}
