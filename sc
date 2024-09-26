
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comp(vector<int> a,vector<int> b)
{
    return a[0]>=b[0];
}



int main()
{
    int n;
    int temp;
    vector<int> R,C;
    vector<vector<int>> SC;
    cin>>n;
    vector<vector<int>> ans(n,vector<int>(n,0));
    //vector<int> heap;
    
    
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        R.push_back(temp);
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        C.push_back(temp);
        SC.push_back({temp,i});
    }
    
    
    
    
    for(int i=0;i<n;i++)
    {
        int col=0;
        int colmax=R[i];
        sort(SC.begin(),SC.end(),comp);
        while(col<n && colmax>0)
        {
           int j = SC[col][1];
           if(C[j]!=0)
           {
               SC[col][0]--;
               colmax--;
               C[j]--;
               col++;
               ans[i][j]=1;
               
           }
           else
           {
               col++;
           }
            
        }
    }
    
    
    
    
    cout<<"XXXXXXXXXx"<<endl;
    
   
    
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
    }
    


    return 0;
}