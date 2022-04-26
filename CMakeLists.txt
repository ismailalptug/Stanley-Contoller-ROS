cmake_minimum_required(VERSION 3.0.2)
project(stanley_contoller_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


catkin_package(
  INCLUDE_DIRS 
        include

  CATKIN_DEPENDS 
        roscpp rospy std_msgs message_runtime

  DEPENDS 
        system_lib
)


include_directories(
  include/
  ${catkin_INCLUDE_DIRS})

add_executable(stanley_node src/stanley_node.cpp
                            src/stanley.cpp
                            src/rosInterface.cpp
                            
)


add_dependencies(stanley_node 
    ${stanley_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(stanley_node 
    ${catkin_LIBRARIES})
