#version 330 core
out vec4 fcol;
uniform vec3 ucol;
void main(){
    fcol=vec4(ucol.rgb,1.0f); // uniform with 100% alpha
}
