#!/usr/bin/perl
# Walter Rasmussen - Spring 2018
# Histogram of letters from dict
# dicHist.pl

$fn="/usr/share/dict/american-english-large"; # Location of words
open(IN,"$fn") or die "Cannot open\n"; # open file

while (<IN>) {
	chomp; # clean newlines 
	@word = split(//); # Seperate each char
	foreach $letter (@word) {
		if ($letter!~m/[A-z]/) { next; } # All chars not A-z are ignored
		$hist{$letter}++; # Chars used as keys, value is number of appearances
	}
}

@histkeys = sort(keys(%hist)); # Gets the keys in alphabetical order
$max = (sort {$a <=> $b} values(%hist))[-1]; # Get largest value in Hash
foreach $key (@histkeys){
	# Normilizes by multipling by 70 then dividing by the largest value in Hash
	# Prints key then # of * based on normilized value 
	print("$key\: " . ('*' x ($hist{$key} * 70 / $max)) . "\n");
}

close(IN); # close file

