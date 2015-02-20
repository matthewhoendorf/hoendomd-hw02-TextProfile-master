/*    @file TextProfile.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-02-2014

			@description Returns text statistics for a string document.
*/

#include <iostream>
#include <vector>

using namespace std;

class TextProfile{
friend class TextProfileTest;
public:
	TextProfile(string text);
  
    /* getCharacterCount() returns the number of PRINTABLE characters
    given in the string.  This includes alphanumeric, plus numbers
    and punctuation. */
	int	getCharacterCount();
	
	/* getLetterCount() returns the number of PRINTABLE letters
    given in the string.  */
	int	getLetterCount();
	
	  /* getLineCount() returns the number of lines in the given string.
	  Lines are delimited by the '\n' character */
	int getLineCount();
	
	  /* getWordCount() returns the number of words in the given string.
	  Words are groups of printable characters with whitespace before and
	  after. */
	int getWordCount();
	
	  /* getSentanceCount() return the number of sentences in the given string
	  A sentence is a sequence of 1. characters that ends (does not include)
	  the characters ! ? . or the end of the file. 2. whitespace on each end
	  and 3. is not empty.  */
	int getSentenceCount();

	
	  /* getAverageWordsPerSentance() returns a float of the average number
	  of words in a sentence, as defined in getSentanceCount above. */
	float getAverageWordsPerSentence();
	
	  /* getAverageWordLength() returns a float of the average number of 
	  alphanumeric characters in all words.  ie, remove punctuation. */
	float getAverageWordLength();
	
	  /* typeTokenRatio() returns a float of the ratio of the number of unique words to 
	  the total number of words.  Most documents contain repeated words.  
	  The numerator of this ratio does not contain any repeats, while 
	  the denominator does. */
	float typeTokenRatio();
	
	  /* returns a float of the Hapax Legomana Ratio.  Similar to the 
	  typeTokenRatio, but the numerator contains the count of words 
	  which are only used exactly ONCE in the text.  */
	float hapaxRatio();
	
	  /* returns a bool - 1 if the character is printable and 0 
	  if otherwise  */
	bool isPrintable(char c);
	
	  /* returns a bool - 1 if the character is an alphabetical letter
	  and 0 if otherwise  */
	bool isAlphabetical(char c);
	
	  /* returns a bool - 1 if the character is a punctuation mark
	  and 0 if otherwise  */
	bool isPunctuation(char c);
	
	  /* returns a char that is the lowercase of what was input.
	  If the char is already lowercase, it does not alter the value.  */
	char makeLower(char c);
	
private:
	TextProfile();

	string text;
	
};
