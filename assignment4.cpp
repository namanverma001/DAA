/*Develop a program to solve a fractional Knapsack problem using a greedy 
method.*/

#include<iostream>
using namespace std;

int main(){
	int n,m;
	cout<<"\nEnter the number of object: ";
	cin>>n;
	cout<<"\nEnter the knapsack size: ";
	cin>>m;
	
	float profit[n],weight[n],div[n],x[n];
	for(int i=0;i<n;i++){
		cout<<"\nEnter the profit of object "<<i+1<<" : ";
		cin>>profit[i];
		cout<<"\nEnter the weight of object "<<i+1<<" : ";
		cin>>weight[i];	
	}


	cout<<"\n| Object\tProfit\tWeight\tProfit/Weight"<<endl;
	for(int i=0;i<n;i++){
		div[i]=(profit[i]/weight[i]);
		cout<<"\t"<<i+1<<"\t"<<profit[i]<<"\t"<<weight[i]<<"\t"<<div[i]<<"\t"<<endl;
	}
	

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
		if(div[j] < div[j+1]){
				swap(profit[j],profit[j+1]);
				swap(weight[j],weight[j+1]);
				swap(div[j],div[j+1]);	
			}
		}
	}
	cout<<"\n---------------------step2----------------------";
	cout<<"\n| Object\tProfit\tWeight\tProfit/Weight"<<endl;

	for(int i=0;i<n;i++){
		cout<<"\t"<<i+1<<"\t"<<profit[i]<<"\t"<<weight[i]<<"\t"<<div[i]<<"\t"<<endl;
	}
	for(int i=0;i<n;i++){
		x[i]=0.0;
	}
	int u=m,i;
	for(i=0;i<n;i++){
		if(weight[i]>u){
			break;	
		}
		x[i]=1.0;
		u=u-weight[i];
	}
	if(i<n){
		 x[i]=u/weight[i];	
	}

	int total_profit=0.0;
	cout<<"\n---------------------step3----------------------";
	cout<<"\n| Object\tProfit\tWeight\tX[i]\tWeight[i]*x[i]\tProfit[i]*x[i]"<<endl;
	for(int i=0;i<n;i++){
		float fact_weight=weight[i]*x[i];
		float obj_profit=profit[i]*x[i];
		total_profit+=obj_profit;
		cout<<"    "<<i+1<<"        "<<profit[i]<<"        "<<profit[i]<<"        "<<x[i]<<"           "<<fact_weight<<"           "<<obj_profit<<endl;
	}
	cout<<"Total profit is : "<<total_profit;
	return 0;
}
