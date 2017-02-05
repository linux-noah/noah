#!/bin/bash

set -eu

TREE_ROOT=${1-~/.noah/tree}
SCRIPT_DIR=`dirname $0`

sudo sh -c "$SCRIPT_DIR/mkgroup.pl | sort | uniq > $TREE_ROOT/etc/group"
sudo sh -c "$SCRIPT_DIR/mkpasswd.pl | sort | uniq > $TREE_ROOT/etc/passwd"

sudo chmod u+w $TREE_ROOT/etc/sudoers
sudo sh -c "echo 'yuichi ALL=(ALL) NOPASSWD: ALL' >> $TREE_ROOT/etc/sudoers"
sudo chmod u-w $TREE_ROOT/etc/sudoers

sudo sh -c "cat /etc/resolv.conf >> $TREE_ROOT/etc/resolv.conf"
