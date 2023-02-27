#pragma once
#include "Operation.h"
#include "VennDiagram.h"
#include <string>
#include <optional>
#include <map>
#include <vector>
#include <tuple>
#include <random>
#include <graphics.h>

#define BG_COLOR WHITE

class GraphSet {
private:
	std::map<std::string, std::vector<std::tuple<int, int>>> _vennPositions;
public:

	GraphSet() {
		std::vector<std::tuple<int, int>> leftPositions = {
		{ 760, 56 }, { 700, 80 }, { 745, 80 }, { 785, 80 }, { 665, 105 },
		{ 715, 105 }, { 765, 105 }, { 650, 130 }, { 700, 130 }, { 750, 130 },
		{ 640, 155 }, { 690, 155 }, { 740, 155 }, { 635, 180 }, { 685, 180 },
		{ 735, 180 }, { 640, 205 }, { 690, 205 }, { 740, 205 }, { 645, 230 },
		{ 695, 230 }, { 745, 230 }, { 655, 255 }, { 705, 255 }, { 745, 255 },
		{ 670, 280 }, { 720, 280 }, { 760, 280 }, { 695, 305 }, { 745, 305 }
		};

		std::vector<std::tuple<int, int>> rightPositions = {
			{ 895, 80 }, { 940, 80 }, { 985, 80 }, { 910, 105 }, { 955, 105 },
			{ 1005, 105 }, { 923, 130 }, { 970, 130 }, { 1020, 130 }, { 935, 155 },
			{ 985, 155 }, { 1035, 155 }, { 935, 180 }, { 990, 180 }, { 1040, 180 },
			{ 935, 205 }, { 985, 205 }, { 1035, 205 }, { 930, 230 }, { 980, 230 },
			{ 1030, 230 }, { 925, 255 }, { 975, 255 }, { 1025, 255 }, { 910, 280 },
			{ 960, 280 }, { 1010, 280 }, { 885, 310 }, { 935, 305 }, { 981, 305 }
		};

		std::vector<std::tuple<int, int>> centerPositions = {
			{ 843, 90 }, { 813, 110 }, { 863, 110 }, { 798, 130 }, { 838, 130 },
			{ 878, 130 }, { 792, 150 }, { 838, 150 }, { 888, 150 }, { 788, 170 },
			{ 838, 170 }, { 888, 170 }, { 788, 190 }, { 838, 190 }, { 888, 190 },
			{ 788, 210 }, { 838, 210 }, { 888, 210 }, { 798, 230 }, { 838, 230 },
			{ 878, 230 }, { 803, 250 }, { 838, 250 }, { 873, 250 }, { 813, 270 },
			{ 863, 270 }, { 843, 290 }
		};

		// vamos a desordenar los vectores
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(leftPositions.begin(), leftPositions.end(), g);
		std::shuffle(rightPositions.begin(), rightPositions.end(), g);
		std::shuffle(centerPositions.begin(), centerPositions.end(), g);

		_vennPositions.insert({ "left", leftPositions });
		_vennPositions.insert({ "right", rightPositions });
		_vennPositions.insert({ "center", centerPositions });
	}

	static void drawBase(Operation operation, VennDiagram vd) {
		setbkcolor(BG_COLOR);
		cleardevice();

		setlinestyle(SOLID_LINE, 0, 1);

		// MARCO
		setcolor(BLACK);
		rectangle(610, 30, 610 + 500, 30 + 360);
		setfillstyle(SOLID_FILL, COLOR(245, 245, 245));
		floodfill(612, 32, BLACK);

		// CONJUNTO A
		setcolor(BLACK);
		circle(780, 200, 150);
		settextstyle(0, 0, 2);
		setcolor(BLACK);
		setbkcolor(COLOR(245, 245, 245));
		outtextxy(680, 340, (char*)"A");

		// CONJUNTO B
		setcolor(BLACK);
		circle(930, 200, 150);
		settextstyle(0, 0, 2);
		setcolor(BLACK);
		setbkcolor(COLOR(245, 245, 245));
		outtextxy(1020, 340, (char*)"B");

		setfillstyle(SOLID_FILL, WHITE);
		floodfill(700, 200, BLACK);
		floodfill(800, 200, BLACK);
		floodfill(1000, 200, BLACK);

		//Titulo Diagrama
		settextstyle(0, 0, 2);
		setcolor(BLACK);
		setbkcolor(BG_COLOR);
		outtextxy(650, 10, (char*)"*****DIAGRAMA DE VENN*****");

		//Titulo Operacion
		settextstyle(0, 0, 2);
		setcolor(BLACK);
		setbkcolor(BG_COLOR);
		outtextxy(30, 275, (char*)"------OPERACION------");

		//imagen
		setcolor(BLACK);
		setbkcolor(BG_COLOR);
		readimagefile("logo.jpg", 15, 15, 600, 250);

		// grafica y datos de los conjuntos
		std::string setAValues = "A = {";
		std::string setBValues = "B = {";

		for (int i = 0; i < vd.getLeft().size(); i++) {
			int n = vd.getLeft().at(i);
			setAValues += std::to_string(n);

			if (i < vd.getLeft().size() - 1) {
				setAValues += ", ";
			}
		}

		for (int i = 0; i < vd.getRight().size(); i++) {
			int n = vd.getRight().at(i);
			setBValues += std::to_string(n);

			if (i < vd.getRight().size() - 1) {
				setBValues += ", ";
			}
		}

		setAValues += "}";
		setBValues += "}";

		setcolor(BLACK);
		setbkcolor(BG_COLOR);
		settextstyle(3, 0, 1);
		outtextxy(50, 300, (char*)setAValues.c_str());
		outtextxy(50, 320, (char*)setBValues.c_str());		
	}

	 void drawUnion(Operation operation, VennDiagram vd) {
		 drawBase(operation, vd);
		 setfillstyle(SOLID_FILL, COLOR(173, 222, 255));
		 floodfill(700, 200, BLACK);
		 floodfill(800, 200, BLACK);
		 floodfill(1000, 200, BLACK);

		 setcolor(BLACK);
		 settextstyle(4, 0, 1);
		 setbkcolor(COLOR(173, 222, 255));

		 auto leftPositions = _vennPositions.at("left");
		 auto rightPositions = _vennPositions.at("right");
		 auto centerPositions = _vennPositions.at("center");

		 for (int i = 0; i < vd.getLeft().size(); i++) {
			 if (i >= leftPositions.size()) break;

			 int x = std::get<0>(leftPositions.at(i));
			 int y = std::get<1>(leftPositions.at(i));
			 setcolor(BLACK);
			 outtextxy(x, y, (char*)std::to_string(vd.getLeft().at(i)).c_str());
		 }

		 for (int i = 0; i < vd.getRight().size(); i++) {
			 if (i >= rightPositions.size()) break;

			 int x = std::get<0>(rightPositions.at(i));
			 int y = std::get<1>(rightPositions.at(i));
			 setcolor(BLACK);
			 outtextxy(x, y, (char*)std::to_string(vd.getRight().at(i)).c_str());
		 }

		 for (int i = 0; i < vd.getIntersection().size(); i++) {
			 if (i >= centerPositions.size()) break;

			 int x = std::get<0>(centerPositions.at(i));
			 int y = std::get<1>(centerPositions.at(i));
			 setcolor(BLACK);
			 outtextxy(x, y, (char*)std::to_string(vd.getIntersection().at(i)).c_str());
		 }

		 std::string resultSetString = "A U B = {";
		 Set setUnion = operation.doUnion();
		 auto unionValues = setUnion.getAsVector();

		 for (int i = 0; i < unionValues.size(); i++) {
			 int n = unionValues.at(i);
			 resultSetString += std::to_string(n);

			 if (i < unionValues.size() - 1) {
				 resultSetString += ", ";
			 }
		 }

		 resultSetString += "}";

		 setcolor(BLACK);
		 settextstyle(3, 0, 1);
		 setbkcolor(BG_COLOR);
		 outtextxy(50, 340, (char*)resultSetString.c_str());


		 setcolor(BLACK);
		 settextstyle(0, 0, 2);
		 setbkcolor(BG_COLOR);
		 outtextxy(750, 400, (char*)"------UNION------");		 
	 }

	void drawIntersection(Operation operation, VennDiagram vd) {
		drawBase(operation, vd);
		setfillstyle(SOLID_FILL, COLOR(255, 173, 173));
		floodfill(810, 200, BLACK);

		setcolor(BLACK);
		settextstyle(4, 0, 1);
		setbkcolor(COLOR(255, 173, 173));

		auto leftPositions = _vennPositions.at("left");
		auto rightPositions = _vennPositions.at("right");
		auto centerPositions = _vennPositions.at("center");

		for (int i = 0; i < vd.getLeft().size(); i++) {
			if (i >= leftPositions.size()) break;

			int x = std::get<0>(leftPositions.at(i));
			int y = std::get<1>(leftPositions.at(i));
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(x, y, (char*)std::to_string(vd.getLeft().at(i)).c_str());
		}

		for (int i = 0; i < vd.getRight().size(); i++) {
			if (i >= rightPositions.size()) break;

			int x = std::get<0>(rightPositions.at(i));
			int y = std::get<1>(rightPositions.at(i));
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(x, y, (char*)std::to_string(vd.getRight().at(i)).c_str());
		}

		for (int i = 0; i < vd.getIntersection().size(); i++) {
			if (i >= centerPositions.size()) break;

			int x = std::get<0>(centerPositions.at(i));
			int y = std::get<1>(centerPositions.at(i));
			setcolor(BLACK);
			setbkcolor(COLOR(255, 173, 173));
			outtextxy(x, y, (char*)std::to_string(vd.getIntersection().at(i)).c_str());
		}

		std::string resultSetString = "A (interseccion) B = {";
		Set setUnion = operation.doUnion();
		auto unionValues = setUnion.getAsVector();

		for (int i = 0; i < unionValues.size(); i++) {
			int n = unionValues.at(i);
			resultSetString += std::to_string(n);

			if (i < unionValues.size() - 1) {
				resultSetString += ", ";
			}
		}

		resultSetString += "}";

		setcolor(BLACK);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(50, 340, (char*)resultSetString.c_str());

		setcolor(BLACK);
		settextstyle(0, 0, 2);
		setbkcolor(BG_COLOR);
		outtextxy(750, 400, (char*)"------INTERSECCION------");		
	}

	void drawDifference(Operation operation, VennDiagram vd, bool isLeft = true) {
		drawBase(operation, vd);
		setfillstyle(SOLID_FILL, COLOR(255, 173, 173));

		if (isLeft) {
			floodfill(700, 200, BLACK);
		}
		else {
			floodfill(1000, 200, BLACK);
		}

		setcolor(BLACK);
		settextstyle(4, 0, 1);
		setbkcolor(COLOR(255, 173, 173));

		auto leftPositions = _vennPositions.at("left");
		auto rightPositions = _vennPositions.at("right");
		auto centerPositions = _vennPositions.at("center");

		for (int i = 0; i < vd.getLeft().size(); i++) {
			if (i >= leftPositions.size()) break;

			int x = std::get<0>(leftPositions.at(i));
			int y = std::get<1>(leftPositions.at(i));
			setcolor(BLACK);

			if (isLeft) {
				setbkcolor(COLOR(255, 173, 173));
			}
			else {
				setbkcolor(WHITE);
			}

			outtextxy(x, y, (char*)std::to_string(vd.getLeft().at(i)).c_str());
		}

		for (int i = 0; i < vd.getRight().size(); i++) {
			if (i >= rightPositions.size()) break;

			int x = std::get<0>(rightPositions.at(i));
			int y = std::get<1>(rightPositions.at(i));
			setcolor(BLACK);

			if (!isLeft) {
				setbkcolor(COLOR(255, 173, 173));
			}
			else {
				setbkcolor(WHITE);
			}

			outtextxy(x, y, (char*)std::to_string(vd.getRight().at(i)).c_str());
		}

		for (int i = 0; i < vd.getIntersection().size(); i++) {
			if (i >= centerPositions.size()) break;

			int x = std::get<0>(centerPositions.at(i));
			int y = std::get<1>(centerPositions.at(i));
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(x, y, (char*)std::to_string(vd.getIntersection().at(i)).c_str());
		}

		std::string resultSetString = (isLeft ? "A - B = {" : "B - A = {");
		Set resultSet = operation.doDifference();
		auto values = resultSet.getAsVector();

		for (int i = 0; i < values.size(); i++) {
			int n = values.at(i);
			resultSetString += std::to_string(n);

			if (i < values.size() - 1) {
				resultSetString += ", ";
			}
		}

		resultSetString += "}";

		setcolor(BLACK);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(50, 340, (char*)resultSetString.c_str());

		setcolor(BLACK);
		settextstyle(0, 0, 2);
		setbkcolor(BG_COLOR);
		outtextxy(750, 400, (char*)"------DIFERENCIA------");
		
	}

	void drawSymmetricDifference(Operation operation, VennDiagram vd) {
		drawBase(operation, vd);
		setfillstyle(SOLID_FILL, COLOR(255, 173, 173));
		floodfill(700, 200, BLACK);
		floodfill(1000, 200, BLACK);

		setcolor(BLACK);
		settextstyle(4, 0, 1);
		setbkcolor(COLOR(255, 173, 173));

		auto leftPositions = _vennPositions.at("left");
		auto rightPositions = _vennPositions.at("right");
		auto centerPositions = _vennPositions.at("center");

		for (int i = 0; i < vd.getLeft().size(); i++) {
			if (i >= leftPositions.size()) break;

			int x = std::get<0>(leftPositions.at(i));
			int y = std::get<1>(leftPositions.at(i));
			setcolor(BLACK);
			outtextxy(x, y, (char*)std::to_string(vd.getLeft().at(i)).c_str());
		}

		for (int i = 0; i < vd.getRight().size(); i++) {
			if (i >= rightPositions.size()) break;

			int x = std::get<0>(rightPositions.at(i));
			int y = std::get<1>(rightPositions.at(i));
			setcolor(BLACK);
			setbkcolor(COLOR(255, 173, 173));
			outtextxy(x, y, (char*)std::to_string(vd.getRight().at(i)).c_str());
		}

		for (int i = 0; i < vd.getIntersection().size(); i++) {
			if (i >= centerPositions.size()) break;

			int x = std::get<0>(centerPositions.at(i));
			int y = std::get<1>(centerPositions.at(i));
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(x, y, (char*)std::to_string(vd.getIntersection().at(i)).c_str());
		}

		std::string resultSetString = "A (diferencia sim.) B = {";
		Set resultSet = operation.doSymmetricDifference();
		auto values = resultSet.getAsVector();

		for (int i = 0; i < values.size(); i++) {
			int n = values.at(i);
			resultSetString += std::to_string(n);

			if (i < values.size() - 1) {
				resultSetString += ", ";
			}
		}

		resultSetString += "}";

		setcolor(BLACK);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(50, 340, (char*)resultSetString.c_str());

		setcolor(BLACK);
		settextstyle(0, 0, 2);
		setbkcolor(BG_COLOR);
		outtextxy(750, 400, (char*)"--DIFERENCIA SIMETRICA--");
	}

	void drawComplement(Operation operation, VennDiagram vd, bool isLeft) {
		drawBase(operation, vd);
		setfillstyle(SOLID_FILL, COLOR(255, 173, 173));

		if (isLeft) {
			floodfill(700, 200, BLACK);
		}
		else {
			floodfill(1000, 200, BLACK);
		}

		setfillstyle(SOLID_FILL, COLOR(255, 173, 173));
		floodfill(612, 32, BLACK);

		setcolor(BLACK);
		settextstyle(4, 0, 1);
		setbkcolor(COLOR(255, 173, 173));

		auto leftPositions = _vennPositions.at("left");
		auto rightPositions = _vennPositions.at("right");
		auto centerPositions = _vennPositions.at("center");

		for (int i = 0; i < vd.getLeft().size(); i++) {
			if (i >= leftPositions.size()) break;

			int x = std::get<0>(leftPositions.at(i));
			int y = std::get<1>(leftPositions.at(i));
			setcolor(BLACK);

			if (isLeft) {
				setbkcolor(COLOR(255, 173, 173));
			}
			else {
				setbkcolor(WHITE);
			}

			outtextxy(x, y, (char*)std::to_string(vd.getLeft().at(i)).c_str());
		}

		for (int i = 0; i < vd.getRight().size(); i++) {
			if (i >= rightPositions.size()) break;

			int x = std::get<0>(rightPositions.at(i));
			int y = std::get<1>(rightPositions.at(i));
			setcolor(BLACK);

			if (!isLeft) {
				setbkcolor(COLOR(255, 173, 173));
			}
			else {
				setbkcolor(WHITE);
			}

			outtextxy(x, y, (char*)std::to_string(vd.getRight().at(i)).c_str());
		}

		for (int i = 0; i < vd.getIntersection().size(); i++) {
			if (i >= centerPositions.size()) break;

			int x = std::get<0>(centerPositions.at(i));
			int y = std::get<1>(centerPositions.at(i));
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(x, y, (char*)std::to_string(vd.getIntersection().at(i)).c_str());
		}
		if (!isLeft) {
			std::string resultSetString = "A (complemento) B = {";
			Set resultSet = operation.doComplement();
			auto values = resultSet.getAsVector();
			for (int i = 0; i < values.size(); i++) {
				int n = values.at(i);
				resultSetString += std::to_string(n);

				if (i < values.size() - 1) {
					resultSetString += ", ";
				}
			}

			resultSetString += "}";

			setcolor(BLACK);
			settextstyle(3, 0, 1);
			setbkcolor(BG_COLOR);
			outtextxy(50, 340, (char*)resultSetString.c_str());
		}
		else {
			std::string resultSetString = "B (complemento) A = {";
			Set resultSet = operation.doComplement();
			auto values = resultSet.getAsVector();
			for (int i = 0; i < values.size(); i++) {
				int n = values.at(i);
				resultSetString += std::to_string(n);

				if (i < values.size() - 1) {
					resultSetString += ", ";
				}
			}

			resultSetString += "}";

			setcolor(BLACK);
			settextstyle(3, 0, 1);
			setbkcolor(BG_COLOR);
			outtextxy(50, 340, (char*)resultSetString.c_str());
		}		

		setcolor(BLACK);
		settextstyle(0, 0, 2);
		setbkcolor(BG_COLOR);
		outtextxy(750, 400, (char*)"------COMPLEMENTO------");
	}


	static void drawPlane() {
		setcolor(RED);
		settextstyle(0, 0, 2);
		setbkcolor(BG_COLOR);
		outtextxy(100, 420, (char*)"********************BIG O********************");

		setcolor(BLACK);
		line(100, 450, 100, 700);
		line(100, 700, 400, 700);

		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		setcolor(BLACK);
		outtextxy(110, 450, (char*)"Tiempo");

		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		setcolor(BLACK);
		outtextxy(320, 710, (char*)"Entrada");
	}

	static void drawBigO_n() {
		drawPlane();
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 2);
		line(100, 700, 370, 480);

		setcolor(BLUE);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(380, 480, (char*)"O(n)");
	}

	static void drawBigO_nlogn() {
		drawPlane();
		setcolor(RED);
		moveto(100, 700);

		for (int i = 1; i <= 10; i++) {
			lineto(70 + i * 30, 700 - (i * log(i) * 20) / 3);
		}

		setcolor(RED);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(380, 480, (char*)"O(n log n)");
	}

	static void drawBigO_2n() {
		drawPlane();
		setcolor(GREEN);
		moveto(100, 700);

		for (int i = 1; i <= 5; i++) {
			lineto(100 + i * 30, 700 - pow(2, i) * 8);
		}

		setcolor(GREEN);
		settextstyle(3, 0, 1);
		setbkcolor(BG_COLOR);
		outtextxy(300, 440, (char*)"O(2^n)");
	}

};



