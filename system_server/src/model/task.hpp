#ifndef TASK_HPP
#define TASK_HPP

#include <cstdint>
#include <iostream>
#include <string>

class Task
{
private:
	uint32_t id;
	std::string description;
	std::string status;
	uint32_t pickUpLocation;
	uint32_t deliveryLocation;
	uint16_t payload;
	double deadline;
	uint32_t robotInCharge;
	uint32_t seqNumber;
	double startTime;
	double endTime;

public:
	Task(uint32_t id = 0, uint32_t pickUpLocation = 0, uint32_t deliveryLocation = 0, uint16_t payload = 0, double deadline = 0);

	void setId(uint32_t id);
	void setDescription(std::string description);
	void setStatus(std::string status);
	void setPickUpLocation(uint32_t pickUpLocation);
	void setDeliveryLocation(uint32_t deliveryLocation);
	void setPayload(uint16_t payload);
	void setDeadline(double deadline);
	void setRobotInCharge(uint32_t robotInCharge);
	void setSeqNumber(uint32_t seqNumber);
	void setStartTime(double startTime);
	void setEndTime(double endTime);

	uint32_t getId() const;
	std::string getDescription() const;
	std::string getStatus() const;
	uint32_t getPickUpLocation() const;
	uint32_t getDeliveryLocation() const;
	uint16_t getPayload() const;
	double getDeadline() const;
	uint32_t getRobotInCharge() const;
	uint32_t getSeqNumber() const;
	double getStartTime() const;
	double getEndTime() const;

	friend bool operator==(const Task &t1, const Task &t2);
	friend std::ostream &operator<<(std::ostream &os, const Task &t);
	bool operator<(const Task &taskObj);

	static const std::string STATUS_NEW;
	static const std::string STATUS_SCHEDULED;
	static const std::string STATUS_PERFORMING_PICK_UP;
	static const std::string STATUS_PERFORMING_DELIVERY;
	static const std::string STATUS_SUCESS;
	static const std::string STATUS_FAILED;
	static const std::string STATUS_TO_CANCEL_USER;
	static const std::string STATUS_CANCELLED_USER;
	static const std::string STATUS_TO_CANCEL_DEADLINE;
	static const std::string STATUS_CANCELLED_DEADLINE;
	static const std::string STATUS_CANCELLED;
};

#endif