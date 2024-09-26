#include<fstream> 
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include <stack>
#include <algorithm>



using namespace std; 

bool comp(vector<int> a,vector<int> b)
{
    return a[0]>=b[0];
}
 
int main() 
{

	ifstream fileIn("input.txt");
	cin.rdbuf(fileIn.rdbuf());
	ofstream fileOut("output.txt");
    cout.rdbuf(fileOut.rdbuf());

	
	int n;
    int temp;
    vector<int> R,C;
    vector<vector<int>> SC;
	vector<vector<int>> ans;
	int ci=0;
	
	

	
	cin>>n;
	for(int i=0;i<n;i++)
				{
					vector<int> dummy;
					for(int j=0;j<n;j++)
						{
							dummy.push_back(0);
						}
						ans.push_back(dummy);
				}
	

	string line1,line2;
	cin>>line1;
	char *chr1 = line1.data();
	char *token = strtok(chr1, ",");

	while (token != NULL)
		{
					//cout<<n;
					
			R.push_back(stoi(token));
			token = strtok(NULL, ",");
					
					
					
				}

	cin>>line2;
	char *chr2 = line2.data();
	token = strtok(chr2, ",");
	while(token != NULL)		
		{
			SC.push_back({stoi(token),ci});
			ci++;
			C.push_back(stoi(token));
			token = strtok(NULL, ",");
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
	    
  
    
    for(int i=0;i<n;i++)
	{
		if(C[i]!=0)
		{
			cout<<0;
			
			return 1;
		}
	}
    

	for(int i=0;i<n;i++)
    {
		int rsum=0;
        for(int j=0;j<n;j++)
			{
				rsum+=ans[i][j];
			}
		if(rsum!=R[i])
		{
			cout<<0;
			
			return 1;
		}
    }

	
			cout<<1;
	

	
    for(int i=0;i<n;i++)
    {
		cout<<endl;
        for(int j=0;j<n-1;j++)
			{
				cout<<ans[i][j]<<",";
				
			}
			cout<<ans[i][n-1];
			
    }

	


	


	

    return 0;



}

