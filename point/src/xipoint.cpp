////////////////////////////////////////////////////////////////////////////////
// Module Name:  xipoint.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.1
// Date:         08.09.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "xipoint.h"

#include <algorithm>        // min
#include <cmath>

namespace xi {

    Point::Point(int x, int y) {
        this->_x = x;
        this->_y = y;
    }

    void Point::shift(int shf) {
        this->setX(this->getX() + shf);
        this->setY(this->getY() + shf);
    }

    void Point::shift(int xSh, int ySh) {
        this->setX(this->getX() + xSh);
        this->setY(this->getY() + ySh);
    }

    void Point::shift(const xi::Point &pt) {
        this->setX(this->getX() + pt.getX());
        this->setY(this->getY() + pt.getY());
    }

    double Point::dist(const xi::Point &other) {
        return sqrt((this->getX() - other.getX())*(this->getX() - other.getX()) +
                                                (this->getY() - other.getY())*(this->getY() - other.getY()));
    }

    int Point::getX() const {
        return this->_x;
    }

    int Point::getY() const {
        return this->_y;
    }

    void Point::setX(int x) {
        this->_x = x;
    }

    void Point::setY(int y) {
        this->_y = y;
    }


    PointArray::PointArray(){
        this->_arr = nullptr;
        this->_size = 0;
    }

    PointArray::PointArray(const Point *points, PointArray::Uint size) {
        this->_arr = new Point[size];

        for (int i = 0; i < size; ++i) {
            this->_arr[i] = points[i];
        }

        this->_size = size;
    }

    PointArray::PointArray(const PointArray &pv) {
        this->_arr = new Point[pv.getSize()];

        for (Uint i = 0; i < pv.getSize(); ++i) {
            this->_arr[i] = *pv.get(i);
        }

        this->_size = pv.getSize();
    }

    PointArray::~PointArray() {
        delete [] this->_arr;
        this->_arr = nullptr;
        this->_size = 0;
    }

    void PointArray::append(const Point &pt) {
        this->resize(this->getSize());

        this->_arr[this->getSize() - 1] = pt;

        this->_size++;
    }

    void PointArray::insert(const Point &pt, PointArray::Uint pos) {
        if (pos >= this->getSize())
            this->append(pt);
        else {
            this->resize(this->getSize() + 1);
            for (PointArray::Uint i = this->getSize() - 1; i > pos; --i) {
                this->_arr[i-1] = this->_arr[i];
            }
            this->_arr[pos] = pt;

            this->_size++;
        }
    }


    void PointArray::resize(PointArray::Uint n) {
        auto new_arr = new Point[n];

        for (PointArray::Uint i = 0; i < std::min(n, this->getSize()); ++i) {
            new_arr = &this->_arr[i];
        }

        delete [] this->_arr;
        this->_arr = new_arr;
        this->_size = n;
    }

    void PointArray::remove(PointArray::Uint pos) {
        if (pos >= this->getSize())
            return;

        if (this->getSize() == 1) {
            this->clear();
        }
        else {
            for (PointArray::Uint i = pos; i < this->getSize()-1; ++i) {
                this->_arr[i] = this->_arr[i+1];
            }

            this->_size = this->getSize() - 1;
        }
    }

    void PointArray::clear() {
        delete [] this->_arr;
        this->_arr = nullptr;
        this->_size = 0;
    }

    double PointArray::computePath() {
        double sum = 0;

        for (PointArray::Uint i = 0; i < this->getSize()-1; ++i) {
            sum += this->get(i)->dist(*this->get(i+1));
        }

        return sum;
    }

    const PointArray::Uint PointArray::getSize() const {
        return this->_size;
    }

    Point *PointArray::get(PointArray::Uint pos) {
        if (pos >= this->_size)
            return nullptr;

        return &(this->_arr[pos]);
    }

    const Point *PointArray::get(PointArray::Uint pos) const {
        if (pos >= this->_size)
            return nullptr;

        return &(this->_arr[pos]);
    }


}