#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <vector>

class TaskManager
{
public:
    typedef bool (*FpTask)();

private:
    typedef std::vector<FpTask> TaskArray;
    typedef TaskArray::size_type SizeType;

public:
    void Execute();
    void Register(FpTask task);

private:
    void Unregister(SizeType id);

private:
    TaskArray m_task;
};

#endif // !TASKMANAGER_H_
