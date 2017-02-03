#!/bin/bash

set -eu

TREE_ROOT=${1-~/.noah/tree}

sudo sh -c "./mkgroup.pl | sort | uniq > $TREE_ROOT/etc/group"
sudo sh -c "./mkpasswd.pl | sort | uniq > $TREE_ROOT/etc/passwd"

sudo chmod u+w $TREE_ROOT/etc/sudoers
sudo sh -c "echo 'yuichi ALL=(ALL) NOPASSWD: ALL' >> $TREE_ROOT/etc/sudoers"
sudo chmod u-w $TREE_ROOT/etc/sudoers
