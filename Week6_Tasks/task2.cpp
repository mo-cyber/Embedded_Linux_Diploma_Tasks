#include <iostream>

class Drawable
{
    public:
        virtual void draw() = 0;
};

class Circle : public Drawable
{
    public:
        void draw() override
        {
            std::cout<<"Hello from circle!"<<std::endl;
        }
};

class Rectangle : public Drawable
{
    public:
        void draw() override
        {
            std::cout<<"Hello from rectangle!"<<std::endl;
        }
};

class Triangle : public Drawable
{
    public:
        void draw() override
        {
            std::cout<<"Hello from triangle!"<<std::endl;
        }
};

int main()
{
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    Drawable* arr[] = {&circle, &rectangle, &triangle};

    for(Drawable* i : arr)
    {
        i->draw();
    }

    return 0;
}