// Shondell Baijoo
// Spring 17
// Gene Alignment

#include <iostream>
using namespace std;

int main()
{
  string seq = "BCCT"; 
  string seq2 = "BT"; 
  int n = seq.length()+1; // 5 
  int m = seq2.length()+1; // 3  
  int score[m][n]; // rows * col
  char trace[m][n]; 
  // scoring 
  int match = 1; 
  int mismatch = -1;
  int gap = -2;
  score[0][0] = 0;
  trace[0][0] = 'X'; 
  for(int i=1; i<n; i++) // columns
  {
	score[0][i] = score[0][i-1] + gap;
	trace[0][i] = 'L'; 
  } 
  for(int j=1; j<m; j++)
  {
	score[j][0] = score[j-1][0] + gap; 
	trace[j][0] = 'U';  
  }
  for(int j=1; j<3; j++) // rows
  {
  	for(int i=1; i<5; i++) // columns
	{
	  int temp = score[j-1][i-1];
	  char c = 'D'; 
	  if(seq[i-1] == seq2[j-1]) 
		temp+=match; 
	  else temp+=mismatch;

	  if(temp < (score[j-1][i] + gap))
	  {
		temp = score[j-1][i] + gap; 
		c = 'U'; 
	   }
	  if(temp < (score[j][i-1] + gap))
	  {
		temp = score[j][i-1]+gap;
		c = 'L'; 
	  } 
	  score[j][i] = temp;  // make score minimal
	  trace[j][i] = c; 
	}
  }   
  for(int i=0; i<3; i++)
  {  
	for(int j=0; j<5; j++) cout << score[i][j] << " "; 
        cout << endl; 
  }
  cout << endl <<endl; 
  for(int i=0; i<3; i++)
  {  
	for(int j=0; j<5; j++) cout << trace[i][j] << " "; 
	cout << endl; 
  }	
  cout << score[m-1][n-1] <<endl;
  string s="", s2="";
  int row=m-1, col = n-1; 
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
  cout << endl << s << endl << s2; // output   
  return 0; 
}
