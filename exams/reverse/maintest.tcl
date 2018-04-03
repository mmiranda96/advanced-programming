#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}


# Sample 1
eval spawn [lrange $argv 0 end]
send "3\r"
send "Hello World\r"
send "Bye World\r"
send "Useless World\r"
expect "World Hello\r" {foreground green; puts "SAMPLE #1 SENTENCE 1 PASSED";reset} default {foreground red;puts "SAMPLE #1 SENTENCE 1 FAILED";reset}
expect "World Bye\r" {foreground green; puts "SAMPLE #1 SENTENCE 2 PASSED";reset} default {foreground red;puts "SAMPLE #1 SENTENCE 2 FAILED";reset}
expect "World Useless\r" {foreground green; puts "SAMPLE #1 SENTENCE 3 PASSED";reset} default {foreground red;puts "SAMPLE #1 SENTENCE 3 FAILED";reset}

# Sample 2
eval spawn [lrange $argv 0 end]
send "5\r"
send "negotiate with reason\r"
send "a quick brown fox\r"
send "this is a random sentance\r"
send "this is not so random a sentance\r"
send "ok bye\r"
expect "reason with negotiate\r" {foreground green; puts "SAMPLE #2 SENTENCE 1 PASSED";reset} default {foreground red;puts "SAMPLE #2 SENTENCE 1 FAILED";reset}
expect "fox brown quick a\r" {foreground green; puts "SAMPLE #2 SENTENCE 2 PASSED";reset} default {foreground red;puts "SAMPLE #2 SENTENCE 2 FAILED";reset}
expect "sentance random a is this\r" {foreground green; puts "SAMPLE #2 SENTENCE 3 PASSED";reset} default {foreground red;puts "SAMPLE #2 SENTENCE 3 FAILED";reset}
expect "sentance a random so not is this\r" {foreground green; puts "SAMPLE #2 SENTENCE 4 PASSED";reset} default {foreground red;puts "SAMPLE #2 SENTENCE 4 FAILED";reset}
expect "bye ok\r" {foreground green; puts "SAMPLE #2 SENTENCE 5 PASSED";reset} default {foreground red;puts "SAMPLE #2 SENTENCE 5 FAILED";reset}

# Sample 3
eval spawn [lrange $argv 0 end]
send "1\r"
send "GJWZVCJVtP eCVVctHmKd VWujjBKLBZ vgHTRrkRcG gcfCOImnle DyZXTBEMHK OSWwPzGPeC MFTpOaNJMp tOsWIuIEkv nvhiEGhDmA PEWmCrsVQj nBDzgtsZRv nEDJEClizk MzxtglNkvb foMgjveoLS CUKiMRXwRY NoYmdNmmmD YgpNrlHlao gVkaBonMKh mLwkzXZwru WgblApQFFn hlWQPLuXQy BVnlJvTYpb zUckgxDloY YBjaeUDweI ljXyamsfGQ JiMzlmWPEL cmiXkMvVht IaupDzBeNd wuNqftQRPv zsVwmwiRcO yowCqySAHL eHfhqJQwNT CbcISTCRvU gGBUUWhZjZ KzCUsnrnGb aNjGyHwtyM YRxhbPoOou uYiAiCXcZy KegowfNfBg DEBFXcOyHg qIrkhoOQUw JqHAtgZXFV DjMkosWDuG TjRCSyROeS yxaypXPOiw CfurJhqLDo JjuKawZgaY uQtyeZZWdS lnQhcIbnVI JdfzhSKawj RjMvraiciW gNxHwRtpKr qjVvhNbsWV eOqrJzKmMg WIaWqJEOje XjHaxxCsEK stELzHInHA lhoNRVuBZl ciwIfYsUKq gldfkjldkd pfdofgDFsd dflpdlffss SDFSDFFSDd gdfgdfgdfd FDGHfghghs WERERertrw BMBNxcBNvc DFGjkYUsad SAQWqwqQWq NMJKUIhjui PdOUUIXCss BNMDyudhgs sdmpodSDhd RTOqwMSHGs AZlofdstjd dfNHQQmghd plpLLKgyyg QADRfghgmv dffpertgdf sdfxcvxcvd olplqdoiie ploosdpkis MFCKSDALSL PWOECMSCSD fsdfsdflll sdpoapsodp axxcvbndsd asddfgoiuu mnbbxcvxcz ERTYUIOIOI plmkUIOwss ETYUIbsewT qazWSXedcR HJiogyiojf dfgdfgdfdd wserplldfd dghnmmxxco efghggffdg FPSdsdfpaq\r"
expect "FPSdsdfpaq efghggffdg dghnmmxxco wserplldfd dfgdfgdfdd HJiogyiojf qazWSXedcR ETYUIbsewT plmkUIOwss ERTYUIOIOI mnbbxcvxcz asddfgoiuu axxcvbndsd sdpoapsodp fsdfsdflll PWOECMSCSD MFCKSDALSL ploosdpkis olplqdoiie sdfxcvxcvd dffpertgdf QADRfghgmv plpLLKgyyg dfNHQQmghd AZlofdstjd RTOqwMSHGs sdmpodSDhd BNMDyudhgs PdOUUIXCss NMJKUIhjui SAQWqwqQWq DFGjkYUsad BMBNxcBNvc WERERertrw FDGHfghghs gdfgdfgdfd SDFSDFFSDd dflpdlffss pfdofgDFsd gldfkjldkd ciwIfYsUKq lhoNRVuBZl stELzHInHA XjHaxxCsEK WIaWqJEOje eOqrJzKmMg qjVvhNbsWV gNxHwRtpKr RjMvraiciW JdfzhSKawj lnQhcIbnVI uQtyeZZWdS JjuKawZgaY CfurJhqLDo yxaypXPOiw TjRCSyROeS DjMkosWDuG JqHAtgZXFV qIrkhoOQUw DEBFXcOyHg KegowfNfBg uYiAiCXcZy YRxhbPoOou aNjGyHwtyM KzCUsnrnGb gGBUUWhZjZ CbcISTCRvU eHfhqJQwNT yowCqySAHL zsVwmwiRcO wuNqftQRPv IaupDzBeNd cmiXkMvVht JiMzlmWPEL ljXyamsfGQ YBjaeUDweI zUckgxDloY BVnlJvTYpb hlWQPLuXQy WgblApQFFn mLwkzXZwru gVkaBonMKh YgpNrlHlao NoYmdNmmmD CUKiMRXwRY foMgjveoLS MzxtglNkvb nEDJEClizk nBDzgtsZRv PEWmCrsVQj nvhiEGhDmA tOsWIuIEkv MFTpOaNJMp OSWwPzGPeC DyZXTBEMHK gcfCOImnle vgHTRrkRcG VWujjBKLBZ eCVVctHmKd GJWZVCJVtP" {foreground green; puts "SAMPLE #3 PASSED";reset} default {foreground red;puts "SAMPLE #3 FAILED";reset}
