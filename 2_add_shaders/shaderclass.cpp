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
	else {
		std::cout << "Can't fine the file\n";
	}
	//throw(errno);
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

	this->compileErrors(vertexShader,shaderType::VERTEX);
	this->compileErrors(fragmentShader, shaderType::FRAGMENT);

	this->programID = glCreateProgram();
	glAttachShader(this->programID, vertexShader);
	glAttachShader(this->programID, fragmentShader);
	glLinkProgram(this->programID);

	this->compileErrors(this->programID, shaderType::PROGRAM);
}

void Shader::createProgram(const GLuint vertex ,const GLuint fragment) {

	this->programID = glCreateProgram();
	glAttachShader(this->programID, vertex);
	glAttachShader(this->programID, fragment);
	glLinkProgram(this->programID);

	this->compileErrors(this->programID, shaderType::PROGRAM);
	
}
void Shader::compileErrors(GLuint shaderId ,shaderType type ) {

	char infoLogs[1024];
	int sucess;

	if (type == shaderType::VERTEX) {
		glGetShaderiv(shaderId,GL_COMPILE_STATUS,&sucess);

		if (!sucess) {
			glGetShaderInfoLog(shaderId, 1024,NULL , infoLogs);
			std::cout << "Failed to Compile the Vertex Shader\n";

		}

	}
	else if (type == shaderType::FRAGMENT) {
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &sucess);

		if (!sucess) {
			glGetShaderInfoLog(shaderId,1024,NULL,infoLogs);
			std::cout << "Failed to Compile the Fragment Shader\n";
		}
	}
	else if (type == shaderType::PROGRAM) {

		glGetProgramiv(shaderId,GL_LINK_STATUS,&sucess);

		if (!sucess) {
			glGetProgramInfoLog(shaderId,1024,NULL,infoLogs);
			std::cout << "Failed to Link the Shader Program\n";
		}
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