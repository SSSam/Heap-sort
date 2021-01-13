#include <iostream>
#include <string>
#include "Heap.h"

Heap heapsort1(Entry* entries,int n){
  Heap sortedheap;
  for(int i=0;i<n;i++){
    sortedheap.insert(entries[i]);
  }
  return sortedheap;
}

Heap heapsort2(Entry* entries,int n){
  Heap sortedheap;
  sortedheap.make(entries, n);
  return sortedheap;
}

void insertHeapsort1(){
  Entry test1[15];
  Heap heap1;
  cout<<"Generating Entries:"<<endl;
  for(int i=0;i<15;i++){
    test1[i].random();
    if(i%5==0&&i>1){cout<<endl;}
    cout<<test1[i].toString();
  }
  cout<<"\nThe Entries has been generated."<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"The sorted key of the Max Heap: "<<endl;
  heap1=heapsort1(test1, 15);
  heap1.printheap();
  cout<<"current capacity: "<<heap1.getcapa()<<endl;
  cout<<"Number of element: "<<heap1.size()<<endl;
  cout<<"Sorting is done with insert()."<<endl;
  cout<<"insertHeapsort1 complete"<< endl<<endl;
}

void makeHeapsort2(){
  Entry test2[15];
  Heap heap2;
  cout<<"Generating Entries:"<<endl;
  for(int i=0;i<15;i++){
    test2[i].random();
    if(i%5==0&&i>1){cout<<endl;}
    cout<<test2[i].toString();
  }
  cout<<"\nThe Entries has been generated."<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"The sorted key of the Max Heap: "<<endl;
  heap2=heapsort2(test2, 15);
  heap2.printheap();
  cout<<"current capacity: "<<heap2.getcapa()<<endl;
  cout<<"Number of element: "<<heap2.size()<<endl;
  cout<<"Sorting is done with make()."<<endl;
  cout<<"makeHeapsort2 complete"<< endl<<endl;
}

void insertHeapsort3(){
  Entry test3[31];
  Heap heap3;
  cout<<"Generating Entries:"<<endl;
  for(int i=0;i<31;i++){
    test3[i].random();
    if(i%5==0&& i>1){cout<<endl;}
    cout<<test3[i].toString();
  }
  cout<<"\nThe Entries has been generated."<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"The sorted key of the Max-Heap: "<<endl;
  heap3=heapsort1(test3, 31);
  heap3.printheap();
  cout<<"current copacity: "<<heap3.getcapa()<<endl;
  cout<<"Number of element: "<<heap3.size()<<endl;
  cout<<"Sorting is done with insert(). "<<endl;
  cout<<"insertHeapsort3 complete"<< endl<<endl;
}

void makeHeapsort4(){
  Entry test4[31];
  Heap heap4;
  cout<<"Generating Entries:"<<endl;
  for(int i=0;i<31;i++){
    test4[i].random();
    if(i%5==0&& i>1){cout<<endl;}
    cout<<test4[i].toString();
  }
  cout<<"\nThe Entries has been generated."<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"The sorted key of the Max-Heap: "<<endl;
  heap4=heapsort2(test4, 31);
  heap4.printheap();
  cout<<"current copacity: "<<heap4.getcapa()<<endl;
  cout<<"Number of element: "<<heap4.size()<<endl;
  cout<<"Sorting is done with make(). "<<endl;
  cout<<"makeHeapsort4 complete"<< endl<<endl;
}

void RemoveMax5(){
  Entry test5[15];
  Heap heap5;
  cout<<"Generating Entries:"<<endl;
  for(int i=0;i<15;i++){
    test5[i].random();
    if(i%5==0&& i>1){cout<<endl;}
    cout<<test5[i].toString();
  }
  cout<<"\nThe Entries has been generated."<<endl;
  cout<<"----------------------------------"<<endl;
  cout<<"The sorted key of the Max Heap: "<<endl;
  heap5=heapsort1(test5, 15);
  heap5.printheap();
  cout<<"Remove the top 3 Max key:"<<endl;
  heap5.removeMax();
  heap5.removeMax();
  heap5.removeMax();
  heap5.printheap();
  cout<<"RemoveMax() passed."<<endl<<endl;
}

void testHeapUnderflow6(){
  try{
    Heap test6;
    Entry e1;
    Entry e2;
    test6.insert(e1);
    test6.insert(e2);
    test6.removeMax();
    test6.removeMax();
    test6.removeMax();
    cout<<"Did Not cathch EmptyHeapException"<<endl;
  }
  catch(EmptyHeapException){
    cout<<"Caught EmptyHeapException"<<endl;}
  cout<<"testHeapUnderflow test passed"<<endl<<endl;
}

int main() {
  insertHeapsort1();
  makeHeapsort2();
  insertHeapsort3();
  makeHeapsort4();
  RemoveMax5();
  testHeapUnderflow6();
  cout<<"All Tests Passed! Thank you! :)"<<endl;
}