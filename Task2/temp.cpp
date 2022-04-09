#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    pid_t pid1 = fork();

    if (pid1 == 0)
        cout<<"pid1:The Child: "<<getpid()<<" The Parent: "<<getppid()<<endl;
    else if (pid1 > 0)
    {
        pid_t pid2 = fork();

        if (pid2 == 0)
            cout<<"pid2:The Child: "<<getpid()<<" The Parent: "<<getppid()<<endl;
        else if (pid2 > 0)
            cout<<"The Twins: "<<pid1 <<" and "<<pid2<<endl;
        else 
            cout<<"pid2 error"<<endl;
    }
    else cout<<"pid1 error"<<endl;
    return 0;
}
