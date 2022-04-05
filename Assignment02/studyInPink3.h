/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
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

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    string toString() const {
        string temp = "<Point[" + to_string(x) + "," + to_string(y) + "]>";
        return temp;
    }

    int distanceTo(const Point& otherPoint) const {
        float d = sqrt((x - otherPoint.x) * (x - otherPoint.x) + (y - otherPoint.y) * (y - otherPoint.y));
        return ceil(d);
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point& point = Point(), Node* next = NULL) {
        this->point = point;
        this->next = next;
    }
    string toString() const {
        string temp = "<Node[" + point.toString() + "]>";
        return temp;
    }
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path() {
        head = nullptr;
        tail = nullptr;
        count = 0;
        length = -1;
    }
    ~Path() {
        Node* ptr = head;
        while (ptr != nullptr)
        {
            head = head->next;
            delete ptr;
            ptr = head;
        }
    }

    void addPoint(int x, int y) {
        Point point(x, y);
        Node* temp = new Node(point);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            count = 1;
            length = 0;
        }
        else {
            Node* ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            tail = temp;
            count++;
            length += point.distanceTo(ptr->point);
        }
    }
    string toString() const {
        string temp = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
        Node* ptr = head;
        while (ptr != nullptr)
        {
            temp += ptr->toString() + ",";
            ptr = ptr->next;
        }
        temp.pop_back();
        temp += "]]>";
        return temp;
    }
    Point getLastPoint() const {
        return tail->point;
    }

    int Length() const {
        return this->length;
    }
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string& name = "") {
        this->name = name;
        path = new Path;
    }
    ~Character() {
        //Don't Know
        delete path;
    }

    string getName() const {
        return this->name;
    }
    void setName(const string& name) {
        this->name = name;
    }

    int setLength() const {
        return path->Length();
    }
    void moveToPoint(int x, int y) {
        path->addPoint(x, y);
    }
    //Add new method
    Point getCurrentPosition()
    {
        return path->getLastPoint();
    }

    string toString() const {
        string temp = "<Character[name:" + name + "," + "path:" + path->toString() + "]>";
        return temp;
    }
};


bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
    int l1 = chMurderer.setLength();
    int l2 = chWatson.setLength();
    if (l1 - l2 <= maxLength)
    {
        outDistance = l1 - l2;
        if (outDistance <= maxDistance)
            return true;
        else
            return false;
    }
    else
    {
        outDistance = -1;
        return false;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
