#!/usr/bin/env ruby

require 'set'

def usage
  puts "Usage: ./list_unimpl_syscall.rb linux-strace-file [noah-syscall.h]"
end

def get_implemented(syscall_h)
  search = [
    "./include/syscall.h",
    "../include/syscall.h",
  ];
  search.unshift(syscall_h) if syscall_h
  syscall_header = search.select {|path| File.exist?(path)}.first
  if syscall_header.nil?
    STDERR.puts "Could not find syscall.h"
  end
  ret = Set.new
  reg = /SYSCALL\([0-9]+, (.*)\)/
  File.open(syscall_header).each {|l|
    syscall = reg.match(l)
    ret.add syscall[1] if syscall
  }
  ret
end

def print_needed(linux_strace, noah_syscall_h)
  implemented = get_implemented(noah_syscall_h)
  reg = /^[0-9]*\s*([a-zA-Z0-9]+)\(/
  File.open(linux_strace).each {|l|
    syscall = reg.match(l)
    if syscall && !implemented.include?(syscall[1])
      puts syscall[1]
      implemented.add syscall[1]
    end
  }
end

if ARGV.length < 1
  usage
  exit
end

puts "Unimplemented systemcalls for '#{ARGV[0]}':"
print_needed(ARGV[0], ARGV[1])
