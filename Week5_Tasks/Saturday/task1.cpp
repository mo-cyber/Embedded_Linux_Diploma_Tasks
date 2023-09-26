#include <iostream>
#include <cstring>
using namespace std;

class mystring
{
    friend ostream& operator<<(ostream& ostr, const mystring& strr);
    friend istream& operator>>(istream& istr, mystring& strr);
    friend mystring operator+(const mystring& str1, const mystring& str2);
    char* str;
    public:
        mystring();
        mystring(char* strr);
        mystring(const mystring& strr);
        mystring(mystring&& strr);
        void popbk();
        void pushbk(char ch);
        int getlength();
        void copy(char strr[], int len, int pos);
        void swp(mystring& strr);
        mystring& operator=(const mystring& strr);
        ~mystring(){delete str;}
};

mystring& mystring::operator=(const mystring& strr)
{
    if(this == &strr)
    {
        return *this;
    }
    delete[] str;
    str = new char[strlen(strr.str) + 1];
    strcpy(str,strr.str);
    return *this;
}

mystring operator+(const mystring& str1, const mystring& str2)
{
    int length = strlen(str1.str) + strlen(str2.str);
    char* ch = new char[length + 1];
    strcpy(ch, str1.str);
    strcat(ch, str2.str);
    ch[length] = '\0';
    mystring temp{ch};
    delete[] ch;
    return temp;
}

istream& operator>>(istream& istr, mystring& strr)
{
    char* ch = new char[1000];
    memset(&ch[0], 0, 1000);
    istr>>ch;
    strr = mystring{ch};
    delete[] ch;
    return istr;
}

ostream& operator<<(ostream& ostr, const mystring& strr)
{
    ostr<<strr.str;
    return ostr;
}

void mystring::swp(mystring& strr)
{
    mystring temp{strr};
    strr = *this;
    *this = temp;
}

void mystring::copy(char strr[], int len, int pos)
{
    for(int i = 0; i < len; i++)
    {
        strr[i] = str[pos + i];
    }
    strr[len] = '\0';
}

void mystring::pushbk(char ch)
{
    int length =  strlen(str);
    char* strr = new char[length + 2];
    for(int i = 0; i < length; i++)
    {
        strr[i] = str[i];
    }
    strr[length] = ch;
    strr[length + 1] = '\0';
    *this = mystring{strr};
    delete[] strr;
}

void mystring::popbk()
{
    int length = strlen(str);
    char* ch = new char[length];
    for(int i = 0; i < length - 1; i++)
    {
        ch[i] = str[i];
    }
    ch[length - 1] = '\0';
    *this = mystring{ch};
    delete[] ch;
}

int mystring::getlength()
{
    return strlen(str);
}

mystring::mystring():str{nullptr}
{
    str = new char[1];
    str[0] = '\0';
}

mystring::mystring(char* strr)
{
    if(strr == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        str = new char[strlen(strr) + 1];
        strcpy(str, strr);
        str[strlen(strr)] = '\0';
    }
}

mystring::mystring(const mystring& strr)
{
    str = new char[strlen(strr.str) + 1];
    strcpy(str, strr.str);
}

mystring::mystring(mystring&& strr)
{
    str = strr.str;
    strr.str = nullptr;
}

int main()
{
    mystring s1;
    char temp1[] = "Mohamed";
    mystring s2{temp1};
    mystring s3{s1};
    char temp2[] = "Ehab";
    mystring s4{mystring{temp2}};
    s2.popbk();
    cout << "Mystring s2: "<< s2 << endl;
    s2.pushbk('x');
    cout << "Mystring s2: "<< s2 << endl;
    cout << "Length of Mystring s2: "<< s2.getlength() << endl;
    char arr[10];
    s2.copy(arr, 3, 0);
    cout << "arr is: "<< arr << endl;
    s4.swp(s2);
    cout << s4 << " " << s2 << endl;
    s4 = s2 + s2;
    cout << "string s4: "<< s4 << endl;

    return 0; 
}