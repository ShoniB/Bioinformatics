// Shondell Baijoo
// Spring 17 Bioinformatics
// Partial Digest: Brute force with Pruning 

#include <iostream> 
#include<vector>
using namespace std; 

// This function finds a solution as it iterates through the solution set (node). 
// If a number does not produce a solution, it will skip that number by decrementing to the previous level, and incrementing back from there.
// If a solution is found, it ends the function and displays the first solution found.

void next(int a[], vector<int> n, int d, int sizeN, int indexK[]);
bool delta(int y, int const X[], int end, vector<int>& l, int max); 

int main()
{
  int a[4] = {0,0,0,0}; // 0 represents a dash
  int k = 3;
  vector<int> n_edit; 
  vector<int> n= {2,2,3,3,4,5,6,7,8,10};
  int indexK[3] = {0,0,0};  // indexing for each level
  int sizeN = 10; 
  int max = n[9]; // max
  n_edit = n;
  vector<int> previous[3]; previous[0] = n; //back up old n
  while(a[0] != -1) // while not back at root
  {
 	next(a, n, k, n.size(), indexK); // increment
	int index = a[0]; // locate number most recently added
	previous[index-1].clear(); 
	previous[index-1] = n; // save that level's n
	vector<int>::iterator it = n.begin();	
	while(it!=n.end() && a[index] != *(it)) it++; 
	if(it!=n.end()){  n.erase(it); }
	if(!delta(a[index], a, index, n, max))
	{ 
	    n.clear(); 
	    n = previous[index-2]; // restore n	
	   // Skip a level 
	    if( a[0] < k ) 
	    {
	      	indexK[index-1]++; // increment pointer to n
	        a[0]--; //decrement level
	        a[index] = 0; // add dash
	    }  
	}//end if !delta
	else { // solution found
	   if(a[0] == k) // Solution found
	   {
		a[0] = -1;  // end loop
		for(int i=1; i<k+1; i++) cout << a[i] << " " ; 
		cout <<max; 
		cout <<endl;
	   }	
	}//end else
  }//end while
  return 0; 
}

// check a full array for a solution
bool delta(int y, int const X[], int end, vector<int>& l, int max)
{
   int newX[end+1]; // create a new solution array to store max as well as previous values
   for(int i=0; i<end; i++)  // fill new solution array
	newX[i] = X[i];
   newX[end] = max;  
   for(int i=1; i<end+1; i++)
   {
	int dist=0;
	if(newX[i]<y)
	    dist = y - newX[i]; 
        else dist = newX[i]-y; 
	if(dist!=0)  // if not a duplicate value
	{ 
	    vector<int>::iterator it = l.begin();
  	    while(it!=l.end() && dist != *(it)) // iterate through vector until match found
  	    {
		it++; 	
	    } //end while
	    if(it == l.end()) return false; // if no match return false
	    else if(dist == *(it)) // if a match is found remove from vector
       	    {
	   	  l.erase(it);    
	    }
	} // end if
   }
   return true; 
}

void next(int a[], vector<int> n, int k, int sizeN, int indexK[])
{
     if(a[0] == k ) // no dashes
     {
	int i = k; // iterate
	if(indexK[i-1] < sizeN-1) // a was not completely maxed at beginning of function 
	{ 
	     indexK[i-1]++;
             a[i] = n[indexK[i-1]]; 
	}
	else { // decrement level
	   a[i] = 0;  
	   a[0]-=2;
	   indexK[i-2]++;
	   indexK[i-1] = indexK[i-2]; 
	} 
     }
     else // dashes 
     {
	int i = a[0]; // get the number of dashes 
	if( sizeN - indexK[i]+1 < k-i+1) // too large to fill in array, decrement level
	{
	    indexK[i-1]++;
	    a[0]--; //decrement level
	    a[i+1] = 0; // add dash
	}
	else{ 
		a[i+1] = n[indexK[i]];
		indexK[i+1] = indexK[i]+1; // won't overcount i < k		
		a[0]++; // go up a level
	}
     }
} 
