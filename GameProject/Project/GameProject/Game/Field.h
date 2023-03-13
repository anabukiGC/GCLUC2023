#pragma once
//Taskを継承
class Field : public Task {
private:
	//画像オブジェクト(前景)
	CImage m_foreground;
	//画像オブジェクト(遠景)
	CImage m_town;
	//画像オブジェクト(最遠景)
	//CImage m_sky;
	//地面の高さ
	float m_ground_y;
	//描画タスク
	DrawTask* m_drawTask;
public:
	//コンストラクタ
	Field();
	//破棄時に描画タスクを取り除きたいためデストラクタが必要
	~Field();
	//オーバーライド必須
	void Update(float deltatime);
	//描画
	void Draw();

	//地面の高さを取得
	float GetGroundY() {
		return m_ground_y;
	}
};