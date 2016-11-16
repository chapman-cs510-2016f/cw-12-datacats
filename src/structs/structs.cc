#include <iostream>
#include "structs.h"

using namespace std;

int main(void)
{
    // The default constructor for a struct just zeroes the values
    Vec3 v = Vec3();
    Vec3 vprime = Vec3();
    Vec2 w = Vec2();
    
    cout << "-----Pass by value test-----" << endl;
    cout << "Original 3 vector:" << endl;
    print_vec(v);
    vprime = set_vec(v, 1.0, 2.0, 3.0);
    cout << "Original 3 vector after modification:" << endl;
    print_vec(v);
    cout << "New 3 vector after modification:" << endl;
    print_vec(vprime);
    
    cout << "-----Pass by reference test-----" << endl;
    cout << "Original 2 vector:" << endl;
    print_vec(w);
    set_vec(w, 1.0, 2.0);
    cout << "Original 2 vector after modification:" << endl;
    print_vec(w);
    
    Vec3 a = Vec3();
    Vec3 b = Vec3();
    Vec3 c = Vec3();
    a = set_vec(a, 1.0, 1.0, 1.0);
    b = set_vec(b, 2.0, 2.0, 2.0);
    cout << "-----Testing '+' for Vec3-----" << endl;
    cout << "-----Printing 2 original vectors-----" << endl;
    print_vec(a);
    print_vec(b);
    c = operator+(a, b);
    cout << "-----Printing addition of vectors-----" << endl;
    print_vec(c);
    
    Vec2 i = Vec2();
    Vec2 j = Vec2();
    Vec2 k = Vec2();
    set_vec(i, 1.0, 1.0);
    set_vec(j, 2.0, 2.0);
    cout << "-----Testing '+' for Vec2-----" << endl;
    cout << "-----Printing 2 original vectors-----" << endl;
    print_vec(i);
    print_vec(j);
    k = operator+(i, j);
    cout << "-----Printing addition of vectors-----" << endl;
    print_vec(k);

    return 0;
}

Vec3 set_vec(Vec3 v, Component x, Component y, Component z)
{
    // Local value v is a copy of the original v
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void set_vec(Vec2 &wr, Component x, Component y)
{
    // Local reference wr refers directly to original memory location
    wr.x = x;
    wr.y = y;
}

void print_vec(const Vec3 v)
{
    cout << "3-Vector : [" << v.x << ", " << v.y << ", " << v.z << "]" << endl;
}

void print_vec(const Vec2 &wr)
{
    // Passing in a reference wr prevents unnecessary memory copying
    cout << "2Vector : [" << wr.x << ", " << wr.y << "]" << endl;
}


// Unlike in C, operators may be type overloaded in C++ as well
Vec3 operator+(const Vec3 &a, const Vec3 &b)
{
    Vec3 c = Vec3();
    /*z.x = a.x + b.x;
    z.y = a.y + b.y;
    z.z = a.z + b.z;*/
    c = set_vec(c, a.x + b.x, a.y + b.y, a.z + b.z);
    return c;
}

Vec2 operator+(const Vec2 &a, const Vec2 &b)
{ 
    Vec2 c = Vec2();
    /*c.x = a.x + b.x;
    c.y = a.y + b.y;*/
    set_vec(c, a.x + b.x, a.y + b.y);
    return c;
}

