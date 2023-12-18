#include <iostream>
using namespace std;

class Polygon 
{
    protected:
    float length, height;
    public:
    virtual float area() = 0;
    void setData();
    
};
void Polygon :: setData ()
{
    cout <<"Enter length: "<<endl;
    cin>>length;
    cout <<"Enter height "<<endl;
    cin >> height;
}
class Rectangle : public Polygon
{
    public:
    float area()
    {
        return (length * height);
        // cout <<length * height<<endl;
    }
    void printArea ()
    {
        cout <<"The area of the rectangle is "<<area()<<endl;
    }
};

class Triangle : public Polygon
{
    public:
    float area ()
    {
        return (0.5 * length * height);
        // cout <<0.5 *(length * height)<<endl;
    }
    void calculateArea ()
    {
        cout <<"The area of Triangle is "<<area()<<endl;
    }
};

int main ()
{
    Polygon *poly_rect, *poly_tri;

    Rectangle rect;
    Triangle tri;
    poly_rect = &rect;
    poly_tri = &tri;
    cout <<"Enter data for the rectangle. "<<endl;
    rect.setData();
    cout <<"Enter data for triangle."<<endl;
    tri.setData();
    // poly_rect->setData();
    // poly_tri->setData();
    
    cout <<"The area of rectangle is "<<poly_rect->area()<<endl;
    
    cout <<"The area of triangle is "<<poly_tri->area()<<endl;
    // poly_rect->area();
    // poly_tri->area();


    // poly_tri->calculateArea(); //invalid
    // poly_rect->printArea();  //invalid



    return 0;
}