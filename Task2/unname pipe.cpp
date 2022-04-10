#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);


    pid_t pid = fork();
    char msg1[256];//son
    char msg2[256];//fa
    
    memset(msg1,0,sizeof(msg1));
    memset(msg2,0,sizeof(msg2));

    int fd1[2]; // son
    int fd2[2]; // fa

    pipe(fd1);pipe(fd2);

    if (pid == 0)
    {
        // cout<<"Child process: "<<endl;
        while (1)
        {
            memset(msg1,0,sizeof(msg1));
            memset(msg2,0,sizeof(msg2));

            read(fd1[0],msg2,30);
            cout<<"Parent: "<<msg2<<endl;

            cout<<"Child: ";
            scanf("%s",msg1);

            write(fd2[1],msg1,strlen(msg1));
            cout<<msg1<<endl;
        }
        close(fd1[0]);close(fd2[1]);
    }
    else if (pid > 0)
    {
        // cout<<"Pareent process: "<<endl;
        while (1)
        {
            memset(msg1,0,sizeof(msg1));
            memset(msg2,0,sizeof(msg2));

            cout<<"Parent: ";
            // cin>>msg2;
            scanf("%s",msg2);

            write(fd1[1],msg2,strlen(msg2));
            
            read(fd2[0],msg1,30);

            cout<<"Child: "<<msg1<<endl;
        }
        close(fd2[0]);close(fd1[1]);
    }
    else 
    {
        cout<<"error"<<endl;
        exit(0);
    }
}
