#ifndef TASK_CONTROLLER_HPP
#define TASK_CONTROLLER_HPP

#include <vector>

#include "../model/task.hpp"
#include "../model/robot.hpp"
#include "../model/location.hpp"
#include "../dao/taskDao.hpp"

#include "../scheduler/chromosome.hpp"

class TaskController
{
private:
    TaskDao td;
    std::vector<Task> tasksToSchedule;

public:
    TaskController();
    TaskController(GeneralDao *gDao);
    ~TaskController();

    void updateTasksToSchedule(uint32_t numberOfTasks);
    bool updateTaskScheduled(std::vector<uint32_t> &tasksScheduled, std::vector<uint32_t> &robots, std::vector<uint32_t> &tasksFailed);
    //most of the paramters of system_server::MsgTask are no used in this method
    //but it make the callScheduler in generalController simple
    bool updateTaskScheduled(std::map<uint32_t, system_server::MsgTaskList> &listOfTaskList, std::vector<uint32_t> &taskFailedId);
    bool updateTask(uint32_t id, TaskDao::Column column, std::string data);
    
    std::vector<Task> *getTaskList();
    Task *getTaskById(uint32_t id);
    Task *getTaskByIndex(uint32_t index);
    void copyTaskList(std::vector<Task> &copy);
    std::size_t getTaskListSize();

    Chromosome generateTasks(uint32_t numberOfTasks, std::vector<Robot> *freeRobotList, std::vector<std::vector<double>> *distanceMatrix, uint32_t numberOfDepots);
    Chromosome generateTasksCoordination(std::vector<Robot> *freeRobotList, std::vector<std::vector<double>> *distanceMatrix);
};

#endif