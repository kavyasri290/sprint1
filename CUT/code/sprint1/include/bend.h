#ifndef BEND_H
#define BEND_H
#include<job.h>

class Bend : public Job{
	public:
		Bend(){};

		//inherited variables from job class
		Bend(string,string,string,int,string,string,string);
		~Bend(){};
		string getShape();
		string getNoOfBends();
		 void displayJob() const;
	private:
		 //declaring instance variables of bend class
		string shape;
		string noOfBends;
};
#endif

