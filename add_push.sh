#!/bin/bash

#to simplify git commands
#execute: ./add_push.sh

git add .
git commit -m $@
git push
