string currentTurn;

while (commandLine >> word) {
	if (word == "-load") {
		load_flag = true;
		string game_file;
		commandLine >> game_file;
		ifstream myfile;
		myfile.open (game_file);

		myfile >> currentTurn; // read in <curTurn>

		string line;
		for (int i = 0; i < 4; ++i) { // read in <builder(0-3)data>
			getline(myfile,line);
			int bricks, energies, glasses, heats, wifis;
			line >> bricks >> energies >> glasses >> heats >> wifis
			builders[i].addBrick(bricks);
			builders[i].addEnergy(energies);
			builders[i].addGlass(glasses);
			builders[i].addHeat(heats);
			builders[i].addWifi(wifis);

			string r_flush;
			line >> r_flush;

			int path;
			while (line >> path) {
				builders[i].addPath(path);
			}

			int address;
			string residence;
			while (line >> address) {
				line >> residence;
				builders[i].addAddress(address);
				// add residence type
				// builders[i].addAddress(address,residence);
			}
		}

		getline(myfile,line);
		int resource;
		int value;
		for (int i = 0; i < 19; ++i) { // read in the Board Layout
			line >> resource >> value;
			if (resource == 0) {
				tiles[i].setRes("BRICK");
				tiles[i].setVal(value);
			}
			else if (resource == 1) {
				tiles[i].setRes("ENERGY");
				tiles[i].setVal(value);
			}
			else if (resource == 2) {
				tiles[i].setRes("GLASS");
				tiles[i].setVal(value);
			}
			else if (resource == 3) {
				tiles[i].setRes("HEAT");
				tiles[i].setVal(value);
			}
			else if (resource == 4) {
				tiles[i].setRes("WIFI");
				tiles[i].setVal(value);
			}
			else if (resource == 5) {
				tiles[i].setRes("PARK");
			}
		}
	}

	else if (word == "-board") {
		string board_file;
		commandLine >> board_file;
		ifstream myfile;
		myfile.open(board_file);
		getline(myfile, line);

		for (int i = 0; i < 19; ++i) { // read in the Board Layout
			line >> resource >> value;
			if (resource == 0) {
				tiles[i].setRes("BRICK");
				tiles[i].setVal(value);
			}
			else if (resource == 1) {
				tiles[i].setRes("ENERGY");
				tiles[i].setVal(value);
			}
			else if (resource == 2) {
				tiles[i].setRes("GLASS");
				tiles[i].setVal(value);
			}
			else if (resource == 3) {
				tiles[i].setRes("HEAT");
				tiles[i].setVal(value);
			}
			else if (resource == 4) {
				tiles[i].setRes("WIFI");
				tiles[i].setVal(value);
			}
			else if (resource == 5) {
				tiles[i].setRes("PARK");
			}
		}
	}
}
