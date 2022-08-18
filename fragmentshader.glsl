#version 330 core

in vec3 encol

out vec4 color;

void main()
{
	color = vec4(encol, 1.0f);
}