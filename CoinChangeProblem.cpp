// Shondell Baijoo
// Bioinformatics Spring 2017 
// Coin change problem : Dynamic Programming 
// Problem: What is the minimum number of coins needed to create the value? 

#include <iostream> 
using namespace std; 

int dynamicOptimal(int g[], int n, int c[], int c_size);

int main() 
{

  int c_size =5; 
  int c[c_size] = {25,20,10,5,1};
  int n =40;
  cout << dynamicOptimal(n, c, c_size) << endl; 
  return 0;
}


int dynamicOptimal(int n, int c[], int c_size)
{
   int g[n+1]; 
   g[0] = 0; // set base case (value 0 = 0 coins)
   for(int i=1; i<n+1; i++) 
   {
        int min = 9999; // set min to high value
	int c_itr=0; 
	while(c[c_itr] > i && c_itr < c_size) // increment c_itr to coin value smaller than or equal to i
	{
	    c_itr++;
	}
	for(int j=c_itr; j<c_size; j++) // check through subsolutions
	{
	    if ( g[ i - c[j] ] < min ) // if the subsolution is less than the minimum
		min = g[ i - c[j] ];  // make this the new minimum
	}
	g[i] = 1 + min; // solution is smallest subsolution + 1
   }
   return g[n]; // return solution for n
}

// O (n * c_size)
