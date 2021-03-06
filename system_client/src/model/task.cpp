#include "task.hpp"

const std::string Task::STATUS_NEW = "N";

Task::Task(uint32_t id, uint32_t pickUpLocation, uint32_t deliveryLocation, uint16_t payload, double deadline)
{
	this->id = id;
	this->pickUpLocation = pickUpLocation;
	this->deliveryLocation = deliveryLocation;
	this->payload = payload;
	this->deadline = deadline;
}

void Task::setId(uint32_t id)
{
	this->id = id;
}

void Task::setDescription(std::string description)
{
	this->description = description;
}

void Task::setStatus(std::string status)
{
	this->status = status;
}

void Task::setPickUpLocation(uint32_t pickUpLocation)
{
	this->pickUpLocation = pickUpLocation;
}

void Task::setDeliveryLocation(uint32_t deliveryLocation)
{
	this->deliveryLocation = deliveryLocation;
}

void Task::setPayload(uint16_t payload)
{
	this->payload = payload;
}

void Task::setDeadline(double deadline)
{
	this->deadline = deadline;
}

void Task::setRobotInCharge(uint32_t robotInCharge)
{
	this->robotInCharge = robotInCharge;
}

void Task::setSeqNumber(uint32_t seqNumber)
{
	this->seqNumber = seqNumber;
}

uint32_t Task::getId() const
{
	return id;
}

std::string Task::getDescription() const
{
	return description;
}

std::string Task::getStatus() const
{
	return status;
}

uint32_t Task::getPickUpLocation() const
{
	return pickUpLocation;
}

uint32_t Task::getDeliveryLocation() const
{
	return deliveryLocation;
}

uint16_t Task::getPayload() const
{
	return payload;
}

uint32_t Task::getRobotInCharge() const
{
	return robotInCharge;
}

uint32_t Task::getSeqNumber() const
{
	return seqNumber;
}

double Task::getDeadline() const
{
	return deadline;
}

bool operator==(const Task &t1, const Task &t2)
{
	return t1.id == t2.id;
}

std::ostream &operator<<(std::ostream &os, const Task &t)
{
	os << t.id << " " << t.pickUpLocation << " "
	   << t.deliveryLocation << " " << t.payload << " " << t.deadline << std::endl;
	return os;
}

bool Task::operator<(const Task &taskObj)
{
	return (this->id < taskObj.id);
}