#include <stdio.h>
#include<bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int n,i,j;
    cout<<"Enter Number of People : ";
    cin>>n;
    //time-quantum=1
    int a[n],b[n],w[n],won[n]={0};
    char pro[n],index[n];
    char ticket[100000];
    memset(ticket,'0',sizeof ticket);
    for(i=0;i<n;i++)
    {
        pro[i]=i+'A';
    }
    int total_burst=0;
    for(i=0;i<n;i++)
    {
        cout<<"Enter Number of Tickets Taken for Person "<<(char)(i+'A')<<" : ";
        cin>>b[i];
        total_burst+=b[i];
        cout<<"Enter Arrival Time of Person "<<(char)(i+'A')<<" : ";
        cin>>a[i];
    }
    cout<<endl;
    cout<<"Person\t\tArrival Time\t\tNo. of Tickets"<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"  "<<pro[i]<<"\t\t     "<<a[i]<<"\t\t\t    "<<b[i]<<endl;
    }
    cout<<endl;
    cout<<"\t::::::::::::After Sorting::::::::::::"<<endl;
    cout<<endl;
    for (i= 0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			//we are just arranging them according to there arrival process
			if (a[j] > a[j + 1])
			{
				int temp2 = a[j];
                a[j] =a[j + 1];
                a[j + 1] = temp2;

                int temp1 = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp1;

                char temp3 = pro[j];
                pro[j] = pro[j + 1];
                pro[j + 1] = temp3;
			}
		}
	}
	for(i=0;i<n;i++)
    {
        index[pro[i]-'A']=i;
	}
	//print table
    cout<<"Person\t\tArrival Time\t\tNo. of Tickets"<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"  "<<pro[i]<<"\t\t     "<<a[i]<<"\t\t\t    "<<b[i]<<endl;
    }
    cout<<endl;
    //ind=0;
    queue <char> q;
  /*  for(i=0;i<n;i++)
        q.push(pro[i]);*/
    int time=0;
    while(total_burst>0)
    {
        if(q.empty())
        {
            for(i=0;i<n;i++)
            {
                if(a[i]==time)
                    q.push(pro[i]);
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(a[i]==time+1)
                    q.push(pro[i]);
            }
        }
        if(q.empty())
        {
            time++;
            continue;
        }
        char c=q.front();
        q.pop();
        int ind=index[c-'A'];

        b[ind]--;
        total_burst--;
        if(b[ind]>0)
            q.push(pro[ind]);
        ticket[time]=c;
        time++;
    }
    cout<<endl;
    cout<<"\t::::::::::::Ticket Possessions::::::::::::"<<endl;
    cout<<endl;
    for(i=0;i<time;i++)
    {
        if(ticket[i]!='0')
        {
            cout<<"Ticket "<<i<<" belongs to "<<ticket[i]<<endl;
        }
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter Amount Person "<<(char)(i+'A')<<" desires to win : ";
        cin>>w[i];
    }
    int sec,max=-1;
    char winner;
    cout<<endl<<"Lottery runs for _ rounds : ";
    cin>>sec;
    int flag=0;
    cout<<endl;
    cout<<"\t::::::::::::Winners::::::::::::"<<endl;
    cout<<endl;
    for(i=0;i<sec;i++)
    {
        int win=rand()%time;
        if(ticket[win]=='0')
        {
            //cout<<"Ticket Doesn't Belong to Anyone"<<endl;
            i--;
        }
        else
        {
            cout<<"Winner of Round ";
            printf("%2d",i+1);
            cout<<" is Ticket ";
            printf("%2d",win);
            cout<<" which belongs to "<<ticket[win]<<endl;
            w[ticket[win]-'A']--;
            won[ticket[win]-'A']++;
            if(won[ticket[win]-'A']>max)
            {
                max=won[ticket[win]-'A'];
                winner=ticket[win];
            }
            if(w[ticket[win]-'A']==0)
            {
                cout<<endl;
                cout<<"\t::::::::::::Winner::::::::::::"<<endl;
                //cout<<endl;
                cout<<"    Person "<<ticket[win]<<" got his desired amount."<<endl;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        cout<<endl<<"Unfortunately no one won his desired amount but Person "<<winner<<" won the maximum amount "<<max<<".\n";
    }
    return 0;
}
/*
Sample Inputs:
5
3 5
1 7
5 5
3 1
2 8
20
14
10
12
15
15
*/
