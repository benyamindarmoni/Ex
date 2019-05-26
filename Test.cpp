#include <iostream>
#include <string>
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.hpp"
using namespace std;
using namespace itertools;
int main()
{
    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);

    if (signal == 0)
    {

     //CHECK THE RANGE:
        std::ostringstream range1, range2, range3, range4;
        for (char c : range('E', 'H'))
            range1 << c;
        for (char c : range('c', 'f'))
            range2 << c;
        for (int i : range(1, 7))
            range3 << i;
        for (double d : range(1.1, 3.1))
            range4 << d ;
       

        testcase.setname("Test range")
            .CHECK_OUTPUT(range1.str(), "EFG")
            .CHECK_OUTPUT(range2.str(), "cde")
            .CHECK_OUTPUT(range3.str(), "123456")
            .CHECK_OUTPUT(range4.str(), "1.12.1");

      //CHEAK CHAIN:
        std::ostringstream chain1,chain2,chain3,chain4;
        for (char c : chain(range('E', 'H'), range('a', 'd')))
            chain1 << c;
        for (char c : chain(range('e', 'g'), string("wow")))
            chain2 << c;
            
        for (int i : chain(range(1, 5), range(5, 10)))
            chain3 << i ;
        for (double d : chain(range(1.5, 2.5), range(1.5, 3.5)))
            chain4 << d ;
      

        testcase.setname("Test chain")
            .CHECK_OUTPUT(chain1.str(), "EFGabc")
            .CHECK_OUTPUT(chain2.str(), "efwow")
            .CHECK_OUTPUT(chain3.str(), "123456789")
            .CHECK_OUTPUT(chain4.str(), "1.51.52.5")
           
            ;
//Test product
        std::ostringstream product1, product2;

        for (auto p : product(range(2,5), range(1,4)))
            product1 << p <<" ";

        for (auto p : product(range(1.2, 3.2), range(3.2, 5.2)))
            product2 << p << " ";

       
      
        testcase.setname("Test product")
            .CHECK_OUTPUT(product1.str(), "2,1 3,2 4,3 ")
            .CHECK_OUTPUT(product2.str(), "1.2,3.2 2.2,4.2 ")
            
        ;

        std::ostringstream powerset1, powerset2, powerset3;

    //Test powerset

        for (auto s : powerset(range(1, 3)))
            powerset1 << s << " ";
        for(auto s : powerset(range(1.3,3.3)))
            powerset2<<s<<" ";
        for(auto s : powerset(range('a','d')))
            powerset3<<s<<" ";    
    
        testcase.setname("Test powerset")
            .CHECK_OUTPUT(powerset1.str(), "{} {1} {2} {1,2} ")
            .CHECK_OUTPUT(powerset2.str(), "{} {1.3} {2.3} {1.3,2.3} ")
            .CHECK_OUTPUT(powerset3.str(), "{} {a} {b} {a,b} {c} {a,c} {b,c} {a,b,c} ")
         ;
//Test zip

        std::ostringstream zip1, zip2, zip3;
        for (auto p : zip(range(1, 2), range(1, 2)))
            zip1 << p << " ";

        for (auto p : zip(range(1.2, 2.2), range(2.2, 3.2)))
            zip2 << p << " ";

        for (auto p : zip(range('a', 'c'), range('d', 'f')))
            zip3 << p << " ";
        testcase.setname("Test zip")
            .CHECK_OUTPUT(zip1.str(), "1,1 ")
            .CHECK_OUTPUT(zip2.str(), "1.2,2.2 ")
            .CHECK_OUTPUT(zip3.str(), "a,d b,e ")
          ;
//test mix
        std::ostringstream mixed;

        for(auto s : product(zip(range(1,3),range(5,7)),zip(range(11,13),range(15,17)))) //(1,5 2,7) (11,15 13,16) 
            mixed<<s<<" ";
        testcase.setname("mix")
            .CHECK_OUTPUT(mixed.str(),"1,5,11,15 1,5,12,16 2,6,11,15 2,6,12,16 ")

            ;

        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }

    cout << "Your grade is: " << grade << endl;
    return 0;
}
