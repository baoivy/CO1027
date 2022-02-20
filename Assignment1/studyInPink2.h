/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
struct Point {
    int x;
    int y;
};

bool OutofBound(char direction, int i, int j)
{
    switch (direction)
    {
        case 'L' :
        {
            j--;
            if (j < 0)
                return false;
            break;
        }
        case 'R':
        {
            j++;
            if (j >= 100)
                return false;
            break;
        }
        case 'U':
        {
            i--;
            if (i < 0)
                return false;
            break;
        }
        case 'D' :
        {
            i++;
            if (i >= 100)
                return false;
            break;
        }
    }
    return true;
}
string g(string p1, string p2) //Not clear
{
    string password; int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        int sum = (int)p1[i] + (int)p2[i] - 96 + temp;
        if (sum <= 9)
        {
            password.push_back((char)sum + 48);
            temp = 0;
        }
        else
        {
            password.push_back((char)sum % 10 + 48);
            temp = sum / 10;
        }
    }
    return password;
}

void sortingThreeNum(int& a, int& b, int& c)
{
    int sum = a + b + c;
    int max = a, min = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    a = min; c = max; b = sum - min - max;
}
bool PimeNumber(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool FiboNumber(int x, int b = 1, int a = 0)
{
    if (x == b && b >= x)
        return true;
    else if(b > x)
        return false;
    return FiboNumber(x, a + b, b);
}
int FindPink(string s)
{
    int count = 0;
    for (int i = 0; i < s.length() - 3; i++)
    {
        if (s.substr(i, 4) == "Pink" || s.substr(i, 4) == "pink") {
            count++;
        }
    }
    return count;
}

int sizeofNumber(int x, int count = 0)
{
    if (x == 0)
        return count;
    return sizeofNumber(x / 10, count + 1);
}

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream FirstNotebook;
    FirstNotebook.open(ntb1);
    string line1; FirstNotebook >> line1; //Can be a getline
    for (int i = line1.length() - 1; i >= line1.length() - 3; i--)
    {
        if (line1[i] < '0' || line1[i] > '9')
            return "000000000";
    }
    int n1 = std::stoi(line1.substr(line1.length() - 3, 3));
    if (n1 == 000) return "000000000";

    int temp; int *freq = new int[n1];
    int j = 0;
    while(FirstNotebook >> temp)
    {
        freq[j] = temp;
        j++;
    }
    FirstNotebook.close();

    int pass1[10];
    for (int i = 0; i <= 9; i++) {
        int temp = 0;
        for (int j = 0; j < n1; j++)
        {
            if (freq[j] == i)
                temp++;
        }
        if (temp < 10)
            pass1[i] = temp;
        else
            pass1[i] = temp % 10;
    }
    
    //delete[] freq;
    string password;
    for (int i = 0; i < 10; i++)
    {
        password += to_string(pass1[i]);
    }
    return password;
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream SecondNotebook;
    SecondNotebook.open(ntb2);
    string size; SecondNotebook >> size;
    if (size.length() != 5) //Checking
        return "1111111111";
    else
    {
        for (int i = 0; i < 5; i++) {
            if (size[i] < '0' || size[i] > '9')
                return "1111111111";
        }
    }
    SecondNotebook.ignore();
    string line; int cntP = 0;
    while (!SecondNotebook.eof())
    {
        getline(SecondNotebook, line);
        cntP += FindPink(line);
    }
    SecondNotebook.close();
    
    if (sizeofNumber(cntP) < 5)
        cntP = cntP * cntP;
    
    string password = to_string(cntP);
    if (sizeofNumber(cntP) < 10)
    {
        while (password.length() < 10)
        {
            password.push_back('9');
        }
    }
    return password;
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    int arr[10][10];
    ifstream ThirdNotebook;
    ThirdNotebook.open(ntb3);
    //Write it in sstream
    for (int i = 0; i < 10; i++)
    {
        string line; getline(ThirdNotebook, line);
        line.push_back('|');
        stringstream ss(line);
        for (int j = 0; j < 10; j++)
        {
            string number; getline(ss, number, '|');
            arr[i][j] = std::stoi(number);
        }
    }
    ThirdNotebook.close();
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i < j)
            {
                while (!PimeNumber(arr[i][j]))
                    arr[i][j]++;
            }
            else if (i > j)
            {
                while (!FiboNumber(arr[i][j]))
                    arr[i][j]++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        sortingThreeNum(arr[i][7], arr[i][8], arr[i][9]);

    string password;
    for (int i = 0; i < 10; i++)
    {
        int max = arr[i][0]; int index;
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] >= max)
            {
                max = arr[i][j];
                index = j;
            }
        }
        password += to_string(index);
    }
    return password;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string finalPassword[9];
    finalPassword[0] = pwd1;
    finalPassword[1] = pwd2;
    finalPassword[2] = pwd3;
    finalPassword[3] = g(pwd1,pwd2);
    finalPassword[4] = g(pwd1, pwd3);
    finalPassword[5] = g(pwd2, pwd3);
    finalPassword[6] = g(finalPassword[3], pwd3);
    finalPassword[7] = g(pwd1, finalPassword[5]);
    finalPassword[8] = g(finalPassword[3], finalPassword[4]);

    string FindedPassword;
    for (int i = 0; i < 9; i++)
    {
        FindedPassword += finalPassword[i] + ',';
    }
    FindedPassword += finalPassword[8];
    return FindedPassword;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = -9;
        }
    }

    arr[0][0] = 0; int x = 0; int y = 0; int tempNum = 0;
    for (int i = 0; i < moves.length(); i++)
    {
        if (OutofBound(moves[i], x, y))
        {
            switch (moves[i])
            {
                case 'L':
                {
                    y--;
                    tempNum += 14;
                    arr[x][y] = tempNum;
                    break;
                }
                case 'R' :
                {
                    y++;
                    tempNum += 14;
                    arr[x][y] = tempNum;
                    break;
                }
                case 'U' :
                {
                    x--;
                    tempNum += 14;
                    arr[x][y] = tempNum;
                    break;
                }
                case 'D' :
                {
                    x++;
                    tempNum += 14;
                    arr[x][y] = tempNum;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < points.length(); i++)
    {
        if (points[i] == '(' || points[i] == ')')
        {
            points.erase(i, 1);
            i--;
        }
    }

    for (int i = 0; i < points.length(); i++)
    {
        if (points[i] == '-' || points[i] == ',')
        {
            points[i] = ' ';
        }
    }   
    Point p[100];
    int index = 0; stringstream ss(points);
    int data1; int count = 0;
    while (ss >> data1)
    {
        if (count % 2 == 0)
            p[index].x = data1;
        else
            p[index].y = data1;
        count++;
        if(count % 2 == 0 && count > 0)
            index++;
    }
  
    bool flag = false; int data = 0;
    int sum = abs(p[0].x) + abs(p[0].y);
    for (int i = 0; i < index; i++)
    {
        if (9*sum <= arr[p[i].x][p[i].y] && arr[p[i].x][p[i].y] != -9)
        {
            flag = true; 
            outCatchUps += 'Y';
            outCatchUps += ',';
            outTimes += to_string(9*sum) + ',';
            data = i + 1;
            break;
        }
        else if (9*sum > arr[p[i].x][p[i].y] || arr[p[i].x][p[i].y] == -9) {
            outCatchUps += 'N';
            outCatchUps += ',';
            outTimes += to_string(9*sum) + ',';
            if (flag == false && i == index - 1)
                break;
            sum += abs(p[i].x - p[i + 1].x) + abs(p[i].y - p[i + 1].y);
        }
    }

    if (flag == true)
    {
        for(int i = data; i < index - 1; i++)
        {
            outCatchUps.push_back('-');
            outCatchUps.push_back(',');
            outTimes.push_back('-');
            outTimes.push_back(',');
        }
        outCatchUps.push_back('-');
        outTimes.push_back('-');
    }
    else if (flag == false)
    {
        outTimes.erase(outTimes.length() - 1, 1);
        outCatchUps.erase(outCatchUps.length() - 1, 1);
    }
    return flag;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream Tagging;
    Tagging.open(tag);
    string email, number;
    getline(Tagging, email);
    getline(Tagging, number);
    email.erase(0, 7);
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            number.erase(i, 1);
            i--;
        }
    }
    int num = std::stoi(number);

    string account;
    account += email + ';';
    for (int i = 0; i < num; i++)
    {
        account += message;
    }
    return account;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
