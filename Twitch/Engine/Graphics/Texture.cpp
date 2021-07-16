#include "Texture.h"

Texture::Texture() {
	id = -1; // what opengl uses to identify the texture 
}

Texture::Texture(int _id) {
	id = _id;
	if (!GetTextureParams()) {
		cout << "Error loading image with ID" << _id << endl;
	}
}

int Texture::GetID() {
	return id;
}

int Texture::GetWidth() {
	return width;
}

int Texture::GetHeight() {
	return height;
}

Texture::Texture(string path) {

	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams()) {
		cout << "Error loading image with path" << path << endl;
	}
}

bool Texture::GetTextureParams() {

	if (id > 0) { // if id is positive, the image loading works
		int miplevel = 0;
		glBindTexture(GL_TEXTURE_2D, id); // we bind our id (a png we loaded) to a GL_TEXTURE_2D so we can reference it in the next two liens
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &height);

		return true;

	}

	return false;
}