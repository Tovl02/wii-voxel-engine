/*
 * BlockRenderer.cpp
 *
 *  Created on: 10.07.2015
 *      Author: Kevin
 */

#include "BlockRenderer.h"
//#include "MipTexture_tpl.h"

BlockRenderer::BlockRenderer( )
{
	//this->setTexture(getTextureHandler()->createTexture( GroundText_png ));
}

BlockRenderer::~BlockRenderer() {

}


void BlockRenderer::Prepare(std::vector<Vector3f*> *positionList, float blockSize, Texture* ptexture)
{
	m_renderBlockSize = blockSize;
	m_positions = positionList;
	GRRLIB_SetTexture(ptexture->getNativeTexture(), true, false);
}

void BlockRenderer::Finish()
{
	m_renderBlockSize = 0.0f;
	m_positions = NULL;
}

// note: we start drawing with the top left corner, top right, bottom right, bottom left
void BlockRenderer::render(/*Vector3f blockPosition, float blockSize*/ )
{
	for(auto it = m_positions->begin(); it != m_positions->end(); ++it)
	{
		Vector3f blockPosition = (**it);

		//CBlock* pBlockToRender = static_cast<CBlock*>(m_Entity);
		//Vector3f blockPosition = position;//Vector3f(.0f, .0f, .0f);// pBlockToRender->getPosition();
		//float blockSize = 1.0f; //pBlockToRender->getSize();

		// see http://www.matrix44.net/cms/wp-content/uploads/2011/03/ogl_coord_object_space_cube.png
		guVector vbo[8] = {
				{ blockPosition.getX() - m_renderBlockSize, blockPosition.getY() + m_renderBlockSize, blockPosition.getZ() + m_renderBlockSize },// v1
				{ blockPosition.getX() - m_renderBlockSize, blockPosition.getY() - m_renderBlockSize, blockPosition.getZ() + m_renderBlockSize }, //v2
				{ blockPosition.getX() + m_renderBlockSize, blockPosition.getY() - m_renderBlockSize, blockPosition.getZ() + m_renderBlockSize }, //v3
				{ blockPosition.getX() + m_renderBlockSize, blockPosition.getY() + m_renderBlockSize, blockPosition.getZ() + m_renderBlockSize }, // v4
				{ blockPosition.getX() - m_renderBlockSize, blockPosition.getY() + m_renderBlockSize, blockPosition.getZ() - m_renderBlockSize }, //v5
				{ blockPosition.getX() + m_renderBlockSize, blockPosition.getY() + m_renderBlockSize, blockPosition.getZ() - m_renderBlockSize }, // v6
				{ blockPosition.getX() + m_renderBlockSize, blockPosition.getY() - m_renderBlockSize, blockPosition.getZ() - m_renderBlockSize }, // v7
				{ blockPosition.getX() - m_renderBlockSize, blockPosition.getY() - m_renderBlockSize, blockPosition.getZ() - m_renderBlockSize } // v8

		};

		//TPLFile crateTPL;
		//TPL_OpenTPLFromMemory(&crateTPL, (void *)MipTexture_tpl, MipTexture_tpl_size);
		//TPL_GetTexture(&crateTPL,crate,&texture);


		//GRRLIB_SetTexture(ptexture->getNativeTexture(), true, false);
		GX_Begin(GX_QUADS, GX_VTXFMT0, 24);
				// front side
				GX_Position3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Normal3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Normal3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Normal3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Normal3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);

				// back side
				GX_Position3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Normal3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Normal3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Normal3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Normal3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);

				// right side
				GX_Position3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Normal3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Normal3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Normal3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Normal3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);

				// left side
				GX_Position3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Normal3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Normal3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Normal3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Normal3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);

				// top side
				GX_Position3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Normal3f32(vbo[4].x, vbo[4].y, vbo[4].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Normal3f32(vbo[5].x, vbo[5].y, vbo[5].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Normal3f32(vbo[3].x, vbo[3].y, vbo[3].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Normal3f32(vbo[0].x, vbo[0].y, vbo[0].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);

				// bottom side
				GX_Position3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Normal3f32(vbo[6].x, vbo[6].y, vbo[6].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,0.0f);
				GX_Position3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Normal3f32(vbo[7].x, vbo[7].y, vbo[7].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,0.0f);
				GX_Position3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Normal3f32(vbo[1].x, vbo[1].y, vbo[1].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(1.0f,1.0f);
				GX_Position3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Normal3f32(vbo[2].x, vbo[2].y, vbo[2].z);
				GX_Color1u32(0xFFFFFFFF);
				GX_TexCoord2f32(0.0f,1.0f);
			GX_End();
	}
}
