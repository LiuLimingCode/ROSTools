#include "time_recorder.h"

template<typename T>
std::string TimeRecorder<T>::printfDataTitle(void)
{
	std::string str
		= topicTitle + ".time.data" + "\t";

	return(str);
}

template<typename T>
std::string TimeRecorder<T>::printfData(void)
{
	std::string str;
	if(flagDataReceived)
	{
		double time = dataReceived.data.sec + (double)dataReceived.data.nsec / (double)1e9;
		
		flagDataReceived = false;

		str = std::to_string(time) + "\t";
	}
	else
	{
		str = std::string("\t");
	}

	return(str);
}

template<typename T>
TimeRecorder<T>::TimeRecorder(ros::NodeHandle& node, std::string& topicName,std::string& topicTitle)
{
	this->topicName = topicName;
	this->topicTitle = topicTitle;

	subscriber = node.subscribe<T>(topicName, 1, &TimeRecorder::DataCallBack, this);

	flagDataReceived = false;
}

template<typename T>
void TimeRecorder<T>::DataCallBack(const boost::shared_ptr<T const> & data)
{
	flagDataReceived = true;
	dataReceived = *data;
}

template class TimeRecorder<std_msgs::Time>;
template class TimeRecorder<std_msgs::Duration>;
