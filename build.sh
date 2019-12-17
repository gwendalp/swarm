#!/bin/bash


cd /home/gwen/Documents/CPP/EVAL/VIBES/viewer/make/;
./VIBes-viewer &
cd /home/gwen/Documents/CPP/EVAL;
g++ main.cpp Robot.cpp vibes.cpp math.cpp -o out;
echo "HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
./out
