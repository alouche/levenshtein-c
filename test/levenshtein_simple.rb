# encoding: UTF-8

lib = File.expand_path(File.dirname(__FILE__) + '/../lib')
$LOAD_PATH.unshift(lib) if File.directory?(lib) && !$LOAD_PATH.include?(lib)

require "levenshtein.so"
require "test/unit"
 
class SimpleLevenshtein < Test::Unit::TestCase

  def test_simple
    assert_equal(1, Levenshtein.distance("helloworld", "helloowrld"))
    assert_equal(3, Levenshtein.distance("kitten", "sitting"))
    assert_equal(2, Levenshtein.distance("Supercalifragilisticexpialidocious", "Supercalifrajilisticexpialidotious"))
    assert_equal(1, Levenshtein.distance("hällo", "hallo"))
  end
end
