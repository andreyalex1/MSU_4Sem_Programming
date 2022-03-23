#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class CData0;
class CData1;

class CPoly2{
    protected:
        std :: vector<std::vector<int>> matrix;
        std :: string out_file;
        int max_dim;
    public:
        CPoly2() = default; // used ONLY in dereived classes, do not use separately.
        CPoly2(int max_dim);    // allocates memory, fills with random numbers
//        CPoly2(const CPoly2& obj) = default;  // copy
        virtual ~CPoly2() = default;  //destructor
//        virtual CPoly2& operator=(const CPoly2& obj) = default;  // copy assignment
        CPoly2& operator++();   //pre- increment
        CPoly2& operator--();
        virtual int file_read(std :: istream& pf) = 0;
        virtual void output() = 0;
        friend CData0  operator+(const CData0& obj1, const CData0& obj2);
        friend CData0  operator-(const CData0& obj1, const CData0& obj2);
        friend CData0 operator++(CPoly2& obj1, int N);
        friend CData0 operator--(CPoly2& obj1, int N);
        friend class CData0;
        friend class CData1;
};

class CData0 : public CPoly2{
    protected:
 //       std :: string out_file;
    public:
        CData0(char* out_file, int max_dim);
        CData0(const CData0& obj) = default;
        CData0(const CData1& obj);
        CData0(const CPoly2& obj): CPoly2(obj){this->out_file[0] = 0;};
        ~CData0()=default;
   //     CData0& operator=(const CPoly2& obj) override;
        CData0& operator=(const CData0& obj) = default;
 //       CData0& operator=(const CData1& obj) ;
        int file_read(std :: istream& pf);
        void output();
        friend class CData1;
        friend CData0  operator+(const CData0& obj1, const CData0& obj2);
        friend CData0  operator-(const CData0& obj1, const CData0& obj2);
};

class CData1 : public CPoly2{
    protected:
        
    public:
        CData1(char* out_file, int max_dim);
        CData1(const CData1& obj) = default;
        CData1(const CData0& obj);
        ~CData1()=default;
//        CData1& operator=(const CPoly2& obj) override;
        CData1& operator=(const CData1& obj) = default;
  //      CData1& operator=(const CData0& obj) ;
        int file_read(std :: istream& pf);
        void output();
        friend class CData0;
        friend CData0  operator+(const CData0& obj1, const CData0& obj2);
        friend CData0  operator-(const CData0& obj1, const CData0& obj2);
};