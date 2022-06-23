#!/bin/zsh

set -e

git checkout master
git fetch upstream
git pull upstream master
git push origin master
