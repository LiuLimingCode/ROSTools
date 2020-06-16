#ifndef TIME_RECORDER_H
#define TIME_RECORDER_H

#include <ros/ros.h>
#include "base_recorder.h"
#include <std_msgs/Time.h>

#define STRING_TIME                      (std::string("Time"))

class TimeRecorder : public BaseRecorder
{

public:
	TimeRecorder(ros::NodeHandle& node, std::string& topicName, std::string& topicType,std::string& topicTitle);
	~TimeRecorder() = default;

	std::string printfDataTitle(void);
	std::string printfData(void);

	void DataCallBack(const std_msgs::Time::ConstPtr& data);

	
protected:
	std_msgs::Time dataReceived;
};

#endif
