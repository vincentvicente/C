#!/bin/bash

# Script accepts a specific folder name as an argument
FOLDER_NAME=$1

# Define the paths for the resources repository and the target class repository
resources_dir="$HOME/5008/course_resources"
class_repo_dir="$HOME/5008/${USER}-5008"

# Navigate to the resources repository directory
echo "Navigating to the resources directory..."
cd "$resources_dir" || { echo "Failed to change directory to $resources_dir. Exiting..."; exit 1; }

# Pull the latest resources from the remote repository
echo "Pulling new resources from the 'course_resources' repo..."
git pull || { echo "Failed to pull changes from the resources repo. Exiting..."; exit 1; }

# Check if a specific folder name was provided as an argument
if [ -z "$FOLDER_NAME" ]; then
  echo "No specific folder provided. Please provide a folder name as an argument."
  exit 1
fi

# Ask the user for confirmation to copy the specific folder
read -p "Would you like to copy folder '$FOLDER_NAME' to '$class_repo_dir'? [y/n]: " confirm
if [ "$confirm" != "y" ]; then
  echo "Operation cancelled by user."
  exit 1
fi

# Copy the folder to the class repository
echo "Copying folder '$FOLDER_NAME' from 'course_resources' to your class repo..."
cp -R "$FOLDER_NAME" "$class_repo_dir" || { echo "Failed to copy folder '$FOLDER_NAME'. Exiting..."; exit 1; }

echo "Successfully copied folder '$FOLDER_NAME' from 'course_resources' to '$class_repo_dir'."

