#version 330 core
out vec4 fcol;
in vec3 tcol;
void main(){
    fcol=vec4(tcol.rgb,1.0);
}
