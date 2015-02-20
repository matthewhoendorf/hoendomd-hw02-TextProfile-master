/*    @file Analyzer.cpp   
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-02-2014

			@description Prints text statictics from a source docuemnt.
*/

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "TextProfile.h"

using namespace std;

TextProfile::TextProfile(string input):text(input){   
  // :text(input) is the same as text = input
};

int TextProfile::getCharacterCount(){

  unsigned int count = 0;

  for(unsigned int i = 0; i < text.length(); i++){
    if(isPrintable(text[i])==1){
      //check if printable ascii char 
      count++;
    }
  }    
  return count;
};

int TextProfile::getLetterCount(){

  unsigned int count = 0;

  for(unsigned int i = 0; i < text.length(); i++){
    if(isAlphabetical(text[i])==1){
      //check if printable ascii char 
      count++;
    }
  }    
  return count;
};



int TextProfile::getLineCount(){

  int number_of_lines = 1;

  for(unsigned int c = 0; c < text.length(); c++){
    if(text[c] == '\n'){ //increment line count for every '\n' in text
      number_of_lines++;
    }
  }
  
  if(text[text.length()-1] == '\n'){ // check for empty line at the end
    number_of_lines--;
  }

  if(getCharacterCount()==0){ //check for empty text
    number_of_lines = 0;
  }
  
  return number_of_lines;
};


int TextProfile::getWordCount(){
  int word_count = 0;
  for(unsigned int n = 1; n <= text.length(); n++){
    if(isPrintable(text[n])==0 && isPrintable(text[n-1])==1){
      word_count++;
    }
  }
  return word_count;
};

int TextProfile::getSentenceCount(){
  int  sentence_count = 0;
  for(unsigned int c = 1; c <= text.length(); c++){ 
    //if char is space, new line, or null
    if(isPrintable(text[c])==0){
      //and if the char before it is a punctuation mark
      if(isPunctuation(text[c-1])==1){
        sentence_count++;
      }
      else if(c==text.length()&&isPrintable(text[c-1])==1){
        sentence_count++;
      }
    }
  }
  return sentence_count;
}

float TextProfile::getAverageWordsPerSentence(){ 
  float avg = (float)getWordCount()/getSentenceCount();
  return avg;
};

float TextProfile::getAverageWordLength(){
  float avg = (float)getLetterCount()/getWordCount();
  return avg;
};

float TextProfile::typeTokenRatio(){
  vector<string> list1;
  char temp;
  string temp2;
  for(unsigned int i = 0; i < text.length(); i++){
    temp = makeLower(text[i]);
    if(isAlphabetical(temp)==1){
      temp2+=temp;
    }
    else{
      if(temp2 != ""){
        list1.push_back(temp2);
      }
      temp2="";
    }
  }
  if(temp2 != ""){
    list1.push_back(temp2);
  }
  sort(list1.begin(), list1.end());
  float old_size = list1.size();
  int size = old_size;
  int i = 1;
  while(i<size){
    if(list1.at(i)==list1.at(i-1)){
      list1.erase(list1.begin()+i);
      size--;
      i--;
    }
    i++;
  }
  float tt_ratio = list1.size()/old_size;
  return tt_ratio;   
};

float TextProfile::hapaxRatio(){
  vector<string> list1;
  char temp;
  string temp2;
  for(unsigned int i = 0; i < text.length(); i++){
    temp = makeLower(text[i]);
    if(isAlphabetical(temp)==1){
      temp2+=temp;
    }
    else{
      if(temp2 != ""){
        list1.push_back(temp2);
      }
      temp2="";
    }
  }
  if(temp2 != ""){
    list1.push_back(temp2);
  }
  sort(list1.begin(), list1.end());
  float old_size = list1.size();
  int count = 0;
  if(list1.at(0)!=list1.at(1)){
    count++;
  }
  for(unsigned int i = 1; i < list1.size()-1;i++){
    if(list1.at(i)!=list1.at(i+1)&&list1.at(i)!=list1.at(i-1)){
      count++;
    }
  }
  if(list1.end()!=list1.end()-1){
    count++;
  }
  return count/old_size;
};

bool TextProfile::isPrintable(char c){
  if(c > '\x20' && c < '\x7f'){
    return 1;
  }
  else{
    return 0;
  }
};

bool TextProfile::isAlphabetical(char c){
  if((c>'\x40' && c<'\x5B')||(c>'\x60' && c<'\x7B')){
    // checks if 'A'-'Z' or 'a'-'z
    return 1;
  }
  else{  
    return 0;
  }
};

bool TextProfile::isPunctuation(char c){
  if(c=='\x3F' || c=='\x21' || c=='\x2E'){
    // checks if '?', '!', or '.'
    return 1;
  }
  else{
    return 0;
  }
};

char TextProfile::makeLower(char c){
  if(c>'\x40' && c<'\x5B'){ 
    //checks if upper case
    c = c + 32;
  }
  return c;
};

