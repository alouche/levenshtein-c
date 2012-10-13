
require 'rake/extensiontask'
require 'rake/testtask'

spec = Gem::Specification.load('levenshtein-c.gemspec')
Rake::ExtensionTask.new('levenshtein', spec)

Rake::TestTask.new do |t|
  t.libs << "test"
  t.test_files = FileList['test/*.rb']
  t.verbose = true
end

