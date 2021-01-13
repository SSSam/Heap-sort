#include <string>
#include <math.h> 
#include "Entry.h"
using namespace std;

class EmptyHeapException {
  public:
  EmptyHeapException(const string& err)
    :errMsg(err){}
    string getErr(){return errMsg;}
  private:
  string errMsg;
};

class Heap{
  private:
    int numele;
    int capacity;
    Entry* arrayheap;
    int parent(int i){return (i-1)/2;}
  public:
    Heap();
    ~Heap(){if(empty()){delete[] arrayheap;}}
    int const getcapa(){return capacity;}
    int const size(){return numele;}
    bool const empty(){return numele==0;}
    void heapify(Entry* entries, int n, int i);
    Entry removeMax();
    void insert(Entry e);
    void make(Entry* entries, int n);
    void printheap();
};

Heap::Heap(){
  capacity=10;
  arrayheap= new Entry[10];
  numele=0;
}

Entry Heap::removeMax(){
  if(empty()){
    throw EmptyHeapException("Empty Heap");}
  else if (size()==1){
    numele--;
    return arrayheap[0];
  }
  else{
    Entry root= arrayheap[0];
    arrayheap[0]=arrayheap[numele-1];
    numele--;
    heapify(arrayheap,numele,0);
    return root;
  }
}

void Heap::insert(Entry e){
  if(size()==capacity){
    capacity=capacity*2;
    Entry* newarray=new Entry[capacity];
    for(int i=0;i<numele;i++){
      newarray[i]=arrayheap[i];
    }
    delete[] arrayheap;
    arrayheap=newarray;
    delete[] newarray;
  }
  int i=size();
  arrayheap[i]=e;
  numele++;
  while(i!=0&& arrayheap[parent(i)].getkey()<arrayheap[i].getkey()){
    swap(arrayheap[i],arrayheap[parent(i)]);
    i=parent(i);
  }
}

void Heap::heapify(Entry* entries, int n, int i){
  int left=1+2*i;
  int right=2+2*i;
  int max=i;
  if (left< n && arrayheap[left].getkey()> arrayheap[max].getkey()){
    max=left;
  }
  if (right< n && arrayheap[right].getkey()> arrayheap[max].getkey()){
    max=right;
  }
  if(max!=i){
    swap(arrayheap[i],arrayheap[max]);
    heapify(arrayheap, n, max);
  }
  
}

void Heap::make(Entry* entries, int n){
  numele=n;
  capacity=n;
  arrayheap=entries;
  int index=(n/2)-1;
  for(int i=index;i>=0;i--){
    heapify(arrayheap,n,i);
  }
}

void Heap::printheap(){
  int height = 0;
  int number_each_level = 1;
  for(int i=0;i<size();i++){
    if(i==number_each_level){
      height+= 1;
      number_each_level+= (1<<height);
      cout<<endl;
    }
    cout<<arrayheap[i].getkey()<<" ";
  }
  cout<<endl;
}
