#!/usr/bin/env ruby

require "open3"

@assertion = {pass: 0, fail: 0, crash: 0}
@assertion_reports = []
@stdout = {pass: 0, fail: 0, crash: 0}
@stdout_reports = []

def main
  puts <<-"EOS"

===============
Test Starts
===============

  EOS
  test_assertion()
  test_stdout()
  puts("")
  report()
end

def test_assertion
  test_targets = Dir.glob(__dir__ + "/test_assertion/build/*")
  test_targets.each do |target|
    out, err, status = Open3.capture3("#{__dir__}/../build/noah #{target}")
    print(out)
    @assertion[:pass] += out.chars.count(".")
    @assertion[:fail] += out.chars.count("F")
    unless status.success?
      @assertion[:crash] += 1 
      print("X")
    end

    unless err.empty? and status.success?
      @assertion_reports << {name: File.basename(target), err: err, crash: !status.success?}
    end
  end
end

def test_stdout
  test_targets = Dir.glob(__dir__ + "/test_stdout/build/*")
  test_targets.each do |target|
    testdata_base = __dir__ + "/test_stdout/" + File.basename(target)
    target_stdin = testdata_base + ".stdin"
    out, err, status = Open3.capture3("#{__dir__}/../build/noah #{target} < #{File.exists?(target_stdin) ? target_stdin : '/dev/null'}")

    if out == File.read(testdata_base + ".expected")
      @stdout[:pass] += 1
      print(".")
    elsif status.success?
      @stdout[:fail] += 1
      print("F")
    else
      @stdout[:crash] += 1
      print("X")
    end

    unless err.empty? and status.success?
      @stdout_reports << {name: File.basename(target), err: err, crash: !status.success?}
    end
  end
end

def report
  puts("")
  (@assertion_reports + @stdout_reports).each_with_index do |report, i|
    puts("#{i}) #{report[:name]}")
    puts(report[:err]) unless report[:err].empty?
    puts(report[:name] + " Crashed !!") if report[:crash]
  end

  puts <<-"EOS"

===============
Assertion Test:
  Pass: #{@assertion[:pass]}, Fail: #{@assertion[:fail]}
  Crash Test Programs: #{@assertion[:crash]}
  Total Assertions: #{@assertion[:pass] + @assertion[:fail]}
Output Test:
  Pass: #{@stdout[:pass]}, Fail: #{@stdout[:fail]}
  Crash Test Programs: #{@stdout[:crash]}
  Total Test Programs: #{@stdout.values.reduce(&:+)}
  EOS
end

main
exit(1) unless @assertion_reports.empty? and @stdout_reports.empty?
