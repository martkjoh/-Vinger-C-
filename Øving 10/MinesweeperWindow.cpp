#include "MinesweeperWindow.h"


MinesweeperWindow::MinesweeperWindow(
	Point xy, int width, int height, int mines, const string& title)
	: Graph_lib::Window(xy, width * cellSize, (height + 1) * cellSize, title), 
	width(width), height(height), mines(mines), status{gameStatus::uavklart}
{
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j) {
			
			int y = i * cellSize;
			int x = j * cellSize;

			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	checkStatus();

	int i = 0;
	while (i < mines)	
	{
		int coord = randomWithLimits(height * width);
		if (tiles[coord].isMine){continue;}
		tiles[coord].isMine = true;
		i++;
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

int MinesweeperWindow::countMines(vector<Point> points) const 
{
	int n = 0;
	for (Point p : points)
	{
		if (at(p).isMine) {n++;}	
	}
	return n;
};

void MinesweeperWindow::openTile(Point xy) 
{
	Tile* t = &at(xy);
	vector<Point> adjPoints = adjacentPoints(xy);
	int n = countMines(adjPoints);
	t->setAdjMines(n);
	t->open();
	if (t->isMine && t->state == Cell::open) 
	{
		status = gameStatus::tap;
		return;
	}

	if (n || (xy.x == 0 && xy.y == 0)) {return;}

	for (Point p : adjPoints)
	{
		if ((p.x == xy.x && p.y == xy.y) || at(p).state == Cell::open) {continue;}
		openTile(p);
	}
}

void MinesweeperWindow::flagTile(Point xy) 
{
	Tile* t = &at(xy);
	t->flag();
	if (t->state == Cell::open) {return;}
	if (t->state == Cell::flagged)
	{
		if (t->isMine) {flaggedMines++;}
		else {flaggedNoneMines++;}
	}
	else
	{
		if (t->isMine) {flaggedMines--;}
		else {flaggedNoneMines--;}
	}
	if (flaggedNoneMines == 0 && flaggedMines == mines){status = gameStatus::seier;}
}

//Kaller opentile ved venstreklikk og flagTile ved h�yreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.checkStatus();
	win.flush();
}

void MinesweeperWindow::checkStatus()
{
	switch(status)
	{
		case gameStatus::uavklart:
		{
			str = "Uoppdagede miner: " + to_string(mines - flaggedMines);
			cout << str << endl;
			break;
		}

		case gameStatus::seier:
		{
			str = "Gratulerer, du vant!";
			break;
		}

		case gameStatus::tap:
		{
			str = "Du tapte";
			break;
		}
	}

	detach(*text);
	text =  new Graph_lib::Text(Point{0, height * cellSize + cellSize / 2}, str);
	attach(*text);
	this->redraw();
}
