#!/bin/bash

dir=$(cd `dirname $0`; pwd)
cd $dir/..
git pull
cd $HOME/.vim_runtime
git pull
cd $HOME/.oh-my-zsh
git pull

