//
// Created by dinak on 11/13/2021.
//

#ifndef UNTITLED_MYARRAY_H
#define UNTITLED_MYARRAY_H

#define INITIAL_CAPACITY 8

// I had a problem telling me that the functions have redefined so I deleted the Array.cpp file
template <class T>
class MyArray{
private:
    int size = 0;
    int capacity = INITIAL_CAPACITY;
    T* data = nullptr;

public:
    //Functon that take that change the size of the array by reallocating it
    //takes the new capacity as an argument
    void reSize(int newCap){
        //initialize new array with the new capacity
        T *newArr=new T[newCap];
        //adding the previous elements to is
        for (int i=0;i<size;i++){
            newArr[i]=data[i];
        }
        //deleting the old one and reallcate it
        delete[]data;
        capacity =newCap;
        data=newArr;
    }
    //constructor that only initialize the array
    MyArray(){
        data=new T[capacity];
        this->size=0;
    }
    //constructor that take an array
    MyArray(T* arr, int size){
        this->size=size;
        data=new T[size];
        //if the size is bigger than the capacity expand it
        if (size>=capacity)
            reSize(capacity*2);
        //adding each element of the array taken to ours
        for (int i=0;i<size;i++)
            data[i]=arr[i];
    }

    //get any member in the array
    T get(int index){
        //return the element as long as it's in the range else return -1
        if (index>=0&&index<size){
            return data[index];
        }
        else {
            return -1;
        }
    }

//add new element to the end of the array
    void push(T element){
//expanding the capacity it's equal size
        if (size==capacity)
        {
            reSize(capacity*2);
        }
//        else if (size==capacity/4)
//        {
//            reSize(capacity/2);
//        }
//adding the element and increment the size
        data[size]=element;
        size++;
    }

    T remove(int index){
        //removing the element as long as it's on the array's range
        //else return -1
        if (!(index < size)||index<0)
            return -1;
        else
        {T removed=data[index];
            //shifting elements around within it
            for (int i = index; i <size; i++){
                data[i] = data[i + 1];}
            //decrement the size
            size--;
            //check whether the capacity is too large for the array
            if (size==capacity/4){
                reSize(capacity/2);
            }
            return removed;}}




    T pop(){
//remove the last element of the array
        return  remove(size-1);}

    //inserting new element to the array
    void insert(int index, T element){
        //pushing the last element
        push(data[size-1]);
        //shift all the element after the element we want to insert
        for(int i=size-2;i>=index;i--){
            //adding the element we want to insert to its position
            data[i]=data[i-1];
        }
        data[index]=element;
    }


    //printing each element in the array
    void print(){
        for (int i=0;i< size;i++){
            std::cout<<data[i]<<std::endl;

        }
        std::cout<<"------------------------------------\n"<<std::endl;
    }



    //return the size of the array
    int get_size(){
        return size;
    }


    //return the capacity of the array
    int get_capacity(){
        return capacity;
    }

};

#endif //UNTITLED_MYARRAY_H
