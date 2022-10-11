#include <iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int *schedule(int **jobs,int n);
int sort(int **jobs, int n);

int main()
{
    int **jobs;
    int n=5;
    jobs=new int*[5];
    for(int i=0;i<5;i++)
    {
        jobs[i]=new int(3);
    }
    int job1[3]={'A',100,2};
    int job2[3]={'B',19,1};
    int job3[3]={'C',27,2};
    int job4[3]={'D',25,1};
    int job5[3]={'E',15,3};
    jobs[0]=job1;
    jobs[1]=job2;
    jobs[2]=job3;
    jobs[3]=job4;
    jobs[4]=job5;

    int *sol;
    sol=new int(3);
    sol=schedule(jobs,n);

    return 0;
}



int* schedule(int **jobs,int n)
{
    int slots;
    slots=sort(jobs,n);
    slots++;

    for(int i=0;i<n;i++)
    {
        cout<<(char)jobs[i][0]<<"\t"<<jobs[i][1]<<"\t"<<jobs[i][2]<<"\n";
    }

    int *solution=new int(slots);
    for(int i=0;i<slots;i++)
    {
        solution[i]=0;
    }


    for(int i=0;i<n;i++)
    {
        int dl=jobs[i][2];
        for(int j=dl-1;j>=0;j--)
        {
            if(solution[j]==0)
            {
                solution[j]=jobs[i][0];
                break;
            }
        }
    }
    cout<<"Solution : ";
    for(int i=0;i<slots;i++)
    {
        cout<<(char)solution[i]<<" ";
    }
    return solution;
    /*
    for(int i=0;i<n;i++)
    {
        cout<<(char)jobs[i][0]<<"\t"<<jobs[i][1]<<"\t"<<jobs[i][2]<<"\n";
    }
    */

    return NULL;
}



int sort(int **jobs,int n)
{
    int *temp;
    int slots=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(jobs[j][1]<jobs[j+1][1])
            {
                slots=(slots>jobs[i][2])?slots:jobs[i][2];
                temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
    return slots;
}
