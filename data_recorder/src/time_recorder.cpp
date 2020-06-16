#include "time_recorder.h"

std::string TimeRecorder::printfDataTitle(void)
{
	std::string str
		= topicTitle + ".time.data" + "\t";

	return(str);
}

std::string TimeRecorder::printfData(void)
{
	std::string str;
	if(flagDataReceived)
	{
		flagDataReceived = false;

		str = std::to_string(dataReceived.data.sec) + "." + std::to_string(dataReceived.data.nsec) + "\t";
	}
	else
	{
		str = std::string("\t");
	}

	return(str);
}

TimeRecorder::TimeRecorder(ros::NodeHandle& node, std::string& topicName, std::string& topicType,std::string& topicTitle)
{
	this->topicName = topicName;
	this->topicType = topicType;
	this->topicTitle = topicTitle;

	subscriber = node.subscribe<std_msgs::Time>(topicName, 1, &TimeRecorder::DataCallBack, this);

	flagDataReceived = false;
}

void TimeRecorder::DataCallBack(const std_msgs::Time::ConstPtr& data)
{
	flagDataReceived = true;
	dataReceived = *data;
}
