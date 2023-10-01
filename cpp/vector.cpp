#include <iostream>
#include <vector>
using namespace std;
class test
{
public:
    vector<float> vec;
    vector<float> vec1;
    vector<float> vec2;
    vector<float> sum;
    void create();
    void modify();
    void multiply();
    void add();
    void display();
};

void test ::create()
{
    int a;
    float data;
    cout << "Enter the size of the vector you want to create" << endl;
    cin >> a;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < a; i++)
    {
        cin >> data;
        vec.push_back(data);
    }
}
void test::modify()
{
    int pos, ch;
    float data;
    cout << "Enter 1 to insert and an element" << endl
         << "2 to DELETE an element" << endl;
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter the index where you want to insert an element" << endl;
        cin >> pos;
        cout << "Enter the element you want to enter" << endl;
        cin >> data;
        vec.insert(vec.begin() + pos, data); // vec.begin() starts from 0.
    }
    else
    {
        if (ch == 2)
        {
            cout << "Enter the index from where you want to delete an element" << endl;
            cin >> pos;
            vec.erase(vec.begin() + pos);
        }
        else
        {
            cout << "Wrong Input!!" << endl;
        }
    }
}

void test::multiply()
{
    int ele;
    cout << "Enter the number you want to multiply your elements with: " << endl;
    cin >> ele;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = vec[i] * ele;
    }
}

void test::add()
{
    int size1, size2, big, small, ele1, ele2;
    cout << "Enter the size of the first vector: " << endl;
    cin >> size1;
    cout << "Enter the size of the second vector: " << endl;
    cin >> size2;
    cout << "Enter the elements of the first vector: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> ele1;
        vec1.push_back(ele1);
    }
    cout << "Enter the elements of the second vector: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> ele2;
        vec2.push_back(ele2);
    }
    if (size1 > size2)
    {
        big = size1;
        small = size2;
        for (int i = 0; i < small; i++)
        {
            sum.push_back(vec1[i] + vec2[i]);
        }
        for (int i = small; i < big; i++)
        {
            sum.push_back(vec1[i]);
        }
    }
    else
    {
        big = size2;
        small = size1;
        for (int i = 0; i < small; i++)
        {
            sum.push_back(vec1[i] + vec2[i]);
        }
        for (int i = small; i < big; i++)
        {
            sum.push_back(vec2[i]);
        }
    }
    cout << "Resultant Vector: (";
    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i];
        if (i != (sum.size() - 1))
        {
            cout << ",";
        }
    }
    cout << ")"<<endl;
    // exit(0);
}
void test::display()
{
    cout << "Your Vector:(";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != (vec.size() - 1))
        {
            cout << ",";
        }
    }
    cout << ")" << endl;
}
int main()
{
    test p;
    int choice;
    while (1)
    {
        cout << "Hello! You can perform the following operations" << endl;
        cout << "Enter:" << endl
             << "1 to CREATE A VECTOR" << endl
             << "2 to MODIFY A VECTOR" << endl
             << "3 to MULTIPLY A VECTOR" << endl
             << "4 to ADD A VECTOR" << endl
             << "5 to DISPLAY YOUR INITIAL VECTOR" << endl
             << "6 to EXIT" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.create();
            break;
        case 2:
            p.modify();
            break;
        case 3:
            p.multiply();
            break;
        case 4:
            p.add();
            break;
        case 5:
            p.display();
            break;
        case 6:
            exit(0);
        default:
            cout << "Wrong Input" << endl;
            exit(0);
        }
    }
    return 0;
}