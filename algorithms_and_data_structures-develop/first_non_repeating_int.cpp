#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
int nonRepeating(int *arr, int size){
    std::map<int, int> m;
    std::map<int, int>::iterator it;
    for(int i = 1; i < size; ++i) {
        it = m.find(arr[i]);
        if( it != m.end()){
            m[arr[i]] = ++(it->second);
        }
        else{
            m[arr[i]] = 1;
        }
    }



    for(int i = 1; i < size; ++i){
        it = m.find(arr[i]);
        if( it != m.end()){
            if(it->second == 1)
            return arr[i];
        }
    }
    return 0;


}



int main(){
    int size;
    int *arr;
    std::cout<<"Enter size: ";
    std::cin>>size;
    arr = new int[size];
    std::cout<<"Enter contents of array: ";
    for(int i = 0; i < size; i++){
                   std::cin>>arr[i];
    }
    std::cout<<"First Non repeating integer in array:"<<nonRepeating(arr,size) << std::endl;
    delete[] arr;
    return 1;
    
}