#!/bin/bash
for i in `seq 1 1`;
    do
            printf "\nRunning test $i:\n" >> results.txt
            ./graph < ./tests/test$i.in >> results.txt
            printf "\n===========\n" >> results.txt
    done
