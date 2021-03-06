#include "Rect.h"

#include <sstream>

Rect::Rect() {
	pos = Vector3(0);
	size = Vector3(0);
	UpdateVertices();
}

Rect::Rect(Vector3 _size) {
	pos = Vector3(0);
	size = Vector3(_size);
	UpdateVertices();
}

Rect::Rect(Vector3 _pos, Vector3 _size) : Rect(_size) { // basically the function after the colon means that that function is done first, then the function in the curly braces
	pos = _pos;
	UpdateVertices();
}

void Rect::MoveBy(Vector3 by) {
	pos = pos + by;
	UpdateVertices();
}

void Rect::MoveTo(Vector3 to) {
	pos = to;
	UpdateVertices();
}

void Rect::SetSize(Vector3 _size) {
	size = _size;
	UpdateVertices();
}

string Rect::ToString() {
	stringstream ss;
	ss << "Pos(" << pos.x << ", " << pos.y << ", " << pos.z << ") - Size(" << size.x << ", " << size.y << ", " << size.z << ")";
	ss << "LL.X: " << lowerLeftVertex.x << "\tY: " << lowerLeftVertex.y << endl;
	ss << "UR.X: " << upperRightVertex.x << "\tY: " << upperRightVertex.y << endl;
	return ss.str();
}

void Rect::UpdateVertices() {
	lowerLeftVertex		= (Vector3(pos.x - (size.x / 2), pos.y - (size.y / 2), 0));
	lowerRightVertex	= (Vector3(pos.x + (size.x / 2), pos.y - (size.y / 2), 0));
	upperLeftVertex		= (Vector3(pos.x - (size.x / 2), pos.y + (size.y / 2), 0));
	upperRightVertex	= (Vector3(pos.x + (size.x / 2), pos.y + (size.y / 2), 0));
}