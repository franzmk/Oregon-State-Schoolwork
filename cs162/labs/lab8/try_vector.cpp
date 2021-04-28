#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
        vector<int> v1, v2;   //Our vector class
        std::vector<int> stdv; //Standard vector

        //Compare operation of our vector to std
        v1.push_back(23);
        v1.push_back(56);
        v1.push_back(76);
        v1.push_back(2);
        v1.push_back(8);
        stdv.push_back(23);
                  
	v2 = v1;

	vector<int> v3(v2);

        cout << "Our v1 size: " << v1.size() << endl;
	cout << "v1[3]: " << v1[3] << endl;
	cout << "Our v2 size: " << v2.size() << endl;
	cout << "v2[3]: " << v2[3] << endl;
	cout << "Our v3 size: " << v3.size() << endl;
	cout << "v3.at(3): " << v3.at(3) << endl;

	cout << "v2.at(9): " << v3.at(9) << endl;

	cout << "STL vector size: " << stdv.size() << endl;

	return 0;
}                         
