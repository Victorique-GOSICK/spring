// TreeDrawer.h: interface for the CTreeDrawer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __BASIC_TREE_DRAWER_H__
#define __BASIC_TREE_DRAWER_H__

#include "archdef.h"

#include <map>
#include "BaseTreeDrawer.h"

#define MAX_TREE_HEIGHT 60

class CBasicTreeDrawer : public CBaseTreeDrawer
{
public:
	CBasicTreeDrawer();
	virtual ~CBasicTreeDrawer();

	void Draw(float treeDistance,bool drawReflection);
	void Update();
	void CreateTreeTex(unsigned int& texnum,unsigned char* data,int xsize,int ysize);
	void AddTree(int type, float3 pos, float size);
	void DeleteTree(float3 pos);

	unsigned int treetex;
	int lastListClean;

	struct TreeStruct{
		float3 pos;
		int type;
	};

	struct TreeSquareStruct {
		unsigned int displist;
		unsigned int farDisplist;
		int lastSeen;
		int lastSeenFar;
		float3 viewVector;
		std::map<int,TreeStruct> trees;
	};

	TreeSquareStruct* trees;
	int treesX;
	int treesY;

	void ResetPos(const float3& pos);
};

#endif // __BASIC_TREE_DRAWER_H__
