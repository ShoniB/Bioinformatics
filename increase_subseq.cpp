// Shondell Baijoo
// Spring 2017

#include<iostream>

using namespace std;

int main()
{
  string seq = "821657439";
  string seq2 = "123456789"; 
  int n = seq.length()+1;  
  int score[n][n]; // seq * seq2
  char trace[n][n]; // U - up, L - left, D- diagnol
  int match = 3; 
  int mismatch = -2;
  int gap = -2;
  score[0][0] = 0; 

  for(int i=1; i<n; i++) // columns - initialize initial gaps
  {
	score[0][i] = score[0][i-1] + gap;
	trace[0][i] = 'L';	
   } 
  for(int j=1; j<n; j++) { // initial gaps 
	score[j][0] = score[j-1][0] + gap;
  	trace[j][0] = 'U'; 
  }  
  for(int j=1; j<n; j++) // rows  
  {
  	for(int i=1; i<n; i++) // columns
	{
	  int temp = score[j-1][i-1]; // A(j-1, i-1) 
	  char c = 'D'; 
	  if(seq[i-1] == seq2[j-1]) 
		temp+=match; 
	  else temp+=mismatch;

	  if(temp < (score[j-1][i] + gap)) // A(j-1, i) + gap
	  {
		temp = score[j-1][i] + gap; 
		c = 'U'; 
	   }
	  if(temp < (score[j][i-1] + gap)) // A(j, i-1) + gap
	  {
		temp = score[j][i-1]+gap;
		c = 'L'; 
	  } 
	  score[j][i] = temp;  // make score minimal
	  trace[j][i] = c; 
	}
  }
  string s = ""; // alignment 
  string s2 = ""; 
  int row =n-1, col =n-1; 
  // Construct the aligned sequences with traceback
  while(row!=0 && col!=0)
  {
	if(trace[row][col] == 'D'){
	    s = seq[col-1] + s; 
	    s2 = seq2[row-1] +s2;
	    row--; col--; 
	}
	else if(trace[row][col] == 'U'){
	   s2 = seq2[row-1] + s2; 
	   s = "_" + s; 
	   row--; 	
	}
	else {
	  s = seq[col-1] +s;
	  s2 = "_" + s2; 
	  col--;	
	}
  } 
  string subseq = ""; 
  for(int i=0; i<n; i++) // if there is a match, add it to the increasing subsequence
  {
     if(s[i] == s2[i])
	subseq = subseq + s[i]; 
  }
  cout << s <<endl <<s2 << endl; 
  cout << subseq << endl; 
  return 0; 
}
