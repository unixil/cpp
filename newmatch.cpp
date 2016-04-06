#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int vsplit(vector<float>::iterator start,vector<float>::iterator end)
{
  if (start==end) 
    {
      cout<<"start is "<<*start<<endl;
      return *start;
    }
  int len=(end-start);
  cout<<len<<"1st"<<endl;
  vector<float>::iterator midAdd=start+len/2;
  vector<float>::iterator midAdd1=midAdd+1;
  cout<<(midAdd-start)<<" is 2nd"<<endl;
  cout<<(end-midAdd-1)<<" is 3rd"<<endl;
  vsplit(start,midAdd);
  vsplit(midAdd1,end);
}
int vmatch(vector<float>::iterator start1,vector<float>::iterator end1,vector<float>::iterator start2,vector<float>::iterator end2)
{
  float t=0.4;
  //assume v1.length()<v2.length(), we try to split v2 by v1 value;
}

int main()
{
  int n=100;
  vector<float> vtest(n);
  for(int i=0;i<n;++i)
    {
      vtest[i]=i+0.3;
    }
  n=500;
  vector<float> vtest2(n);
  for(int i=0;i<n;++i)
    {
      vtest2[i]=i;
    }

  vsplit(vtest.begin(),vtest.end());
  vmatch(vtest.begin(),vtest.end(),vtest2.begin(),vtest2.end())
  return 0;
}
