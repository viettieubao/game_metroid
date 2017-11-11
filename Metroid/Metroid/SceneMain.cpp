
#include "SceneMain.h"
#define GROUND_Y 450

SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	samus->Update(t, camera);

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	BG->Draw(camera);
	samus->Draw(camera);
	G_SpriteHandler->End();
	
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_LEFT)) {
		if (IsKeyDown(DIK_DOWN)) {
			if (samus->getattacking() == 0) {
				samus->Sit();
				samus->Stop();
				return;
			}
		}
		else
		{
			camera->CenterSprite(samus->getx(), samus->gety());
			camera->UpdateCamera(samus->getx(), samus->gety(), -Delta*samus->getx());
			samus->MoveLeft();
			samus->StandUp();
			return;
		}
	}
	if (IsKeyDown(DIK_RIGHT)) {
		if (IsKeyDown(DIK_DOWN)) {
			if (samus->getattacking() == 0) {
				samus->Sit();
				samus->Stop();
				return;
			}
		}
		else
		{
			camera->CenterSprite(samus->getx(), samus->gety());
			camera->UpdateCamera(samus->getx(), samus->gety(), -Delta*samus->getx());
			samus->MoveRight();
			samus->StandUp();
			return;
		}
	}
	if (IsKeyDown(DIK_DOWN)) {
		if (samus->getattacking() == 0) {
			samus->Sit();
			return;
		}
	}
	else {
		samus->Stop();
		samus->StandUp();
		return;
	}

}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	//load background
	camera = new GCamera();
	BG = new CBackground(1);
	camera->viewport.x = 1023;//1023
	camera->viewport.y = 470;//480
	samus = new CSamus(1264,129);
	
}

void SceneMain::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{case DIK_UP:
		if (samus->getattacking() == 0) {
			samus->Jump();
			break;
		}
	default:
		break;
	}
}


SceneMain::~SceneMain(void)
{
}
