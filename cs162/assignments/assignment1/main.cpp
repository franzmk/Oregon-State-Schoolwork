/*
 * Program Filename: magic.cpp
 * Author: Max
 * Date: 4/12/19
 * Description: This is the driver file for the magic program. It does what it needs to do, in relation to wizard logins and spell sorting.
 * Input: Two file names in the form of command line arguments
 * Output: N/a
 */

#include "magic.h"

using namespace std;

int main(int argc, char** argv) {
	int wiz_index, num_wizards;
	string file1, file2;
	wizard *wiz;

	check_num_args(argc);

	check_files(argv, file1, file2);
	
	login(file1, &wiz, wiz_index, num_wizards);

	sort(wiz, wiz_index, num_wizards, file2);

	return 0;
}
