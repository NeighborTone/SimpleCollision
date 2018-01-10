#pragma once
#include "DxLib.h"
#include <vector>
#include<map>
#include<string>
//DxLibのサウンドを改造したクラス。IDはロードした順に0から振られる。
class Sound
{
private:
	bool flag;																		//BGM再生フラグ
	std::vector<int>BGM;															//BGMデータ格納用
	std::vector<int>SE;															//SEデータ格納用
	std::map<std::string, int> m_se;
public:
	int Volume;																		//音量用（あんまり意味ないけど...）
	Sound() { Volume = 0; };														//コンストラクタ
	~Sound() {};																	//デストラクタ
	void SetSE(const char *FileName);										//第一引数にSEをのパスを指定しロードする。複数ロードでき、配列の後ろに格納される(0~)
	void SetBGM(const char *FileName);										//BGMのパスを指定してロードし、再生フラグを立てる
	void SinglePlayBGM_Loop(int gain = 100);								//BGMをループ再生。引数に音量を指定できる(0~100)デフォルトは100%
	void SinglePlayBGM_Back(int gain = 100);								//BGMをループなしで再生。引数に音量を指定できる(0~100)デフォルトは100%
	void MultiPlayBGM_Loop();													//複数のBGMを同時ループ再生する。主にインタラクティブなBGMに使う
	void ChangeBGMVolume(int BGM_ID,int gain);							//指定したBGMの音量を変更する
	void PlaySE(int SE_ID, bool flag = false, int gain = 100);		//第一引数に格納されたSEのIDを指定し再生、第二引数に重複して効果音を鳴らすかどうかの指定、第三引数に音量を指定できる(0~100)デフォルトは100%
	void DeleteBGM();																//格納したBGMを解放し、フラグを再セットする
	void DeleteSE();																//格納したSEを解放
	void PrintID();
};
