#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

/*
template <class datatype>
class Tensor{
    protected:
        datatype* arr;
        long int len;
    public:
        Tensor(long int len);
        Tensor(const Tensor& obj);
        Tensor(const Tensor&& obj);
        ~Tensor();
        Tensor& operator=(const Tensor& obj);
        Tensor& operator+(const datatype& value);
        Tensor& operator-(const datatype& value);
        Tensor& operator*(const datatype& value);
        Tensor& operator/(const datatype& value);
        Tensor& operator+(const Tensor<datatype>& obj);
        Tensor& operator-(const Tensor<datatype>& obj);
        Tensor& operator*(const Tensor<datatype>& obj);
        Tensor& operator/(const Tensor<datatype>& obj);
        datatype& operator[](long value);
};

template <class datatype>
Tensor<datatype> :: Tensor(long int len){
    this->len = len;
    this->arr = new datatype[len];
    return;
}

template <class datatype>
Tensor<datatype> :: Tensor(const Tensor& obj){
    int c;
    this->len = obj.len;
    this->arr = new datatype[len];
    for(c = 0; c < this->len; ++c){
        this->arr[c] = obj.arr[c];
    }
    return;
}

template <class datatype>
Tensor<datatype> :: Tensor(const Tensor&& obj){
    int c;
    this->len = obj.len;
    this->arr = obj.arr;
    return;
}

template <class datatype>
Tensor<datatype> :: ~Tensor(){
    delete[] this->arr;
    this=> len = 0;
    return;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator+(const datatype& value){
    int c;
    for(c = 0; c < this->len; ++c){
        this->arr[c] += value;
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator-(const datatype& value){
    int c;
    for(c = 0; c < this->len; ++c){
        this->arr[c] -= value;
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator*(const datatype& value){
    int c;
    for(c = 0; c < this->len; ++c){
        this->arr[c] *= value;
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator/(const datatype& value){
    int c;
    for(c = 0; c < this->len; ++c){
        this->arr[c] /= value;
    }
    return *this;
}
//1234
template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator+(const Tensor<datatype>& obj){
    int c;
    if(obj->len != this->len){
        cout <<"Objects are of different lengths!" << endl;
        return *this;
    }
    for(c = 0; c < this->len; ++c){
        this->arr[c] += obj->arr[c];
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator-(const Tensor<datatype>& obj){
    int c;
    if(obj->len != this->len){
        cout <<"Objects are of different lengths!" << endl;
        return *this;
    }
    for(c = 0; c < this->len; ++c){
        this->arr[c] -= obj->arr[c];
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator*(const Tensor<datatype>& obj){
    int c;
    if(obj->len != this->len){
        cout <<"Objects are of different lengths!" << endl;
        return *this;
    }
    for(c = 0; c < this->len; ++c){
        this->arr[c] *= obj->arr[c];
    }
    return *this;
}

template <class datatype>
Tensor<datatype>& Tensor<datatype> :: operator/(const Tensor<datatype>& obj){
    int c;
    if(obj->len != this->len){
        cout <<"Objects are of different lengths!" << endl;
        return *this;
    }
    for(c = 0; c < this->len; ++c){
        this->arr[c] /= obj->arr[c];
    }
    return *this;
}
//1234
template <class datatype>
datatype& Tensor<datatype> :: operator[](long index){
    return this->arr[index];
}


*/

class CPoly2{
    protected:
        int** matrix;
        int max_dim;
    public:
        CPoly2(int max_dim);
        CPoly2(const CPoly2& obj);
        CPoly2(const CPoly2&& obj);
        virtual ~CPoly2();
        CPoly2 operator+(const CPoly2& obj);
        CPoly2 operator-(const CPoly2& obj);
        void operator=(const CPoly2& obj);
        CPoly2& operator++();
        CPoly2& operator--();
        virtual void file_read(FILE* pf);
        virtual void output();
};

class CData0 : public CPoly2{
    protected:
        char out_file[100];
    public:
        CData0(char* out_file, int max_dim);
        CData0(const CData0& obj);
        CData0(const CData0&& obj);
        ~CData0()=default;
        void file_read(FILE* pf);
        void output();
};

class CData1 : public CPoly2{
    protected:
        char out_file[100];
    public:
        CData1(char* out_file, int max_dim);
        CData1(const CData1& obj);
        CData1(const CData1&& obj);
        ~CData1()=default;
        void file_read(FILE* pf);
        void output();
};

CPoly2 :: CPoly2(int max_dim){
    int c;
    this->max_dim = max_dim;
    matrix = new int*[max_dim];
    for(c = 0; c < this->max_dim; ++c){
        matrix[c] = new int[max_dim];
    }
    return;
}

CPoly2 :: CPoly2(const CPoly2& obj){
    int c1, c2;
    this->max_dim = obj.max_dim;
    matrix = new int*[max_dim];
    for(c1 = 0; c1 < this->max_dim; ++c1){
        matrix[c1] = new int[max_dim];
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] = obj.matrix[c1][c2];
        }
    }
    return;
}

CPoly2 :: CPoly2(const CPoly2&& obj){
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    return;
}

CPoly2 :: ~CPoly2(){
    int c;
 //   this->max_dim = 0;
    for(c = 0; c < this->max_dim; ++c){
        delete[] matrix[c];
    }
    delete[] matrix;
    return;
}

CPoly2 CPoly2 :: operator+(const CPoly2& obj){
    int dim_min, c1, c2;
    CPoly2 res((this->max_dim > obj.max_dim ? *this : obj));
    if( this->max_dim < obj.max_dim){
        dim_min = this->max_dim;
    }
    else{
        dim_min = obj.max_dim;
    }
    for(c1 = 0; c1 < dim_min; ++c1){
        for(c2 = 0; c2 < dim_min; ++c2){
            res.matrix[c1][c2] = this->matrix[c1][c2] + obj.matrix[c1][c2];
        }
    }
    return res;
}

CPoly2 CPoly2 :: operator-(const CPoly2& obj){
    int dim_min, c1, c2;
    CPoly2 res((this->max_dim > obj.max_dim ? *this : obj));
    if( this->max_dim < obj.max_dim){
        dim_min = this->max_dim;
    }
    else{
        dim_min = obj.max_dim;
    }
    for(c1 = 0; c1 < dim_min; ++c1){
        for(c2 = 0; c2 < dim_min; ++c2){
            res.matrix[c1][c2] = this->matrix[c1][c2] - obj.matrix[c1][c2];
        }
    }
    return res;
}

void CPoly2 :: operator=(const CPoly2& obj){
    int c1, c2;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        delete[] this->matrix[c1];
    }
    delete[] this->matrix;
    this->max_dim = obj.max_dim;
    matrix = new int*[max_dim];
    for(c1 = 0; c1 < this->max_dim; ++c1){
        matrix[c1] = new int[max_dim];
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] = obj.matrix[c1][c2];
        }
    }
    return;
}

CPoly2& CPoly2 :: operator++(){
    int c1,c2;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] *= c1;
        }
    }
    return *this;
}

CPoly2& CPoly2 :: operator--(){
    int c1,c2;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c2][c1] *= c1;
        }
    }
    return *this;
}

void CPoly2 :: output(){
    cout << "Oops, called output of the base class!" << endl;
    return;
}

void CPoly2 :: file_read(FILE* pf){
    pf = pf;
    cout << "Oops, called file_read of the base class!" << endl;
    return;
}

CData0 :: CData0(char* out_file, int max_dim): CPoly2(max_dim){
    strcpy(this->out_file, out_file);
    return;
}

CData0 :: CData0(const CData0& obj): CPoly2(obj){
    strcpy(this->out_file, obj.out_file);
    return;
}

CData0 :: CData0(const CData0&& obj): CPoly2(obj){
    strcpy(this->out_file, obj.out_file);
    return;
}

/*
CData0 :: ~CData0(){
    int c;
 //   this->max_dim = 0;
    for(c = 0; c < this->max_dim; ++c){
        delete[] matrix[c];
    }
    delete[] matrix;
    return;
}
*/
void CData0 :: output(){
    int c1,c2;
    ofstream pf;
    pf.open(this->out_file);
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            pf << this->matrix[c1][c2] << " ";
        }
    }
    pf.close();
    return;
}

void CData0 ::file_read(FILE* pf){
    int c1, c2;
    fscanf(pf,"%s", this->out_file);
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            fscanf(pf, "%d", &(this->matrix[c1][c2]));
        }
   //     fprintf(pf, "\n");
    }
    return;
}

CData1 :: CData1(char* out_file, int max_dim): CPoly2(max_dim){
    strcpy(this->out_file, out_file);
    return;
}

CData1 :: CData1(const CData1& obj): CPoly2(obj){
    strcpy(this->out_file, obj.out_file);
    return;
}

CData1 :: CData1(const CData1&& obj): CPoly2(obj){
    strcpy(this->out_file, obj.out_file);
    return;
}

void CData1 :: output(){
    int c1,c2;
    ofstream pf;
    pf.open(this->out_file);
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            pf << this->matrix[c2][c1] << " ";
        }
    }
    pf << endl;
    pf.close();
    return;
}

void CData1 ::file_read(FILE* pf){
    int c1, c2;
    fscanf(pf,"%s", this->out_file);
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            fscanf(pf, "%d", &(this->matrix[c2][c1]));
        }
      //  fprintf(pf, "\n");
    }
    return;
}

int main (void){
    int stat = 0, len = 0, c, scan_stat;
    CPoly2** arr, **temp;// =  new CData0((char*)"qwerty.txt",3);
    FILE* pf = fopen("1.txt", "r");
    if(pf == NULL){
        cout << "File does not exist!" << endl;
        return -1;
    }
    arr = new CPoly2*[1];
    scan_stat = fscanf(pf, "%d", &stat) ;
    cout << scan_stat << endl;
    while(scan_stat != EOF && scan_stat > 0){
        len++;
        temp = new CPoly2*[len - 1];
        for(c = 0; c < len - 1;++c){
            temp[c] = arr[c];
        }
        delete[] arr;
        arr = new CPoly2*[len];
        for(c = 0; c < len - 1;++c){
            arr[c] = temp[c];
        }
        delete[] temp;
        if(stat == 0){
            arr[len - 1] = new CData0((char*)"qwerty.txt",3); // название файла в конструкторе ни на что не влияет, оно переписывается при чтении файла.
        }
        if(stat == 1){
            arr[len - 1] = new CData1((char*)"qwerty.txt",3);
        }
        arr[len - 1]->file_read(pf);
    scan_stat = fscanf(pf, "%d", &stat) ;
    }
    if(len >= 3){
        *arr[2] = *arr[0] + *arr[1];
        ++(*arr[0]);
        --(*arr[1]);
        CPoly2 tester( *(arr[0]));
        tester.output();
    }
    for(c = 0; c < len; ++c){
        arr[c]->output();
        delete arr[c];
    }
    delete[] arr;
    fclose(pf);
    return 1;
}