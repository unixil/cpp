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
//generate sorted compare file
vector<float>* vsort(vector<float> a)
{
  std::sort(a.begin(),a.end());
  return &a;
}
//find the middle file to split the vector
vector<float>::iterator vfindprev(vector<float>::iterator vstart,vector<float>::iterator vend,float desireValue)
{
  midpoint=vstart+(vend-vstart)/2;
  if (*midpoint<(desireValue+tvalue) and *(midpoint+1)>(desireValue+tvalue))
	{
	    return midpoint; 
	}
  else if(*(midpoint+1)<(desireValue+tvalue))
    {vfindprev(midpoint+,vend);}
  else if(*midpoint>(desireValue+tvalue))
    {vfindprev(vstart,midpoint);}
}
vector<float>::iterator vfindpost(vector<float>::iterator vstart,vector<float>::iterator vend,float desireValue)
{
  midpoint=vstart+(vend-vstart)/2;
  if (*midpoint>(desireValue-tvalue) and *(midpoint-1)<(desireValue-tvalue))
	{
	    return midpoint; 
	}
  else if(*(midpoint)<(desireValue-tvalue))
    {vfindpost(midpoint+,vend);}
  else if(*(midpoint-1)>(desireValue-tvalue))
    {vfindpost(vstart,midpoint);}
}

int vmatch(vector<float>::iterator rstart1,vector<float>::iterator rend1,vector<float>::iterator mstart1,vector<float>::iterator mend1 )
{
  //set tolorence limit
  float t=0.4;
  //iterate until one of the vector has only one element or the max-min is less than t
  if(rend1-rstart1==1 or mend1-mstart1==1 or *mend1-*mstart1<=t or *rend1-*rstart1<=t){
    cout<<"split finished"<<endl;
    return 0;
  }
  //check if the element are single element in the sub vector, 
  //if yes run the for loop to computer the nearest elementb in the other vector
  //if no; split the vector
  //---- find the middle element of one vector and split each of the two vector into 2 vector


  //assume v1.length()<v2.length(), we try to split v2 by v1 value;
  cout << rend1-rstart1 << endl;
  //  cout <<(start1+(end1-start1)/2) <<endl;
  vector<float>::iterator splitelem=rstart1+(rend1-rstart1)/2;
  cout << splitelem << endl;

  //find the split element
  //vfind;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  prevpoint=vfindprev(rstart1,rend1,*splitelem);
  cout<<prevpoint<<endl;
  postpoint=vfindpost(rstart1,rend1,*splitelem);
  cout<<postpoint<<endl;
  //iterate
  vmatch(rstart1,prevpoint,mstart1,splitelem);
  vmatch(prevpoint+1,rend1,splitelem+1,mend1);
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
  vsort(vtest1);
  lentest1=vtest1.size();
  //if data file is toobig you should write it to file
  for(i=0,i<lentest1;++i)cout<<vtest1[i]<<endl;
  vsort(vtest2);
  lentest1=vtest2.size();
  //if data file is toobig you should write it to file
  for(i=0,i<lentest2;++i)cout<<vtest2[i]<<endl;
  vsplit(vtest.begin(),vtest.end());
  vmatch(vtest.begin(),vtest.end(),vtest2.begin(),vtest2.end());
  return 0;
}
