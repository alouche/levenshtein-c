
Gem::Specification.new do |s|
  s.name        = "levenshtein-c"
  s.version     = "0.1.0"
  s.description = "Levenshtein ruby lib with unicode support"
  s.summary     = "Simple Ruby C Levenshtein algorithm lib"
  s.author      = "Ali Abbas"
  s.email       = "ali@alouche.net"
  s.homepage    = "https://github.com/alouche/levenshtein-c"
  s.files       = Dir.glob("ext/**/*.{c,rb}") + Dir.glob("lib/**/*.rb")
  s.extensions << "ext/levenshtein/extconf.rb"
  s.add_development_dependency "rake-compiler"
end
