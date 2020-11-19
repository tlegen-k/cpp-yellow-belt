## Figures
You are given the main function, which reads commands for working with a set of geometric shapes from standard input:
```cpp
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
```
As you can see from the code, there are two kinds of commands:

- ADD - add a shape to the set;
- PRINT - for each shape in the set, print the name, perimeter and area.

The program supports three types of shapes: rectangle, triangle and circle. Their addition is described as follows:

1. ADD RECT width height - add a rectangle with dimensions width and height (for example, ADD RECT 2 3).
2. ADD TRIANGLE a b c - add a triangle with sides a, b and c (for example, ADD TRIANGLE 3 4 5).
3. ADD CIRCLE r - add a circle of radius r (for example, ADD CIRCLE 5).

Without changing the main function, implement the missing functions and classes:

- base class Figure with purely virtual methods Name, Perimeter and Area;
- the Triangle, Rect, and Circle classes that inherit from the Figure class and override its virtual methods;
- the CreateFigure function, which, depending on the content of the input stream, creates a shared_ptr <Rect>, shared_ptr <Triangle>, or shared_ptr <Circle>.

It is guaranteed that the sizes of all shapes are natural numbers no greater than 1000. Use 3.14 for the PI value.
