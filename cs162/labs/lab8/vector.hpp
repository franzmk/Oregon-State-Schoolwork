#include <stdlib.h>
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;
using std::out_of_range;
using std::exception;
template <class T>
class vector {
   private:
        T *v;
        int s;
   public:
        vector(){
	        s=0;
     	        v=NULL;
        }
						   	  
        ~vector(){
	        delete [] v;
        }
	
	vector(vector<T> &other) {
		s = other.s;
		v = new T[s];
		for(int i = 0; i < s; i++) {
			v[i] = other.v[i];
		}
	}

	void operator=(vector<T> &other) {
		if(this != &other) {
			delete [] v;
			s = other.s;
			v = new T[s];
			for(int i = 0; i < s; i++) {
				v[i] = other.v[i];
			}
		}
	}

        int size() {
		return s;
        }
	
        void push_back(T ele) {
		T *temp;
     	        temp = new T[++s];
     	        for(int i=0; i<s-1; i++)
    	        	temp[i]=v[i];

	        delete [] v;
    	        v=temp;
     	        v[s-1]=ele;
	}

	T operator[](int index) {
		return v[index];
	}

	T at(int index) {
		try {
			if(index > s) {
				throw std::out_of_range("out of my vector bounds");
			}
			else return v[index];
		}
		catch(std::out_of_range) {
			cout << "The index " << index << " is out of range of the vector!" << endl;
		}
	}
};
