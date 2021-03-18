class MarketHeaderBackground : Life_RscText {
	idc = 23034;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(0.022);
};

class MarketListHeader: Life_RscListNBox {
	idc = 23032;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.4, 0.55, 0.7 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
		class DisplayName {
			text = "Item";
			value = 0;
		};
		class Weight {
			text = "Weight";
			value = -1;
			data = "data";
		};
		class Legal {
			text = "Legal";
			value = -1;
			data = "data";
		};
		class SellPrice { 
			text = "Sell Price";
			value = -1;
			data = "data";
		};
	};
};

class MarketListBackground : Life_RscText {
	idc = 23035;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + 0.022);
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(UI_HEIGHT - 0.022);
};

class MarketList : Life_RscListNBox {
	idc = 23033;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + 0.022);
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(UI_HEIGHT - 0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.4, 0.55, 0.7 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};