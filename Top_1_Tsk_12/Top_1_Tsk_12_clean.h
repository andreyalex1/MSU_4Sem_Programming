#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

class CData0;
class CData1;

class CPoly2{
    protected:
        int** matrix;
        int max_dim;
        char out_file[100];
    public:
        CPoly2() = default; // used ONLY in dereived classes, do not use separately.
        CPoly2(int max_dim);    // allocates memory, fills with random numbers
        CPoly2(const CPoly2& obj);  // copy
        CPoly2(CPoly2&& obj);   // move
        virtual ~CPoly2();  //destructor
     //   virtual CPoly2& operator+(const CPoly2& obj) = 0;
     //   virtual CPoly2& operator-(const CPoly2& obj) = 0;
        virtual void operator=(const CPoly2& obj);  // copy assignment
        virtual void operator=(CPoly2&& obj);   // move assignment
        CPoly2& operator++();   //pre- increment
        CPoly2& operator--();
        virtual void file_read(FILE* pf) = 0;
        virtual void output() = 0;
        friend CData0  operator+(const CPoly2& obj1, const CPoly2& obj2);
        friend CData0  operator-(const CPoly2& obj1, const CPoly2& obj2);
        friend CData0 operator++(CPoly2& obj1, int N);
        friend CData0 operator--(CPoly2& obj1, int N);
/*        friend CData0 operator++(CData0& obj1, int N);
        friend CData0 operator--(CData0& obj1, int N);
        friend CData0 operator++(CData1& obj1, int N);
        friend CData0 operator--(CData1& obj1, int N);  */
};

class CData0 : public CPoly2{
    protected:
        
    public:
        CData0(char* out_file, int max_dim);
 //       CData0(const CData0& obj);
 //       CData0(const CData0&& obj);
 //       CData0(const CData1& obj);
 //       CData0(CData1&& obj);
        CData0(const CPoly2& obj): CPoly2(obj){this->out_file[0] = 0;};
 //       ~CData0()=default;
 //       void operator=(const CData0& obj);
 //       void operator=(CData0&& obj);
        void file_read(FILE* pf);
        void output();
        friend class CData1;
};

class CData1 : public CPoly2{
    protected:
 //       char out_file[100];
    public:
        CData1(char* out_file, int max_dim);
  //      CData1(const CData1& obj);
  //      CData1(const CData1&& obj);
   //     CData1(const CData0& obj);
   //     CData1(CData0&& obj);
        CData1(const CPoly2& obj): CPoly2(obj){this->out_file[0] = 0;};
   //     ~CData1()=default;
  //      void operator=(const CData1& obj);
  //      void operator=(CData1&& obj);
        void file_read(FILE* pf);
        void output();
        friend class CData0;
};