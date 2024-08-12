
#include"texture.h"


Texture::Texture(const char* texturePath ,GLenum texType , GLenum slot) :textureID{0}, data{ nullptr }, texWidth{ 1 }, texHeight{ 1 }, texChannels{ 1 } {

	data = stbi_load(texturePath, &texWidth, &texHeight, &texChannels,0);

	if (this->texChannels == 1) {
		texFormat = format = GL_RED;
	}
	else if (this->texChannels == 3) {
		texFormat = format = GL_RGB;
	}
	else if (this->texChannels == 4) {
		texFormat = format = GL_RGBA;
	}

	glGenTextures(1,&this->textureID);
	glActiveTexture(slot);

	glBindTexture(texType,this->textureID);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, this->texFormat, texWidth, texHeight, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, 0);

}
void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.programID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
	glUniform1i(texUni, unit);
}
void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D,this->textureID);
}
GLenum Texture::getTextureFormat() {
	return this->format;
}