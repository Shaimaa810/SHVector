#ifndef SHVECTOR_SHVECTOR_H
#define SHVECTOR_SHVECTOR_H
#include <bits/stdc++.h>
using namespace std;
template<typename T>

class SHVector {
private:
    T* data;
    int Size;
    int Capacity;
    T* itr;

public:
    SHVector(int Capacity){
        this->Capacity = Capacity;
        Size = 0;
        data = new T[Capacity];
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SHVector() {
        Size = 0;
        Capacity = 0;
        data = new T[Capacity];
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SHVector(T* arr, int size){
        data = new T[size];
        this->Size = size;
        Capacity = size;
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // copy constructor
    SHVector(SHVector& vec){
        Size = vec.size();
        Capacity = vec.Capacity;
        data = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            data[i] = vec.data[i];
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Destructor
    ~SHVector(){
        delete []data;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // copy assignment
    SHVector& operator=(SHVector& vec){
        delete []data;
        Size = vec.size();
        Capacity = vec.Capacity;
        data = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            data[i] = vec.data[i];
        }
        return *this;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // move assignment
    SHVector& operator=(SHVector&& vec){
        delete []data;
        Size = vec.size();
        Capacity = vec.Capacity;
        data = vec.data;
        vec.data = nullptr;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // push_back function
    int push_back(T element){
        if(Capacity == Size){
            Capacity += 10;
            T *temp = new T[Size];
            for (int i = 0; i < Size; ++i) {
                temp[i] = data[i];
            }
            delete []data;
            data = new T[Capacity];
            for (int i = 0; i < Size; ++i) {
                data[i] = temp[i];
            }
            delete []temp;
        }
        data[Size] = element;
        Size++;
        return Size;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // pop_back function
    T pop_back(){
        Size--;
        T *temp = new T[Size];
        T last_element = data[Size];
        for (int i = 0; i < Size; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            data[i] = temp[i];
        }
        delete []temp;
        return last_element;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void clear(){
        delete []data;
        Size = 0;
        data = new T[Capacity];
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool empty(){
        return (Size == 0);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator==(SHVector& vec){
        if(Size != vec.size())
            return false;
        else{
            for (int i = 0; i < Size; ++i) {
                if(data[i] != vec.data[i])return false;
            }
        }
        return true;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator>(SHVector& vec){
        for (int i = 0; i < Size; ++i) {
            if(data[i] < vec.data[i])return false;
        }
        return true;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator<(SHVector& vec){
        for (int i = 0; i < Size; ++i) {
            if(data[i] > vec.data[i])return false;
        }
        return true;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int size(){
        return Size;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    template<class t>
    friend ostream& operator<<(ostream& out, SHVector<t> vec);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int capacity(){
        return Capacity;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // iterators
    typedef T* iterator;
    iterator begin(){
        itr = &data[0];
        return itr;
    }
    iterator end(){
        itr = &data[Size];
        return itr;
    }
    T operator*(){
        for (int i = 0; i < Size; ++i) {
            if(itr == &data[i]){
                return data[i];
            }
        }
    }
    // prefix increment
    iterator  operator++(){
        for (int i = 0; i < Size; ++i) {
            if(itr == &data[i]){
                ++itr;
                return itr;
            }
        }
    }
    // postfix increment
    iterator operator++(int){
        for (int i = 0; i < Size; ++i) {
            if(itr == &data[i]){
                itr++;
                return itr;
            }
        }
    }
    iterator operator+(int n){
        for (int i = 0; i < Size; ++i) {
            if(itr == &data[i]){
                i += n;
                itr = &data[i];
                return itr;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // delete only 1 element
    void erase(iterator it){
        try{
            if(it >= begin() && it < end()){
                T* temp = new T[Size - 1];
                for (int i = 0, j = 0; i < Size; ++i) {
                    if(it != &data[i]){
                        temp[j] = data[i];
                        j++;
                    }
                }
                delete []data;
                data = new T[Capacity];
                Size--;
                for (int i = 0; i < Size; ++i) {
                    data[i] = temp[i];
                }
                delete []temp;
            }
            else{
                throw invalid();
            }
        }
        catch (invalid e){
            cout << "invalid iterator\n";
        }
    }
    class invalid{};
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // delete range of elements
    void erase(iterator it1, iterator it2){
        try{
            if(it1 <= it2 && it1 >= begin() && it1 <= end() && it2 >= begin() && it2 <= end()){
                int new_size = Size - ((it2 - begin()) - (it1 - begin()));
                //cout << new_size << '\n';
                T* temp = new T[new_size];
                for (int i = 0, j = 0; i < Size; ++i) {
                    if(&data[i] < it1 || &data[i] >= it2){
                        temp[j] = data[i];
                        j++;
                    }
                }
                delete []data;
                data = new T[Capacity];
                Size = new_size;
                for (int i = 0; i < Size; ++i) {
                    data[i] = temp[i];
                }
                delete []temp;
            }
            else{
                throw invalid();
            }
        }
        catch (invalid e){
            cout << "invalid iterators\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void insert(iterator it, T element){
        try{
            if(it >= begin() && it < end()){
                int id = it - begin();
                if(Size == Capacity)
                    Capacity += 10;
                T* temp = new T[Size];
                for (int i = 0; i < Size; ++i) {
                    temp[i] = data[i];
                }
                delete []data;
                data = new T[Capacity];
                for (int i = 0, j = 0; i < Size; ++i, ++j) {
                    if(i == id){
                        data[j] = element;
                        j++;
                        data[j] = temp[i];
                    }
                    else{
                        data[j] = temp[i];
                    }
                }
                Size++;
            }
            else{
                throw invalid();
            }
        }
        catch (invalid e){
            cout << "invalid iterator\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    T& operator[](int index){
        return data[index];
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void resize(int new_size, T n = 0){
        if(new_size < Size){
            T* temp = new T[new_size];
            for (int i = 0; i < new_size; ++i) {
                temp[i] = data[i];
            }
            delete []data;
            data = new T[Capacity];
            for (int i = 0; i < new_size; ++i) {
                data[i] = temp[i];
            }
            Size = new_size;
            delete []temp;
        }
        else{
            T* temp = new T[Size];
            for (int i = 0; i < Size; ++i) {
                temp[i] = data[i];
            }
            if(Capacity < new_size)
                Capacity += new_size;
            delete []data;
            data= new T[Capacity];
            for (int i = 0; i < new_size; ++i) {
                if(i < Size)
                    data[i] = temp[i];
                else
                    data[i] = n;
            }
            Size = new_size;
            delete []temp;
        }
    }

};
#endif //SHVECTOR_SHVECTOR_H
