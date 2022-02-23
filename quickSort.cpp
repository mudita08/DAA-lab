#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;
template <class t>
class QuickSorting
{
 t A[1000];
public:
 int n,count;   
 void input();
 void Randomized_quick(t A[], int p, int r);
 int Randomized_partition(t A[], int p, int r, int n);
 int Partition(t A[], int p, int r);
 void display();
};
template <class t>
void QuickSorting<t>::input()
{
 count=0;
 cout<<"ENTER THE NUMBER OF ELEMENTS:"<<endl;
 cin>>n;
 for(int i=1;i<=n;i++)
 A[i]=(rand()%1000);
 Randomized_quick(A,1,n);
}
template <class t>
int QuickSorting<t>::Partition(t A[], int p, int r)
{
 int x,i,j,temp,temp2;
 x=A[r];
 i=p-1;
 for(j=p;j<r;j++)
 {
 if(A[j]<=x)
 {
 i++;
 temp=A[i];
 A[i]=A[j];
 A[j]=temp;
 count++;
 }
 }
 return (i+1);
}
template <class t>
void QuickSorting<t>::Randomized_quick(t A[], int p, int r)
{
 int q;
 if(p<r)
 {
 q=Randomized_partition(A,p,r,n);
 Randomized_quick(A,p,q-1);
 Randomized_quick(A,q+1,r);
 }
}
template <class t>
int QuickSorting<t>::Randomized_partition(t A[], int p, int r, int n)
{
 int i, temp;
 i=p+rand()%(r-p+1);
 temp=A[r];
 A[r]=A[i];
 return Partition(A,p,r);
}
template <class t>
void QuickSorting<t>::display()
{
 for(int i=1;i<=n;i++)
 cout<<A[i]<<"\t";
 cout<<endl;
 cout<<"COMPARISONS: "<<count<<endl;
}
int main()
{
 char ch='y';
 QuickSorting <int> obj;
 ofstream fout;
 fout.open("Quick_Sort.csv");
 fout<<"n"<<","<<"count";
 fout<<endl;
 while(ch=='y'||ch=='Y')
 {
 obj.input();
 obj.display();
 fout<<obj.n<<","<<obj.count;
 fout<<endl;
 cout<<"DO YOU WANT TO CONTINUE?"<<endl;
 cin>>ch;
 }
 fout.close();
 return 0;
}