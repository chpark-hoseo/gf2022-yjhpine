#include "TileLayer.h"

TileLayer::TileLayer(int tilesize ,int rowcount, int colcount, TileMap tilemap, TilesetList tilesets)
{
	m_Tilesets = tilesets;
	m_RowCount = rowcount;
	m_ColCount = colcount;
	m_TileMap = tilemap;
	m_Tilesets = tilesets;
}
void TileLayer::Render()
{
	for (unsigned int i = 0; i < m_RowCount; i++)
	{
		for (unsigned int j = 0; j < m_ColCount; j++)
		{
			int tileID = m_TileMap[i][j];

			if (tileID == 0)
				continue;
			else {
				int index;
				if (m_Tilesets.size() > 1) {
					for (unsigned int k = 1; k < m_Tilesets.size(); k++) {
						if (tileID > m_Tilesets[k].First && tileID < m_Tilesets[k].LastID) {
							tileID = tileID + m_Tilesets[k].TileCount - m_Tilesets[k].LastID;
							index = k;
							break;
						}
					}
				}
				Tileset ts = m_Tilesets[index];
				int tileRow = tileID / ts.ColCount;
				int tileCol = tileID - tileRow * ts.ColCount - 1;

				if (tileID % ts.ColCount == 0)
				{
					tileRow--;
					tileCol = ts.ColCount - 1;
				}
				//TextureManager::Instance()->draw("Tile", )
			}
		}
	}
}
void TileLayer::Update()
{

}