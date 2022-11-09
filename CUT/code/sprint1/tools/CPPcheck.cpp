#include <iostream>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "machinescheduler.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestStudent : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSchedule);
    CPPUNIT_TEST(displayCut);
    CPPUNIT_TEST(displayBend);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void cut(void);
    void bend(void);
    

private:

    Schedule *s1, *s2;
};

//-----------------------------------------------------------------------------

void TestSchedule::displayCut(void)
{
        CPPUNIT_ASSERT( 10== s1->getLength());
	CPPUNIT_ASSERT( "square"== s2->getShape());
}

void TestSchedule::displayBend(void)
{
    	CPPUNIT_ASSERT("J001" == Cut::jobId);
	CPPUNIT_ASSERT("J002 == Bend::jobId);
}



void TestStudent::setUp(void)
{
    s1 = new S1();
    s2 = new S2();
    s1->setStudent("J001","cut", "M1", 45,"Alpha",10, 5); 
    s2->setStudent("J002","Bend, "M2", 30,"serine", "Square","corners"); 
}

void TestSchedule::tearDown(void)
{
    delete s1;
    delete s2;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestSchedule );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppStudentResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

