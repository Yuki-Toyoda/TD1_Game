#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

/*================================
	コピペ用↓
=================================*/

/*********************************
    大見出しコピペ
*********************************/

/******** 小見出しコピペ用 **********/

/*================================
    コピペ用↑
=================================*/

/******** ウィンドウ名の指定 **********/
const char kWindowTitle[] = "LC1A_16_トヨダユウキ_TD1_課題";

/******** ウィンドウサイズの指定 **********/
const int kWinodowWidth = 1280; //x
const int kWindowHeight = 720; //y

/*********************************
    定数の宣言ここまで
*********************************/

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWinodowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/*********************************
		構造体宣言ここから
	*********************************/

	/*================================
		コピペ用↓
	=================================*/

	/*********************************
		大見出しコピペ
	*********************************/

	/********  **********/

	typedef struct vector2 {

		float x; //x
		float y; //y

	};

	typedef struct Distance {

		vector2 distance;
		float length;

	};

	typedef struct chara {

		vector2 translate; //位置
		vector2 moveDirection; //動作方向
		float vectorLength; //ベクトル長さ

		float radius; //当たり判定半径

		float speed; //スピード
		float defSpeed; //スピードデフォルト/

		int HP; //キャラクタHP

		int damage; //与えるダメージ

		int graph; //キャラ画像
		int graphRadius; //画像半径

	};

	/*================================
		コピペ用↑
	=================================*/

	/*********************************
		構造体宣言ここまで
	*********************************/

	/*********************************
		変数宣言ここから
	*********************************/

	vector2 worldPosOrigin{

		0,
		kWindowHeight

	};

	chara player{

		640.0f, 360.0f,
		0.0f, 0.0f,
		0.0f,

		1.0f,

		5.0f,
		5.0f,

		1,

		10,

		Novice::LoadTexture("./resources/graph/player/player.png"),
		128

	};

	/*********************************
		変数宣言ここまで
	*********************************/

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*********************************
			更新処理ここから
		*********************************/

		/*================================
			コピペ用↓
		=================================*/

		/*********************************
		    大見出しコピペ
		*********************************/

		/******** 小見出しコピペ用 **********/

		/*================================
		    コピペ用↑
		=================================*/

		/******** フルスクリーン **********/
		Novice::SetWindowMode(kFullscreen);

		/******** プレイヤー移動 **********/

		//ベクトル初期化
		player.moveDirection.x = 0.0f;
		player.moveDirection.y = 0.0f;

		//キーを押すとその方向に移動する
		if (keys[DIK_UP] || keys[DIK_W]) {

			player.moveDirection.y++;

		}
		
		if (keys[DIK_LEFT] || keys[DIK_A]) {

			player.moveDirection.x--;

		}

		if (keys[DIK_DOWN] || keys[DIK_S]) {

			player.moveDirection.y--;

		}

		if (keys[DIK_LEFT] || keys[DIK_D]) {

			player.moveDirection.x++;

		}

		//ベクトルの長さを求める
		player.vectorLength = sqrt(pow(player.moveDirection.x, 2) + pow(player.moveDirection.y, 2));

		//ベクトルの長さが0以外の時
		if (player.vectorLength != 0.0f) {

			//x方向の移動
			player.translate.x += player.moveDirection.x / player.vectorLength * player.speed;

			//y方向の移動
			player.translate.y += player.moveDirection.y / player.vectorLength * player.speed;

		}
		else {

			player.translate.x += player.moveDirection.x * player.speed;

			player.translate.y += player.moveDirection.y * player.speed;

		}

		/*********************************
			更新処理ここまで
		*********************************/

		/*********************************
			描画処理ここから
		*********************************/

		/*================================
		    コピペ用↓
		=================================*/

		/*********************************
		    大見出しコピペ
		*********************************/

		/******** 小見出しコピペ用 **********/

		/*================================
		    コピペ用↑
		=================================*/

		/******** プレイヤー描画 **********/
		Novice::DrawQuad(

			worldPosOrigin.x + player.translate.x - player.graphRadius / 2,
			worldPosOrigin.y - player.translate.y - player.graphRadius / 2,

			worldPosOrigin.x + player.translate.x + player.graphRadius / 2,
			worldPosOrigin.y - player.translate.y - player.graphRadius / 2,

			worldPosOrigin.x + player.translate.x - player.graphRadius / 2,
			worldPosOrigin.y - player.translate.y + player.graphRadius / 2,

			worldPosOrigin.x + player.translate.x + player.graphRadius / 2,
			worldPosOrigin.y - player.translate.y + player.graphRadius / 2,

			0,
			0,

			player.graphRadius,
			player.graphRadius,

			player.graph,
			WHITE

		);

		/******** プレイヤーデバック描画 **********/

		//座標
		Novice::ScreenPrintf(0, 10, "Px : %4.2f Py : %4.2f", player.translate.x, player.translate.y);

		//スピード
		Novice::ScreenPrintf(0, 30, "PSx : %4.2f PSy : %4.2f", player.speed, player.defSpeed);

		/*********************************
			描画処理ここまで
		*********************************/

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
