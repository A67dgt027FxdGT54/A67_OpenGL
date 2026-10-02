#version 330 core
layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec3 v_col;
layout (location = 2) in vec2 v_tex;
out vec3 tcol;
out vec2 ttex;
uniform mat4 tr;
void main(){
    gl_Position=tr*vec4(v_pos.x,v_pos.y,v_pos.z,1.0);
    tcol=v_col;
    ttex=v_tex;
}
