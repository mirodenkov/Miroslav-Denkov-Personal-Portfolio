import subprocess


def check_ros():
    result = subprocess.run(
        "echo $ROS_DISTRO", shell=True, capture_output=True, text=True
    )
    if result.stdout.strip() == "jazzy":
        print("ROS environment is sourced!")
    else:
        print("ROS environment not sourced!")


def reset_controller():
    result_cm1 = subprocess.run(
        ['ros2 service call /ufactory/set_mode xarm_msgs/srv/SetInt16 "{data: 1}"'],
        shell=True,
        text=True,
        timeout=5,
    )

    result_cm2 = subprocess.run(
        ['ros2 service call /ufactory/set_state xarm_msgs/srv/SetInt16 "{data: 0}"'],
        shell=True,
        text=True,
        timeout=5,
    )


def main():
    check_ros()
    reset_controller()


if __name__ == "__main__":
    main()
