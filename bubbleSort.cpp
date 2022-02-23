# include <iostream>
# include <fstream>
# include <stdlib.h>
using namespace std;

template <class t>
class Bsort{
public:
    t a[500];
    t n;
    void input();
    void display();
    int sort();
};
template <class t>
void Bsort<t>::input(){
    int i;
    cout<<"Enter the no of elements in array : ";
    cin>>n;
    for(i=1; i<=n; i++){
        a[i]=rand()%100;
    }
}
template <class t>
void Bsort<t>::display(){
      for(int i=1; i<=n; i++){
        cout<<a[i]<<" ";
      }
      cout<<endl;
}
template<class T>
int Bsort<T>:: sort()
{
    T temp;
    int i,j,count=0;
    char switched='T';
    for(i=0; i<n-1 && switched=='T'; i++)
    {
        switched='F';
        for(j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                switched='T';
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            count++;
        }
        
    }
    cout<<"The array after sorting is : "<<endl;
    display();
    cout<<"The no of comparisions are : "<<count<<endl;
    return count;
}
int main(){

    ofstream f("BubbleSort.csv");
    int c;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        Bsort<int> b;
        b.input();
        cout<<"The elements of the array are : "<<endl;
        b.display();
        c=b.sort();
        if(f){

           f<<b.n<<","<<c;
           f<<endl;
        }
        cout<<"Do you want to continue ? (y/n) : ";
        cin>>ch;
        cout<<endl;
    }
    return 0;
}

