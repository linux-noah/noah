#!/bin/bash

sudo sh -c "./mkgroup.pl | sort | uniq > ~/.noah/tree/etc/group"
sudo sh -c "./mkpasswd.pl | sort | uniq > ~/.noah/tree/etc/passwd"

sudo chmod u+w ~/.noah/tree/etc/sudoers
sudo sh -c 'echo "yuichi ALL=(ALL) NOPASSWD: ALL" >> ~/.noah/tree/etc/sudoers'
sudo chmod u-w ~/.noah/tree/etc/sudoers
