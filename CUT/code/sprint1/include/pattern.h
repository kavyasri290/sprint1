#ifndef PATTERN_H
#define PATTERN_H
#include<job.h>

class Pattern : public Job{
	public:
		Pattern(){};
		Pattern(string,string,string,int,string,string);
		~Pattern(){};
		string getPatternName();
		void displayJob() const;
	private:
		string patternName;
};
#endif

