#include "header.h"

//Main function, runs the show
int main(int argc, char **argv){
    //Init a new 2d point array
    Point **p;
  
    //Init the input file
    ifstream in;
  
    //Open the input file
    in.open(argv[1]);
  
    //Check if the input file opened
    if(in.bad()){
        cout << "File not found." << endl;
        exit(1);
    } else { //If it opened, begin
        //Init the number of test cases
        int numTests = 0;
        //Read the number of test cases from input file
        in >> numTests;

        //For loop runs numTests times
        for(int i = 0; i < numTests; i++) {
            //Init size of each test case and read it from the inptu file
            int size;
            in >> size;
          
            //Set 2d point array and init new graph
            p = new Point*[size];
            Graph graph(size);
          
            //Init x and y vals for new point
            int x, y;
            int index = 0;
          
            for(int j = 0; j < size; j++) {
                //Read x and y vals from input file
                in >> x;
                in >> y;
              
                //Fill new point with x and y vals
                p[index] = new Point(x, y);
              
                //Create a node with index + 1 node number and the newly created point
                Node n(index + 1, p[index]);
              
                //Add the node to the graph
                graph.addNode(n);
            }

            //Setup graph
            int r = graph.setup();

            //Print test case num and the MST weight
            cout << "Test Case " << i + 1 << " - ";
            graph.prim();
            cout << endl;
        }
        
        //Close the input file
        in.close();
    }

    return 0;
}