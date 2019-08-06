#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h> //for px4's external pose estimate

int main(int argc, char **argv) {
    

    ros::init(argc, argv, "indoor_control_node");
    ros::NodeHandle nh;

    //NOTE For px4's external pose estimate
    ros::Publisher px4_external_pose_estimate = nh.advertise<geometry_msgs::PoseStamped>("/mavros/vision_pose/pose",10);

    ros::Rate r(30); // 10 hz
    while (ros::ok())
    {
		geometry_msgs::PoseStamped  final_pose;
		final_pose.pose.position.x = 1.0;
		final_pose.pose.position.y = 1.0;
		final_pose.pose.position.z = 0.0;
		final_pose.header.stamp =  ros::Time::now ();//msgLeft->header.stamp
		px4_external_pose_estimate.publish(final_pose);

		r.sleep();
		ros::spinOnce();
    }

    
    return 0;
}
