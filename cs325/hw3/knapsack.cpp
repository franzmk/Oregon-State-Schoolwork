#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace std::chrono;

//This is a function that will return the higher value when comparing two vlaues
int max(int a, int b) {
    //If a is bigger than b, a is returned
    if(a > b) return a;
    //If b is bigger than a, b is returned
    else return b;
}

//This is the recursive function
int knapSackRec(int W, int *wt, int *val, int n) {
    //Check if either W or n is 0, if so, exit
    if (W == 0 || n == 0) {
        return 0;
    }
    //This checks the weight of the nth item, if it's more than W, we must exclude it
    if (wt[n - 1] > W) {
        return knapSackRec(W, wt, val, n - 1);
    } else { //If it's less than W, then we return the max between the nth item that is included and the nth item that isn't included
        return max(val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1), knapSackRec(W, wt, val, n - 1));
    }
}

//Used GeeksforGeeks for inspiration on this function
//This is the DP function
int knapSackDP(int W, int *wt, int *val, int n) {
    //Initialize an array knapsack
    int knapsack[n + 1][W + 1];
  
    //These for loops will fill the array knapsack
    for (int i = 0; i <= n; i++) {
        for (int weight = 0; weight <= W; weight++) {
            //If the weight or i is 0, we place a 0 in the array
            if (i == 0 || weight == 0) {
                //This adds a 0 to the array
                knapsack[i][weight] = 0;
            } else if (wt[i - 1] <= weight) { //This checks if the ith item weight is less than the current item weight
                //This line adds the maximum between the ith value and the previous value to the array knapsack
                knapsack[i][weight] = max(val[i - 1] + knapsack[i - 1][weight - wt[i - 1]], knapsack[i - 1][weight]);
            } else { //If no other if statement, then the else
                //This line adds the ith items to the array knapsack
                knapsack[i][weight] = knapsack[i - 1][weight];
            }
        }
    }
    //Return the max at n, W
    return knapsack[n][W];
}

//Main function
int main() {
    //Seed random time
    srand(time(NULL));
    //Set n to 10
    int n = 10;

    //Initialize val and wt arrays
    int *val;
    int *wt;
    //Set W to 100
    int W = 100;

    //For loop that runs 10 times to get 10 trials
    for(int j = 0; j < 7; j++) {
        //Initialize wt and val arrays with correct size
        val = new int[n];
        wt = new int[n];

        //Fill val and wt with appropriate random ints
        for(int i = 0; i < n; i++) {
            val[i] = (rand() % 500) + 1;
        }
        for(int i = 0; i < n; i++) {
            wt[i] = (rand() % 30) + 1;
        }

        //Start timing recursive function
        auto recStart = high_resolution_clock::now();
        //Call recursive function
        int recResult = knapSackRec(W, wt, val, n);
        //Stop timing recursive function
        auto recStop = high_resolution_clock::now();

        //Calculate the recursive functions total time
        auto recDuration = duration_cast<microseconds>(recStop - recStart).count();

        //Start timing recursive function
        auto dpStart = high_resolution_clock::now();
        //Call recursive function
        int dpResult = knapSackDP(W, wt, val, n);
        //Stop timing recursive function
        auto dpStop = high_resolution_clock::now();

        //Calculate the recursive functions total time
        auto dpDuration = duration_cast<microseconds>(dpStop - dpStart).count();

        //Print necessary variables
        cout << "n = " << n << " W = " << W << " Rec time = " << recDuration << " µs DP time = " << dpDuration<< " µs max Rec = " << recResult << " max DP = " << dpResult<< endl;

        //Increase n by 5
        n = n + 5;

        //Delete val and wt arrays
        delete[] val;
        delete[] wt;
    }

    return 0;
}