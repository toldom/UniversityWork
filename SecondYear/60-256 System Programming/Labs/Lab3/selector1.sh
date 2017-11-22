#!/bin/bash
word1=`grep -n $1<headandtail.txt | cut -b1 | head -n1`
word2=`grep -n $2<headandtail.txt | cut -b1 | head -n1`
head -n $word2 headandtail.txt | tail -n $((word1-word2-1))
