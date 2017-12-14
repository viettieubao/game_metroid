
#include "SceneMain.h"
#define GROUND_Y 450

SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	samus->Update(t, camera);
	camera->viewport.x = samus->fX-255;

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	BG->Draw(camera);
	samus->Draw(camera);
	G_SpriteHandler->End();
	
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	
	if (IsKeyDown(DIK_LEFT)) {
		
			camera->CenterSprite(samus->getx(), samus->gety());
			camera->UpdateCamera(samus->getx(), samus->gety(), -Delta*samus->getx());
			samus->MoveLeft();
			/*samus->StandUp();*/
			return;

	}
	if (IsKeyDown(DIK_RIGHT)) {
		if (IsKeyDown(DIK_DOWN)) {
			if (samus->getattacking() == 0) {
				samus->Stop();
				return;
			}
		}
		else
		{
			camera->CenterSprite(samus->getx(), samus->gety());
			camera->UpdateCamera(samus->getx(), samus->gety(), -Delta*samus->getx());
			samus->MoveRight();
			/*samus->StandUp();*/
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
	samus = new CSamus(1264,113);
	
}

void SceneMain::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{case DIK_X:
		if (samus->getattacking()==0)
			samus->Jump();
			break;
	case DIK_DOWN:
		samus->setrolling(1);
		samus->Roll();
		samus->StandUp();
		break;
	case DIK_UP:
		samus->setrolling(0);
		break;
	default:
		break;
	}

}


SceneMain::~SceneMain(void)
{
}
