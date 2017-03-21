# HaHa
Project HaHa - A HaHa string to Latin string converter. 
Given an input string in HaHa, this will produce all Latin equivalents based on the rules at www.maxwellabrams.com/sandbox/ha.php

This is written in C++ for speed. On my test machine, a 26-ha long string took 58 seconds in C++, 14 minutes in Java, and crashed the broswer in JS

Compile instructions: gcc haha.cpp -o ha.out
Usage example: ./ha.out ha > ha_output.txt
ha_output.txt will contain: a

Time your results (try LARGE haha strings ;)) with command: time ./ha.out hahaha > ha_output.txt
