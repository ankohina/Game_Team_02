
#include "Collison.h"

//IsHitRectの定義(四角)
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// 当たっているときの処理
		return true;
	}
	return false;
}

//IsHitCircleの定義(円)
bool IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr) {
	if ((CircleAr + CircleBr) * (CircleAr + CircleBr) >
		(CircleAx - CircleBx) * (CircleAx - CircleBx) + (CircleAy - CircleBy) * (CircleAy - CircleBy))
	{
		// 当たっているときの処理
		return true;
	}
	return false;
}
