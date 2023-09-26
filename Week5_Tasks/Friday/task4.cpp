#include <iostream>
#include <cstring>

class String 
{
    private:
        char* data;
        size_t length;
    public:
        String(const char* str)
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }

        ~String()
        {
            delete[] data;
        }

        String(const String& str)
        {
            length = str.length;
            data = new char[length + 1];
            strcpy(data, str.data);
        }

        String& operator=(const String& str)
        {
            if(this == &str)
            {
                return *this;
            }

            delete[] data;

            length = str.length;
            data = new char[length + 1];
            strcpy(data, str.data);

            return *this;
        }

        size_t getLength() const
        {
            return length;
        }
        const char* getString() const
        {
            return data;
        }
};

int main()
{
    String myString("Mohamed Ehab");
    std::cout<<"myString length: "<<myString.getLength()<<std::endl;
    std::cout<<"myString data: "<<myString.getString()<<std::endl;

    String newString = myString;
    std::cout<<"newString length: "<<newString.getLength()<<std::endl;
    std::cout<<"newString data: "<<newString.getString()<<std::endl;

    return 0;
}