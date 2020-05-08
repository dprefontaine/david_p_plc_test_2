#!/usr/bin/perl

#David Prefontaine
#4/22/20

#Problem 2 of Test 2

#-----------------------------------------------
#Showing dynamic and static scoping in Perl

$staticVarExample = "toast";
$dynamicVarExample = "ee";

sub lexicalScopeTest {
    my $staticVarExample = "trost";
    
    lexicalPrint();
}

sub dynamicScopeTest {
    local $dynamicVarExample = "eggs";
    
    dynamicPrint();
}

sub lexicalPrint {
    print "$staticVarExample-";
}

sub dynamicPrint {
    print "$dynamicVarExample";
}

lexicalScopeTest();
dynamicScopeTest();

print "\n";

print "$staticVarExample-";
print "$dynamicVarExample";
