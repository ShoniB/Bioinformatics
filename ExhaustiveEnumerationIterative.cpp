// Shondell Baijoo
// BioInformatics: Spring 2017

#include <iostream>
using namespace std; 

void display(int a[], int s);  
void iterate(int arr[], int max_arr[], int size, int index); 

int main()
{
    int size = 3;  // test values
    int a1[size] = {2,3,4};
    int a[size] = {0,0,0}; 
    iterate(a, a1, size, size-1); 
    return 0; 
}

void iterate(int arr[], int max_arr[], int size, int index)
{
    if(arr[index]<max_arr[index]) 
    {
	arr[index]++;
	if(index<size-1)
	    index = size-1; 
	display(arr,size); 
	iterate(arr, max_arr, size, index);
    }
    else if (index>0){
	for(int i=index; i<size; i++)
	    arr[i] = 0;
	index--; 
	iterate(arr, max_arr, size, index); 	
    }
}

void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
	cout << arr[i] << " " ; 
    cout <<endl; 
}
