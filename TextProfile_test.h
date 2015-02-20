/*    @file TextProfile_test.h  
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-02-2014
      @version 0.01   
      Copyright 2014 Matt Hoendorf

			Unit tests for TextProfile class.
*/

#include <TextProfile.h>

#include <cxxtest/TestSuite.h>

class TextProfileTest : public CxxTest::TestSuite {
public:

/* --  getCharCount ----------------------------------*/
	void testCharCount0(){
		TextProfile a("");
		TS_ASSERT_EQUALS(a.getCharacterCount(), 0 );
	}
	
	void testCharCount1(){
		TextProfile a("a");
		TS_ASSERT_EQUALS(a.getCharacterCount(), 1 );
	}
	void testCharCount2(){
		TextProfile a("a. b.");
		TS_ASSERT_EQUALS(a.getCharacterCount(), 4 );
	}
	
	
/* --  getLineCount ----------------------------------*/
	void testLineCount0(){
		TextProfile a("abcd\n");
		TS_ASSERT_EQUALS(a.getLineCount(), 1 );
	}
	void testLineCount1(){
		TextProfile a("abcd");
		TS_ASSERT_EQUALS(a.getLineCount(), 1 );
	}
	void testLineCount2(){
		TextProfile a("abcd\nefgh.");
		TS_ASSERT_EQUALS(a.getLineCount(), 2 );
	}
	
/* --  getWordCount ----------------------------------*/
	void testWordCount0(){
		TextProfile a("boy");
		TS_ASSERT_EQUALS(a.getWordCount(), 1 );
	}
	void testWordCount1(){
		TextProfile a("boy girl");
		TS_ASSERT_EQUALS(a.getWordCount(), 2 );
	}
	void testWordCount2(){
		TextProfile a("boy. girl.");
		TS_ASSERT_EQUALS(a.getWordCount(), 2 );
	}
	void testWordCount3(){
		TextProfile a("boy\ngirl");
		TS_ASSERT_EQUALS(a.getWordCount(), 2 );
	}
	
/* --  getSentenceCount ----------------------------------*/
  void testGetSentenceCount0(){
		TextProfile a("This is a sentence.\n");
		TS_ASSERT_EQUALS(a.getSentenceCount(), 1);
	}
	void testGetSentenceCount1(){
		TextProfile a("This is a sentence");
		TS_ASSERT_EQUALS(a.getSentenceCount(), 1);
	}
	void testGetSentenceCount2(){
		TextProfile a("This is a sentence\nthis.\nis\ntoo");
		TS_ASSERT_EQUALS(a.getSentenceCount(), 2);
	}
  void testGetSentenceCount3(){
		TextProfile a("Sentence? Sentence!");
		TS_ASSERT_EQUALS(a.getSentenceCount(), 2);
	}
	
/* --  getAverageWordsPerSentence ----------------------------------*/
  void testGetAverageWordsPerSentence0(){
		TextProfile a("This is a sentence.");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}
	void testGetAverageWordsPerSentence1(){
		TextProfile a("This is a sentence");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}
	void testGetAverageWordsPerSentence2(){
		TextProfile a("This is a sentence.\n");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}
	void testGetAverageWordsPerSentence3(){
		TextProfile a("This is a sentence! This is another sentence?\n");
		TS_ASSERT_DELTA(a.getAverageWordsPerSentence(), 4, 0.01);
	}

/* --  getAverageWordLength ----------------------------------*/
  void testGetAverageWordLength0(){
		TextProfile a("This");
		TS_ASSERT_DELTA(a.getAverageWordLength(), 4, 0.01);
	}
	void testGetAverageWordLength1(){
		TextProfile a("This. Fart. Toad.");
		TS_ASSERT_DELTA(a.getAverageWordLength(), 4, 0.01);
	}
	void testGetAverageWordLength2(){
		TextProfile a("This\n");
		TS_ASSERT_DELTA(a.getAverageWordLength(), 4, 0.01);
	}
	void testGetAverageWordLength3(){
		TextProfile a("Th* is\n");
		TS_ASSERT_DELTA(a.getAverageWordLength(), 2, 0.01);
	}
	
	
/* --  typeTokenRatio ----------------------------------*/
	void testTypeTokenRatio0(){
		TextProfile a("this is a big big sentence this is a big sentence");
		TS_ASSERT_DELTA(a.typeTokenRatio(), 0.5, 0.1);
	}
	void testTypeTokenRatio1(){
		TextProfile a("foo foo bar bar hey");
		TS_ASSERT_DELTA(a.typeTokenRatio(), 0.6, 0.1);
	}
	void testTypeTokenRatio2(){
		TextProfile a("foo. foo. bar. bar. hey.");
		TS_ASSERT_DELTA(a.typeTokenRatio(), 0.6, 0.1);
	}
	void testTypeTokenRatio3(){
		TextProfile a("writingthiscode sucked. writing this code.");
		TS_ASSERT_DELTA(a.typeTokenRatio(), 1, 0.1);
	}

/* --  hypaxRatio ----------------------------------*/
  void testHapaxRatio0(){
		TextProfile a("this is a sentance? of a sentance is ");
		TS_ASSERT_DELTA(a.hapaxRatio(), 0.25, 0.01);
	}
	void testHapaxRatio1(){
		TextProfile a("my mom. your mom.");
		TS_ASSERT_DELTA(a.hapaxRatio(), 0.5, 0.01);
	}
	void testHapaxRatio2(){
		TextProfile a("yo! YO! hello! HI!");
		TS_ASSERT_DELTA(a.hapaxRatio(), 0.75, 0.01);
	}
  void testHapaxRatio3(){
		TextProfile a("HELLO hello bono vertigo");
		TS_ASSERT_DELTA(a.hapaxRatio(), 0.5, 0.01);
	}

	
/* -- White Box Tests ------------------------------------------------- */

};
