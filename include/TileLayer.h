#pragma once
#include "Layer.h"
#include "Game.h"

struct Tileset {
	int First, LastID;
	int RowCount, ColCount;
	int TileCount, TileSize;
	std::string Name, Source;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer : public Layer
{
public:
	TileLayer(int tilesizem, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets);
	virtual void Render();
	virtual void Update();
	inline TileMap GetTileMap() { return m_TileMap; }
private:
	int m_TileSize;
	int m_RowCount, m_ColCount;

	TileMap m_TileMap;
	TilesetList m_Tilesets;

};