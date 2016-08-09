#!/usr/bin/env ruby

require "open3"
require "shellwords"

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
    out, err, status = Open3.capture3("#{__dir__.shellescape}/../build/noah #{target.shellescape}")
    print(out)
    @assertion[:pass] += out.chars.count(".")
    @assertion[:fail] += out.chars.count("F")
    unless status.success?
      @assertion[:crash] += 1 
      print("X")
    end

    unless err.empty? && status.success?
      @assertion_reports << {name: File.basename(target), diff: nil, err: err, crash: !status.success?} # C assertion cannot print "diff" currently, so let it nil
    end
  end
end

def test_stdout
  test_targets = Dir.glob(__dir__ + "/test_stdout/build/*")
  test_targets.each do |target|
    testdata_base = __dir__ + "/test_stdout/" + File.basename(target)
    target_stdin = File.exists?(testdata_base + ".stdin") ? (testdata_base + ".stdin").shellescape : "/dev/null"
    target_arg = File.exists?(testdata_base + ".arg") ? File.read(testdata_base + ".arg") : ""
    expected = File.read(testdata_base + ".expected")
    out, err, status = Open3.capture3("#{__dir__.shellescape}/../build/noah #{target.shellescape} #{target_arg} < #{target_stdin}")

    if out == expected
      @stdout[:pass] += 1
      print(".")
    elsif status.success?
      @stdout[:fail] += 1
      print("F")
    else
      @stdout[:crash] += 1
      print("X")
    end

    unless err.empty? && status.success? && out == expected
      @stdout_reports << {name: File.basename(target), diff: [expected, out], err: err, crash: !status.success?}
    end
  end
end

def report
  puts("")
  (@assertion_reports + @stdout_reports).each_with_index do |report, i|
    puts("#{i}) #{report[:name]}")
    puts(report[:err]) unless report[:err].empty?
    if report[:diff] && report[:diff][0] != report[:diff][1]
      puts "== Expected"
      puts report[:diff][0]
      puts "== Actual"
      puts report[:diff][1]
      puts "=="
    end
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
