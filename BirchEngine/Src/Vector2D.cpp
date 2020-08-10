#include "Vector2D.h"

//constructors

Vector2D::Vector2D()
{
	x = 0.0f;
	y = 0.0f;

}

//overload constructor

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

// math functions

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->x += x;
	this->y += y;

	return *this; // return the vector
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
	this->x -= x;
	this->y -= y;

	return *this; // return the vector
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	this->x *= x;
	this->y *= y;

	return *this; // return the vector
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	this->x /= x;
	this->y /= y;

	return *this; // return the vector
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{

	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{

	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{

	return v1.Multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{

	return v1.Divide(v2);
}