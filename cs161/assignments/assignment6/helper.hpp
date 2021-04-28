#include <fstream>
#include <string.h>


/*********************************************************************
 ** Program Filename: fileWrite
 ** Author: Mason Sidebottom
 ** Date: Feb. 2019
 ** Description: Helper functionality for binary file IO
 *********************************************************************/
class fileWriter {
	private:
		std::ofstream file;

	public:
		/*********************************************************************
		 ** Function: Constructor
		 ** Description: Sets up writer class
		 ** Parameters: String -> File name
		 ** Pre-Conditions: N/A
		 ** Post-Conditions: osfstream is initialized to be used in output mode,
		 **						with binary output.
		 *********************************************************************/ 
		fileWriter (const char * filename) : file(filename, std::ofstream::out | std::ofstream::binary){}


		/*********************************************************************
		 ** Function: Destructor
		 ** Description: Closes file
		 ** Pre-Conditions: File is open
		 ** Post-Conditions: File will be closed
		 *********************************************************************/ 
		~fileWriter () { this->file.close(); }
		
		/*********************************************************************
		 ** Function: Write 
		 ** Description: Writes a file using binary data, instead of string
		 **					representation. 
		 ** Pre-Conditions: File is open 
		 *********************************************************************/ 
		template <typename T>
		void write(const T val){
			// Create byte array of with as many bytes in type
			unsigned char * str = new unsigned char [sizeof(T)];

			// Copy contents of memory
			memcpy(str, &val, sizeof(T));
			
			// Write individual bytes so that all zeros are written 
			for(int i = 0; i < sizeof(T); i++)
				this->file << str[i];

			// Free byte array
			delete [] str;
		}

		/*********************************************************************
		 ** Function: Overloaded stream operator 
		 ** Description: Calls write, see above
		 ** Returns: fileWrite &, allows for fW << a < b << c << ... 
		 *********************************************************************/ 
		template <typename T>
		friend fileWriter& operator<<(fileWriter & writer, const T val){
			writer.write(val);
			return writer;
		}
};

