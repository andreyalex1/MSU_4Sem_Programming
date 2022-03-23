#include "Top_1_Tsk_12_clean.h"

CPoly2 :: CPoly2(int max_dim){
    int c1, c2;
    this->max_dim = max_dim;
    matrix = new int*[max_dim];
    for(c1 = 0; c1 < this->max_dim; ++c1){
        matrix[c1] = new int[max_dim];
        for(c2 = 0; c2 < this->max_dim; ++c2){
            matrix[c1][c2] = rand()%11;
        }
    }
    return;
}

CPoly2 :: CPoly2(const CPoly2& obj){
    int c1, c2;
 //   cout << "Base copy constructor called!" << endl;
    this->max_dim = obj.max_dim;
    matrix = new int*[max_dim];
    for(c1 = 0; c1 < this->max_dim; ++c1){
        matrix[c1] = new int[max_dim];
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] = obj.matrix[c1][c2];
  //          cout << this->matrix[c1][c2] << " ";
        }
    }
//    cout << endl;
    return;
}

CPoly2 :: CPoly2(CPoly2&& obj){
    std::cout << "Base move constructor called!" << endl;
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    obj.matrix = NULL;
    obj.max_dim = 0;
    return;
}

CPoly2 :: ~CPoly2(){
    int c;
    if(this->matrix != NULL){
        for(c = 0; c< this->max_dim; ++c){
            if(this->matrix[c] != NULL){
                delete[] this->matrix[c];
            }
        }
        delete[] this->matrix;
    }
    return;
}

CData0  operator+(const CPoly2& obj1, const CPoly2& obj2){
    int dim_min, c1, c2;
    CData0 res((obj1.max_dim > obj2.max_dim ? obj1 : obj2));
    if( obj1.max_dim < obj2.max_dim){
        dim_min = obj1.max_dim;
    }
    else{
        dim_min = obj2.max_dim;
    }
    for(c1 = 0; c1 < dim_min; ++c1){
        for(c2 = 0; c2 < dim_min; ++c2){
            res.matrix[c1][c2] = obj1.matrix[c1][c2] + obj2.matrix[c1][c2];
        }
    }
    return res;
}

CData0  operator-(const CPoly2& obj1, const CPoly2& obj2){
    int dim_min, c1, c2;
    CData0 res((obj1.max_dim > obj2.max_dim ? obj1 : obj2));
    if( obj1.max_dim < obj2.max_dim){
        dim_min = obj1.max_dim;
    }
    else{
        dim_min = obj2.max_dim;
    }
    for(c1 = 0; c1 < dim_min; ++c1){
        for(c2 = 0; c2 < dim_min; ++c2){
            res.matrix[c1][c2] = obj1.matrix[c1][c2] - obj2.matrix[c1][c2];
        }
    }
    return res;
}

CData0 operator++(CPoly2& obj1, int){
    CData0 temp(static_cast<CData0&> (obj1));
    ++obj1;
    return temp;
}

CData0 operator--(CPoly2& obj1, int){
    CData0 temp (static_cast<CData0&> (obj1));
    --obj1;
    return temp;
}

void CPoly2 :: operator=(const CPoly2& obj){
    int c1, c2;
    if(this->matrix != NULL){
        for(c1 = 0; c1 < this->max_dim; ++c1){
            if(this->matrix[c1] != NULL){
                delete[] this->matrix[c1];
            }
        }
        delete[] this->matrix;
    }
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

void CPoly2 :: operator=(CPoly2&& obj){
    std::cout << "move assignment called!" << endl;
    int c1;//, c2;
 //   cout << "Move base called!" << endl;
    if(this->matrix != NULL){
        for(c1 = 0; c1 < this->max_dim; ++c1){
            if(this->matrix[c1] != NULL){
                delete[] this->matrix[c1];
            }
        }
        delete[] this->matrix;
    }
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    obj.matrix = NULL;
    obj.max_dim = 0;
    return;
}

CPoly2& CPoly2 :: operator++(){
    int c1,c2;
//    cout << "max_dim = " << this->max_dim << endl;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] *= c2;
        }
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim - 1; ++c2){
            this->matrix[c1][c2] = this->matrix[c1][c2 + 1];
        }
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        this->matrix[c1][this->max_dim - 1] = 0;
    }
    return *this;
}

CPoly2& CPoly2 :: operator--(){
    int c1,c2;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] *= c1;
        }
    }
    for(c1 = 0; c1 < this->max_dim - 1; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            this->matrix[c1][c2] = this->matrix[c1 + 1][c2];
        }
    }
    for(c1 = 0; c1 < this->max_dim; ++c1){
        this->matrix[this->max_dim - 1][c1] = 0;
    }
    return *this;
}
 
CData0 :: CData0(char* out_file, int max_dim): CPoly2(max_dim){
    this->out_file[0] = 0;
    strcpy(this->out_file, out_file);
    return;
}
/*
CData0 :: CData0(const CData0& obj): CPoly2(obj){
    this->out_file[0] = 0;
    strcpy(this->out_file, obj.out_file);
    cout << obj.out_file << endl;
    return;
}

CData0 :: CData0(const CData1& obj): CPoly2(obj){
    strcpy(this->out_file, obj.out_file);
    return;
}

CData0 :: CData0(CData1&& obj): CPoly2(std::move(obj)){
    cout << "Move conversion called!" << endl;
  //  this->max_dim = obj.max_dim;
  //  this->matrix = obj.matrix;
  //  obj.matrix = NULL;
  //  obj.max_dim = 0;
    strcpy(this->out_file, obj.out_file);
    return;
}

CData0 :: CData0(const CData0&& obj): CPoly2(obj){
    this->out_file[0] = 0;
//    cout << obj.out_file << endl;
    if(obj.out_file != NULL && obj.out_file != NULL){
        strcpy(this->out_file, obj.out_file);
    }
    return;
}



void CData0 :: operator=(const CData0& obj){
    this->out_file[0] = 0;
    CPoly2::operator=(obj);
    strcpy(this->out_file, obj.out_file);
}

void CData0 :: operator=(CData0&& obj){
    this->out_file[0] = 0;
    CPoly2::operator=(obj);
    strcpy(this->out_file, obj.out_file);
}
*/
void CData0 :: output(){
    int c1,c2;
 //   cout << this->out_file << endl;
    ofstream pf;
    pf.open(this->out_file, std::ofstream::app);
    for(c1 = 0; c1 < this->max_dim; ++c1){
        for(c2 = 0; c2 < this->max_dim; ++c2){
            pf << this->matrix[c1][c2] << " ";
        }
    }
    pf << endl;
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
    this->out_file[0] = 0;
    strcpy(this->out_file, out_file);
    return;
}

/*
CData1 :: CData1(const CData1& obj): CPoly2(obj){
    this->out_file[0] = 0;
    strcpy(this->out_file, obj.out_file);
    std::cout << obj.out_file << endl;
    return;
}



CData1 :: CData1(const CData1&& obj): CPoly2(obj){
    this->out_file[0] = 0;
    strcpy(this->out_file, obj.out_file);
    return;
}

CData1 :: CData1(const CData0& obj): CPoly2(obj){
    this->out_file[0] = 0;
    strcpy(this->out_file, obj.out_file);
    return;
}

CData1 :: CData1( CData0&& obj): CPoly2(obj){
    cout << "Move conversion called!" << endl;
    this->out_file[0] = 0;
    strcpy(this->out_file, obj.out_file);
    return;
}


void CData1 :: operator=(const CData1& obj){
    this->out_file[0] = 0;
    CPoly2::operator=(obj);
    strcpy(this->out_file, obj.out_file);
}

void CData1 :: operator=(CData1&& obj){
 //   cout << "CData1  move assignment called!" << endl;
    this->out_file[0] = 0;
    CPoly2::operator=(obj);
    strcpy(this->out_file, obj.out_file);
}
*/


void CData1 :: output(){
    int c1,c2;
 //   cout << this->out_file << endl;
    ofstream pf;
    pf.open(this->out_file, std::ofstream::app);
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

CPoly2* Factory (int stat, CPoly2** arr, int len, FILE* pf, int polylen){
    if(stat == 0){
            arr[len - 1] = new CData0((char*)"qwerty.txt",polylen); // название файла в конструкторе ни на что не влияет, оно переписывается при чтении входного файла.
        }
    if(stat == 1){
        arr[len - 1] = new CData1((char*)"qwerty.txt",polylen);
    }
    if(stat == 0 || stat == 1){
        arr[len - 1]->file_read(pf);
        return arr[len - 1];
    }
    return NULL;
}

int main (void){
CPoly2 *a= new CData0((char *)"0.txt",3);
CPoly2* b=new CData1((char *)"00.txt",2);
a->output();
//cout << "123" << endl;
((*a)++).output();
*a=*b;
a->output();
b->output();
(++*b).output();
delete a;delete b;
CData1 a1((char *)"q.txt",3);
CData0 a2((char *)"q.txt",3); 
CData1 a3((char *)"q.txt",3); 

/* ПРОВЕРИМ ПРЕОБРАЗОВАНИЕ ПЕРЕМЕЩЕНИЕМ МЕЖДУ ДОЧЕРНИМИ КЛАССАМИ  */
cout << "<-- TESTING MOVE CONVERSION! -->" << endl;
// Оператор сложения определен только для двух объектов одного дочернего класса, 
// при сложении объектов разных классов производится преобразование пермещением, оно быстрее чем обычный конструктор.
// то есть следующая строчка эквивалентна a1 = a2 + CData0(a3);
a1 = a2 + a3;    
cout << "<-- MOVE CONVERSION TESTED! -->" << endl;
/* ПРОВЕРЕНО */

    int stat = 0, len = 0, c, scan_stat, polylen = 0;
    CPoly2** arr, **temp;// =  new CData0((char*)"qwerty.txt",3);
    FILE* pf = fopen("1.txt", "r");
    if(pf == NULL){
        cout << "File does not exist!" << endl;
        return -1;
    }
    fscanf(pf, "%d", &polylen);
    arr = new CPoly2*[1];
    scan_stat = fscanf(pf, "%d", &stat) ;
    cout << scan_stat << endl;
    // считывание
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
        CPoly2* flag = Factory(stat, arr, len, pf, polylen);
        delete[] temp;
        if(flag == NULL){
            cout << "something is wrong with the file!" << endl;
            len --;
            goto end;
        }
        
    scan_stat = fscanf(pf, "%d", &stat) ;
    }
    for(c = 0; c < len; ++c){
        arr[c]->output();
    }
    //проверка суммы и инкремента/декремента
    if(len >= 3){
        *arr[2] = *arr[0] + *arr[1];
        --(*arr[1]);
        *arr[0] = (*arr[0])--;
    }
    //печать
    for(c = 0; c < len; ++c){
        arr[c]->output();
    }
  
  // сдвиг
   {
    CData0 temp_2 ( *arr[0]);
    for(c = 1; c < len; ++c){
        *arr[c - 1] = *arr[c];
    }
    *arr[len - 1] = temp_2;
   }
    //печать
    for(c = 0; c < len; ++c){
        arr[c]->output();
    }
    end:
        for(c = 0; c < len; ++c){
            delete arr[c];
        }
        delete[] arr;
        fclose(pf);
        return 1;
}