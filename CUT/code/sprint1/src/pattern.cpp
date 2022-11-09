#include <iostream>
#include<pattern.h>
using namespace std;

Pattern::Pattern(string jobId,string description,string machineNo,int duration,string client,string patternName){
		this->patternName=patternName;
		
	}
string Pattern::getPatternName(){return patternName;}

void Pattern::displayJob() const{
		Job::displayJob();
		cout<<","<<patternName<<endl;
	}


	
