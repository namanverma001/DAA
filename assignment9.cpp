#include<iostream>
#include<vector>
using namespace std;

//global var
int n,sackSize;
int maxProfit=-1;
vector<string> answer;

void solveKnapsack(string s,int index,int P[],int W[],int curWsum,int curPsum)
{
    if(index==n)
    {
        if (curWsum<=sackSize)
        {
            if (curPsum>maxProfit)
            {
                maxProfit=curPsum;
                answer.clear();
                answer.push_back(s);
            }
            else if (curPsum==maxProfit)
            {
                answer.push_back(s);
            }
        }
        
        return ;
        
    }

    if (curWsum>sackSize)
    {
        return; //bounding check
    }
    
    solveKnapsack(s+'1',index+1,P,W,curWsum+W[index],curPsum+P[index]);
    solveKnapsack(s+'0',index+1,P,W,curWsum,curPsum);
    
}



int main()
{

    cout<<"\n\nENter number of objects: ";
    cin>>n;
    cout<<"\n\nEnter sack size : ";
    cin>>sackSize;

    cout<<"\n\nEnter weight and then its profit  : \n";

    int P[n];
    int W[n];

    for (int i = 0; i < n; i++)
    {
        cin>>W[i]>>P[i];
    }
    
    solveKnapsack("",0,P,W,0,0);


    cout<<"\n\nMax profit -> "<<maxProfit<<"\n\n";
    
    for (int i = 0; i < answer.size(); i++)
    {
        cout<<answer[i]<<endl;
    }

    return 0;
}


/*
PS F:\c cpp\TY\DAA> g++ '.\ass9 knapsack backtracking.cpp'
PS F:\c cpp\TY\DAA> .\a.exe


ENter number of objects: 3


Enter sack size : 5


Enter weight and then its profit  :
2 10
3 5
3 5




Max profit -> 15

110
101
PS F:\c cpp\TY\DAA>


*/ 