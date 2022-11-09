#ifndef CUT_H
#define CUT_H
#include <job.h>
using namespace std;

class Cut : public Job{
	public:
		Cut(){};

		//inherited variables from job class
		Cut(string,string,string,int,string,int,int);
		~Cut(){};
		int getLength();
		int getNoOfUnits();
	        void displayJob() const;
	private:
		//declring instance variable of cut class
		int length;
		int noOfUnits;
};
#endif

