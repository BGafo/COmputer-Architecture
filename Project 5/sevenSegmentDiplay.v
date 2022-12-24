input [3:0] numeral_bit;

output a;
output b;
output c;
output d;
output e;
output f;
output g;

wire not_numeral_bit_3;
wire not_numeral_bit_2;
wire not_numeral_bit_1;
wire not_numeral_bit_0;

wire not_numeral_bit_3_and_not_numeral_bit_2;
wire not_numeral_bit_1_and_not_numeral_bit_0;



wire maxterm_01;
wire maxterm_04;
wire maxterm_01_or_maxterm_04;




wire maxterm_05;
wire maxterm_06;
wire maxterm_05_or_maxterm_06;



wire maxterm_02;



wire maxterm_01;
wire maxterm_04;
wire maxterm_07;
wire maxterm_09;
wire maxterm_01_or_maxterm_04;
wire maxterm_07_or_maxterm_09;
wire maxterm_01_or_maxterm_04_or_maxterm_07_or_maxterm_09;





wire minterm_00;
wire minterm_02;
wire minterm_06;
wire minterm_08;
wire minterm_00_or_minterm_02;
wire minterm_06_or_minterm_08;







wire maxterm_01;
wire maxterm_02;
wire maxterm_03;
wire maxterm_07;
wire maxterm_01_or_maxterm_02;
wire maxterm_03_or_maxterm_07;
wire maxterm_01_or_maxterm_02_or_maxterm_03_or_maxterm_07;





wire maxterm_00;
wire maxterm_01;
wire maxterm_07;
wire maxterm_00_or_maxterm_01;
wire maxterm_00_or_maxterm_01_or_maxterm_07;





assign not_numeral_bit_3 = ~ numeral_bit[3];
assign not_numeral_bit_2 = ~ numeral_bit[2];
assign not_numeral_bit_1 = ~ numeral_bit[1];
assign not_numeral_bit_0 = ~ numeral_bit[0];



assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_01 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign maxterm_04 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign maxterm_01_or_maxterm_04 = maxterm_01 | maxterm_04;
assign a = ~ maxterm_01_or_maxterm_04;










assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_05 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & not_numeral_bit_0;
assign maxterm_06 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign maxterm_05_or_maxterm_06 = maxterm_05 | maxterm_06;
assign b = ~ maxterm_05_or_maxterm_06;






assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & not_numeral_bit_0;
assign maxterm_02 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign c = ~ maxterm_02;










assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_01 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign maxterm_04 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & numeral_bit[0];
assign maxterm_07 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = numeral_bit[3] & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_09 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign maxterm_01_or_maxterm_04 = maxterm_01 | maxterm_04;
assign maxterm_07_or_maxterm_09 = maxterm_07 | maxterm_09;
assign maxterm_01_or_maxterm_04_or_maxterm_07_or_maxterm_09 = maxterm_01_or_maxterm_04 | maxterm_07_or_maxterm_09;

assign d = ~ maxterm_01_or_maxterm_04_or_maxterm_07_or_maxterm_09;








assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign minterm_00 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & not_numeral_bit_0;
assign minterm_02 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & not_numeral_bit_0;
assign minterm_06 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = numeral_bit[3] & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign minterm_08 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign minterm_00_or_minterm_02 = minterm_00 | minterm_02;
assign minterm_06_or_minterm_08 = minterm_06 | minterm_08;

assign e = minterm_00_or_minterm_02 | minterm_06_or_minterm_08;









assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_01 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & not_numeral_bit_0;
assign maxterm_02 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & numeral_bit[0];
assign maxterm_03 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & numeral_bit[0];
assign maxterm_07 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign maxterm_01_or_maxterm_02 = maxterm_01 | maxterm_02;
assign maxterm_03_or_maxterm_07 = maxterm_03 | maxterm_07;

assign maxterm_01_or_maxterm_02_or_maxterm_03_or_maxterm_07 = maxterm_01_or_maxterm_02 | maxterm_03_or_maxterm_07;
assign f = ~ maxterm_01_or_maxterm_02_or_maxterm_03_or_maxterm_07;







assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign maxterm_00 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_numeral_bit_1_and_not_numeral_bit_0 = not_numeral_bit_1 & numeral_bit[0];
assign maxterm_01 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign not_numeral_bit_3_and_not_numeral_bit_2 = not_numeral_bit_3 & numeral_bit[2];
assign not_numeral_bit_1_and_not_numeral_bit_0 = numeral_bit[1] & numeral_bit[0];
assign maxterm_07 = not_numeral_bit_3_and_not_numeral_bit_2 & not_numeral_bit_1_and_not_numeral_bit_0;

assign maxterm_00_or_maxterm_01 = maxterm_00 | maxterm_01;
assign maxterm_00_or_maxterm_01_or_maxterm_07 = maxterm_00_or_maxterm_01 | maxterm_07;

assign g = ~ maxterm_00_or_maxterm_01_or_maxterm_07;





