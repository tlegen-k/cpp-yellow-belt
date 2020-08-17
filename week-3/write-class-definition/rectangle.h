/*
 * rectangle.h
 *
 *  Created on: Apr 17, 2020
 *      Author: tlegenkamidollayev
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#pragma once
class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;
    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_;
    int height_;
};




#endif /* RECTANGLE_H_ */
