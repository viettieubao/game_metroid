
#include "SceneMain.h"
#define GROUND_Y 450

SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	BG->Draw(camera);
	samus->Draw(camera);
	samus->Update(t);

	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_RIGHT))
	{
		samus->isturnleft = false;
	}
	else
		if (IsKeyDown(DIK_LEFT))
		{
			samus->isturnleft = true;
		}
}



void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	//load background
	BG = new CBackground(1);
	camera = new CCamera();
	camera->viewport.x = 1023;
	camera->viewport.y = 2846;
	samus = new CSamus(1087,2475);
}

void SceneMain::OnKeyDown(int KeyCode)
{
	
}

SceneMain::~SceneMain(void)
{
}
