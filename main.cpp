#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    long id;
    string firstName;
    string lastName;
    string phoneNumber;
};

vector<Student>list;

void backToMenu();

void deleteStudent()
{
    for (const auto &st : list)
    {
        cout << "id: " << st.id << "\t";
        cout << "first name: " << st.firstName << "\t";
        cout << "last name: " << st.lastName << "\t";
        cout << "phone number: " << st.phoneNumber << "\t";
        cout << endl;
    }

    int id;
    cout << "type id to delete";
    cin >> id;

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if (iter->id == id)
        {
            list.erase(iter);
            break;
        }
    }

    cout << "student deleted successfully";
    backToMenu();
}

void showStudent()
{
    for (const auto &st : list)
    {
        cout << "id: " << st.id << "\t";
        cout << "first name: " << st.firstName << "\t";
        cout << "last name: " << st.lastName << "\t";
        cout << "phone number: " << st.phoneNumber << "\t";
        cout << endl;

        backToMenu();
    }
}

void AddStudent()
{
    long id;
    string firstName, lastName, phoneNumber;

    cout << "Enter id: ";
    cin >> id;
    cout << endl << "Enter first name: ";
    cin >> firstName;
    cout << endl << "Enter last name: ";
    cin >> lastName;
    cout << endl << "Enter phone number: ";
    cin >> phoneNumber;

    Student st;
    st.id = id;
    st.firstName = firstName;
    st.lastName = lastName;
    st.phoneNumber = phoneNumber;

    list.push_back(st);
    backToMenu();
}

void showMenu()
{
    int q = 0;

    do {
        cout << "Welcome to my app, what do you want to do?" << endl;
        cout << "1) Show students" << endl;
        cout << "2) Add student" << endl;
        cout << "3) Delete student" << endl;
        cin >> q;

    } while (q < 1 || q > 3);

    switch (q)
    {
    case 1:
        showStudent();
        break;
    case 2:
        AddStudent();
        break;
    case 3:
        deleteStudent();
        break;
    default:
        cout << "404 not found!";
    }

}

void backToMenu()
{
    cout << endl << "success!" << endl;
    char c = 'n';

    do {
        cout << "back to menu? ";
        c = getchar();
    } while (c != 'y' && c != 'n');

    if (c == 'y')
        showMenu();
}

int main()
{
    showMenu();

    // for (auto it = list.rbegin(); it != list.end(); it++)
    // {
    //     if (it->id == 1) list.erase(it);
    //     it--;
    // }
}
