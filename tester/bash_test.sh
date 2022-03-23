#!/bin/bash

# Place this bash file in the same folder as the executable
# the executable has to ready as well.

if [[ $(./philo 4 300 200 200 4 | grep "died") ]]; then
	echo "true 1"
else
	echo "false 1"
fi

if [[ ! $(./philo 4 500 200 200 4 | grep "died") ]]; then
	echo "true 2"
else
	echo "false 2"
fi

if [[ $(./philo 1 800 200 200 4 | grep "died") ]]; then
	echo "true 3"
else
	echo "false 3"
fi

if [[ ! $(./philo 5 800 200 200 7 | grep "died") ]]; then
	echo "true 4"
else
	echo "false 4"
fi

if [[ ! $(./philo 4 410 200 200 7 | grep "died") ]]; then
	echo "true 5"
else
	echo "false 5"
fi

if [[ $(./philo 4 310 200 100 10 | grep "died") ]]; then
	echo "true 6"
else
	echo "false 6"
fi

