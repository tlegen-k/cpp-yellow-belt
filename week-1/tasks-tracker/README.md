## Tasks tracker

Implement TeamTasks class, that allows to store statistics on the task statuses of the development team.
```cpp
{
    // Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);
};

}
```
The PerformPersonTasks method must implement the following algorithm:

    Let's take a look at all of the outstanding developer tasks person.
    Let's sort them by statuses: first, all tasks in the NEW status, then all tasks in the IN_PROGRESS status, and finally, tasks in the TESTING status.
    Let's consider the first task_count tasks and transfer each of them to the following status in accordance with the natural order: NEW → IN_PROGRESS → TESTING → DONE.
    Let's return a tuple of two elements: information about the statuses of the updated tasks (including those that ended up in the DONE status) and information about the statuses of the remaining uncompleted tasks.

If there is no developer named person, the PerformPersonTasks method should return a tuple of two empty TasksInfo

It is guaranteed that task_count is positive. If task_count exceeds the current number of uncompleted tasks of the developer, it is sufficient to assume that task_count is equal to the number of uncompleted tasks: you do not need to update the status of any task twice in this case.

In addition, it is guaranteed that the GetPersonTasksInfo method will not be called for a developer who has no tasks.
An example of the PerformPersonTasks method

Let's assume that a particular developer has 10 tasks with the following statuses:

    NEW - 3
    IN_PROGRESS - 2
    TESTING - 4
    DONE - 1

The PerformPersonTasks command is received with the task_count = 4 parameter, which means the status update for 3 tasks from NEW to IN_PROGRESS and for 1 task from IN_PROGRESS to TESTING. Thus, the new task statuses will be as follows:

    IN_PROGRESS - 3 updated, 1 old
    TESTING - 1 updated, 4 old
    DONE - 1 old

In this case, you need to return a tuple of 2 dictionaries:

    Updated tasks: IN_PROGRESS - 3, TESTING - 1.
    Tasks not updated, excluding completed ones: IN_PROGRESS - 1, TESTING - 4.

None of the dictionaries should contain unnecessary elements, that is, statuses that correspond to zero tasks.

By convention, DONE tasks do not need to be returned in untouched tasks (untouched_tasks).
Note

Updating a dictionary while iterating over it can lead to unpredictable consequences. If such a need arises, it is recommended to first collect information about the updates in a separate temporary dictionary, and then apply them to the main dictionary.
