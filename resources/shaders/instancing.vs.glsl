#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in mat4 instanceMatrix;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * instanceMatrix * vec4(position, 1.0f);
    TexCoords = texCoords;
    FragPos = vec3(instanceMatrix * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(instanceMatrix))) * normal;
}
