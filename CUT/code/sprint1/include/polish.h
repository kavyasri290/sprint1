#ifndef POLISH_H
#define POLISH_H
#include<job.h>

class Polish : public Job{
	public:
		Polish(){};
		Polish(string, string,string,int,string,string,string);
		~Polish(){};
		string getPolishName();
		string getColour();
		void displayJob() const;
	private:
		string polishName;
		string colour;
};
#endif
