import os

from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    param_dir = LaunchConfiguration('param_dir', default=os.path.join(
        get_package_share_directory('practice'),
        'param',
        'turtlesim.yaml'
        ))


    return LaunchDescription([
        
        Node(package='practice',
             executable='msgPublisher',
             output='screen',
             ),
        Node(package='practice',
             executable='msgSubscriber1',
             output='screen',
             ),
        Node(package='practice',
             executable='msgSubscriber2',
             output='screen',
             ),
        Node(package='practice',
             executable='timePublisher',
             output='screen',
             ),
        Node(package='practice',
             executable='timeSubscriber',
             output='screen',
             ),   
        Node(package='turtlesim',
            executable='turtlesim_node',
            output='screen',
            parameters=[param_dir]
            )                  
        ])

  