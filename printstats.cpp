/*    @file printstats.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-02-2014

			@description Prints statistics about a given text file
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <ctype.h>
#include <stdio.h>

#include "TextProfile.h"

using namespace std;

int main(int argc, char* argv[]){

  char* input_file_name = NULL;
  int i;
     
  opterr = 0;
  
  while ((i = getopt (argc, argv, "i:")) != -1){
    switch (i){
      case 'i':
        input_file_name = optarg;
        break;
      case '?':
        if (optopt == 'i'){
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        }
        else if (isprint (optopt)){
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        }
        else{
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        }
        return 1; 
      default:
        abort ();
    }
  }
  
  if(input_file_name==NULL){
    cout << "\nUsage: ./printstats -­i <filename>\n" << endl;
    return 0;
  }
  
  cout << input_file_name << endl;

  ifstream file;  // The following lines reads an entire text file and saves
	file.open( input_file_name,  iostream::in); // it to a string.

	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	char *buffer = new char[length];
	file.read(buffer, length);
	file.close();

	string sfile(buffer);
	delete[] buffer;
	
	TextProfile p(sfile);
	
	
	cout << "Printable char count: " << p.getCharacterCount() << endl;
	cout << "Line count: " << p.getLineCount() << endl;
	cout << "Word count: " << p.getWordCount() << endl;
	cout << "Sentence count: " << p.getSentenceCount() << endl;
	cout << "Avg words per sentence: " << p.getAverageWordsPerSentence() << endl;
	cout << "Avg word length: " << p.getAverageWordLength() << endl;
	cout << "TypeToken ratio: " << p.typeTokenRatio() << endl;
	cout << "Hapax ratio: " << p.hapaxRatio() << "\n" << endl;
	
	return 0;
}
