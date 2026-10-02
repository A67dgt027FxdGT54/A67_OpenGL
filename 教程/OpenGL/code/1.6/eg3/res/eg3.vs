#version 330 core
layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec2 v_tex;
out vec2 ttex;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
void main(){
    gl_Position=proj*view*model*vec4(v_pos.x,v_pos.y,v_pos.z,1.0);
    ttex=v_tex;
}
