#include <iostream>
using namespace std;

class Vec3D {

private:
    float x;
    float y;
    float z;

public:

    //constructor with default value initlization
    Vec3D(): x(0.0), y(0.0), z(0.0) {}
    //constructor in case of values given
    Vec3D(float axisone, float axistwo, float axisthree): x(axisone), y(axistwo), z(axisthree){}
    
    //getter methods to access private instance variables
    float getX() const{
        return x;
    }

    float getY() const{
        return y;
    }
    
    float getZ() const{
        return z;
    }


    //overload + operator
    Vec3D operator+ (const Vec3D second)const{
        Vec3D sum;
        sum.x = x + second.x;
        sum.y = y + second.y;
        sum.z = z + second.z;

        return sum;

    }

    //overload * operator with scalar value an integer
    Vec3D operator*(int scalar) const{
        Vec3D answer;
        answer.x = x * (float)scalar;
        answer.y = y * (float)scalar;
        answer.z = z * (float)scalar;

        return answer;
    }

    //overload * operator with scalar value a decimal
    Vec3D operator* (float scalar) const{
        Vec3D answer;
        answer.x = x * scalar;
        answer.y = y * scalar;
        answer.z = z * scalar;

        return answer;
    }

    

    //overload unary operator -
    Vec3D operator- () const{
        Vec3D invert;
        invert.x = -1.0 * x;
        invert.y = -1.0 * y;
        invert.z = -1.0 * z;

        return invert;
    }

    /*
    //overload unary operator - using the 'this' keyword
    Vec3D operator- (){
        this->x = -1.0 * this->x;
        this->y = -1.0 * this->y;
        this->z = -1.0 * this->z;

        return this;
    }
    */


};

//overload '<<' operator in case of using cout
std::ostream& operator<<(std::ostream& stream, const Vec3D& vec){
    stream << vec.getX() << ", "<< vec.getY() << ", " << vec.getZ();
    return stream;
}

int main(){

    const Vec3D a(1.0, 2.0, 3.0);
    const Vec3D b(2.0, 1.5, -1.2);
    Vec3D c = a + b;
    Vec3D d = a * 2;
    Vec3D e = -b;

    cout << a+b << endl;
    cout << d << endl;
    cout << e;


}