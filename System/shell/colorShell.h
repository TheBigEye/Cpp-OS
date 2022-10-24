#ifndef SYSTEM_SHELL_COLORSHELL_H_
#define SYSTEM_SHELL_COLORSHELL_H_

#include <iostream>

// BACKGROUND COLOR _ FOREGROUND COLOR
const int NORMAL_NORMAL = 7;

const int BLACK_BLACK = 0;
const int BLACK_BLUE = 1;
const int BLACK_GREEN = 2;
const int BLACK_AQUA = 3;
const int BLACK_RED = 4;
const int BLACK_PURPLE = 5;
const int BLACK_YELLOW = 6;
const int BLACK_WHITE = 7;
const int BLACK_GRAY = 8;
const int BLACK_LIGHTBLUE = 9;
const int BLACK_LIGHTGREEN = 10;
const int BLACK_LIGHTAQUA = 11;
const int BLACK_LIGHTRED = 12;
const int BLACK_LIGHTPURPLE = 13;
const int BLACK_LIGHTYELLOW = 14;
const int BLACK_LIGHTWHITE = 15;

const int BLUE_BLACK = 16;
const int BLUE_BLUE = 17;
const int BLUE_GREEN = 18;
const int BLUE_AQUA = 19;
const int BLUE_RED = 20;
const int BLUE_PURPLE = 21;
const int BLUE_YELLOW = 22;
const int BLUE_WHITE = 23;
const int BLUE_GRAY = 24;
const int BLUE_LIGHTBLUE = 25;
const int BLUE_LIGHTGREEN = 26;
const int BLUE_LIGHTAQUA = 27;
const int BLUE_LIGHTRED = 28;
const int BLUE_LIGHTPURPLE = 29;
const int BLUE_LIGHTYELLOW = 30;
const int BLUE_LIGHTWHITE = 31;

const int GREEN_BLACK = 32;
const int GREEN_BLUE = 33;
const int GREEN_GREEN = 34;
const int GREEN_AQUA = 35;
const int GREEN_RED = 36;
const int GREEN_PURPLE = 37;
const int GREEN_YELLOW = 38;
const int GREEN_WHITE = 39;
const int GREEN_GRAY = 40;
const int GREEN_LIGHTBLUE = 41;
const int GREEN_LIGHTGREEN = 42;
const int GREEN_LIGHTAQUA = 43;
const int GREEN_LIGHTRED = 44;
const int GREEN_LIGHTPURPLE = 45;
const int GREEN_LIGHTYELLOW = 46;
const int GREEN_LIGHTWHITE = 47;

const int AQUA_BLACK = 48;
const int AQUA_BLUE = 49;
const int AQUA_GREEN = 50;
const int AQUA_AQUA = 51;
const int AQUA_RED = 52;
const int AQUA_PURPLE = 53;
const int AQUA_YELLOW = 54;
const int AQUA_WHITE = 55;
const int AQUA_GRAY = 56;
const int AQUA_LIGHTBLUE = 57;
const int AQUA_LIGHTGREEN = 58;
const int AQUA_LIGHTAQUA = 59;
const int AQUA_LIGHTRED = 60;
const int AQUA_LIGHTPURPLE = 61;
const int AQUA_LIGHTYELLOW = 62;
const int AQUA_LIGHTWHITE = 63;

const int RED_BLACK = 64;
const int RED_BLUE = 65;
const int RED_GREEN = 66;
const int RED_AQUA = 67;
const int RED_RED = 68;
const int RED_PURPLE = 69;
const int RED_YELLOW = 70;
const int RED_WHITE = 71;
const int RED_GRAY = 72;
const int RED_LIGHTBLUE = 73;
const int RED_LIGHTGREEN = 74;
const int RED_LIGHTAQUA = 75;
const int RED_LIGHTRED = 76;
const int RED_LIGHTPURPLE = 77;
const int RED_LIGHTYELLOW = 78;
const int RED_LIGHTWHITE = 79;

const int PURPLE_BLACK = 80;
const int PURPLE_BLUE = 81;
const int PURPLE_GREEN = 82;
const int PURPLE_AQUA = 83;
const int PURPLE_RED = 84;
const int PURPLE_PURPLE = 85;
const int PURPLE_YELLOW = 86;
const int PURPLE_WHITE = 87;
const int PURPLE_GRAY = 88;
const int PURPLE_LIGHTBLUE = 89;
const int PURPLE_LIGHTGREEN = 90;
const int PURPLE_LIGHTAQUA = 91;
const int PURPLE_LIGHTRED = 92;
const int PURPLE_LIGHTPURPLE = 93;
const int PURPLE_LIGHTYELLOW = 94;
const int PURPLE_LIGHTWHITE = 95;

const int YELLOW_BLACK = 96;
const int YELLOW_BLUE = 97;
const int YELLOW_GREEN = 98;
const int YELLOW_AQUA = 99;
const int YELLOW_RED = 100;
const int YELLOW_PURPLE = 101;
const int YELLOW_YELLOW = 102;
const int YELLOW_WHITE = 103;
const int YELLOW_GRAY = 104;
const int YELLOW_LIGHTBLUE = 105;
const int YELLOW_LIGHTGREEN = 106;
const int YELLOW_LIGHTAQUA = 107;
const int YELLOW_LIGHTRED = 108;
const int YELLOW_LIGHTPURPLE = 109;
const int YELLOW_LIGHTYELLOW = 110;
const int YELLOW_LIGHTWHITE = 111;

const int WHITE_BLACK = 112;
const int WHITE_BLUE = 113;
const int WHITE_GREEN = 114;
const int WHITE_AQUA = 115;
const int WHITE_RED = 116;
const int WHITE_PURPLE = 117;
const int WHITE_YELLOW = 118;
const int WHITE_WHITE = 119;
const int WHITE_GRAY = 120;
const int WHITE_LIGHTBLUE = 121;
const int WHITE_LIGHTGREEN = 122;
const int WHITE_LIGHTAQUA = 123;
const int WHITE_LIGHTRED = 124;
const int WHITE_LIGHTPURPLE = 125;
const int WHITE_LIGHTYELLOW = 126;
const int WHITE_LIGHTWHITE = 127;

const int GRAY_BLACK = 128;
const int GRAY_BLUE = 129;
const int GRAY_GREEN = 130;
const int GRAY_AQUA = 131;
const int GRAY_RED = 132;
const int GRAY_PURPLE = 133;
const int GRAY_YELLOW = 134;
const int GRAY_WHITE = 135;
const int GRAY_GRAY = 136;
const int GRAY_LIGHTBLUE = 137;
const int GRAY_LIGHTGREEN = 138;
const int GRAY_LIGHTAQUA = 139;
const int GRAY_LIGHTRED = 140;
const int GRAY_LIGHTPURPLE = 141;
const int GRAY_LIGHTYELLOW = 142;
const int GRAY_LIGHTWHITE = 143;

const int LIGHTBLUE_BLACK = 144;
const int LIGHTBLUE_BLUE = 145;
const int LIGHTBLUE_GREEN = 146;
const int LIGHTBLUE_AQUA = 147;
const int LIGHTBLUE_RED = 148;
const int LIGHTBLUE_PURPLE = 149;
const int LIGHTBLUE_YELLOW = 150;
const int LIGHTBLUE_WHITE = 151;
const int LIGHTBLUE_GRAY = 152;
const int LIGHTBLUE_LIGHTBLUE = 153;
const int LIGHTBLUE_LIGHTGREEN = 154;
const int LIGHTBLUE_LIGHTAQUA = 155;
const int LIGHTBLUE_LIGHTRED = 156;
const int LIGHTBLUE_LIGHTPURPLE = 157;
const int LIGHTBLUE_LIGHTYELLOW = 158;
const int LIGHTBLUE_LIGHTWHITE = 159;

const int LIGHTGREEN_BLACK = 160;
const int LIGHTGREEN_BLUE = 161;
const int LIGHTGREEN_GREEN = 162;
const int LIGHTGREEN_AQUA = 163;
const int LIGHTGREEN_RED = 164;
const int LIGHTGREEN_PURPLE = 165;
const int LIGHTGREEN_YELLOW = 166;
const int LIGHTGREEN_WHITE = 167;
const int LIGHTGREEN_GRAY = 168;
const int LIGHTGREEN_LIGHTBLUE = 169;
const int LIGHTGREEN_LIGHTGREEN = 170;
const int LIGHTGREEN_LIGHTAQUA = 171;
const int LIGHTGREEN_LIGHTRED = 172;
const int LIGHTGREEN_LIGHTPURPLE = 173;
const int LIGHTGREEN_LIGHTYELLOW = 174;
const int LIGHTGREEN_LIGHTWHITE = 175;

const int LIGHTAQUA_BLACK = 176;
const int LIGHTAQUA_BLUE = 177;
const int LIGHTAQUA_GREEN = 178;
const int LIGHTAQUA_AQUA = 179;
const int LIGHTAQUA_RED = 180;
const int LIGHTAQUA_PURPLE = 181;
const int LIGHTAQUA_YELLOW = 182;
const int LIGHTAQUA_WHITE = 183;
const int LIGHTAQUA_GRAY = 184;
const int LIGHTAQUA_LIGHTBLUE = 185;
const int LIGHTAQUA_LIGHTGREEN = 186;
const int LIGHTAQUA_LIGHTAQUA = 187;
const int LIGHTAQUA_LIGHTRED = 188;
const int LIGHTAQUA_LIGHTPURPLE = 189;
const int LIGHTAQUA_LIGHTYELLOW = 190;
const int LIGHTAQUA_LIGHTWHITE = 191;

const int LIGHTRED_BLACK = 192;
const int LIGHTRED_BLUE = 193;
const int LIGHTRED_GREEN = 194;
const int LIGHTRED_AQUA = 195;
const int LIGHTRED_RED = 196;
const int LIGHTRED_PURPLE = 197;
const int LIGHTRED_YELLOW = 198;
const int LIGHTRED_WHITE = 199;
const int LIGHTRED_GRAY = 200;
const int LIGHTRED_LIGHTBLUE = 201;
const int LIGHTRED_LIGHTGREEN = 202;
const int LIGHTRED_LIGHTAQUA = 203;
const int LIGHTRED_LIGHTRED = 204;
const int LIGHTRED_LIGHTPURPLE = 205;
const int LIGHTRED_LIGHTYELLOW = 206;
const int LIGHTRED_LIGHTWHITE = 207;

const int LIGHTPURPLE_BLACK = 208;
const int LIGHTPURPLE_BLUE = 209;
const int LIGHTPURPLE_GREEN = 210;
const int LIGHTPURPLE_AQUA = 211;
const int LIGHTPURPLE_RED = 212;
const int LIGHTPURPLE_PURPLE = 213;
const int LIGHTPURPLE_YELLOW = 214;
const int LIGHTPURPLE_WHITE = 215;
const int LIGHTPURPLE_GRAY = 216;
const int LIGHTPURPLE_LIGHTBLUE = 217;
const int LIGHTPURPLE_LIGHTGREEN = 218;
const int LIGHTPURPLE_LIGHTAQUA = 219;
const int LIGHTPURPLE_LIGHTRED = 220;
const int LIGHTPURPLE_LIGHTPURPLE = 221;
const int LIGHTPURPLE_LIGHTYELLOW = 222;
const int LIGHTPURPLE_LIGHTWHITE = 223;

const int LIGHTYELLOW_BLACK = 224;
const int LIGHTYELLOW_BLUE = 225;
const int LIGHTYELLOW_GREEN = 226;
const int LIGHTYELLOW_AQUA = 227;
const int LIGHTYELLOW_RED = 228;
const int LIGHTYELLOW_PURPLE = 229;
const int LIGHTYELLOW_YELLOW = 230;
const int LIGHTYELLOW_WHITE = 231;
const int LIGHTYELLOW_GRAY = 232;
const int LIGHTYELLOW_LIGHTBLUE = 233;
const int LIGHTYELLOW_LIGHTGREEN = 234;
const int LIGHTYELLOW_LIGHTAQUA = 235;
const int LIGHTYELLOW_LIGHTRED = 236;
const int LIGHTYELLOW_LIGHTPURPLE = 237;
const int LIGHTYELLOW_LIGHTYELLOW = 238;
const int LIGHTYELLOW_LIGHTWHITE = 239;

const int LIGHTWHITE_BLACK = 240;
const int LIGHTWHITE_BLUE = 241;
const int LIGHTWHITE_GREEN = 242;
const int LIGHTWHITE_AQUA = 243;
const int LIGHTWHITE_RED = 244;
const int LIGHTWHITE_PURPLE = 245;
const int LIGHTWHITE_YELLOW = 246;
const int LIGHTWHITE_WHITE = 247;
const int LIGHTWHITE_GRAY = 248;
const int LIGHTWHITE_LIGHTBLUE = 249;
const int LIGHTWHITE_LIGHTGREEN = 250;
const int LIGHTWHITE_LIGHTAQUA = 251;
const int LIGHTWHITE_LIGHTRED = 252;
const int LIGHTWHITE_LIGHTPURPLE = 253;
const int LIGHTWHITE_LIGHTYELLOW = 254;
const int LIGHTWHITE_LIGHTWHITE = 255;

#endif /* SYSTEM_SHELL_COLORSHELL_H_ */
