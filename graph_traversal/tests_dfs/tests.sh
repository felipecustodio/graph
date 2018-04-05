#!/bin/bash
        for i in `seq 1 7`;
        do
                printf "\nRunning test $i: " >> results.txt
                ./graph < ./$i.in >> ../results.txt
                printf "\n===========\n"
        done
