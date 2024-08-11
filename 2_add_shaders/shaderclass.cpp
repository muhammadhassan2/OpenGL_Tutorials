#include"shaderclass.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char *vertexShader_ , const char *fragmentShader_) {

	this->vertexCode = get_file_contents(vertexShader_);
	this->fragmentCode = get_file_contents(fragmentShader_);


	const char* vertexSource,* fragmentSource;

	vertexSource = this->vertexCode.c_str();
	fragmentSource = this->fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);



}
void Shader::compileErrors(GLuint shaderId ,shaderType type ) {

	if (type == shaderType::VERTEX) {


	}
	else if (type == shaderType::FRAGMENT) {

	}
	else if (type == shaderType::PROGRAM) {

	}

}
void Shader::setFloat(const std::string &uniform_name , float value) {

}

void Shader::setInt(const std::string& uniform_name, int value) {

}

void Shader::Activate() {
	glUseProgram(programID);
}

void Shader::Delete() {
	glDeleteProgram(programID);
}