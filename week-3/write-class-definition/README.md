## Write definition of class

You are given full definition of class Rectangle
```cpp
{
    class Rectangle {
    public:
        Rectangle(int width, int height)
        {
            width_ = width;
            height_ = height;
        }

        int GetArea() const {
            return width_ * height_;
        }

        int GetPerimeter() const {
            return 2 * (width_ + height_);
        }

        int GetWidth() const { return width_; }
        int GetHeight() const { return height_; }

    private:
        int width_, height_;
    };
}
```
Send the header file rectangle.h containing the declaration for the Rectangle class. This should be a complete header file that can be used in a large project. In particular, it must solve the problem of double inclusion.
