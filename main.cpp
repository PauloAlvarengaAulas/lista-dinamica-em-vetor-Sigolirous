#include <iostream>
using namespace std;
#define TAM 20
template <class T>
class List{
    private:
        T *vec;
        int lenght, end;
    public: 
        List(const int &size){
            lenght = size;
            vec = new T[lenght];
            end = -1;
        }
        ~List(){
            delete [] vec;
        }
        bool append(const T &value){
            if(end<lenght-1){
                ++end;
                vec[end]=value;
                return true;
            }else{
                return false;
            }
        }
        bool put(const T &value){
            if(end<lenght-1){
                int adjust = end;
                while(adjust >= 0){
                    vec[adjust+1] = vec[adjust];
                    adjust--;
                }
                vec[0] = value;
                end++;
                return true;
            }else{
                return false;
            }
        }
        bool putMd(const T &value, const int &position){
            if(end<lenght-1){
                int adjust = end;
                while(adjust >= position){
                    vec[adjust+1] = vec[adjust];
                    adjust--;
                }
                vec[position] = value;
                end++;
                return true;
            }else{
                return false;
            }
        }
        bool pop(){
            if(end == -1){
                return false;
            }else{
                end--;
                return true;
            }
        }
        bool popBg(){
           if(end<lenght-1){
                for(int i = 0; i < end; i++){
                    vec[i] = vec[i+1];
                }
                end--;
                return true;
            }else{
                return false;
            }            
        }
        bool popMd(int const &pos){
            if(end>pos){
                for(int i = pos; i < end; i++){
                    vec[i] = vec[i+1];
                }
                end--;
                return true;                
            }else{
                return false;
            }
        }        
        void show(){
            cout<<"[";
            for(int i = 0; i <= end; i++){
                cout<<" "<<vec[i];
            }
            cout<<" ]"<<endl;
        }
        T showMd(int const &pos){
            if(pos<end){
                return vec[pos];
            }else{
                cout<<"Dont exist"<<endl;
            }
            
        }
        int length(){
            return end;
        }
};


int main(){
    List<int> L(20);
    for(int i = 0; i<19; i++){
        L.append(i);
    }
    L.show();
    L.popBg();
    L.popMd(3);
    L.show();
    L.showMd(0);
    cout<<L.length()<<endl;
    return 0;
}