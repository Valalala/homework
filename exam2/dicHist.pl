#!/usr/bin/perl
# Walter Rasmussen - Spring 2018
# Histogram of letters from dict
# dicHist.pl

use warnings;

$fn="/usr/share/dict/words";
open(IN,"$fn") or die "Cannot open\n";

while (<IN>) {
	chomp;
	@word = split(//);
	foreach $letter (@word) {
		if ($letter!~m/[A-z]/) { next; }
		$hist{$letter}++;
	}
}

@histkeys = sort(keys(%hist));
#foreach $key (keys(%hist)) {
#	print("$key\: $hist{$key}\n");
#}
foreach $key (@histkeys){
	print("$key\: $hist{$key}\n");
}

