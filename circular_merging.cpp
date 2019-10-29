#include<bits/stdc++.h>
using namespace std;
int long long sumall(int long long arr[],int long long a,int long long b)
{
	int long long sum=0;
	for(int i=a;i<=b;i++)
	{
		sum=sum+arr[i];
	}
	return sum;
}
int long long khatarnak(int long long arr[],int long long a,int long long b,int long long dyn[][500])
{
	if(dyn[a][b]!=0)
	{
		return dyn[a][b];
	}
	if(a==b)
	{
		dyn[a][b]=0;
		return dyn[a][b];
	}
	if(a+1==b)
	{
		dyn[a][b]=arr[a]+arr[b];
		return dyn[a][b];
	}
	int long long min=10000000000000000;
	int long long s=sumall(arr,a,b),t;
	for(int i=a;i<b;i++)
	{
		t=s+khatarnak(arr,a,i,dyn)+khatarnak(arr,i+1,b,dyn);
		if(min>t)
		{
			min=t;
		}
	}
	
	dyn[a][b]=min;
	return min;
}
int main()
{
	int long long test,size,i,j,k;
	cin>>test;
	while(test--)
	{
		cin>>size;
		int long long dyn[500][500]={0};
		int long long arr[1000],copy[1000],c=0;
		for(i=0;i<size;i++)
		{
			cin>>arr[i];
		}
		int long long max=0;
		for(i=0;i<size;i++)
		{
			if(max<arr[i])
			{
				max=arr[i];
				k=i;
			}
		}
		for(i=k+1;i<size;i++)
		{
			copy[c++]=arr[i];
		}
		for(i=0;i<=k;i++)
		{
			copy[c++]=arr[i];
		}
		for(i=0;i<size;i++)
		{
			arr[i]=copy[i];
		}
		cout<<khatarnak(arr,0,size-1,dyn)<<endl;
	}
	return 0;
}
