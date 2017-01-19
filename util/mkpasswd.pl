#!/usr/bin/perl

use strict;

my ($name, $password, $uid, $gid, $dir, $shell, $gecos);

open(USER, "dscacheutil -q user |");

while (<USER>) {
    chomp;
    $name = $1 if $_ =~ /name: (.*)/;
    $password = $1 if $_ =~ /password: (.*)/;
    $uid = $1 if $_ =~ /uid: (.*)/;
    $gid = $1 if $_ =~ /gid: (.*)/;
    $dir = $1 if $_ =~ /dir: (.*)/;
    $shell = $1 if $_ =~ /shell: (.*)/;
    $gecos = $1 if $_ =~ /gecos: (.*)/;
    if ($_ eq "") {
        print "$name:$password:$uid:$gid:$gecos:$dir:$shell\n";
    }
}
