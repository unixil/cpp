#include <iostream>
#include <vector>
using namespace std;
class matrixtest
{
public:
  matrixtest(int dim1);
  matrixtest(int dim1, int dim2);
  matrixtest();

  int shuchu();
private:
vector<double> m1;
vector<vector<double> > m2;
};

matrixtest::matrixtest(int dim1)
{
cout << dim1 <<endl;
m1.resize(dim1);
for (int i = 0; i<dim1;++i)
  m1[i]=i;
for (int i = 0; i<dim1;++i)
  cout <<m1[i]<<endl;
}

matrixtest::matrixtest(int dim1,int dim2)
{
cout << dim1 << dim2 <<endl;
}

matrixtest::matrixtest()
{
cout<< "empty"<<endl;
}

int matrixtest::shuchu()
{
cout<< "shuchu" <<endl;
}
