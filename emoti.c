/*
 * emoti.c
 * This file is part of emoti
 *
 * Copyright (C) 2015 - Joe Glancy
 *
 * emoti is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * emoti is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with emoti. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * PLEASE NOTE: This may not work with all terminals, you will have to
 * try through trial-and-error, although I can say that it should work
 * on the Gnome terminalm LXTerminal and most other modern ones with
 * unicode support.
 */

#include <stdio.h>
#include <stdlib.h>

// Here follows the large emoti array declarations:
short *e1[] = {"^ω^", // Happy
               "( ﾟヮﾟ)",
               "。(⌒∇⌒。)",
               "( ´ ▽ ` )ﾉ",
               "(¬‿¬)",
               "＼（＠￣∇￣＠）／",
               "｡^‿^｡",
               "＼(^▽^＠)ノ",
               "⊂((・▽・))⊃",
               "(　´∀｀)", // 10
               "(　＾∇＾)",
               "(・∀・)",
               "(“⌒∇⌒”)",
               "｡◕‿◕｡",
               "“ヽ(´▽｀)ノ”",
               "(*＾ワ＾*)",
               "（＾ｖ＾）",
               "(＾▽＾)",
               "(◍•ᴗ•◍)",
               "(●⌒∇⌒●)", // 20
               "(●´∀｀●)",
               "＼（＾▽＾）／",
               "＼（Ｔ∇Ｔ）／",
               "´･ᴗ･`",
               "＼(*T▽T*)／",
               "ヾ(＾∇＾)",
               "Ⓗⓐⓟⓟⓨ",
               "(◠‿◠)",
               "o(〃＾▽＾〃)o",
               "(^ワ^＝)", // 30
               "(=^▽^=)",
               "◉‿◉",
               "ヾ(○･ω･)ﾉ",
               "乂⍲‿⍲乂",
               "米＾－＾米",
               "ლ（´∀`ლ）",
               "(人 •͈ᴗ•͈)"
               };
#define amount_happy 37
short *e2[] = {"(´；ω；`)", // Sad
               ":-(2"
               };
#define amount_sad 2
short *e3[] = {"( ꒪Д꒪)ノ", // Angry
               "(　ﾟДﾟ)＜!!",
                 "ヽ༼ ಠ益ಠ ༽ﾉ",
               "＼(>o<)ノ",
               "＼(>o<)/",
               "٩(╬ʘ益ʘ╬)۶",
               "(╬⓪益⓪)",
               "╚╚|░☀▄☀░|╝╝",
                 "ヽ(`Д´)ﾉ",
                 "(｀ ハ´)", // 10
               "( ≧Д≦)",
               "(⋋▂⋌)",
               "-`д´-",
               "＼(｀0´)／",
                 "ヽ(｀⌒´メ)ノ",
                 "ヽ(●-`Д´-)ノ",
               "（＞д＜）",
                 "ヽ(#`Д´)ﾉ",
                 "ヽ(#ﾟДﾟ)ﾉ",
               "ಠ_ಠ", // 20
               "ಠ▃ಠ",
               "((╬●∀●)",
               "(╬•᷅д•᷄╬)",
               "ఠ ͟ಠ",
               "૮( ᵒ̌皿ᵒ̌ )ა",
               "(╬⓪益⓪)",
               "୧༼ಠ益ಠ༽୨",
               "＼`•̀益•́´／",
               "(｀Д´)",
               "(ﾉ｀Д´)ﾉ", // 30
               "ヽ(｀Д´)ノ",
               "ヽ(｀Д´#)ﾉ",
               "ヾ(ﾒ｀･д･´)ﾉﾞ",
               "(o･｀Д´･o)",
               "┗|｀O´|┛",
               "｜。｀＞Д＜｜",
               "ι(｀ロ´)ノ",
               "ヽ(｀δ´)ノ",
               "（♯▼皿▼）",
               "（｀Δ´）！" // 40
               "ヽ(`Д´)ﾉ"
               "（=｀〜´=）",
               "(｀Д´*)"
               };
#define amount_angry 43
short *e4[] = {"ヽ(*⌒∇⌒*)ﾉ", // Excited
               "＼（＾▽＾）／",
               "(((o(*ﾟ▽ﾟ*)o)))",
               "(★^O^★)",
               "＼(^▽^＠)ノ",
               "ヾ(@^▽^@)ノ",
               "o(^▽^)o",
               "Ｏ(≧∇≦)Ｏ",
               "o(〃＾▽＾〃)o",
               "٩(●˙▿˙●)۶", // 10
               "٩(^ᴗ^)۶"
               };
#define amount_excited 11
short *e5[] = {"(♥ε♥)", // Love
               "ʕ•̫͡•ʔ❤ʕ•̫͡•ʔ",
               "(^3^)",
               "(≚ᄌ≚)ℒℴѵℯ❤",
               "❣◕ ‿ ◕❣",
               "꒰ღ˘‿˘ற꒱❤⃛",
               "(΄◞ิ౪◟ิ‵)♥",
               "(‘∀’●)♡",
               "(´ ▽｀).。ｏ♡",
               "(●♡∀♡)", // 10
               "( ＾◡＾)❤",
               "(｡♥‿♥｡)",
               "(* ˘⌣˘)◞[_]♥[_]ヽ(•‿• )",
               "( ˘ ³˘)♥",
               "(´∀｀)♡",
               "(◍•ᴗ•◍)❤",
               "(♥ω♥*)",
               "(♥ω♥ ) ~♪",
               "(Ɔ ˘⌣˘)♥(˘⌣˘ C)",
               "♡｡ﾟ.(*♡´‿` 人´‿` ♡*)ﾟ♡ °・", // 20
               "♥～(‘▽^人)",
               "♥（ﾉ´∀`）",
               "✿♥‿♥✿",
               "乂❤‿❤乂",
               "웃+웃=❤",
               "(≚ᄌ≚)ℒℴѵℯ❤",
               "Ϛ⃘๑•͡ .̫•๑꒜ℒℴѵℯ❤",
               "(⑅ ॣ•͈ᴗ•͈ ॣ)∟ᵒᵛᵉ૫૦∪",
               "ฅ ̳͒•ˑ̫• ̳͒ฅ♡",
               "(ღ˘⌣˘)❛ั◡❛ัღ)", // 30
               "(ෆ`꒳´ෆ) ˡºᵛᵉ❤⃛",
               "(۶•౪•)۶❤٩(•౪•٩)",
               "(•౪•)۶❤٩(•౪•)",
               "⊂（♡⌂♡）⊃",
               "ღˇ◡ˇ(ᵕ꒶̮ᵕෆ",
               "♡✧。 (⋈◍＞◡＜◍)。✧♡",
               "(´ε｀*)ιον∈ Υου"
               };
#define amount_love 37
short *e6[] = {"৳৸ᵃᵑᵏ Ꮍ৹੫ᵎ", // Thanks
               "(๑ᴖ◡ᴖ๑)",
               "ღˇ◡ˇ",
               "(◍•ᴗ•◍)❤"
               };
#define amount_thanks 4
short *e7[] = {"＜(。_。)＞", // Sorry
               "๑•́ㅿ•̀๑) ᔆᵒʳʳᵞ",
               "m(._.)m",
               "o(_ _)o",
               "m(_ _)m",
               "<(_ _)>",
               "(ノ．_．)ノ",
               "≦(._.)≧",
               "(m。_。)m",
               "m(｡_｡；))m", // 10
               "m(＠´＿｀＠)m",
               "ヾ(_ _*)",
               "( .. )",
               "ｍ（．＿．）ｍ",
               "m(*- -*)m",
               "(o*｡_｡)o"
               };
#define amount_sorry 16
short *e8[] = {"（・∀・ ）", // Laughing
               "（　´∀｀）",
               "｡ﾟ(　´∀｀)ﾟ｡",
               "（⌒▽⌒）",
               "(◍˃̶ᗜ˂̶◍)ﾉ”",
               "(˵¯̴͒ꇴ¯̴͒˵)",
               "(๑❛ꇳ❛๑)",
               "( 〃´艸｀)"
               };
#define amount_laughing 8
short *e9[] = {"(•ө•)",// Bird
               "є(･Θ･｡)э››",
               "（・θ・）",
               "（・⊝・）",
               "(◉Θ◉)",
               "（ﾟ∈ﾟ）",
               "ˎ₍•ʚ•₎ˏ",
               "ˏ₍•ɞ•₎ˎ",
               "◎▼◎",
               "꜀( ˊ̠˂˃ˋ̠ )꜆", // 10
               "♩є(･Θ･｡)э",
               "ㄟ( ･ө･ )ㄏ",
               "ლ(⁰⊖⁰ლ)",
               "ϵ( ‘Θ’ )϶",
               "ლ(◉◞⊖◟◉｀ლ)",
               "♡(㋭ ਊ ㋲)♡",
               "๏ ⌔̮ ๏",
               "⚈̤꒫⚈̤",
               "(○∇○)",
               "(･Θ･)", // 20
               "˳⚆ɞ⚆˳",
               "o(｀Θ´)○",
               "( ˊ̱˂˃ˋ̱ )",
               "(´◉◞⊖◟◉｀)",
               "ミ◕ฺｖ◕ฺ彡",
               "ヾ(ﾟΘﾟ )ヾ",
               "／(#｀ ∈∋ ´)＼",
               "⊹⋛⋋(◐⊝◑)⋌⋚⊹",
               "| •́ ▾ •̀ |",
               "(　＾Θ＾)" // 30
               };
#define amount_bird 30
short *e10[] = {"(￣(エ)￣)", // Bear
                "(^(エ)^)",
                "(●￣(ｴ)￣●)",
                "(●｀･(ｴ)･´●)",
                "(´(エ)｀)",
                "(ó㉨ò)",
                "ʕ·͡ˑ·ཻʔ",
                "⊂(￣(工)￣)⊃",
                "⊂(￣(ｴ)￣)⊃",
                "＼(・｀(ｪ)・)/", // 10
                "＼(・｀(ｪ)・)/",
                "ヽ(￣(ｴ)￣)ﾉ",
                "ʕ •́؈•̀ ₎",
                "ヾ(T(エ)Tヽ)",
                "┏((＝￣(ｴ)￣=))┛"
                "(♥ó㉨ò)ノ",
                "(๏㉨๏)",
                "(๑･㉨･๑)",
                "(♥ó㉨ò)ノ",
                "ヾ(♥ó㉨ò)ﾉ", // 20
                "(･(ｪ)･)",
                "⊂(▼(工)▼ﾒ)⊃",
                "ᶘ ᵒ㉨ᵒᶅ",
                "(人´㉨｀)♡"
                "[｡◉㉨◉]",
                "ʕ◉ᴥ◉ʔ",
                " (｡ﾉ･(ｴ)･｡)ﾉ"
                };
#define amount_bear 27
short *e11[] = {"(^._.^)ﾉ", // Cat
                "(^人^)",
                "(=^･^=)",
                "(=｀ω´=)",
                "(=｀ェ´=)",
                "(=;ェ;=)",
                "（ΦωΦ）",
                "(^-人-^)",
                "(=^･ｪ･^=)",
                "(●ↀωↀ●)", // 10
                "(^･ｪ･^)",
                "~(=^‥^)ノ",
                "~(=^‥^)/",
                "V(=^･ω･^=)v",
                "ㅇㅅㅇ",
                "₍˄·͈༝·͈˄₎ฅ˒˒",
                "₍˄ุ.͡˳̫.˄ุ₎ฅ˒˒",
                "(≚ᄌ≚)",
                "ฅ^•ﻌ•^ฅ",
                "[^._.^]ﾉ", // 20
                "₍ᵔ·͈༝·͈ᵔ₎",
                "₍˄·͈༝·͈˄*₎◞ ̑̑",
                "((=ﾟｴﾟ=))",
                "(^･ω･^=)~",
                "( =^･ｪ･^)",
                "ﾍ(=^･ω･^= )ﾉ",
                "((≡ﾟ♀ﾟ≡))",
                "ヽ(ΦωΦヽ)",
                "ヾ(=^・・^)",
                "( =^･_･^)", // 30
                "~(=^･ω･^)",
                "(=･ｪ･=?",
                "(=･ｪ･=)",
                "=^∇^*=",
                "(ﾉΦωΦ)ﾉ",
                "|n＾ω＾|η",
                "(＾*･.･*＾)",
                "ฅ(*ΦωΦ*) ฅ",
                "(ﾉ*ФωФ)ﾉ",
                "o(^・x・^)w", // 40
                "ヽ(^‥^=ゞ)",
                "ヽ(=^･ω･^=)丿",
                "(=^-ω-^=)"
                };
#define amount_cat 43
short *e12[] = {"U ´꓃ ` U", // Dog
                "(^・(I)・^)",
                "(U・x・U)",
                "U￣ｰ￣U",
                "ｖ・。・Ｖ",
                "Uo･ｪ･oU",
                "(❍ᴥ❍ʋ)",
                "(・ᴥ・ʋ)",
                "▿‧͈•̻‧͈▿",
                "◖⚆ᴥ⚆◗", // 10
                "▼･。･▼",
                "▽･ｪ･▽ﾉ”",
                "(Ｕ◕ฺ㉨◕ฺ)ノ",
                "| * O ᴥ O * |",
                "⊂ﾟＵ┬────┬~"
                };
#define amount_dog 15
short *e13[] = {"٩(͡๏̯͡๏)۶", // Confused
                "(•ิ_•ิ)?",
                "(‘◇’)?",
                "(゜-゜)",
                "｢(ﾟﾍﾟ)",
                "( •᷄ὤ•᷅)？",
                "( ؕؔʘ̥̥̥̥ ه ؔؕʘ̥̥̥̥ )?",
                "〈(゜。゜)",
                "ヽ(゜Q。)ノ？",
                "ヾ(´･ ･｀｡)ノ”", // 10
                "【・ヘ・?】",
                "【・_・?】",
                "「(°ヘ°)",
                "(ㆀ˘･з･˘)ωҺaｔ？",
                "∑（｡･Д･｡）???",
                "ʕ•ૅૄ•ʔ",
                "(・・？)",
                "(ﾟヘﾟ)？",
                "(ﾟДﾟ?)",
                "(o゜ー゜o)??", // 20
                "（・∩・）？",
                "( -_・)?",
                "??r(･x･｡)???",
                "Σ(・Д・)!?"
                };
#define amount_confused 24
short *e14[] = {"❤ ϚϦοςӧԼձϮϵ❣⃛", // Food/drink
                "~旦_(^O^ )",
                "♨(⋆‿⋆)",
                "~(=^‥^)_旦~",
                "且_(ﾟ◇ﾟ；)ノﾞ",
                "( ・・)つ―{}@{}@{}-",
                "且_(ﾟ◇ﾟ；)ノﾞ",
                "―⊂ZZZ⊃",
                "(●´▽｀●)_旦”☆”旦_(○´ー｀○)",
                "(っ˘ڡ˘ς)" // 10
                };
#define amount_food 10
short *e15[] = {"(*´∀｀*人*´∀｀*)", // Friends
                "( ⌒o⌒)人(⌒-⌒ )v",
                "( ⌒-⌒)人(⌒o⌒ )v",
                "(=´∀`)人(´∀‘=)",
                "└(^o^ )Ｘ( ^o^)┘",
                "ヘ( ^o^)ノ＼(^_^ )",
                "(((＠°▽°＠)八(＠°▽°＠)))",
                "(*´･ω･)(･ω･`*)",
                "(((*°▽°*)八(*°▽°*)))♪",
                "(((*°▽°*)八(*°▽°*)))", // 10
                "(〃⌒▽⌒)八(〃⌒▽⌒〃)八(⌒▽⌒〃)"
                "(Ɔ˘⌣˘)(˘⌣˘)˘⌣˘ C)",
                "＼（＾∀＾）メ（＾∀＾）ノ",
                "(*￣▽￣)ノ”(^∇^*)",
                "ヾ(*⌒∇⌒)八(⌒∇⌒*)ツ",
                "✽-(ˆ▽ˆ)/✽ ✽\(ˆ▽ˆ)-✽",
                "♪～(◔◡◔ิ)人(╹◡╹๑)～♪",
                "(๑´・‿・)(・‿・｀●)",
                "ヽ(ﾟ▽ﾟ*)乂(*ﾟ▽ﾟ)ﾉ",
                "(v´∀｀)ﾊ(´∀｀v)", // 20
                "（○・▽・○）人（●・▽・●）ノ",
                "ヾ（○・▽・○）人（●・▽・●）ノ"
                };
#define amount_friends 22
short *e16[] = {"(Ɔ˘⌣˘)(˘⌣˘)˘⌣˘ C)", // Hug
                "ⒽⓤⒼ",
                "(ღ˘⌣˘)˘◡˘ღ)",
                "(ღ˘⌣˘)˘⌣˘ღ)",
                "(_＾∇＾)･◡･)η",
                "⊂((・▽・))⊃",
                "(っ´▽｀)っ",
                "(っ´∀｀)っ",
                "(oﾟ▽ﾟ)o",
                "(⊃｡•́‿•̀｡)⊃", // 10
                "(ﾉ^^)乂(^^ )ﾉ",
                "(ɔ ˘⌣˘)˘⌣˘ c)",
                "(　￣▽)爻(▽￣　)",
                "(*･ω･)つ⊂(･ω･*)"
                };
#define amount_hug 14
short *e17[] = {"(。_＋)", // Unwell
                "((((*｡_｡)_",
                "(๑-﹏-๑)",
                "(﹡︠﹏ु﹡︡)",
                "(ू̯⋆̧ ͕⋆᷅ू̯ )  ༘˟",
                "ヽ(_ _ヽ)彡",
                "ミ(ノ_ _)ノ",
                "(ヘ＿　＿)ヘ",
                "ヘ(＿　＿ヘ)",
                "(;・ж;・;)", // 10
                "◝(๑⁺᷄д⁺᷅๑)◞՞ᵘᵍʰ",
                "(。・艸・)",
                "（＃´Ⅹ｀＃）",
                "⊂((° x。))⊃",
                "｡.*:・’ﾟ:。'(((＋_＋)))｡.*:ﾟ･’ﾟﾟ:。’･ﾟ"
                };
#define amount_unwell 15
short *e18[] = {"୨୧ᕼᗩᑭᑭY ᗷIᖇTᕼᗞᗩY୨୧", // Birthday
                "ᕼᗩᑭᑭY ᗷIᖇTᕼᗞᗩY",
                "ℋ੨ppყ ᙖ ౹̊ণ৳hძ੨ყ",
                "✯ℋᵅᵖᵖᵞ ℬⁱʳᵗᑋᵈᵃᵞ✯",
                "ℋᵅᵖᵖᵞ ℬⁱʳᵗᑋᵈᵃᵞ",
                "┌iiii┐",
                "(*’∀`)ﾊ┌iiiiii┐ﾊ(‘∀`*)",
                "(*･ω･)ﾉ”┌iii┐♡",
                ".*･ﾟ☆ндрру(*⌒▽⌒*)b вiятнDду☆ﾟ･*",
                ".*･ﾟ☆ндрруヾ(*^▽^*)ﾉвiятнDду☆ﾟ･*.", // 10
                "ᕼᗩᑭᑭY ᗷIᖇTᕼᗞᗩY 畄",
                "ℋ੨ppყ ᙖ ౹̊ণ৳hძ੨ყ 畄",
                "～ΒΙяΤΗDΑΥ LOVE❤(◍•ᴗ•◍)/",
                "～ΒΙяΤΗDΑΥ LOVE❤(◍•ᴗ•◍)ノ",
                ".*･ﾟ☆Happyヾ(*ε*)ﾉBirthday☆ﾟ･*.",
                "(　ﾟ∀ﾟ)っ由"
                };
#define amount_birthday 16
short *e19[] = {"･･ᗰદ૨૨ʏ ᘓમ૨ıડτന੨ડ･･", // Christmas
                "⋆ᗰદ૨૨ʏ⋆ᐠ₍⁽˚⑅̆˚⁾₎ᐟ⋆ᘓમ૨ıડτന੨ડ⋆",
                "ΜᎧrRγ сняᎥᎦτмᏜs",
                "～ΜᎧrRγ сняᎥᎦτмᏜs～",
                "⁷₍⁽՚ᵕ՝⁾₎₇",
                "(　ﾟ∀ﾟ)っ由",
                "ﾟ･:*:･｡(〃･ω･)ﾉ由☆*:;;;:*Ｍｅｒｒｙ　Ｘ’ｍａｓ*:;;;:*☆由ヽ(･ω･〃)｡･:*:･ﾟ",
                "[o･ω･]ﾉ*мёЯЯЧ CнЯIsтмДs",
                ".｡+ﾟ*[o･ω･]ﾉ*мёЯЯЧ CнЯIsтмДs*.｡+ﾟ*",
                "☆мёггу снгisтмдsﾟ☆" // 10
                };
#define amount_christmas 10
short *e20[] = {"ヘ(◕。◕ヘ)", // Halloween
                "(˼●̙̂ ̟ ̟̎ ̟ ̘●̂˻)",
                "←～（o ｀▽´ )oΨ",
                "(((༼•̫͡•༽)))",
                "༼•̫͡•༽",
                "へ(oゝo)へ",
                "ʔ•̫͡•ཻʕ",
                "人*´∀｀)＜Тяiск оя тяёат♪＞(´∀｀*人",
                "Тяiск оя тяёат",
                "(m▼w▼)m[ ☆･ﾟ:*нαΙΙощёёй*:ﾟ･☆]m(▼w▼m)", // 10
                "нαΙΙощёёй",
                "*нαΙΙощёёй*"
                };
#define amount_halloween 12

#define VERSION_STR "1.0.1"
// Every version has it's own emoticon instead of a codename
#define VERSION_EMOTI "~(=^‥^)_旦~" // Cat with hot chocolate

#define emoti_happy e1
#define emoti_sad e2
#define emoti_angry e3
#define emoti_excited e4
#define emoti_love e5
#define emoti_thanks e6
#define emoti_sorry e7
#define emoti_laughing e8
#define emoti_bird e9
#define emoti_bear e10
#define emoti_cat e11
#define emoti_dog e12
#define emoti_confused e13
#define emoti_food e14
#define emoti_friends e15
#define emoti_hug e16
#define emoti_unwell e17
#define emoti_birthday e18
#define emoti_christmas e19
#define emoti_halloween e20

int main(int a, char *v[]) {
	unsigned short c;
	srand(time(NULL));
	if (a<2) {
		printf("Usage: emoti emoticon-type\n");
		return 1;
	}
	
	for (c=1; c<a; c++) {
		//srand(time(NULL));
		if (!strcmp(v[c], "help")) {
			printf("\
emoti version %s %s\n\
emoti is a little program that prints out a variety of Japanese emoticons\n\
upon request.\n\
Usage: emoti emoticon-type\n\
emoticon-type can be a series of different (or the same) types of emoticons. The program\n\
will print out all of the requested emoticons, one-after-the-other.\n\
\n\
The types avaliable are:\n\
 - happy\n\
 - sad\n\
 - angry\n\
 - excited\n\
 - love\n\
 - thanks\n\
 - sorry\n\
 - laughing\n\
 - bird\n\
 - bear\n\
 - cat\n\
 - dog\n\
 - confused\n\
\n\n\
Copyright (C) 2015 Joe Glancy\n\
\n\
emoti is free software: you can redistribute it and/or modify\n\
it under the terms of the GNU General Public License as published by\n\
the Free Software Foundation, either version 3 of the License, or\n\
(at your option) any later version.\n\
\n\
Bash is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
GNU General Public License for more details.\n\
\n\
You should have received a copy of the GNU General Public License\n\
along with emoti.  If not, see <http://www.gnu.org/licenses/>.\n\n\
", VERSION_STR, VERSION_EMOTI);
				return 0;
		}
		if (!strcmp(v[c], "version")) {
			printf("emoti v%s\n", VERSION_STR);
			return 0;
		}
	}
	for (c=1; c<a; c++) {
		if (!strcmp(v[c], "happy")) {
			printf("%s\n", emoti_happy[rand() % amount_happy]);
		}
		else if (!strcmp(v[c], "sad")) {
			printf("%s\n", emoti_sad[rand() % amount_sad]);
		}
		else if (!strcmp(v[c], "angry")) {
			printf("%s\n", emoti_angry[rand() % amount_angry]);
		}
		else if (!strcmp(v[c], "excited")) {
			printf("%s\n", emoti_excited[rand() % amount_excited]);
		}
		else if (!strcmp(v[c], "love")) {
			printf("%s\n", emoti_love[rand() % amount_love]);
		}
		else if (!strcmp(v[c], "thanks")) {
			printf("%s\n", emoti_thanks[rand() % amount_thanks]);
		}
		else if (!strcmp(v[c], "sorry")) {
			printf("%s\n", emoti_sorry[rand() % amount_love]);
		}
		else if (!strcmp(v[c], "laughing")) {
			printf("%s\n", emoti_laughing[rand() % amount_laughing]);
		}
		else if (!strcmp(v[c], "bird")) {
			printf("%s\n", emoti_bird[rand() % amount_bear]);
		}
		else if (!strcmp(v[c], "bear")) {
			printf("%s\n", emoti_bear[rand() % amount_bear]);
		}
		else if (!strcmp(v[c], "cat")) {
			printf("%s\n", emoti_cat[rand() % amount_cat]);
		}
		else if (!strcmp(v[c], "dog")) {
			printf("%s\n", emoti_dog[rand() % amount_dog]);
		}
		else if (!strcmp(v[c], "confused")) {
			printf("%s\n", emoti_confused[rand() % amount_confused]);
		}
		else if (!strcmp(v[c], "food")) {
			printf("%s\n", emoti_food[rand() % amount_food]);
		}
		else if (!strcmp(v[c], "friend") || !strcmp(v[c], "friends")) {
			printf("%s\n", emoti_friends[rand() % amount_friends]);
		}
		else if (!strcmp(v[c], "hug") || !strcmp(v[c], "hugs")) {
			printf("%s\n", emoti_hug[rand() % amount_hug]);
		}
		else if (!strcmp(v[c], "unwell") || !strcmp(v[c], "sick")) {
			printf("%s\n", emoti_unwell[rand() % amount_unwell]);
		}
		else if (!strcmp(v[c], "birthday")) {
			printf("%s\n", emoti_birthday[rand() % amount_birthday]);
		}
		else if (!strcmp(v[c], "christmas")) {
			printf("%s\n", emoti_christmas[rand() % amount_christmas]);
		}
		else if (!strcmp(v[c], "halloween")) {
			printf("%s\n", emoti_halloween[rand() % amount_halloween]);
		}
		
		else {
			printf("(Unrecognised option: \"%s\")\n", v[c]);
		}
	}
	return 0;
}

