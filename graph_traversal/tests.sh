#!/bin/bash
        for i in `seq 1 7`;
        do
                printf "\nRunning test $i: " >> results.txt
                ./graph_traversal < tests/$i.in >> results.txt
        done
