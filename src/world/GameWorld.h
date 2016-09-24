/*
 * GameWorld.h
 *
 *  Created on: 23.01.2016
 *      Author: Kevin
 */

#ifndef _GAMEWORLD_H_
#define _GAMEWORLD_H_

#include <map>
#include "blocks/BlockManager.h"
#include "chunk/Chunk.h"
#include "../renderer/BlockRenderer.h"
#include "../scenes/Basic3DScene.h"
#include "../utils/MathHelper.h"

#define CHUNK_AMOUNT_X 50
#define CHUNK_AMOUNT_Z 50

#define CHUNK_PLAYER_FOV 7 // how many chunks the player can see

typedef struct ChunkPositionComparer
{
	bool operator()(const class Vector3f* s1, const class Vector3f* s2) const
	{
	    return s1->GetX() < s2->GetX() || (s1->GetX() == s2->GetX() && s1->GetZ() < s2->GetZ());
	}
} ChunkPositionComparer;

class CGameWorld {
public:
	CGameWorld( class Basic3DScene* pScene );
	virtual ~CGameWorld();
	void GenerateWorld();
	void Draw();

	class CBlockManager& GetBlockManager();
	class CChunk* GetChunkAt(const Vector3f& centerPosition) const;
	class CChunk* GetChunkByWorldPosition(const Vector3f& worldPosition);
	void RemoveBlockByWorldPosition(const Vector3f& blockPosition);
	void AddBlockAtWorldPosition(const Vector3f& blockPosition, BlockType type);
	void UpdateFocusedBlockByWorldPosition( const Vector3f& blockPosition );
	BlockType GetBlockByWorldPosition(const Vector3f& worldPosition);
	Vector3f GetBlockPositionByWorldPosition(const Vector3f& worldPosition);
	Vector3f GetNewPlayerPosition( const Vector3f& playerWorldPosition );


private:
	bool ChunkInFov( Vector3f& chunkPosition, Vector3f& playerPosition, unsigned int fov);
	void DrawFocusOnSelectedCube();

private:
	class Basic3DScene* m_pScene;
	CBlockManager* m_blockManager;
	std::map<const class Vector3f*, class CChunk*, ChunkPositionComparer> m_ChunkList;

	Vector3f m_SelectedBlockPosition;
	bool m_bHasSelectedBlock = false;

	char* m_pChunkLogBuffer;
	char* m_pDisplayListSizeLogBuffer;

	char* m_pBlocksLogBuffer;
	char* m_pFaceLogBuffer;

};

#endif /* _GAMEWORLD_H_ */