#include <iostream>
#include <stdio.h>
using namespace std;

class Child;

class Base{
    protected:
        int* arr;
        int len;
    public:
        Base(int len){
            int c;
            arr = new int[len];
            this->len = len;
            for(c = 0; c < this->len ;++c){
                this->arr[c] = rand()%11;
            }
        }
        Base(const Base& obj){
            int c;
            this->len = obj.len;
            this->arr = new int[obj.len];
            for(c = 0; c < obj.len; ++c){
                this->arr[c] = obj.arr[c];
            }
        }
        Base(Base&& obj){
            this->len = obj.len;
            this->arr = obj.arr;
            obj.arr = 0;
            obj.len = 0;
        }
        virtual ~Base(){
            if(this->arr != NULL){
                delete[] this->arr;
            }
            this->len = 0;
        }
        int& operator[](int index){
            return this->arr[index];
        }
        Base& operator++(){
            int c;
            int* temp = new int[this->len];
            for( c = 0; c < this->len; ++c){
                temp[c] = this->arr[c];
            }
            delete[] this->arr;
            this->arr = new int[this->len * 2];
            for(c = 0; c < this->len * 2; ++c){
                this->arr[c] = temp[c % this->len];
            }
            delete[] temp;
            return *this;
        }
        friend Child operator++(Child obj, int);
        friend Child operator+(const Child& obj1, const Child& obj2);
        virtual bool test(int value){
            if(value % 2 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int Len(){
            return this->len;
        }
        void invert(){
            int c1 = 0, c2 = this->len - 1, temp;
            while(c1 <= c2){
                while(c1 < this->len && this->test(this->arr[c1]) <= 0){
                    c1++;
                }
                while(c2 >= 0 && this->test(this->arr[c2]) <= 0){
                    c2--;
                }
                if(c1 <= c2){
                    temp = this->arr[c1];
                    this->arr[c1] = this->arr[c2];
                    this->arr[c2] = temp;
                }
                c1++;
                c2--;
            }
            
        }
};

class Child: public Base{
    public:
        Child(int len):Base(len){};
        Child(const Base& obj): Base(obj){};
        ~Child(){};

        bool test(int value){
            if(value % 2 == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
};

Child operator++(Child obj, int){
    Child temp (obj);
    ++obj;
    return temp;
}

Child operator+(const Child& obj1, const Child& obj2){
    int c, min_len;
    Child res(obj1.len < obj2.len ? obj2.len : obj1.len);
    min_len = obj1.len > obj2.len ? obj2.len : obj1.len;
    for(c = 0; c < min_len; ++c){
        res[c] = obj2.arr[c] + obj1.arr[c];
    }
    return res;
}



int main(void){
    int c;
    Base* v = new Child(Base(10) + Child(Base(17)) + (Child(5)++) +  ++Base(5));
    for(c = 0 ; c < v->Len(); ++c){
        cout << (*v)[c] << " ";
    }
    cout << endl;
   // cout << v->Len() << endl;
    delete v;
    Base obj1(12);
    for(c = 0 ; c < obj1.Len(); ++c){
        cout << obj1[c] << " ";
    }
    cout << endl;
    obj1.invert();
    for(c = 0 ; c < obj1.Len(); ++c){
        cout << obj1[c] << " ";
    }
    cout << endl;
    Child obj2(obj1);
    for(c = 0 ; c < obj2.Len(); ++c){
        cout << obj2[c] << " ";
    }
    cout << endl;
    obj2.invert();
    for(c = 0 ; c < obj2.Len(); ++c){
        cout << obj2[c] << " ";
    }
    cout << endl;
}