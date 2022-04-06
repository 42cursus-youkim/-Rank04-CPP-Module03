#!/bin/bash

NAME=$1

#exit if no name is given using [[]]
if [[ -z $NAME ]]; then
  echo "No name given"
  exit 1
fi

for ex in ex0?/; do
  git add $ex/src/$NAME.cpp $ex/include/$NAME.hpp
done

git status