#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template <class t>
class isort
{
public:
    t arr[500];
    int n;
    void input();
    void display();
    int sort();
};
template <class t>
void isort<t>:: input()
{
    int i;
    cout<<"\n Enter the number of elements :";
    cin>>n;
    for(i=1; i<=n; i++)
        arr[i]=rand()%100;
}
template<class t>
void isort<t> :: display()
{
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
}
template<class t>
int isort<t>:: sort()
{
    int i,j,count=0;
    t key;
    for (i = 1; i <= n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; 
            j -= 1; 
            count++;
        }
        count++;
        arr[j + 1] = key;

    }
    cout<<"\n The array after sorting :";
    display();
    cout<<"\n The number of comparisons are:"<<count;
    return count;
}
int main()
{
   ofstream f("insertionSort.csv");
   int c;
   char ch='y';
  while(ch=='y'||ch=='y')
   {
       isort<int>i;
       i.input();
       cout<<"\n The element of an array are:";
       i.display();
       c = i.sort();
       if(f)
       {
           f<<i.n<<","<<c;
           f<<endl;
       }
        cout<<"\nDo you want to continue(y/n): ";
       cin>>ch;
   }
   f.close();
    return 0;
}