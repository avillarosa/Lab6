class Table{

private:
	Color color;
	int numberOfLegs;
	Material material;
	Dimension tableDim;
	int surfaceArea;
	vector < Book > books;
	vector <TissueBox> tissueBoxes;
	vector <Lamp> lamps;


public:
	Color getColor(){
		return color;
	}

	int getNumberOfLegs(){
		return numberOfLegs;
	}

	Material getMaterial(){
		return material;
	}

	int getLength(){
		return tableDim.length;
	}

	int getWidth(){
		return tableDim.width;
	}

	int getSurfaceArea(){
		return surfaceArea;
	}

	int getNumberOfBooks(){
		return books.size();
	}

	int getNumberOfTissueBoxes(){
		return tissueBoxes.size();
	}

	int getNumberOfLamps(){
		return lamps.size();
	}

	vector<Book> getBooks(){
		return books;
	}

	void setColor(string c){
		if (c == "black"){
			color = BLACK;
		}
		else if (c == "brown"){
			color = BROWN;
		}
		else if (c == "white"){
			color = WHITE;
		}
		else if (c == "green"){
			color = GREEN;
		}
		else{
			color = RED;
		}
	}

	void setNumberOfLegs(int numLegs){
		numberOfLegs = numLegs;
	}

	void setMaterial(string m){
		if (m == "wood"){
			material = WOOD;
		}
		else if (m == "metal"){
			material = METAL;
		}
		else{
			material = CERAMIC;
		}
	}

	void setLength(int l){
		tableDim.length = l;
	}

	void setWidth(int w){
		tableDim.width = w;
	}

	void setSurfaceArea(int length, int width){
		surfaceArea = length * width;
	}

	void addBook(Book book){
		if (surfaceArea >= book.getSurfaceArea()){
			books.push_back(book);
			surfaceArea -= book.getSurfaceArea();
			cout << endl << book.getTitle() << " has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for " << book.getTitle() << "." << endl;
		}
	}

	void removeBook(){
		if (!books.empty()){
			int i = books.size();
			surfaceArea += books[i - 1].getSurfaceArea();
			cout << endl << books[i - 1].getTitle() << " has been removed from the table." << endl;
			books.pop_back();
		}
		else{
			cout << endl << "There are currently no books on the table." << endl;
		}
	}

	void addTissueBox(TissueBox tissueBox){
		if (surfaceArea >= tissueBox.getSurfaceArea()){
			tissueBoxes.push_back(tissueBox);
			surfaceArea -= tissueBox.getSurfaceArea();
			cout << endl << "The tissue box has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for this tissue box." << endl;
		}
	}

	void removeTissueBox(){
		if (!tissueBoxes.empty()){
			int i = tissueBoxes.size();
			surfaceArea += tissueBoxes[i - 1].getSurfaceArea();
			cout << endl << "The most recent tissue box placed has been removed from the table." << endl;
			tissueBoxes.pop_back();
		}
		else{
			cout << endl << "There are currently no tissue boxes on the table." << endl;
		}
	}

	void addLamp(Lamp lamp){
		if (surfaceArea >= lamp.getSurfaceArea()){
			lamps.push_back(lamp);
			surfaceArea -= lamp.getSurfaceArea();
			cout << endl << "The lamp has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for this lamp." << endl;
		}
	}

	void removeLamp(){
		if (!lamps.empty()){
			int i = lamps.size();
			surfaceArea += lamps[i - 1].getSurfaceArea();
			cout << endl << "The most recent lamp placed has been removed from the table." << endl;
			lamps.pop_back();
		}
		else{
			cout << endl << "There are currently no lamps on the table." << endl;
		}
	}

	void input(){
		string tableMaterial;
		string tableColor;
		//int numberOfLegs;
		int tableLength;
		int tableWidth;
		//int tableSurfaceArea;

		cout << "Please select the material you would like your table "
			<< "to be made out of: (wood / metal / ceramic) ";
		cin >> tableMaterial;
		while (tableMaterial != "wood" && tableMaterial != "metal" && tableMaterial != "ceramic"){
			cout << "Invalid response. Please respond with \"wood,\"  \"metal,\" or \"ceramic.\" ";
			cin >> tableMaterial;
		}

		setMaterial(tableMaterial);

		cout << "Please select the number of legs you would like "
			<< "your table to have(1, 3, or 4): ";
		cin >> numberOfLegs;

		while (numberOfLegs != 1 && numberOfLegs != 3 && numberOfLegs != 4){
			cout << "Invalid response. Please respond with \"1,\"  \"3,\" or \"4.\" ";
			cin >> numberOfLegs;
		}

		setNumberOfLegs(numberOfLegs);

		cout << "Please select the color of table you would like: "
			<< "(black, brown, white, green, red) ";
		cin >> tableColor;
		while (tableColor != "black" && tableColor != "brown" && tableColor != "white"
			&& tableColor != "green" && tableColor != "red"){
			cout << "Invalid response. Please respond with \"black,\"  \"brown,\""
				<< " \"white,\" \"green,\" or \"red.\" ";
			cin >> tableColor;
		}

		setColor(tableColor);

		cout << "How many inches long would you like your table to be? ";
		cin >> tableLength;
		setLength(tableLength);

		cout << "How many inches wide would you like your table to be? ";
		cin >> tableWidth;
		setWidth(tableWidth);

		table.setSurfaceArea(tableLength, tableWidth);
		cout << "The current surface area of the table available is "
			<< surfaceArea << " square inches." << endl;
	}

	void output(){
		cout << endl << "You currently have " << getNumberOfBooks() << " books, "
			<< getNumberOfTissueBoxes() << " tissue boxes, and "
			<< getNumberOfLamps() << " lamps on your table." << endl << endl;
	}

};