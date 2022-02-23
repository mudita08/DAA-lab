#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
template<class t>
class msort 
{
    public:
    t ar[1000];
    int n;
    int count;
    void input();
    void display();
    t mergesort(t ar[], int p , int r);
    void merge(t ar[], int p, int q, int r);
};

template<class t>
void msort<t> :: input()
{
    int i;
    cout<<"\nEnter number of elements: ";
    cin>>n;
    for (i = 1; i<=n ; ++i)
        ar[i] = rand()%100;
}
template<class t>
void msort<t> :: display()
{
    for(int i=1; i<=n; i++)
        cout<<ar[i]<<" ";
}
template<class t>
t msort<t> :: mergesort(t ar[], int p, int r)
{
    if (p<r)
    {
        int q = (p+r-1)/2;
        mergesort(ar,p,q);
        mergesort(ar,q+1,r);
        merge(ar,p,q,r);
    }
    return count;
}


template<class t>
void msort<t> :: merge(t ar[], int p, int q, int r)
{
    int i, j;
    int n1 = q-p+1;
    int n2 = r-q;
    t L[500] , R[500];
  for(i=1;i<=n1;i++)
    L[i]=ar[p+i-1];
  for(j=1; j<=n2;j++)
    R[j]=ar[q+j];
    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;
    i=j=1;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            ar[k]=L[i];
            i++;
        }
        else
        {
            ar[k]=R[j];
            j++;
        }
        count++;
    }
}

int main()
{
    ofstream f("mergeSort.csv");
    int c;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        msort<int> m;
        m.input();
        cout<<"\nThe elements of array: ";
        m.display();
        m.count = 0;
        c = m.mergesort(m.ar, 1, m.n);
        cout<<"\n After sorting: ";
        m.display();
        if(f)
        {
            f<<m.n<<","<<c;
            f<<endl;
        }
        cout<<"\n Number of comaparisons: "<<c;
        cout<<"\nDo you wish to continue(y/n): ";
        cin>>ch;
    }
    f.close();
    return 0;
}