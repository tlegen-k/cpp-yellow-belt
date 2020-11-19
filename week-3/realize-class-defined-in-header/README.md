## Realize class defined in header file

You are given the template_phone_number.h header file containing the declaration of the PhoneNumber class. At the same time, the comments describe the behavior that is expected from the implementation of this class[template_phone_number.h](./template_phone_number.h).

```cpp
{
    #pragma once

    #include <string>

    using namespace std;

    class PhoneNumber {
    public:
      /* Принимает строку в формате +XXX-YYY-ZZZZZZ
         Часть от '+' до первого '-' - это код страны.
         Часть между первым и вторым символами '-' - код города
         Всё, что идёт после второго символа '-' - местный номер.
         Код страны, код города и местный номер не должны быть пустыми.
         Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

         Примеры:
         * +7-495-111-22-33
         * +7-495-1112233
         * +323-22-460002
         * +1-2-coursera-cpp
         * 1-2-333 - некорректный номер - не начинается на '+'
         * +7-1233 - некорректный номер - есть только код страны и города
      */
      explicit PhoneNumber(const string &international_number);

      string GetCountryCode() const;
      string GetCityCode() const;
      string GetLocalNumber() const;
      string GetInternationalNumber() const;

    private:
      string country_code_;
      string city_code_;
      string local_number_;
    };

}
```
Please send a cpp-file with **definitions** of methods of the PhoneNumber class that implement the described behavior.

**How your code will be tested**

The automated testing system will add your cpp file to the project containing another cpp file with unit tests for the PhoneNumber class, as well as the phone_number.h file. Then it will build this project and, if the compilation is successful, it will run the resulting executable file. If it succeeds (that is, unit tests do not find errors in your implementation), then your submission will be counted.
