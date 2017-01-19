#!/usr/bin/perl

use strict;

my ($name, $password, $gid, @users);

open(GROUP, "dscacheutil -q group |");

while (<GROUP>) {
    chomp;
    $name = $1 if $_ =~ /name: (.*)/;
    $password = $1 if $_ =~ /password: (.*)/;
    $gid = $1 if $_ =~ /gid: (.*)/;
    if ($_ =~ /users: (.*)/) {
        @users = split ' ', $1;
    }
    if ($_ eq "") {
        print "$name:$password:$gid:";
        if (@users) {
            print join(',', @users);
        }
        print "\n";
        @users = undef;
    }
}
