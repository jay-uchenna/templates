//
//  main.cpp
//  template_learning
//
//  Created by Jedidiah Uchenna on 04.01.2022.
//
#include <iostream>
#include <string>

template <typename T>


class simple_vector{
    private:
        T *item;
        int size;
        int num_elements;
    public:
        simple_vector(int size);
        simple_vector():simple_vector(3){
        }
        void clear_sv();
        void push_back(T );
        int get_size() const;
        int get_num_elements() const;
        T& operator[](int );
        template <typename U>
        friend std::ostream& operator<<(std::ostream&, const simple_vector<U>&);
        ~simple_vector(){
            delete [] this->item;
        }
        simple_vector& operator=(const simple_vector<T>& );
        simple_vector (const simple_vector& );
    };
template <typename T>
simple_vector<T>::simple_vector(int size){
            this->size = size;
            this->num_elements = 0;
            this ->item = new T [this->size];
        }
template <typename T>
void simple_vector<T>::clear_sv(){
            delete [] this->item;
            this->size = 3;
            this->num_elements = 0;
            this ->item = new T[this->size];
        }
template <typename T>
simple_vector<T>& simple_vector<T>::operator=(const simple_vector<T>& sv){
            if(this != &sv){
                delete [] this->item;
                this->item = new T [sv.size];
                this-> size = sv.size;
                this-> num_elements = sv.num_elements;
                for(int i = 0; i < this->size; i++){
                    this->item[i] = sv.item[i];
                }
            }
            return *this;
        }
template <typename T>
void simple_vector<T>::push_back(T v){
    if(this->num_elements >= this->size){
        int new_size = this->size * 2;
        T *temp = new T [new_size];
        for(int i = 0; i < this->num_elements; i++){
            temp[i] = this->item[i];
        }
        delete [] this->item;
        this->item = temp;
        this->size = new_size;
    }
    item[num_elements++] = v;
}
template <typename T>
int simple_vector<T>::get_size() const{
    return this->size;
}
template <typename T>
int simple_vector<T>::get_num_elements() const{
    return this ->num_elements;
}
template <typename T>
T& simple_vector<T>::operator[](int index){
    return this->item[index];
}
template <typename U>
std::ostream& operator<<(std::ostream& out, const simple_vector<U>& sv){
    out << "[ ";
    for (int i = 0; i < sv.num_elements; i++){
       out << sv.item[i] << " ";
    }
    out << "]\n";
    return out;
}
template <typename T>
simple_vector<T>::simple_vector (const simple_vector& sv){
            this->item = new T [sv.size];
            this-> size = sv.size;
            this-> num_elements = sv.num_elements;
            for(int i = 0; i < this->size; i++){
                this->item[i] = sv.item[i];
            }
        }

int main()
{
    
    simple_vector <int> nigeria(4);
    
    nigeria.push_back(1);
    nigeria.push_back(33);
    nigeria.push_back(0);
    nigeria.push_back(5);
    nigeria.push_back(2);
    nigeria.push_back(8);
    nigeria.push_back(0);
    nigeria.push_back(444);
    nigeria.push_back(554);
    nigeria.push_back(23);
    nigeria.push_back(5);
    nigeria.push_back(66);
    nigeria.push_back(0);
    nigeria.push_back(34);
    nigeria.push_back(633);
    nigeria.push_back(34);
    nigeria.push_back(344);
    nigeria.push_back(343);
    nigeria.push_back(34);
    nigeria.push_back(34222);

    std::cout << "size: " << nigeria.get_size() << "  num_elements: " << nigeria.get_num_elements() << "\n";
    std::cout << "nigeria[7]: " << nigeria[7]<< "\n";
    nigeria[7] = -45;
    std::cout << "nigeria[7]: " << nigeria[7]<< "\n";
    std::cout << nigeria;

    simple_vector<int> france;
    std::cout << "france size: " << france.get_size() << " france num_elements: " << france.get_num_elements() << "\n";
    france = nigeria;

    nigeria.clear_sv();

    std::cout << "size: " << nigeria.get_size() << "  num_elements: " << nigeria.get_num_elements() << "\n";


    std::cout << "france size: " << france.get_size() << " france num_elements: " << france.get_num_elements() << "\n";
    std::cout << "france[7]: " << france[7]<< "\n";
    france[7] = -45;
    std::cout << "france[7]: " << france[7]<< "\n";
    std::cout << france;

    simple_vector<std::string> jack;

    jack.push_back("im in love");
    jack.push_back("darling");

    std::cout << jack;

    return 0;
}

 
