#pragma once
#include "DxLib.h"
#include <vector>

//DxLibのサウンドを改造したクラス。IDはロードした順に0から振られる。
class Sound
{
private:
	bool seFlag;																	//ワンショットSE用
	bool flag;																		//BGM再生フラグ
	std::vector<int>BGM;															//BGMデータ格納用
	std::vector<int>SE;															//SEデータ格納用
public:
	int Volume;																		//音量用（あんまり意味ないけど...）
	Sound() { Volume = 0;seFlag = false; };								//コンストラクタ
	~Sound() {};																	//デストラクタ
	void SetSE(const char *FileName);										//第一引数にSEをのパスを指定しロードする。複数ロードでき、配列の後ろに格納される(0~)
	void SetBGM(const char *FileName);										//BGMのパスを指定してロードし、再生フラグを立てる
	void PlayBGM_Loop(int gain = 100);										//BGMをループ再生。引数に音量を指定できる(0~100)デフォルトは100%
	void PlayBGM_Back(int gain = 100);										//BGMをループなしで再生。引数に音量を指定できる(0~100)デフォルトは100%
	void MultiPlayBGM_Loop();													//複数のBGMを同時ループ再生する。主にインタラクティブなBGMに使う
	void ChangeBGMVolume(int BGM_ID,int gain);							//指定したBGMの音量を変更する
	void PlaySE(int SE_ID,  int gain = 100, bool flag = false);		//第一引数に格納されたSEのIDを指定し再生、第二引数に重複して効果音を鳴らすかどうかの指定、第三引数に音量を指定できる(0~100)デフォルトは100%
	void PlayOneShotSE(int SE_ID, int gain = 100);						//一度だけSEを鳴らす
	void SetOneShotSE();															//ワンショットSEを再セット
	void DeleteBGM();																//格納したBGMを解放し、フラグを再セットする
	void DeleteSE();																//格納したSEを解放
	void PrintID();																//格納しているIDの数を出力する
};
