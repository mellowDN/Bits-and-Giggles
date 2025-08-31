//the following code consists of a simple implementation of a vector class in C++
//it supports basic operations like push_back, pop_back, push_front, pop_front, size, capacity and operator overloading for indexing and output stream

#include <bits/stdc++.h>
using namespace std;
template <class T>
class vec{
    
    T* ptr;
    int sz;
    int cap;
    
    
    void resize(){
        cap=cap*2;
        T* newPtr= new T[cap];
        for(int i=0; i<sz; i++){
            newPtr[i]=ptr[i];
        }
        delete[] ptr;
        ptr=newPtr;
    }
    public:
    vec(){
        ptr=new T[cap];
        sz=0;
        cap=1;
    }
    ~vec(){
        delete[] ptr;
    }
    
    void push_back(T v){
        if(sz==cap) resize();
        ptr[sz]=v;
        sz++;
    }
    void pop_back(){
        if(sz>0) sz--;
    }
    void push_front(T v){
        if(sz==cap) cap=cap*2;
        T* arr= new T[cap];
        arr[0]=v;
        for(int i=0; i<sz; i++){
            arr[i+1]=ptr[i];
        }
        sz++;
        delete[] ptr;
        ptr=arr;
    }
    void pop_front(){
        if(sz>0){
            for(int i=1; i<sz; i++){
                ptr[i-1]=ptr[i];
            }
        }
        else{
            cout<<"out of bounds access"<<endl;
        }
        sz--;
    }
    int size(){
        return sz;
    }
    int capacity(){
        return capacity;
    }
    T& operator[](int idx){
        if(0>idx && idx>=sz){
            cout<<"index out of bounds"<<endl;
            return ptr[sz-1];
        }
        return ptr[idx];
    }
    template<typename U>
    friend ostream& operator<<(ostream& out, vec<U>& v);
};
template<typename U>
ostream& operator<<(ostream& out, vec<U>& v){
    for(int i=0; i<v.size(); i++){
        out<<v[i]<<" ";
    }
    cout<<endl;
    return out;
}
int main(){
    vec<int> v1;
    v1.push_back(5);
    v1.push_back(6);
    v1.push_front(4);
    v1.pop_front();
    v1.push_front(4);
    cout<<v1.size()<<endl;
    cout<<v1<<endl;
    
    return 0;
}