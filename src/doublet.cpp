#include "../lib/doubletsolver.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc < 4){
    	cerr << "usage: ./search index_file...Please provide a dictionary file" << endl;
    	return 1;
  	}

	DoubletSolver ladders(argv[1],argv[2],argv[3]);
	ladders.solve();
	
	return 0;
}