#include "Building.h"

Building::Building(float width, float leght, float height, int x, int y, int z, Texture* texture)
{
	this->width = width;
	this->leght = leght;
	this->height = height;
	this->rect.x = x;
	this->rect.y = y;
	this->rect.z = z;
	this->_texture = texture;
	this->_box = NULL;
}
Building::~Building()
{

}
void Building::CreateBuilding()
{
	_box = BasicCad::MakeBox(leght, width, height);
	glPushMatrix();
	glTranslatef(rect.x, rect.y, rect.z);
	glEnable(GL_TEXTURE_2D);
	_texture->Bin();
	glCallList(_box);
	_texture->UnBin();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}