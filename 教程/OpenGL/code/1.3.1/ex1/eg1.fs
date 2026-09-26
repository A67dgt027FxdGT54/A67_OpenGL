#version 330 core
out vec4 fcol;
in vec3 tpos;
void main(){
    fcol=vec4(tpos.xyz,1.0);
}
