# include <iostream>
# include <fstream>
# include <stdlib.h>
using namespace std;

template <class t>
class Heap{
     t a [1000];
public:

    int size, heapSize, temp,count;
    void input();
    void display();
    void MAX_HEAPIFY(int a[], int i);
    void Build_MH(int a[]);
    void HeapSort(int a[]);
    int left(int i);
    int right(int i);
};
template <class t>
void Heap<t>::input(){
    int i;
    count=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<endl;
    cout<<"Elements of Array Before Sorting :"<<endl;
    for(i=1; i<=size; i++){
        a[i]=(rand()%1000+1);
        cout<<a[i]<<"\t";
    }
    heapSize=size;
    HeapSort(a);
}
template <class t>
void Heap<t>::display(){
      for(int i=1; i<=size; i++){
        cout<<a[i]<<"\t";
      }
      cout<<endl;
}
template <class t>
int Heap<t>::left(int i){
    return (i*2);
}
template <class t>
int Heap<t>::right(int i){
    return (i*2+1);
}
template <class t>
void Heap<t>::MAX_HEAPIFY(int a[], int i){

    int l,r,largest;
    l=left(i);
    r=right(i);
    if(l<=heapSize && a[l]>a[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    count++;
     if(r<=heapSize && a[r]>a[largest]){
        largest=r;
    }
    count++;
    if(largest!=i){
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        MAX_HEAPIFY(a,largest);
    }
}
template <class t>
void Heap<t>::Build_MH(int a[]){
    for(int i=size/2; i>=1; i--){
        MAX_HEAPIFY(a,i);
    }
}
template<class t>
void Heap<t>::HeapSort(int a[]){
    Build_MH(a);
    for(int i=size; i>=2; i--){
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapSize=heapSize-1;
        MAX_HEAPIFY(a,1);
    }
}
int main(){

    cout<<endl;
    ofstream f("HeapSort.csv");
    int c;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        Heap<int> h;
        h.input();
        cout<<endl;
        cout<<"AFTER SORTING : "<<endl;
        h.display();
        if(f){

            f<<h.size<<","<<h.count;
            f<<endl;
        }
        cout<<endl;
        cout<<"No of Comparisions :"<<h.count<<endl;
        cout<<"Do you want to continue ? (y/n) : ";
        cin>>ch;
        cout<<endl;
    }
    f.close();
    return 0;
}
