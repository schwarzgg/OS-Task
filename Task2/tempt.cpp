#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    FILE *input,*output;
    int cnt=1;

    char msg[256];
    memset(msg,0,sizeof(msg));

    input=fopen("fifo","r");
    if (input == NULL)
    {
        cout<<"error in fdopen"<<endl;
        exit(1);
    }
    while ((cnt = fread(msg,sizeof(char),256,input) > 0))
        cout<<"received success:"<<msg<<endl;
    fclose(input);

    output=fopen("fifo","w");
    if (output == NULL)
    {
        cout<<"erroe in fdopen"<<endl;
        exit(1);
    }
    
    sprintf(msg,"this is a test example");
    fwrite(msg,sizeof(char),256,output);
    fclose(output);
    return 0;
}
