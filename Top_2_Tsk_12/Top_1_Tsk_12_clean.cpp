#include "Top_1_Tsk_12_clean.h"

CPoly2 :: CPoly2(int max_dim){
    int c1, c2;
    this->max_dim = max_dim;
    for(c1 = 0; c1 < this->max_dim; ++c1){
        std :: vector<int> temp;
        for(c2 = 0; c2 < this->max_dim; ++c2){
            temp.push_back(rand()%11);
        }
        matrix.push_back(temp);
    }
    return;
}



CData0  operator+(const CData0& obj1, const CData0& obj2){
    int dim_min, c1, c2;
    CData0 res((obj1.max_dim > obj2.max_dim ? obj1 : obj2));
    res.out_file = obj1.out_file;
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

CData0  operator-(const CData0& obj1, const CData0& obj2){
    int dim_min, c1, c2;
    CData0 res((obj1.max_dim > obj2.max_dim ? obj1 : obj2));
    res.out_file = obj1.out_file;
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
    this->out_file= out_file;
    return;
}


CData0 :: CData0(const CData1& obj): CPoly2(obj){
    this->out_file = obj.out_file;
    return;
}
/*
CData0& CData0 :: operator=(const CPoly2& obj){
    cout << "Cdata0 assignment called" << endl;
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    this->out_file = static_cast<const CData0&>(obj).out_file;
    return *this;
}
*/

/*
CData0& CData0 :: operator=(const CData1& obj){
    cout << "cdata0 assignment called" << endl;
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    this->out_file = obj.out_file;
    return *this;
}*/

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

int CData0 ::file_read(std :: istream& pf){
    int c1 = 0, c2 = 0;
    std :: string str;
    
    pf >> this->out_file ;
    std :: getline(pf, str);

    std :: stringstream ss(str);
    string str_num;
    int num;
    std :: vector <int> temp;
    while(ss >> str_num){ 
        try {
            num  = stoi(str_num);
            }
        catch (const std::invalid_argument& ia) {
            cout << "ERROR" << endl;
	        std::cerr << "Invalid argument: " << ia.what() << '\n';
            return -1;
        }
        temp.push_back(num);
    }
    this->max_dim = std::ceil(std::sqrt(temp.size()));
    for(c1 = 0; c1 < this->max_dim; ++c1){
        std :: vector <int> temp2;
        for(c2 = 0; c2 < this->max_dim; ++c2){
            if((int)temp.size() > (int)(c1 * this->max_dim + c2)){
                temp2.push_back(temp[c1 * this->max_dim + c2]);
            }
            else{
                temp2.push_back(0);
            }
//            cout << endl <<  temp2.size() << endl;
        }
        this->matrix.push_back(temp2);
    }
    return 1;
}

CData1 :: CData1(char* out_file, int max_dim): CPoly2(max_dim){
    this->out_file[0] = 0;
    this->out_file = out_file;
    return;
}


CData1 :: CData1(const CData0& obj): CPoly2(obj){
    this->out_file[0] = 0;
    this->out_file = obj.out_file;
    return;
}

/*
CData1& CData1 :: operator=(const CPoly2& obj){
    cout << "Cdata1 assignment called" << endl;
    CData1* other = static_cast<CData1*>(const_cast<CPoly2*>(&obj));
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    cout << "1 "<< static_cast<CData1*>(const_cast<CPoly2*>(&obj))->out_file << endl;
    this->out_file = other->out_file;
    return *this;
} */
/*
CData1& CData1 :: operator=(const CData0& obj){
    cout << "cdata1 assignment called" << endl;
    this->max_dim = obj.max_dim;
    this->matrix = obj.matrix;
    this->out_file = obj.out_file;
    return *this;
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

int CData1 ::file_read(std :: istream& pf){
    int c1 = 0, c2 = 0;
    std :: string str;
    pf >> this->out_file ;
    std :: getline(pf, str);
    std :: stringstream ss(str);
    int num;
    string str_num;
    std :: vector <int> temp;
    while(ss >> str_num){ 
        try {
            num  = stoi(str_num);
            }
        catch (const std::invalid_argument& ia) {
            cout << "ERROR" << endl;
	        std::cerr << "Invalid argument: " << ia.what() << '\n';
            return -1;
        }
        temp.push_back(num);
    }
    this->max_dim = std::ceil(std::sqrt(temp.size()));
    for(c1 = 0; c1 < this->max_dim; ++c1){
        std :: vector <int> temp2;
        for(c2 = 0; c2 < this->max_dim; ++c2){
            if((int)temp.size() > (int)(c2 * this->max_dim + c1)){
                temp2.push_back(temp[c2 * this->max_dim + c1]);
            }
            else{
                temp2.push_back(0);
            }
        }
        this->matrix.push_back(temp2);
    }
    return 1;
}

CPoly2* Factory (int stat, CPoly2** arr, int len, std :: istream& pf){
    if(stat == 0){
            arr[len - 1] = new CData0((char*)"qwerty.txt",0); // название файла в конструкторе ни на что не влияет, оно переписывается при чтении входного файла.
        }
    if(stat == 1){
        arr[len - 1] = new CData1((char*)"qwerty.txt", 0);
    }
    if(stat == 0 || stat == 1){
        if(arr[len - 1]->file_read(pf) < 0){
            delete arr[len-1];
            return NULL;
        }
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

    a1 = a2 + a3;    

    int stat = 0, len = 0, c;
    CPoly2** arr, **temp;// =  new CData0((char*)"qwerty.txt",3);
    std :: ifstream pf;
    pf.open("1.txt");

    if(!pf.is_open()){
        cout << "File does not exist!" << endl;
        return -1;
    }
    arr = new CPoly2*[1];
    pf >> stat;
    // считывание
    while(pf.peek() != EOF){
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
        CPoly2* flag = Factory(stat, arr, len, pf);
        delete[] temp;
        if(flag == NULL){
            cout << "something is wrong with the file!" << endl;
            len --;
            goto end;
        }
        
    pf >> stat;
    }
    for(c = 0; c < len; ++c){
        arr[c]->output();
    }
    //проверка суммы и инкремента/декремента
    if(len >= 3){
    //    *arr[2] = *arr[0] + *arr[1];
    //    --(*arr[1]);
    //    *arr[0] = (*arr[0])--;
        (*arr[2]) ++;
    }
    //печать
    for(c = 0; c < len; ++c){
        arr[c]->output();
    }
  
  // сдвиг
   {
    CData0 temp_2 = *static_cast<CData0*>(arr[0]);
    for(c = 1; c < len; ++c){
        *arr[c - 1] = *static_cast<CData0*>(arr[c]);
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
        pf.close();
        return 1;
}