#ifndef TIME_RECORDER_H
#define TIME_RECORDER_H

#include <ros/ros.h>
#include "base_recorder.h"
#include <std_msgs/Time.h>
#include <std_msgs/Duration.h>

#define STRING_DURATION                  (std::string("Duration"))
#define STRING_TIME                      (std::string("Time"))

namespace DataRecorder {

	template<typename T>
	class TimeRecorder : public BaseRecorder
	{

	public:
		TimeRecorder(ros::NodeHandle& node, std::string& topicName,std::string& topicTitle);
		~TimeRecorder() = default;

		std::string printfDataTitle(void);
		std::string printfData(void);

		void DataCallBack(const boost::shared_ptr<T const> & data);

		
	protected:
		T dataReceived;
	};

} // namespace DataRecorder

#endif
