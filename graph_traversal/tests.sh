#!/bin/bash
        printf "BFS\n" >> results.txt
        for i in `seq 1 7`;
        do
                printf "\nRunning test $i:\n" >> results.txt
                ./graph < ./tests_bfs/$i.in >> results.txt
                printf "\n===========\n" >> results.txt
        done
        printf "\nDFS\n" >> results.txt
        for i in `seq 1 7`;
        do
                printf "\nRunning test $i:\n" >> results.txt
                ./graph < ./tests_dfs/$i.in >> results.txt
                printf "\n===========\n" >> results.txt
        done
