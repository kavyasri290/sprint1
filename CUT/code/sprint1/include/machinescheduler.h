#ifndef MACHINESCHEDULER_H
#define MACHINESCHEDULER_H
#include <array>
#define MAX 100;
using namespace std;
class MachineScheduler
{
	public:
		
		MachineScheduler(){};
		int readInputFile(const char* inpFile);
	private:
		int d1=1;int d2=1;int d3=1;int d4=1;
		extern array <Schedule1,MAX> s1;
		extern array <Schedule2,MAX> s2;
		extern array <Schedule3,MAX> s3;
	

};
//declareing thread class
class Thread{
	public:
		void thread1();
		void thread2();
		void thread3();
};


#endif
