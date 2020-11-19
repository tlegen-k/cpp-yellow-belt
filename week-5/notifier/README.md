## Notifier
In this task, you need to develop the SmsNotifier and EmailNotifier classes that send SMS and e-mail notifications, respectively, and an abstract base class for them.

You are given the functions SendSms and SendEmail, which simulate sending SMS and e-mail.
```Cpp
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```
Develop:

1. Abstract base class INotifier, which will have one purely virtual method void Notify (const string & message).

2. The SmsNotifier class, which:

- is a descendant of the INotifier class;
- in the constructor takes one parameter of type string - phone number;
- overrides the Notify method and calls the SendSms function from it.

3. The EmailNotifier class, which;

- is a descendant of the INotifier class;
- in the constructor takes one parameter of type string - an email address;
- overrides the Notify method and calls the SendEmail function from it.
