// Shondell Baijoo
// Spring 2017
// Viterbi Algorithm

#include<iostream>
#include<math.h>  
using namespace std;

int main()
{
    int x_size = 59; // length of sequence
    int x[x_size] = {6,5,1,1,6,6,4,5,3,1,3,2,6,5,1,2,4,5,3,6,6,6,4,6,3,1,6,3,6,6,6,3,1,6,2,3,2,6,4,5,5,2,3,6,2,6,6,6,6,6,6,2,5,1,5,1,6,3,1}; // sequence
    // emission prob. for loaded dice to land on anything other than 6
    double eL1to5 = 0.1;
    double eL6 = 0.5; // emission prob. for loaded die to land on 6 
    // emissison prob. for fair die
    double eF = 1.0/6.0;
    // Prob for state changes
    double aLtoF = 0.1;
    double aFtoL = 0.05; 
    double aLtoL = 0.9; 
    double aFtoF = 0.95; 
    double prob[2][x_size]; // matrix to store probabilities
    char backtrack[2][x_size]; // backtracking
    double eL =0;
    // start 
    if(x[0] == 6)
	eL = eL6; 
    else 
	eL = eL1to5;
    prob[0][0] = (log10(0.5)+1) + log10(eL);
    prob[1][0] = (log10(0.5)+1) + log10(eF); 
    backtrack[0][0] = 'L'; //Start state
    backtrack[1][0] = 'F'; // start
    for(int i=1; i<x_size; i++) // for each letter in sequence
    {
	if(x[i] == 6)
	    eL = eL6; // set eL to .5 if character is 6
	else 	
	    eL = eL1to5; 
	// compute loaded probability 
	double maxL, maxF; 
	double temp=0.0; 
	maxL = log10(aLtoL) + prob[0][i-1]; 
	backtrack[0][i] = 'L'; 
	temp = log10(aFtoL) + prob[1][i-1]; 
	if(maxL < temp) 
	{
	    maxL = temp;
	    backtrack[0][i] = 'F';   
	}
	cout << "l: max:" << maxL << " temp: " << temp << endl; 
	prob[0][i] = log(eL) + maxL; 
	// fair probability 	
	maxF = log10(aFtoF) + prob[1][i-1]; 
	backtrack[1][i] = 'F'; 
	temp = log10(aLtoF) + prob[0][i-1]; 
	cout << "f: max:" << maxF << " temp: " << temp << endl; 
	if(maxF < temp)
	{
	    maxF = temp;
	    backtrack[1][i] = 'L'; 
	}
	prob[1][i] = log(eF) + maxF;
	// for display
	cout << backtrack[0][i] << " " << backtrack[1][i] << endl;
	cout << prob[0][i] << " " << prob[1][i] << endl;  
    }
    int max; 
    if(prob[0][x_size-1] < prob[1][x_size-1]) // choose max of backtrack paths
	max=1; 
    else 	
	max=0; 
    for(int i=0; i<x_size; i++) // display output 
	cout << backtrack[max][i] << " "; 
    cout << endl; 
    return 0;
}
