#include <iostream> 
using namespace std;

class Retangle{ 
    int width, height;
    public: 
        void setValues(int width, int height);
        int area(){
            return width*height;
        }
};

void Retangle::setValues(int w, int h){
    width = w;
    height = h;
}

int main(){
    Retangle r;
    r.setValues(2,3);
    cout<<"area: "<<r.area();
    return 0;
}