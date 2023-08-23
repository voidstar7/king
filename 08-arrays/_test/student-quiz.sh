#!/bin/bash

input1="8 3 3 5 2\n"
input2="5 4 4 2 1\n"
input3="2 2 3 2 9\n"
input4="9 2 2 2 4\n"
input5="2 1 3 2 3\n"

./a.out <<EOF
$input1
$input2
$input3
$input4
$input5
EOF
