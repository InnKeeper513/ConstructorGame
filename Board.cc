#include "Board.h"


using namespace std;

string displayPath(int add){
	// If there are no owner for the road, display the road number
	if(paths[add].getBuilder() == "N"){
			if(add >= 10)
				return to_string(add);
			else return " " + to_string(add);
	} else return paths[add].getBuilder() + "R";
}
string displayAddress(int add){
	// If there are no owner then just display the number of the address
	if(addresses[add].getBuilder() == "N"){
			if(add >= 10)
				return to_string(add);
			else return " " + to_string(add);
	}else{
		return addresses[add].getBuilder() + addresses[add].getBuildingType();
	}
}
void displayResource(int add){

}

void displayGoose(int add){

}
void displayAmount(int add){

}

// Display the board
// TODO will need to display the board base on different tile types, resources, etc..
ostream &operator<<(ostream &out, Board &board) {
out << "                    |" << displayAddress(0) << "|--" << displayPath(0) << "--|" << displayAddress(1) << "|" << endl;
out << "                      |         |" << endl;
out << "                     " << displayPath(1) << "    0   " << displayPath(2) << endl;
out << "                      |  " << "BRICK " << " |" << endl;
out << "          |" << displayAddress(2) << "|--" << displayPath(3) << "--|" << displayAddress(3) << "|  " << " 3" << "  |" << displayAddress(4) << "|--" << displayPath(4) <<"--|" << displayAddress(5) << "|"  << endl;
out << "            |         |         |         |" << endl;
out << "           " << displayPath(5) << "    1   " << displayPath(6) << "        " << displayPath(7) << "   " << " 2" << "   " << displayPath(8) << endl;
out << "            |  " << "ENERGY"<<" |         | "<<" HEAT  "<< " |" << endl;
out << "|" << displayAddress(6) << "|--" << displayPath(9) << "--|" << displayAddress(7) << "|  " << "10" << "  |" << displayAddress(8) << "|--" << displayPath(10) << "--|" << displayAddress(9) << "|  " << " 5" << "  |" << displayAddress(10) << "|--" << displayPath(11) << "--|" << displayAddress(11) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(12) << "   " << " 3" << "   " << displayPath(13) << "        " << displayPath(14) << "   " << " 4" << "   " << displayPath(15) << "        " << displayPath(16) << "   " << " 5" << "   " << displayPath(17) << endl;
out << "  |  "<< "ENERGY" << " |         |  " << "PARK  " << " |         |  " << "HEAT  " << " |" << endl;
out << "|" << displayAddress(12) << "|  " << " 4" << "  |" << displayAddress(13) << "|--" << displayPath(18) << "--|" << displayAddress(14) << "|      |" << displayAddress(15) << "|--" << displayPath(19) << "--|" << displayAddress(16) << "|  " << "10" << "  |" << displayAddress(17) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(20) << "        " << displayPath(21) << "    6   " << displayPath(22) << "        " << displayPath(23) << "   " << " 7" << "   " << displayPath(24) << "        " << displayPath(25) << endl;
out << "  |         |  " << "GLASS " << " |         |  " << "BRICK " << " |         |" << endl;
out << "|" << displayAddress(18) << "|--" << displayPath(26) << "--|" << displayAddress(19) << "|  " << "11" << "  |" << displayAddress(20) << "|--" << displayPath(27) << "--|" << displayAddress(21) << "|  " << " 3" << "  |" << displayAddress(22) << "|--" <<displayPath(28) << "--|" << displayAddress(23) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(29) << "   " << " 8" << "   " << displayPath(30) << "        " << displayPath(31) << "   " << " 9" << "   " << displayPath(32)  << "        " << displayPath(33) << "   " << "10" << "   " << displayPath(34) << endl;
out << "  |  "<< "HEAT  " << " |         |  " << "BRICK " << " |         |  " << "BRICK " << " |" << endl;
out << "|" << displayAddress(24) << "|  " << " 8" << "  |" << displayAddress(25) << "|--" << displayPath(35) << "--|" << displayAddress(26) << "|  " << " 2" << "  |" << displayAddress(27) << "|--" << displayPath(36) << "--|" << displayAddress(28) << "|  " << " 6" << "  |" << displayAddress(29) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(37) << "        " << displayPath(38) << "   11   " << displayPath(39) << "        " << displayPath(40) << "   " << "12" << "   " << displayPath(41) << "        " << displayPath(42) << endl;
out << "  |         |  " << "ENERGY " << "|         |  " << "WIFI  " << " |         |" << endl;
out << "|" << displayAddress(30) << "|--" << displayPath(43) << "--|" << displayAddress(31) << "|  " << " 8" << "  |" << displayAddress(32) << "|--" << displayPath(44) << "--|" << displayAddress(33) << "|  " << "12" << "  |" << displayAddress(34) << "|--" << displayPath(45) << "--|" << displayAddress(35) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(46) << "   " << "13" << "   " << displayPath(47) << "        " << displayPath(48) << "   " << "14" << "   " << displayPath(49) << "        " << displayPath(50) << "   " << "15" << "   " << displayPath(51) << endl;
out << "  |  "<< "ENERGY " << "|         |  " << "WIFI  " << " |         |  " << "GLASS " << " |" << endl;
out << "|" << displayAddress(36) << "|  " << " 5" << "  |" << displayAddress(37) << "|--" << displayPath(52) << "--|" << displayAddress(38) << "|  " << "11" << "  |" << displayAddress(39) << "|--" << displayPath(53) << "--|" << displayAddress(40) << "|  " << " 4" << "  |" << displayAddress(41) << "|" << endl;
out << "  |         |         |         |         |         |" << endl;
out << " " << displayPath(54) << "        " << displayPath(55) << "   16   " << displayPath(56) << "        " << displayPath(57) << "   " << "17" << "   " << displayPath(58) << "        " << displayPath(59) << endl;
out << "  |         |  " << "WIFI  " << " |         |  " << "GLASS " << " |         |" << endl;
out << "|" << displayAddress(42) << "|--" << displayPath(60) << "--|" << displayAddress(43) << "|  " << " 6" << "  |" << displayAddress(44) << "|--" << displayPath(61) << "--|" << displayAddress(45) << "|  " << " 9" << "  |" << displayAddress(46) << "|--" << displayPath(62) << "--|" << displayAddress(47) << "|" << endl;
out << "            |         |         |         |" << endl;
out << "           " << displayPath(63) << "        " << displayPath(64) << "   18   " << displayPath(65) << "        " << displayPath(66) << endl;
out << "            |         |  " << "GLASS " << " |         |" << endl;
out << "          |" << displayAddress(48) << "|--" << displayPath(67) << "--|" << displayAddress(49) << "|  " << " 9" << "  |" << displayAddress(50) << "|--" << displayPath(68) <<"--|" << displayAddress(51) << "|"  << endl;
out << "                      |         |" << endl;
out << "                     " << displayPath(69) << "        "  << displayPath(70) << endl;
out << "                      |         |" << endl;
out << "                    |" << displayAddress(52) << "|--" << displayPath(71) << "--|" << displayAddress(53) << "|" << endl;

	return out;
}
Board::Board(){
	//TODO Initialize the board

	// Initialize the address
	for (int i = 0; i <= 53; i++){

		addresses.emplace_back(Address(i));

	}
	// Initialize the pahts between addresses
	for(int j = 0; j <= 71; j++){
		paths.emplace_back(Path(j));
	}

	// Add connections between addresses
	addresses[0].addAddress(1);
	addresses[0].addAddress(3);
	addresses[1].addAddress(0);
	addresses[1].addAddress(4);
	addresses[2].addAddress(3);
	addresses[2].addAddress(7);
	addresses[3].addAddress(0);
	addresses[3].addAddress(2);
	addresses[3].addAddress(8);
	addresses[4].addAddress(1);
	addresses[4].addAddress(9);
	addresses[4].addAddress(5);
	addresses[5].addAddress(4);
	addresses[5].addAddress(10);
	addresses[6].addAddress(7);
	addresses[6].addAddress(12);
	addresses[7].addAddress(2);
	addresses[7].addAddress(6);
	addresses[7].addAddress(13);
	addresses[8].addAddress(3);
	addresses[8].addAddress(9);
	addresses[8].addAddress(14);
	addresses[9].addAddress(4);
	addresses[9].addAddress(8);
	addresses[9].addAddress(15);
	addresses[10].addAddress(5);
	addresses[10].addAddress(16);
	addresses[10].addAddress(11);
	addresses[11].addAddress(10);
	addresses[11].addAddress(17);
	addresses[12].addAddress(6);
	addresses[12].addAddress(18);
	addresses[13].addAddress(7);
	addresses[13].addAddress(14);
	addresses[13].addAddress(19);
	addresses[14].addAddress(8);
	addresses[14].addAddress(13);
	addresses[14].addAddress(20);
	addresses[15].addAddress(9);
	addresses[15].addAddress(16);
	addresses[15].addAddress(21);
	addresses[16].addAddress(10);
	addresses[16].addAddress(15);
	addresses[16].addAddress(22);
	addresses[17].addAddress(11);
	addresses[17].addAddress(23);
	addresses[18].addAddress(12);
	addresses[18].addAddress(19);
	addresses[18].addAddress(24);
	addresses[19].addAddress(13);
	addresses[19].addAddress(18);
	addresses[19].addAddress(25);
	addresses[20].addAddress(14);
	addresses[20].addAddress(21);
	addresses[20].addAddress(26);
	addresses[21].addAddress(15);
	addresses[21].addAddress(20);
	addresses[21].addAddress(27);
	addresses[22].addAddress(16);
	addresses[22].addAddress(23);
	addresses[22].addAddress(28);
	addresses[23].addAddress(22);
	addresses[23].addAddress(17);
	addresses[23].addAddress(29);
	addresses[24].addAddress(18);
	addresses[24].addAddress(30);
	addresses[25].addAddress(19);
	addresses[25].addAddress(31);
	addresses[25].addAddress(26);
	addresses[26].addAddress(20);
	addresses[26].addAddress(25);
	addresses[26].addAddress(32);
	addresses[27].addAddress(21);
	addresses[27].addAddress(33);
	addresses[27].addAddress(28);
	addresses[28].addAddress(22);
	addresses[28].addAddress(27);
	addresses[28].addAddress(34);
	addresses[29].addAddress(23);
	addresses[29].addAddress(35);
	addresses[30].addAddress(24);
	addresses[30].addAddress(31);
	addresses[30].addAddress(36);
	addresses[31].addAddress(25);
	addresses[31].addAddress(30);
	addresses[31].addAddress(37);
	addresses[32].addAddress(26);
	addresses[32].addAddress(33);
	addresses[32].addAddress(38);
	addresses[33].addAddress(27);
	addresses[33].addAddress(32);
	addresses[33].addAddress(39);
	addresses[34].addAddress(28);
	addresses[34].addAddress(35);
	addresses[34].addAddress(40);
	addresses[35].addAddress(29);
	addresses[35].addAddress(34);
	addresses[35].addAddress(41);
	addresses[36].addAddress(42);
	addresses[36].addAddress(30);
	addresses[37].addAddress(31);
	addresses[37].addAddress(38);
	addresses[37].addAddress(43);
	addresses[38].addAddress(32);
	addresses[38].addAddress(37);
	addresses[38].addAddress(44);
	addresses[39].addAddress(33);
	addresses[39].addAddress(40);
	addresses[39].addAddress(45);
	addresses[40].addAddress(34);
	addresses[40].addAddress(39);
	addresses[40].addAddress(46);
	addresses[41].addAddress(35);
	addresses[41].addAddress(47);
	addresses[42].addAddress(36);
	addresses[42].addAddress(43);
	addresses[43].addAddress(37);
	addresses[43].addAddress(42);
	addresses[43].addAddress(48);
	addresses[44].addAddress(38);
	addresses[44].addAddress(45);
	addresses[44].addAddress(49);
	addresses[45].addAddress(39);
	addresses[45].addAddress(44);
	addresses[45].addAddress(50);
	addresses[46].addAddress(40);
	addresses[46].addAddress(47);
	addresses[46].addAddress(51);
	addresses[47].addAddress(41);
	addresses[47].addAddress(46);
	addresses[48].addAddress(43);
	addresses[48].addAddress(49);
	addresses[49].addAddress(44);
	addresses[49].addAddress(48);
	addresses[49].addAddress(52);
	addresses[50].addAddress(45);
	addresses[50].addAddress(51);
	addresses[50].addAddress(53);
	addresses[51].addAddress(46);
	addresses[51].addAddress(50);
	addresses[52].addAddress(49);
	addresses[52].addAddress(53);
	addresses[53].addAddress(50);
	addresses[53].addAddress(52);

	paths[0].addPath(0);
	paths[0].addPath(1);
	paths[1].addPath(0);
	paths[1].addPath(3);
	paths[2].addPath(1);
	paths[2].addPath(4);
	paths[3].addPath(2);
	paths[3].addPath(3);
	paths[4].addPath(4);
	paths[4].addPath(5);
	paths[5].addPath(2);
	paths[5].addPath(7);
	paths[6].addPath(3);
	paths[6].addPath(8);
	paths[7].addPath(4);
	paths[7].addPath(9);
	paths[8].addPath(5);
	paths[8].addPath(10);
	paths[9].addPath(6);
	paths[9].addPath(7);
	paths[10].addPath(8);
	paths[10].addPath(9);
	paths[11].addPath(10);
	paths[11].addPath(11);
	paths[12].addPath(6);
	paths[12].addPath(12);
	paths[13].addPath(7);
	paths[13].addPath(13);
	paths[14].addPath(8);
	paths[14].addPath(14);
	paths[15].addPath(9);
	paths[15].addPath(15);
	paths[16].addPath(10);
	paths[16].addPath(16);
	paths[17].addPath(11);
	paths[17].addPath(17);
	paths[18].addPath(13);
	paths[18].addPath(14);
	paths[19].addPath(15);
	paths[19].addPath(16);
	paths[20].addPath(12);
	paths[20].addPath(18);
	paths[21].addPath(13);
	paths[21].addPath(19);
	paths[22].addPath(14);
	paths[22].addPath(20);
	paths[23].addPath(15);
	paths[23].addPath(21);
	paths[24].addPath(16);
	paths[24].addPath(22);
	paths[25].addPath(17);
	paths[25].addPath(23);
	paths[26].addPath(18);
	paths[26].addPath(19);
	paths[27].addPath(20);
	paths[27].addPath(21);
	paths[28].addPath(22);
	paths[28].addPath(23);
	paths[29].addPath(18);
	paths[29].addPath(24);
	paths[30].addPath(19);
	paths[30].addPath(25);
	paths[31].addPath(20);
	paths[31].addPath(26);
	paths[32].addPath(21);
	paths[32].addPath(27);
	paths[33].addPath(22);
	paths[33].addPath(28);
	paths[34].addPath(23);
	paths[34].addPath(29);
	paths[35].addPath(25);
	paths[35].addPath(26);
	paths[36].addPath(27);
	paths[36].addPath(28);
	paths[37].addPath(24);
	paths[37].addPath(30);
	paths[38].addPath(25);
	paths[38].addPath(31);
	paths[39].addPath(26);
	paths[39].addPath(32);
	paths[40].addPath(27);
	paths[40].addPath(33);
	paths[41].addPath(28);
	paths[41].addPath(34);
	paths[42].addPath(29);
	paths[42].addPath(35);
	paths[43].addPath(30);
	paths[43].addPath(31);
	paths[44].addPath(32);
	paths[44].addPath(33);
	paths[45].addPath(34);
	paths[45].addPath(35);
	paths[46].addPath(30);
	paths[46].addPath(36);
	paths[47].addPath(31);
	paths[47].addPath(37);
	paths[48].addPath(32);
	paths[48].addPath(38);
	paths[49].addPath(33);
	paths[49].addPath(39);
	paths[50].addPath(34);
	paths[50].addPath(40);
	paths[51].addPath(35);
	paths[51].addPath(41);
	paths[52].addPath(37);
	paths[52].addPath(38);

	paths[53].addPath(39);
	paths[53].addPath(40);
	paths[54].addPath(36);
	paths[54].addPath(42);
	paths[55].addPath(37);
	paths[55].addPath(43);
	paths[56].addPath(38);
	paths[56].addPath(44);
	paths[57].addPath(39);
	paths[57].addPath(45);
	paths[58].addPath(40);
	paths[58].addPath(46);
	paths[59].addPath(41);
	paths[59].addPath(47);
	paths[60].addPath(42);
	paths[60].addPath(43);
	paths[61].addPath(44);
	paths[61].addPath(45);
	paths[62].addPath(46);
	paths[62].addPath(47);
	paths[63].addPath(43);
	paths[63].addPath(48);
	paths[64].addPath(44);
	paths[64].addPath(49);
	paths[65].addPath(45);
	paths[65].addPath(50);
	paths[66].addPath(46);
	paths[66].addPath(51);
	paths[67].addPath(48);
	paths[67].addPath(49);
	paths[68].addPath(50);
	paths[68].addPath(51);
	paths[69].addPath(49);
	paths[69].addPath(52);
	paths[70].addPath(50);
	paths[70].addPath(53);
	paths[71].addPath(52);
	paths[71].addPath(53);

// path add neighbour
// tile add address










}
