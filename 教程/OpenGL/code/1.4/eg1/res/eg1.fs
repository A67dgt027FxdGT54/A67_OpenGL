#version 330 core
out vec4 fcol;
in vec3 tcol;
in vec2 ttex;
uniform sampler2D tex;
void main(){
    fcol=texture(tex,ttex); 
}
