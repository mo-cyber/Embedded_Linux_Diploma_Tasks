#include <iostream>
#include <fstream>
#include <stdlib.h>

std::string firstName, lastName, phoneNumber;

void list();
void add();
void dlt();
void dlt_all();
void search();
void close();
bool check_length(std::string number);
bool check_number(std::string number);

void list()
{
    system("cls");
    std::ifstream contact("contacts.txt");
    contact.seekg(0, std::ios::end);
    if(contact.tellg() == 0)
    {
        system("cls");
        std::cout<<"No contacts found."<<std::endl;
    }
    else
    {
        system("cls");
        contact.seekg(0, std::ios::beg);
        while(contact >> firstName >> lastName >> phoneNumber)
        {
            std::cout<<firstName<<" "<<lastName<<" "<<phoneNumber<<std::endl;
        }   
    }
    contact.close();
    system("pause");
}

void add()
{
    system("cls");
    std::ofstream contact("contacts.txt", std::ios::app);
    std::cout<<"Enter first name: ";
    std::cin>>firstName;
    std::cout<<"Enter last name: ";
    std::cin>>lastName;
    std::cout<<"Enter phone number: ";
    std::cin>>phoneNumber;
    if(check_length(phoneNumber))
    {
        if(check_number(phoneNumber))
        {
            contact<<firstName<<" "<<lastName<<" "<<phoneNumber<<std::endl;
            system("cls");
            std::cout<<"Contact saved successfully."<<std::endl;
        }
        else
        {
            std::cout<<"Phone number digits should only be from 0 to 9."<<std::endl;
        }
    }
    else
    {
        std::cout<<"Phone number should be 11 digits."<<std::endl;
    }
    system("pause");
}

void dlt()
{
    system("cls");
    bool check = false;
    std::string fname, lname;
    std::ifstream contact("contacts.txt");
    std::ofstream temp("temp.txt", std::ios::app);
    std::cout<<"Enter the first and last name of the user: ";
    std::cin>>fname>>lname;
    while(contact >> firstName >> lastName >> phoneNumber)
    {
        if(firstName == fname && lastName == lname)
        {
            check = true;
            continue;
        }
        temp<<firstName<<" "<<lastName<<" "<<phoneNumber<<std::endl;
    }
    contact.close();
    temp.close();
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    if(check)
    {
        system("cls");
        std::cout<<"User deleted successfully."<<std::endl;
    }
    else
    {
        std::cout<<"User not found."<<std::endl;
    }
    system("pause");
}

void dlt_all()
{
    system("cls");
    remove("contacts.txt");
    std::ofstream contact("contacts.txt", std::ios::app);
    contact.close();
    system("cls");
    std::cout<<"Users deleted successfully."<<std::endl;
    system("pause");
}

void search()
{
    system("cls");
    bool check = false;
    std::string fname, lname;
    std::ifstream contact("contacts.txt");
    std::cout<<"Enter the first and last name of the user: ";
    std::cin>>fname>>lname;   
    while(contact >> firstName >> lastName >> phoneNumber)
    {
        if(firstName == fname && lastName == lname)
        {
            check = true;
            std::cout<<"First name: "<<firstName<<std::endl;
            std::cout<<"Last name: "<<lastName<<std::endl;
            std::cout<<"Phone number: "<<phoneNumber<<std::endl;
        }
    }
    if(!check)
    {
        std::cout<<"User not found."<<std::endl;
    }
    system("pause");
}

void close()
{
    system("cls");
    std::cout<<"Thank you for using the address book."<<std::endl;
    system("pause");
    exit(1);
}

bool check_length(std::string number)
{
    if(number.length() == 11)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_number(std::string number)
{
    for(int i = 0; i < number.length(); i++)
    {
        if(!(int(number[i]) >= 48 && int(number[i]) <= 57))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout<<"Welcome to your favourite address book!"<<std::endl;
    while(1)
    {
        system("cls");
        std::string input;
        std::cout<<"What do you want to do?"<<std::endl;
        std::cout<<"\t|List\t\t|List all users"<<std::endl;
        std::cout<<"\t|Add\t\t|Adds an user"<<std::endl;
        std::cout<<"\t|Delete\t\t|Deletes an user"<<std::endl;
        std::cout<<"\t|Delete_all\t|Removes all users"<<std::endl;
        std::cout<<"\t|Search\t\t|Search for an user"<<std::endl;
        std::cout<<"\t|Close\t\t|Closes the address book"<<std::endl;
        std::cin>>input;
        if (input == "List")
        {
            list();
        }
        else if (input == "Add")
        {
            add();
        }
        else if(input == "Delete")
        {
            dlt();
        }
        else if (input == "Delete_all")
        {
            dlt_all();
        }
        else if (input == "Search")
        {
            search();
        }
        else if (input == "Close")
        {
            close();
        }
        else
        {
            std::cout<<"Please re-enter an input as specified in the list."<<std::endl;
        }
    }

    return 0;
}