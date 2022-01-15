/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////


int Day(int x)
{
    int a = 30;
    int b = 28;
    int c = 31;
    switch (x) {
    case 4:
        return a;
        break;
    case 2:
        return b;
        break;
    case 6:
        return a;
        break;
    case 9:
        return a;
        break;
    case 11:
        return a;
        break;
    default:
        return c;
        break;
    }

}

bool checkPrime(int x)
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

bool CheckSquareEven(int x)
{
    if (x % 2 == 0 && round(sqrt(x)) == sqrt(x))
        return true;
    else
        return false;
}
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    if (E1 < 0 && E1 > 999)
    {
        return -999;
    }
    
    if (E1 >= 0 && E1 <= 399)
    {
        // EXP1 : Sherlock Homes
        if (E1 % 2 == 1)
            EXP1 = ceil(EXP1 + E1 / 10.0);
        else
            EXP1 = ceil(EXP1 - E1 / 5.0);
        // EXP2 : Watson
        if (E1 >= 0 && E1 <= 49)
            EXP2 = EXP2 + 25;
        else if (E1 >= 50 && E1 <= 99)
            EXP2 = EXP2 + 50;
        else if (E1 >= 100 && E1 <= 149)
            EXP2 = EXP2 + 85;
        else if (E1 >= 150 && E1 <= 199)
            EXP2 = EXP2 + 25 + 50;
        else if (E1 >= 200 && E1 <= 249)
            EXP2 = EXP2 + 25 + 85;
        else if (E1 >= 250 && E1 <= 299)
            EXP2 = EXP2 + 50 + 85;
        else if (E1 >= 300 && E1 <= 399)
            EXP2 = EXP2 + 25 + 50 + 85;
        //Reset
        if (EXP2 > 900)
            EXP2 = 900;
        if (EXP1 > 900)
            EXP1 = 900;
    }
    else if (E1 >= 400 && E1 <= 999)
    {
        float info_1 = E1 / 7.0 + 9;
        float info_2 = E1 / 9.0 + 11;
        float info_3 = E1 / 5.0 + 6;

        if (E1 >= 400 && E1 <= 499)
            EXP2 = ceil(EXP2 + info_1);
        if (E1 >= 500 && E1 <= 599)
            EXP2 = ceil(EXP2 + info_2);
        if (E1 >= 600 && E1 <= 699)
            EXP2 = ceil(EXP2 + info_3);
        if (E1 >= 700 && E1 <= 799)
        {
            EXP2 = ceil(EXP2 + info_1);
            if (EXP2 > 900)
                EXP2 = 900;
            if (EXP2 > 200)
                EXP2 = ceil(EXP2 + info_2);
        }
        if (E1 >= 800 && E1 <= 999)
        {
            EXP2 = ceil(EXP2 + info_1 + info_2);
            if (EXP2 > 900)
                EXP2 = 900;
            if (EXP2 > 600)
            {
                EXP2 = ceil(EXP2 + info_3);
                if (EXP2 > 900)
                    EXP2 = 900;
                EXP2 = ceil(1.15 * EXP2);
            }
        }
        EXP1 = ceil(EXP1 - 0.1 * E1);
     
        if (EXP2 > 900)
            EXP2 = 900;
        if (EXP1 > 900)
            EXP2 = 900;
    }
    
    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    double d = E2 / 9.0 + 10;
    int temp = EXP2;
    if (E2 < 0 && E2 >999)
    {
        return -999;
    }
    
    if (E2 >= 0 && E2 <= 299)
    {
        EXP2 = ceil(EXP2 + d);
        if(temp < EXP2)
            EXP1 = ceil(EXP1 + d / 3.0);
    }
    else if (E2 >= 300 && E2 <= 499)
    {
        EXP2 = ceil(EXP2 + d);
        if (temp < EXP2)
            EXP1 = ceil(EXP1 + d / 3.0);
        if (EXP2 > 900)
            EXP2 = 900;
        if (EXP1 > 900)
            EXP2 = 900;
        int temp1 = EXP2;
        EXP2 = ceil(EXP2 + 0.35 * E2);
        if (temp1 < EXP2)
            EXP1 = ceil(EXP1 + 0.35 * E2 / 3.0);
    }
    else if (E2 >= 500 && E2 <= 999)
    {
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d / 3.0);
        if (EXP2 > 900)
            EXP2 = 900;
        if (EXP1 > 900)
            EXP2 = 900;
        int temp1 = EXP2;
        
        double d2 = 0.35 * E2;
        EXP2 = ceil(EXP2 + d2);
        EXP1 = ceil(EXP1 + d2 / 3.0);
        if (EXP2 > 900)
            EXP2 = 900;
        if (EXP1 > 900)
            EXP2 = 900;
        float d3 = 0.17*(d2 + d);
        EXP2 = ceil(EXP2 + d3);
        EXP1 = ceil(EXP1 + d3 / 3.0);
    }
    if (EXP2 > 900)
        EXP2 = 900;
    if (EXP1 > 900)
        EXP2 = 900;
    
    HP2 = ceil(HP2 - pow(E2, 3) / pow(2, 23));
    if (E2 % 2 == 0)
    {
        M2 = ceil(M2 + pow(E2, 2) / 50);
    }
    
    if (M2 > 2000)
        M2 = 2000;
    if (HP2 < 0)
        HP2 = 0;
    return EXP1 + HP2 + EXP2 + M2;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    //Road 1
    if (E3 < 0 && E3 >999)
        return -999;
    
    int odd[9];
    for (int i = 0,j = 1; i < 9; i++, j+=2)
    {
        odd[i] = (j + E3) % 26 + 65;
    }

    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (odd[i] == 80)
        {
            int k = i+1;
            HP1 = ceil(HP1 - odd[i] * k * 2);
            EXP1 = EXP1 + (1000 - odd[i] * k) % 101;
            M1 = ceil(M1 - k * E3 / 9.0);
            count++;
        }
    }

    if (count == 0)
        M1 = ceil(M1 - 9 * 9 * E3 / 9.0);
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 900)
        EXP1 = 900;
    if (M1 < 0)
        M1 = 0;
    
    //Road 2
    int prime[7];
    for (int i = 0; i < 7; i++)
    {
        static int j = 0;
        while (!checkPrime(j))
            j++;
        prime[i] = j;
        prime[i] = (j + E3) % 26;
        j++;
    }
    
    int s = 0, m;
    for (int i = 0; i < 7; i++)
    {
        s += prime[i];
    }
    m = ceil(s / 7);

    int count_2 = 0;
    for (int i = 0; i < 7; i++)
    {
        prime[i] = (prime[i] + s + m) % 26 + 65;
        if (prime[i] == 80)
        {
            int k = i + 1;
            HP1 = ceil(HP1 - prime[i] * k * 2);
            EXP1 = EXP1 + (1000 - prime[i] * k) % 101;
            M1 = ceil(M1 - k * E3 / 9.0);
            count_2++;
        }
    }
    if (count_2 == 0)
        M1 = ceil(M1 - 7 * 7 * E3 / 9.0);

    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 900)
        EXP1 = 900;
    if (M1 < 0)
        M1 = 0;
    //Road3
    int squareEven[20];
    for (int i = 0; i < 20; i++)
    {
        static int j = 0;
        while(!CheckSquareEven(j))
            j++;
        squareEven[i] = j;
        squareEven[i] = (squareEven[i] + E3 * E3) % 113;
        j++;
    }
    
    int max = squareEven[0];
    for (int i = 0; i < 20; i++)
    {
        if (squareEven[i] > max)
            max = squareEven[i];
    }

    int count3 = 0;
    for (int i = 19; i >= 0; i--)
    {
        squareEven[i] = ceil((squareEven[i] + E3) / (double)max);
        squareEven[i] = squareEven[i] % 26 + 65;
        if (squareEven[i] == 80)
        {
            int k = 20 - i;
            HP1 = ceil(HP1 - squareEven[i] * k * 3);
            EXP1 = EXP1 + (3500 - squareEven[i] * k) % 300;
            M1 = ceil(M1 - k * E3 / 9.0);
            count3++;
        }
    }

    if(count3 == 0)
        M1 = ceil(M1 - 20 * 20 * E3 / 9.0);

    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 900)
        EXP1 = 900;
    if (M1 < 0)
        M1 = 0;
    //Road 4
    int DayofMonth[12];
    for (int i = 0; i < 12; i++)
    {
        DayofMonth[i] = Day(i+1);
        DayofMonth[i] = ceil(DayofMonth[i]+pow(E3/29.0,3));
        DayofMonth[i] = DayofMonth[i] % 9;
    }
    
    int min = DayofMonth[0];
    int min_idx = 0;
    for (int i = 0; i < 12; i++)
    {
        if (DayofMonth[i] < min)
        {
            min = DayofMonth[i];
            min_idx = i+1; //Don't know what index?
        }
    }

    if (min_idx == 0)
        min_idx++;
    int count4 = 0;
    for (int i = 11; i >= 0; i--)
    {
        DayofMonth[i] = ceil((DayofMonth[i] + E3) * (min / min_idx));
        DayofMonth[i] = DayofMonth[i] % 26 + 65;
        if (DayofMonth[i] == 80)
        {
            int k = 12 - i;
            HP1 = ceil(HP1 - DayofMonth[i] * k * 4);
            EXP1 = EXP1 + (4500 - DayofMonth[i] * k) % 400;
            M1 = ceil(M1 - k * E3 / 9.0);
            count4++;
        }

    }

    if (count4 == 0)
        M1 = ceil(M1 - 12 * 12 * E3 / 9.0);
    
    
    if (HP1 < 0)
        HP1 = 0;
    if (EXP1 > 900)
        EXP1 = 900;
    if (M1 < 0)
        M1 = 0;

    //Not find anything
    if (count + count_2 + count4 + count3 == 0)
    {
        HP1 = HP1 - (59 * E3) % 900;
        EXP1 = EXP1 - (79 * E3) % 300;
        if (HP1 < 0)
            HP1 = 0;
        if (EXP1 < 0)
            EXP1 = 0;
        if (M1 < 0)
            M1 = 0;
        return -1;
    }
    
    return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
