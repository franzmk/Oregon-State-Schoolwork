#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//This is a function that will return the higher value when comparing two vlaues
int max(int a, int b) {
    //If a is bigger than b, a is returned
    if(a > b) return a;
    //If b is bigger than a, b is returned
    else return b;
}

//Used GeeksforGeeks for inspiration on this function
//This is the DP function
int knapSackDP(int W[], int P[], int N, int M, vector<int> &items) {
    //Initialize an array knapsack
    int knapsack[N + 1][M + 1];
  
    //These for loops will fill the array knapsack
    for(int i = 0; i <= N; i++) {
        for(int weight = 0; weight <= M; weight++) {
            //If the weight or i is 0, we place a 0 in the array
            if(i == 0 || weight == 0) {
                //This adds a 0 to the array
                knapsack[i][weight] = 0;
            }else if(W[i - 1] <= weight) { //This checks if the ith item weight is less than the current item weight
                //This line adds the maximum between the ith value and the previous value to the array knapsack
                knapsack[i][weight] = max(P[i - 1] + knapsack[i - 1][weight - W[i - 1]], knapsack[i - 1][weight]);
            }else{ //If no other if statement, then the else
                //This line adds the ith items to the array knapsack
                knapsack[i][weight] = knapsack[i - 1][weight];
            }
        }
    }

    //Set w to the maximum weight
    int w = M;
    //Set max to the maximum value in knapsack
    int max = knapsack[N][M];
    //For loop runs as long as i and max aren't 0
    for(int i = N; i > 0 && max > 0; i--) {
        //If the max weight doesn't equal the previous item's weight, enter if
        if(max != knapsack[i-1][w]) {
            //Add item to the items vector
            //items.push_back(i);
            items.insert(items.begin(), i);
            //Decrease the max and the weight
            max -= P[i-1];
            w -= W[i-1];
        }
    }

    //Return the max at n, W
    return knapsack[N][M];
}

//This is the main function
int main() {
    //Initialize variables
    int T, N, F, M = 0;
    int P[100];
    int W[100];

    //Initialize vector
    vector<vector<int>> items(100);

    //Initialize and in and out stream
    ifstream in;
    ofstream out;

    //Open shopping.txt
    in.open("shopping.txt");
    //If it can't open, error
    if(!in.is_open()) {
        cout << "Error opening shopping.txt!" << endl;
        return 1;
    }

    //Create results.txt
    out.open("results.txt");
    //If it can't open, error
    if(!out.is_open()) {
        cout << "Error opening results.txt!" << endl;
        return 1;
    }

    //Collect the number of test cases
    in >> T;
    //For loop runs T times
    for(int i = 0; i < T; i++) {
        //Collect the number of items
        in >> N;

        //Collect the price and weight for all N items
        for(int j = 0; j < N; j++) {
            in >> P[j];
            in >> W[j];
        }

        //Collect the number of family members
        in >> F;

        //Create maxPrice variable
        int maxPrice = 0;

        //For each family member, collect their maximum weight and calculate their maxPrice
        for(int k = 0; k < F; k++) {
            in >> M;
            //knapsackDP is called on each family member's set of items to get their maxPrice
            maxPrice = maxPrice + knapSackDP(W, P, N, M, items[k]);
        }

        //Print to results.txt
        out << "Test Case " << i + 1 << endl;
        out << "Total Price " << maxPrice << endl;
        out << "Member Items" << endl;

        //For loop runs F times
        for(int x = 0; x < F; x++) {
            //My values were printing in decreasing order, so I sort them before printing to get them in increasing order
            sort(items[x].begin(), items[x].end());
            out << x + 1 << ":";
            //For all items in the current row, print them
            for(int y = 0; y < items[x].size(); y++) {
                out << items[x][y] << " ";
            }
            out << endl;
        }
        out << endl;
        //Clear and resize the vector so no previous values are carried over
        items.clear();
        items.resize(100);
    }

    //Close both files
    in.close();
    out.close();

    return 0;
}