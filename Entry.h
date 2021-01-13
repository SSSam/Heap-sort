#include <string>
using namespace std;

class Entry{
  private:
    int key;
    string data;
  public:
    Entry();
    Entry(int k, string val){
      key=k;
      data=val;
    }
    ~Entry(){}
    void random();
    int getkey(){return key;}
    string getdata(){return data;}
    string toString();
    void printentry(Entry* entries);
};

void Entry::random(){
  key=rand()%100;
  data='a'+rand()%26;
  data+='a'+rand()%26;
  data+='a'+rand()%26;
}

Entry::Entry(){
  random();
}

string Entry::toString(){
  return "("+to_string(getkey())+", "+getdata()+")";
}