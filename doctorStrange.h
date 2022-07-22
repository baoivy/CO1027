//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef doctorStrange_h
#define doctorStrange_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

///STUDENT'S ANSWER BEGINS HERE
///STUDENTS CAN ADD HELPER FUNCTIONS
bool checkFibo(int x, int b = 1, int a = 0)
{
    if (x == b)
        return true;
    else if (b > x)
        return false;
    return checkFibo(x, a + b, b);
}

bool checkPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int G(int i,int hp) {
    hp++;
    while (checkPrime(hp) == false)
    {
        hp++;
    }
    return (i + hp) % 100;
}

bool Event1_5(int &hp, int &lv, int &exp, int numEvent, int count_event, int& bonusEXP, int& bonusDamamge, bool fake_wong, bool wong) {
    int b = count_event % 10;
    int LV_0 = count_event > 6 ? (b > 5 ? b : 5) : b;
    if (lv > LV_0 || wong == true) {
        switch (numEvent)
        {
            case 1:
                bonusEXP =  10;
                break;
            case 2:
                bonusEXP = 20;
                break;
            case 3:
                bonusEXP = 40;
                break;
            case 4:
                bonusEXP = 50;
                break;
            case 5:
                bonusEXP = 70;
                break;
        }
        return true;
    }
    else if(lv == LV_0){
        switch (numEvent)
        {
            case 1:
                bonusEXP = 5;
                break;
            case 2:
                bonusEXP = 10;
                break;
            case 3:
                bonusEXP = 20;
                break;
            case 4:
                bonusEXP = 25;
                break;
            case 5:
                bonusEXP = 35;
                break;
        }
        return true;
    }
    else if(lv <= LV_0 || fake_wong == true) {
        double damage = 0;
        switch (numEvent)
        {
            case 1:
                damage = 1.5 * (double)LV_0 * 10;
                break;
            case 2:
                damage = 2.5 * (double)LV_0 * 10;
                break;
            case 3:
                damage = 4.5 * (double)LV_0 * 10;
                break;
            case 4:
                damage = 7.5 * (double)LV_0 * 10;
                break;
            case 5:
                damage = 9.5 * (double)LV_0 * 10;
                break;
        }
        bonusDamamge = damage;
    }
    return false;
}

int solve_spell(string spell, string res, int i = 0, int j = 0) {
    if (j == res.length())
        return 1;
    if (i == spell.length())
        return 0;

    if (spell[i] == res[j])
        return solve_spell(spell, res, i + 1, j + 1) + solve_spell(spell, res, i + 1, j);
    else
        return solve_spell(spell, res, i + 1, j);
}

int sumAllMatrix(int arr[][7], int r, int c, int m) {
    int sum = 0;
    for (int i = r; i < r + m; i++) {
        for (int j = c; j < c + m; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool checkAscending(int arr[][7], int r, int c, int m) {
    for (int i = c; i < c + m; i++) {
        for (int j = r; j < r + m - 1; j++) {
            if (arr[i][j] > arr[i][j + 1])
                return false;
        }
    }
    return true;
}

bool binary_searching(int arr[], int size, int target, int &x) {
    int left = 0; int right = size - 1;
    while (left <= right) {
        x++;
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            right = mid - 1;
        else if(arr[mid] > target)
            left = mid + 1;
    }
    return false;
}

/**void pushback(int*& arr, int size, int val) {
    if (size < 1) {
        arr = new int[size + 1];
        arr[size] = val;
        size++;
    }
    else if(size >= 1) {
        int* tmp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = arr[i];
        }
        tmp[size] = val;
        delete arr;
        arr = tmp;
        size++;
    }
}*/

struct Event {
    int HP;
    int numEvent;
};

void pushback(Event*& arr, int &size, int hp, int numEvent) {
    if (size < 1) {
        arr = new Event[size + 1];
        arr[size].HP = hp;
        arr[size].numEvent = numEvent;
        size++;
    }
    else if (size >= 1) {
        Event* tmp = new Event[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = arr[i];
        }
        tmp[size].HP = hp;
        tmp[size].numEvent = numEvent;
        delete arr;
        arr = tmp;
        size++;
    }
}

void changeLV(int &hp, int &lv, int &exp, string &HP) {
    int bonusLV = exp / 100;
    lv += bonusLV;
    lv = lv > 10 ? 10 : lv;
    if (lv == 10 && exp > 100)
        exp = 100;
    else
        exp %= 100;

    hp += 10 * bonusLV;
    hp = hp > 999 ? 999 : hp;
    int maxHP = std::stoi(HP);
    maxHP += 50 * bonusLV;
    maxHP = maxHP > 999 ? 999 : maxHP;
    HP = to_string(maxHP);
}

int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    events.pop_back();
    events.erase(0, 1);
    int hp = std::stoi(HP), exp = std::stoi(EXP), ts = std::stoi(TS), lv = std::stoi(LV);
    int g = 0, num_livitation = 3;
    bool livitation = false, fake_livitation = false, wong = false, fake_wong = false, summon_livitation = true, cannot_summon_livitation = false;
    int num_wong_help = 3, num_wong_fake_help = 3, first_meet = true;
    int count_event = 1;
    int bonusDamage = 0, bonusEXP = 0;
    bool poisonApple = false; int num_poisonApple = 3;
    int tmp_lvl;
    Event* pre_event = new Event[1]; int size = 0;
    bool event15 = false; int idx_hp_max = 0; int result = 0;
    bool event12 = false; int tmp_ts;
    
    stringstream ss(events);
    string sequence_Event;
    
    while (getline(ss, sequence_Event, '#')) {
        int numEvent;
        stringstream ss1(sequence_Event);
        ss1 >> numEvent;
        pushback(pre_event, size, hp, numEvent);
        if (event15 == true) {
            numEvent = pre_event[idx_hp_max].numEvent;
        }
        if (poisonApple == true && wong == false) {
            num_poisonApple--;
            if (num_poisonApple == 0) {
                poisonApple = false;
                lv = tmp_lvl;
                num_poisonApple = 3;
            }
        }
        if (numEvent >= 1 && numEvent <= 5) {
            bool event1_5 = Event1_5(hp, lv, exp, numEvent, count_event, bonusEXP, bonusDamage, fake_wong, wong);
            if (event1_5 == true) {
                exp += bonusEXP;
                if (exp >= 100) {
                    changeLV(hp, lv, exp, HP);
                }
                if (wong == true) {
                    num_wong_help--;
                    if (num_wong_help == 0) {
                        wong = false;
                        num_wong_help = 3;
                    }
                }

            }
            else if (event1_5 == false) {
                if (livitation == true && num_livitation != 0) {
                    hp -= bonusDamage * (100 - G(count_event, hp)) / 100;
                    num_livitation--;
                    if (num_livitation == 0) {
                        livitation = false;
                        lv = (lv < 3) ? 1 : lv;
                        summon_livitation == true;
                    }
                }
                else 
                    hp -= bonusDamage;

                if (fake_wong == true) {
                    num_wong_fake_help--;
                    if (num_wong_fake_help == 0) {
                        fake_wong = false;
                        num_wong_fake_help = 3;
                    }
                }
                if (hp < 0) {
                    if (ts == 0) {
                        result = -1;
                        break;
                    }
                    else {
                        hp = std::stoi(HP);
                        if (fake_wong == true)
                        {
                            fake_wong = false;
                            num_wong_fake_help = 3;
                        }
                        ts--;
                    }
                }
            }

            if (std::stoi(HP) < 0) {
                return -1;
            }
        }
        else if (numEvent == 6) {
            string line; int num_attack = 0, num_defense = 0;
            ss1 >> line;
            for (int i = 0; i < line.length(); i++) {
                line[i] = tolower(line[i]);
            }
            num_attack = solve_spell(line, "attack");
            num_defense = solve_spell(line, "defense");
            int func_x = (line.length() + count_event) % 100;
            int win_rate = 10 * num_attack, hp_rate = 10 * num_defense;
            if (livitation == true) {
                win_rate += G(count_event, hp);
                hp_rate += G(count_event, hp);
            }
            if (win_rate > func_x) {
                ts++; exp += 200;
                if (exp >= 100) {
                    changeLV(hp, lv, exp, HP);
                }
            }
            else {
                if (hp < 100) {
                    result = -1;
                    break;
                }
                if (hp_rate < 100)
                    hp = hp - hp * (100 - hp_rate) / 100;
            }
        }
        else if (numEvent == 7) {
            livitation = true;
            if (fake_wong == true) {
                //Write later
                fake_wong = false;
                num_wong_fake_help = 3;
            }
            if (num_livitation > 0 && summon_livitation == false)
                continue;
            if (cannot_summon_livitation == true)
                continue;
            lv = (lv <= 8) ? (lv + 2) : lv;
            summon_livitation = false;
        }
        else if (numEvent == 8) {
            if (first_meet == true) {
                wong = true;
                first_meet = false;
            }
            else if (first_meet == false) {
                fake_wong = true;
                if (lv > 7) {
                    fake_wong = false;
                }
                else if (wong == true) {
                    fake_wong = false;
                    num_wong_help--;
                    if (num_wong_help == 0)
                        wong = false;
                }
                else {
                    livitation = false;
                    fake_livitation = true;
                }
            }
        }
        else if (numEvent == 9) {
            hp = std::stoi(HP);
            poisonApple = false;
            fake_wong = false;
            if (fake_livitation == true) {
                livitation = true;
                fake_livitation = false;
            }
            if(livitation == true)
                num_livitation = 3;
        }
        else if (numEvent == 10) {
            int bonus = hp;
            while (!checkFibo(bonus)) {
                bonus--;
            }
            hp += bonus;
            hp = (hp > std::stoi(HP)) ? std::stoi(HP) : hp;
        }
        else if (numEvent == 11) {
            if(wong == true){
                num_wong_help--;
                if (num_wong_help == 0)
                    wong = false;
                count_event++;
                continue;
            }
            else if (fake_wong == true) {
                num_wong_fake_help--;
                if (num_wong_fake_help == 0) {
                    fake_wong = false;
                    num_wong_fake_help = 3;
                }
            }
            hp -= 50;
            if (hp < 0) {
                if (ts == 0) {
                    result = -1;
                    break;
                }
                else {
                    hp = std::stoi(HP);
                    ts--;
                    if (fake_wong == true)
                    {
                        fake_wong = false;
                        num_wong_fake_help = 3;
                    }
                }
            }
            poisonApple = true;
            tmp_lvl = lv;
            lv = (lv < 3) ? 1 : (lv - 2);
        }
        else if (numEvent == 12) {
            string first_str, second_str;
            ss1 >> first_str >> second_str;
            int idx = (first_str.length()) / 2;
            if (first_str.length() <= 2)
                continue;
            string str1 = first_str.substr(0, idx);
            string str2 = first_str.substr(idx + 1);
            str1 = string(str1.rbegin(), str1.rend());
            str2 = string(str2.rbegin(), str2.rend());
            string res; res += str1; res.push_back(first_str[idx]);  res += str2;
            int time_rotate = (str2.length()) % 10;
            while (time_rotate--) {
                for (int i = 0; i < res.length(); i++) {
                    res[i]++;
                    if (res[i] == 'Z' + 1 || res[i] == 'z' + 1) {
                        res[i] -= 26;
                    }
                }
            }
            if (res.find(second_str) != string::npos) {
                exp += 30;
                if (exp >= 100) {
                    changeLV(hp, lv, exp, HP);
                }
                hp -= 0.1 * hp;
                int maxHP = std::stoi(HP); maxHP -= 0.1 * maxHP;
                HP = to_string(maxHP);
                event12 = true;
            }
            else {
                exp += 15;
                if (exp >= 100) {
                    changeLV(hp, lv, exp, HP);
                }
                livitation = false;
                cannot_summon_livitation = true;
                tmp_ts = ts; ts = 0;
                event12 = false;
            }
        }
        else if (numEvent == 13) {
            int matrix[7][7];
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    ss1 >> matrix[i][j];
                }
            }
            int min = INT_MAX;
            int row_min = 0; int col_min = 0;
            int m = (count_event % 7) > 2 ? (count_event % 7) : 2;
            for (int i = 0; i < 7 - m; i++) {
                for (int j = 0; j < 7 - m; j++) {
                    int tmp = sumAllMatrix(matrix, i, j, m);
                    if (tmp < min) {
                        min = tmp;
                        row_min = i;
                        col_min = j;
                    }
                }
            }
            if (checkAscending(matrix, row_min, col_min, m)) {
                hp += min * (row_min + col_min);
                if (hp > std::stoi(HP))
                    hp = std::stoi(HP);
            }
            else {
                hp -= min * (row_min + col_min);
                if (hp < 0 && event12 == true) {
                    hp = 1;
                }
                else if (hp < 0)
                    return -1;
            }
        }
        else if (numEvent == 14) {
            int arr[1000];
            int size = 0;
            int x = 0;
            int target1; ss1 >> target1;
            while (ss1 >> arr[size]) {
                size++;
            }
            if (binary_searching(arr, size, target1, x)) {
                lv = 1;
                hp = hp - x * (count_event % 10) * 7;
                if (hp < 0) {
                    if (ts == 0) {
                        result = -1;
                        break;
                    }
                    else {
                        hp = std::stoi(HP);
                        ts--;
                    }
                }
                
            }
            else {
                exp += 150;
                livitation = true;
                cannot_summon_livitation = false;
                ts = tmp_ts;
                if (exp >= 100) {
                    changeLV(hp, lv, exp, HP);
                }
            }
        }
        else if (numEvent == 15 && event15 == false) {
            event15 = true;
            int max = 0;
            for (int i = 0; i < size; i++) {
                if (pre_event[i].HP > max) {
                    max = pre_event[i].HP;
                    idx_hp_max = i;
                }
            }
            if (ts > 0) {
                ts--;
                if (max == hp) {
                    continue;
                }
                lv = 10;
                exp = 100;
                hp = max;
            }
        }
        count_event++;

    }

    HP = to_string(hp); EXP = to_string(exp); LV = to_string(lv); TS = to_string(ts);
    delete[] pre_event;
    ///Result outcome
    events.insert(0, "!");
    events.push_back('!');
    std::cout << HP << " " << LV << " " << EXP << " " << TS << endl;
    std::cout << events << endl;
    if (result == -1)
        return -1;
    result = std::stoi(HP) + std::stoi(LV) + std::stoi(EXP) + std::stoi(TS);
    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */
