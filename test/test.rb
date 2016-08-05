#!/usr/bin/env ruby

require 'minitest'
require 'minitest/autorun'

class TestUserProgram < MiniTest::Test

  def self.create_test_suite
    test_targets = Dir.glob(__dir__ + "/build/*")
    test_targets.each do |target|
      testdata_base = __dir__ + "/test_stdout/" + File.basename(target)
      add_test(target, testdata_base + ".stdin", testdata_base + ".expected")
    end
  end

  def self.add_test(target, target_in, expected)
    define_method("test_" + File.basename(target)) do
      assert_equal(File.read(expected), `#{__dir__}/../build/noah #{target} < #{File.exists?(target_in) ? target_in : "/dev/null"}`)
    end
  end

  create_test_suite()
end
