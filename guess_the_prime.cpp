#include<bits/stdc++.h>
using namespace std;
set<long long> factors_prime(int long long no)
{
	set<long long> factors;
	while (no % 2 == 0)  
    {  
        factors.insert(2);
        no = no/2;  
    }
    for (int i = 3; i <= sqrt(no); i = i + 2)  
    {
        while (no % i == 0)  
        {  
            factors.insert(i);
            no = no/i;  
        }  
    }  
    if (no > 2)  
        factors.insert(no);
    return factors;
}

vector<long long int> print_Intersection(vector<long long int> arr1, vector<long long int> arr2) 
{ 
	int m=arr1.size(); int n=arr2.size();
  int i = 0, j = 0; 
  vector<long long int>v;
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
       i++; 
    else if (arr2[j] < arr1[i]) 
       j++; 
    else
    { 
       v.push_back(arr2[j]); 
       i++; 
       j++; 
    } 
  } 
  return v;
} 



main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		long long int x,y,l,a=99998,b,c,d=a*a,i,j,k;
		string str;
		printf("1 99998\n");
		fflush(stdout);
		scanf("%lld",&l);
		if(l<0)
		{
			break;
		}
		c=d-l;
		set<long long> factors=factors_prime(c);
		vector<long long> v1,v2;
		for(auto it=factors.begin();it!=factors.end();it++)
		{
			v1.push_back(*it);
		}
		for(i=0;i<v1.size();i++)
		{
			if(d%v1[i]==l)
			{
				v2.push_back(v1[i]);
			}
		}
		int long long temp=v2.size();
		if(v2.size()==1)
		{
			printf("2 %lld\n",v2[0]);
			fflush(stdout);
			cin>>str;
			if(str=="No")
			{
				break;
			}
		}
		v1.clear();
			for(i=0;i<v2.size();i++)
			{
				v1[i]=v2[i];
			}
			v1.resize(i);
		while(v2.size()>1)
		{
			b=v2[v2.size()-1];
			d=b*b;
			printf("1 %lld\n",b);
			fflush(stdout);
			scanf("%lld",&l);
			if(l<0)
			{
				break;
			}
			c=d-l;
			set<long long> factor_new=factors_prime(c);
			vector<long long> v3,final,save,v4;
			for(auto it=v2.begin();it!=v2.end();it++)
			{
				save.push_back(*it);
			}
			v2.clear();
			v1.clear();
			for(auto it=factor_new.begin();it!=factor_new.end();it++)
			{
				v1.push_back(*it);
			}
			for(i=0;i<v1.size();i++)
			{
				if(d%v1[i]==l)
				{
					v4.push_back(v1[i]);
				}
			}
			v2=print_Intersection(save,v4);
			if(v2.size()==1)
			{
			printf("2 %lld\n",v2[0]);
			fflush(stdout);
			cin>>str;
			if(str=="No")
			{
				break;
			}
			}
			v1.clear();
			for(i=0;i<v2.size();i++)
			{
				v1[i]=v2[i];
			//cout<<afterCheck[i]<<" ";
			}
			//v1.resize(i);
			
		}
	}
}

