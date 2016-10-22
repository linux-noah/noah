#!/usr/bin/env ruby

require "open3"
require "shellwords"
require "pathname"

@assertion = {pass: 0, fail: 0, premature: 0}
@assertion_reports = []
@stdout = {pass: 0, fail: 0, premature: 0}
@stdout_reports = []
@shell = {pass: 0, fail: 0, premature: 0}
@shell_reports = []

@verbose = false

def main
  if ARGV[0] == "-v"
    ARGV.shift
    @verbose = true
  end
  targets = ARGV.empty? ? nil : ARGV
  puts <<-"EOS"

===============
Test Starts
===============

  EOS
  test_assertion(targets)
  test_stdout(targets)
  test_shell(targets)
  puts("")
  report()
end

def relative(path)
  p = Pathname.new(path)
  p.relative_path_from(Pathname.new(Dir.pwd)).to_s
end

def puts_testname(target)
  puts "\n===#{File.basename(target)}" if @verbose
end

def test_assertion(targets = nil)
  Dir.glob(__dir__ + "/test_assertion/build/*").each do |target|
    next if targets && !targets.include?(File.basename(target))
    puts_testname(target)
    out, err, status = Open3.capture3("#{__dir__.shellescape}/../build/noah #{relative(target).shellescape}")
    
    nr_tests_match = /1->([0-9]+)/.match(out.lines[0])
    if nr_tests_match
      nr_tests = nr_tests_match[1].to_i
    else
      nr_tests = -1 # It seems that the test crashed
    end

    print(out.lines[1..-1].join("")) if out.lines.length > 0

    passes = out.chars.count(".")
    fails = out.chars.count("F")
    is_premature = !status.success? || nr_tests != out.chars.count(".") + out.chars.count("F")

    @assertion[:pass] += passes
    @assertion[:fail] += fails
    if is_premature
      @assertion[:premature] += 1
      print("X")
    end

    if fails > 0 || is_premature
      @assertion_reports << {name: File.basename(target), diff: ["(diff unavailable)", "(diff unavailable)"], err: err, premature: is_premature}
    end
  end
end

def test_stdout(targets = nil)
  Dir.glob(__dir__ + "/test_stdout/build/*").each do |target|
    next if targets && !targets.include?(target)
    puts_testname(target)
    testdata_base = __dir__ + "/test_stdout/" + File.basename(target)
    target_stdin = File.exists?(testdata_base + ".stdin") ? (testdata_base + ".stdin").shellescape : "/dev/null"
    target_arg = File.exists?(testdata_base + ".arg") ? File.read(testdata_base + ".arg") : ""
    expected = File.read(testdata_base + ".expected")
    out, err, status = Open3.capture3("#{__dir__.shellescape}/../build/noah #{relative(target).shellescape} #{target_arg} < #{target_stdin}")

    if out == expected
      @stdout[:pass] += 1
      print(".")
    elsif status.success?
      @stdout[:fail] += 1
      print("F")
    else
      @stdout[:premature] += 1
      print("X")
    end

    unless err.empty? && status.success? && out == expected
      @stdout_reports << {name: File.basename(target), diff: [expected, out], err: err, premature: !status.success?}
    end
  end
end

def test_shell(targets = nil)
  Dir.glob(__dir__ + "/test_shell/build/*").each do |target|
    next if targets && !targets.include?(target)
    puts_testname(target)
    run = __dir__ + "/test_shell/" + File.basename(target) + ".sh"

    _, err, status = Open3.capture3("NOAH=#{__dir__.shellescape}/../build/noah TARGET=#{relative(target).shellescape} /bin/bash #{relative(run).shellescape}")

    if status.success?
      @shell[:pass] += 1
      print(".")
    else
      @shell[:fail] += 1
      print("F")
    end

    unless err.empty? && status.success?
      @shell_reports << {name: File.basename(target), diff: ["(diff unavailable)", "(diff unavailable)"], err: err, premature: false}
    end
  end
end

def report
  puts("")
  (@assertion_reports + @stdout_reports + @shell_reports).each_with_index do |report, i|
    puts("#{i}) #{report[:name]}")
    puts(report[:err]) unless report[:err].empty?
    if report[:diff] && report[:diff][0] != report[:diff][1]
      puts "== Expected"
      puts report[:diff][0]
      puts "== Actual"
      puts report[:diff][1]
      puts "=="
    end
    puts(report[:name] + " stopped prematurely!!") if report[:premature]
  end

  puts <<-"EOS"

===============
Assertion Test:
  Pass: #{@assertion[:pass]}, Fail: #{@assertion[:fail]}
  Premature Test Programs: #{@assertion[:premature]}
  Total Assertions: #{@assertion[:pass] + @assertion[:fail]}
Output Test:
  Pass: #{@stdout[:pass]}, Fail: #{@stdout[:fail]}
  Premature Test Programs: #{@stdout[:premature]}
  Total Test Programs: #{@stdout.values.reduce(&:+)}
Shell Test:
  Pass: #{@shell[:pass]}, Fail: #{@shell[:fail]}
  Total Test Programs: #{@shell.values.reduce(&:+)}
  EOS
end

main
exit(1) unless @assertion_reports.empty? and @stdout_reports.empty?
