#version 330 core

layout(location = 0) in vec2 vertexPosition;
out vec4 fColor;

void main() {
     fColor = vec4(0.5, 0.4, 0.8, 1.0);
     gl_Position.xy = vertexPosition;
     gl_Position.z = 0.0;
     gl_Position.w = 1.0;
}