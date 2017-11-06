
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
	//samus->Update(t);
	G_SpriteHandler->End();
	
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_RIGHT))
	{
		//samus->isturnleft = false;
		camera->viewport.x += 10;
	}
	else
		if (IsKeyDown(DIK_LEFT))
		{
			//samus->isturnleft = true;
			camera->viewport.x -= 10;
		}
}



void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	//load background
	camera = new CCamera();
	BG = new CBackground(1);
	camera->viewport.x = 1023;//1023
	camera->viewport.y = 480;//480
	samus = new CSamus(1264,129);
	
}

void SceneMain::OnKeyDown(int KeyCode)
{
	
}

SceneMain::~SceneMain(void)
{
}
