#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
#define MAX 1000

//Point class
class Point {
    private:
        //x and y values for a single point
        int x;
        int y;

    public:
        //Constructor to set default values
        Point() {
            x = -1;
            y = -1;
        }
      
        //Modified constructor to set x and y to a and b
        Point(int a, int b) {
            x = a;
            y = b; 
        }
      
       //Set x function
        void setX(int a) {
            x = a;
        }
      
        //Set y function
        void setY(int a) {
            y = a;
        }
      
        //Get x function
        int getX() {
            return x;
        }
      
        //Get y function
        int getY(){
            return y;
        }
};

//Node class
class Node {
    private:
        int n; //Node number
        Point *p; //(x, y) point for that node

    public:
       //Consdtructor to set default values
        Node() {
            n = -1;
            p = NULL;
        }
      
        //Modified constructor to set number and point
        Node(int _n, Point *_p) {
            n = _n;
            p = _p;
        }
      
        //Set n function
        void setN(int _n) {
            n = _n;
        }
      
        //Set point function
        void setPoint(Point *_p) {
            p = _p;
        }
      
        //Get n function
        int getN() {
            return n;
        }
      
        //Get point function
        Point *getPoint(){
            return p;
        }
};

//Graph class
class Graph {
    private:
        int size; //Node size for that graph
        int **arr; //Array for graph points
        Node *node; //Array of nodes
        int ind; //Index value to keep track of nodes
      
        //Calculate distance between points
        int distance(Point *a, Point *b) {
            //This is the equation we were given
            double d = sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
            //Add 0.5 to and cast as an int to round the distance to nearest int
            int d1 = (int)(d + 0.5);
	        return d1;
        }
      
    public:
        //Constructor for default values
        Graph(int _s){
            //Set index
            ind = -1;
          
            //Set size to given value
            size = _s;
          
            //Init 2d array for points
            arr = new int*[size];
          
            //Init first node
            node = new Node[size];
          
            //Fill 2d array
            for (int i = 0; i < size; i++) {
                arr[i] = new int[size];
            }
        }

        //Add node function
        void addNode(Node n) {
            ind++;
            node[ind] = n;
        }

        //Get node function
        Node getNodeAtIndex(int a){
            return node[a];
        }

        //Setup function will fill array with distances
        int setup() {
            //Check to make sure ind is equal to size - 1
            if (ind == size - 1) {
                //For loop runs size times
                for (int i = 0; i < size; i++) {
                    //Create new node
                    Node na = node[i];
                    //For loop runs size times
                    for (int j = 0; j < size; j++) {
                        //Create second new node
                        Node nb = node[j];
                        //Fill array with distance between those nodes
                        arr[i][j] = distance(na.getPoint(), nb.getPoint());
                    }
                }

                //Store maximum value in the diagonal
                for (int i = 0; i < size; i++) {
                    arr[i][i] = -1;
                }
                //Return 0 if a distance was added
                return 0;
            } else {
                //Return 1 if no new distance was added to array
                return 1;
            }
        }

        //minKey function gets the minimum indexing value
        int minKey(int key[], bool mSet[]) {
            //Set variables
            int _min = MAX, m_index;

            //Calculate the min. indexing val
            for (int i = 0; i < size; i++) {
                if (mSet[i] == false && key[i] < _min){
                    _min = key[i];
                    m_index = i;
                }
            }
            return m_index;
        }

        //printWeight will print the weight of the current graph
        void printWeight(int *p) {
            //total is init
            int total = 0;
            //For loop runs size times
            for (int i = 1; i < size; i++) {
                //Add the distance at each point to the total
                total += arr[i][p[i]];
            }
            //Print total
            cout << "MST Weight: " << total;
        }

        //Using prims, find the mst
        //I used GFG and the lecture slides as a reference
        void prim() {
            //Init arrays
            int *p = new int[size];
            int *key = new int[size];
            bool *mSet = new bool[size];

            //Fill arrays
            for (int i = 0; i < size; i++) {
                key[i] = MAX;
                mSet[i] = false;
            }

            //Set default values
            key[0] = 0;
            p[0] = -1;

            //For loop runs size - 1 times
            for (int i = 0; i < size - 1; i++) {
                //Get next min. key index
                int u = minKey(key, mSet);
              
                mSet[u] = true;
              
                //For loop runs size times
                for (int j = 0; j < size; j++) {
                    //Set minimum key and the corresponding parent
                    if (arr[u][j] && mSet[j] == false && arr[u][j] < key[j]) {
                        p[j] = u;
                        key[j] = arr[u][j];
                    }
                }
            }
            //Call printWeight to print the weight for that graph
            printWeight(p);
        }
};
